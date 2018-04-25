#include "rsawidget.h"
#include "ui_rsawidget.h"

rsaWidget::rsaWidget(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::rsaWidget)
{
    ui->setupUi(this);

    ui->encryptButton->setEnabled(false);
    ui->decryptButton->setEnabled(false);
}

rsaWidget::~rsaWidget()
{
    delete ui;
}
