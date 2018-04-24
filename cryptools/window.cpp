#include "window.h"

window::window(QWidget *parent) : QWidget(parent), rec(QGuiApplication::primaryScreen()->geometry())
{
    setWindowFlags(Qt::FramelessWindowHint);

    //time_t m_last_time;

    titleBarWidget = new titleBar(this);
    sizeGrip = new QSizeGrip(this);
    sizeGrip->move(width()-10, height()-10);

    connect(titleBarWidget->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(titleBarWidget->minimizeButton, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
    connect(titleBarWidget->maximizeButton, SIGNAL(clicked(bool)), this, SLOT(maximizeClicked()));
    connect(titleBarWidget->unmaximizeButton, SIGNAL(clicked(bool)), this, SLOT(maximizeClicked()));

    connect(titleBarWidget, SIGNAL(clickMouseSignal(QMouseEvent*)), this, SLOT(clickedMouse(QMouseEvent*)));
    connect(titleBarWidget, SIGNAL(releaseMouseSignal(QMouseEvent*)), this, SLOT(releasedMouse(QMouseEvent*)));
    connect(titleBarWidget, SIGNAL(movement(QMouseEvent*)), this, SLOT(moveWindow(QMouseEvent*)));

    centralWidget = new QWidget(this);

    xMargin = new int;
    yMargin = new int;

    *xMargin = 10;
    *yMargin = 10;

    if (isMaximized())
        titleBarWidget->maximizeButton->hide();
    else
        titleBarWidget->unmaximizeButton->hide();
}

void window::maximizeClicked()
{
    if (isMaximized()) {
        showNormal();
        resize(normalWidth, normalHeight);
        move(normalX, normalY);
        titleBarWidget->unmaximizeButton->hide();
        titleBarWidget->maximizeButton->show();
    } else {
        normalWidth = width(); normalHeight = height();
        normalX = x(); normalY = y();
        showMaximized();
        titleBarWidget->maximizeButton->hide();
        titleBarWidget->unmaximizeButton->show();
    }
}

void window::moveWindow(QMouseEvent *event)
{

    QPoint p = event->globalPos();

    move(p.x() - m_DiffX, p.y() - m_DiffY);
//    shadowWidget->setGeometry(-20, -20, width()+40, height()+40);
}

void window::clickedMouse(QMouseEvent *event)
{
    m_DiffX = event->x();
    m_DiffY = event->y();

    setCursor(QCursor(Qt::SizeAllCursor));
}

void window::releasedMouse(QMouseEvent *event)
{
    Q_UNUSED(event);

    setCursor(QCursor(Qt::ArrowCursor));
}

void window::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    titleBarWidget->resize(width(), 40);
    sizeGrip->move(width()-10, height()-10);
    centralWidget->setGeometry(*xMargin, 40+*yMargin, width()-2*(*xMargin), height()-40-2*(*yMargin));
//    shadowWidget->setGeometry(-20, -20, width()+40, height()+40);
}

void window::setWindowTitle(const QString &titleString)
{
    titleBarWidget->changeTitle(titleString);
}

void window::setTitleBarIcon(QPixmap icon)
{
    titleBarWidget->setIcon(icon);
}

void window::setCentralWidget(QWidget *widget)
{
    centralWidget = widget;
    centralWidget->setGeometry(*xMargin, 40+*yMargin, width()-2*(*xMargin), height()-40-2*(*yMargin));
}

void window::setCentralWidgetMargin(int x, int y)
{
    *xMargin = x;
    *yMargin = y;
}
