#include "basicpermutationgroupwidget.h"
#include "ui_basicpermutationgroupwidget.h"

BasicPermutationGroupWidget::BasicPermutationGroupWidget(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BasicPermutationGroupWidget)
{
    ui->setupUi(this);
    ui->inputWritingDir->hide();
    ui->outputReadingDir->hide();

}

BasicPermutationGroupWidget::~BasicPermutationGroupWidget()
{
    delete ui;
}

void BasicPermutationGroupWidget::on_showKeyCheckBox_stateChanged()
{
    if (ui->showKeyCheckBox->isChecked())
        ui->keyLine->setEchoMode(QLineEdit::Normal);
    else
        ui->keyLine->setEchoMode(QLineEdit::Password);
}

void BasicPermutationGroupWidget::on_encryptButton_clicked()
{
    QMessageBox::warning(this, "Warning", "This function is too unstable and therefore cannot be used yet !");
    return;
    switch (ui->directionComboBox->currentIndex()) {
    case 0:
        ui->outputText->setText(permutationEncrypt(tools::Column, ui->inputText->toPlainText(), ui->keyLine->text()));
        break;
    case 1:
        ui->outputText->setText(permutationEncrypt(tools::Row, ui->inputText->toPlainText(), ui->keyLine->text()));
        break;
    case 2:
        ui->outputText->setText(permutationEncrypt(tools::Grid, ui->inputText->toPlainText(), ui->keyLine->text()));
        break;
    }
}

void BasicPermutationGroupWidget::on_decryptButton_clicked()
{
    QMessageBox::warning(this, "Warning", "This function is too unstable and therefore cannot be used yet !");
    return;
}

void BasicPermutationGroupWidget::on_advancedCheckBox_stateChanged()
{
    if (ui->advancedCheckBox->isChecked()){
        ui->inputWritingDir->show();
        ui->outputReadingDir->show();
    }
    else  {
        ui->inputWritingDir->hide();
        ui->outputReadingDir->hide();
    }

}
