#include "corewidget.h"

CoreWidget::CoreWidget(QWidget *parent) : QWidget(parent)
{
    w_layout = new QGridLayout(this);

    vige = new VigenereGroupWidget(this);

    cesar = new caesarGroupWidget(this);

    permute = new BasicPermutationGroupWidget(this);

    w_layout->addWidget(vige, 0, 0, 8, 2);
    w_layout->addWidget(cesar, 0, 2, 8, 2);
    w_layout->addWidget(permute, 0, 4, 8, 2);
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
