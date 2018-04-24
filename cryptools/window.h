#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDebug>
#include <QSizeGrip>
#include <QPoint>
#include <QMouseEvent>
#include <QRect>
#include <QList>
#include <QApplication>
#include <QScreen>
#include <QPropertyAnimation>
#include <QGuiApplication>
#include "titlebar.h"
class titleBar;

class window : public QWidget
{
    Q_OBJECT
public:
    explicit window(QWidget *parent = 0);

    QSizeGrip *sizeGrip;
    titleBar *titleBarWidget;

    QRect rec;

    int m_DiffX, normalWidth, normalX;
    int m_DiffY, normalHeight, normalY;

    int *xMargin;
    int *yMargin;

    QWidget *centralWidget;

    void setWindowTitle(const QString &titleString);
    void setTitleBarIcon(QPixmap icon);
    void setCentralWidget(QWidget *widget);
    void setCentralWidgetMargin(int x, int y);
signals:
protected:
    void resizeEvent(QResizeEvent *event);
private:

public slots:
    void maximizeClicked();
    void moveWindow(QMouseEvent *event);
    void clickedMouse(QMouseEvent *event);
    void releasedMouse(QMouseEvent *event);
};

#endif // WINDOW_H
