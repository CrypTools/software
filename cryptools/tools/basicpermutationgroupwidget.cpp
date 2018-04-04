#include "basicpermutationgroupwidget.h"
#include "ui_basicpermutationgroupwidget.h"

BasicPermutationGroupWidget::BasicPermutationGroupWidget(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::BasicPermutationGroupWidget)
{
    ui->setupUi(this);
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
{}
