#include "corewidget.h"

CoreWidget::CoreWidget(QWidget *parent) : QWidget(parent)
{
    w_layout = new QGridLayout(this);

    vige = new VigenereGroupWidget(this);

    w_layout->addWidget(vige, 0, 0, 8, 2);
}


void CoreWidget::experimentalSlot()
{
    QMessageBox::warning(this, "hey", "don't click me !");
}

//void CoreWidget::resizeEvent(QResizeEvent *event)
//{
//    Q_UNUSED(event);

//    vige->resize(width(), height());
//}