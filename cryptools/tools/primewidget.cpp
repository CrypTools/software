#include "primewidget.h"
#include "ui_primewidget.h"

primeWidget::primeWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::primeWidget)
{
    ui->setupUi(this);

    ui->logText->hide();
    ui->stopButton->setEnabled(false);
    ui->buttonBox->buttons().value(0)->setEnabled(false);

    generatorInst = new generator;
    generatorInst->moveToThread(&calcThread);

    connect(&calcThread, &QThread::finished, generatorInst, &QObject::deleteLater);
    connect(this, &primeWidget::startCalc, generatorInst, &generator::primeGenerator);
    connect(generatorInst, &generator::finished, this, &primeWidget::whenFinished);
    connect(generatorInst, &generator::numberTested, this, &primeWidget::testLog);
    calcThread.start();
}

primeWidget::~primeWidget()
{
    calcThread.quit();
    calcThread.wait();
    delete ui;
}

void primeWidget::on_checkBox_clicked()
{
    ui->logText->setHidden(ui->checkBox->isChecked()^1);
}

void primeWidget::on_startButton_clicked()
{
    ui->buttonBox->buttons().value(1)->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
    c = 0;
    emit startCalc(ui->amountSpin->value(), ui->lenghtSpin->value(), results);
}

void primeWidget::on_stopButton_clicked()
{
    generatorInst->running = false;
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->buttonBox->buttons().value(1)->setEnabled(true);
    whenFinished(); //cheating
    ui->logText->setPlainText("Aborted");
    ui->buttonBox->buttons().value(0)->setEnabled(false);
}

void primeWidget::whenFinished()
{
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->buttonBox->buttons().value(1)->setEnabled(true);
    ui->buttonBox->buttons().value(0)->setEnabled(true);
    ui->logText->clear();
    for (int i=0; i<ui->amountSpin->value(); ++i){
        ui->logText->appendPlainText("Prime " + QString::number(i) + ": " + QString::fromStdString(results[i].get_str()) + "\n\n");
    }
}

void primeWidget::testLog()
{
    c+=1;
    ui->lcdNumber->display(c);
    ui->logText->appendPlainText("\nTested: " +  QString::number(c));
}
