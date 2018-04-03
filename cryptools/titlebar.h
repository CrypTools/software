#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QTime>
#include <QWidget>
#include <QLabel>
#include "buttons.h"

class WindowButton;

class titleBar : public QWidget
{
    Q_OBJECT
public:
    explicit titleBar(QWidget *parent = 0);

    WindowButton *minimizeButton;
    WindowButton *maximizeButton;
    WindowButton *closeButton;
    WindowButton *unmaximizeButton;

    QTime m_last_time;

    QLabel *separator;
    QLabel *title_bar_icon;
    QLabel *titleWidget;

    void changeTitle(QString title);

signals:
protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent  (QMouseEvent  *event);
    void mouseReleaseEvent(QMouseEvent  *event);
    void mouseMoveEvent   (QMouseEvent  *event);
signals:
    void movement(QMouseEvent *event);
    void clickMouseSignal(QMouseEvent *event);
    void releaseMouseSignal(QMouseEvent *event);

public slots:
    void setIcon(QPixmap icon);
};

#endif // TITLEBAR_H
