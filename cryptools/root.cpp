#include "root.h"

#define exitDuration 350
#define exitCurve QEasingCurve::OutCirc

root::root()
{
    setWindowTitle("cryptools");
    setMinimumWidth(300);
    setMinimumHeight(140);
    setCentralWidgetMargin(10, 10);
    setWindowIcon(QIcon(":/Icons/window_icon.png"));
    setTitleBarIcon(QPixmap(":/Icons/window_icon.png"));

    r_cWidget = new CoreWidget(this);

    setCentralWidget(r_cWidget);

    exitAnimation = new QPropertyAnimation(this, "geometry");
    exitAnimation->setDuration(exitDuration);

    connect(exitAnimation, SIGNAL(finished()), qApp, SLOT(quit()));
}

void root::closeEvent(QCloseEvent *event)
{
    showNormal();
    setMinimumSize(0, 0);
    exitAnimation->setStartValue(QRect(x(), y(), width(), height()));
    exitAnimation->setEasingCurve(QEasingCurve(exitCurve));
    exitAnimation->setEndValue(QRect(x(), y()+height()/2, width(), 0));
    exitAnimation->start();
    event->ignore();
}

