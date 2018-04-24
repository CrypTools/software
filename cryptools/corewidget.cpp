#include "corewidget.h"

CoreWidget::CoreWidget(QWidget *parent) : QWidget(parent)
{
    w_layout = new QGridLayout(this);

    vige = new VigenereGroupWidget(this);

    cesar = new caesarGroupWidget(this);

    permute = new BasicPermutationGroupWidget(this);
    permute->hide();

    primeDialog = new primeWidget(this);
    primeDialog->hide();
    primeDialog->setModal(true);

    button = new QPushButton("Prime dialog", this);

    w_layout->addWidget(vige, 0, 0, 8, 2);
    w_layout->addWidget(cesar, 0, 2, 8, 2);
    w_layout->addWidget(button, 0, 4, 2, 2);
    //w_layout->addWidget(permute, 0, 4, 8, 2);

    connect(button, SIGNAL(clicked(bool)), this, SLOT(experimentalSlot()));
}


void CoreWidget::experimentalSlot()
{
    primeDialog->show();
}

