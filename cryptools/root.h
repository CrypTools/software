#ifndef ROOT_H
#define ROOT_H

#include <QLabel>
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


};

#endif // ROOT_H
