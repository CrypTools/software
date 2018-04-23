#include "caesargroupwidget.h"
#include "ui_caesargroupwidget.h"

caesarGroupWidget::caesarGroupWidget(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::caesarGroupWidget)
{
    ui->setupUi(this);
}

caesarGroupWidget::~caesarGroupWidget()
{
    delete ui;
}

void caesarGroupWidget::on_showShiftCheckBox_stateChanged()
{
    if (ui->showShiftCheckBox->isChecked())
        ui->shiftLineEdit->setEchoMode(QLineEdit::Normal);
    else
        ui->shiftLineEdit->setEchoMode(QLineEdit::Password);
}

void caesarGroupWidget::on_encryptButton_clicked()
{
    ui->outputText->setText(caesarEncrypt(ui->inputText->toPlainText(), ui->shiftLineEdit->text().toInt()));
}

void caesarGroupWidget::on_decryptButton_clicked()
{
    ui->outputText->setText(caesarDecrypt(ui->inputText->toPlainText(), ui->shiftLineEdit->text().toInt()));
}
