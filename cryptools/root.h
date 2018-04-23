#ifndef ROOT_H
#define ROOT_H

#include <QLabel>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QCloseEvent>

#include "window.h"
class window;
#include "corewidget.h"
class CoreWidget;

class root : public window
{
    Q_OBJECT

public:
    root();
private:
    CoreWidget *r_cWidget;
    QPropertyAnimation *exitAnimation;

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // ROOT_H
