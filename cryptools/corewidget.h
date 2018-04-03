#ifndef COREWIDGET_H
#define COREWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include "custombutton.h"
class CustomButton;
#include "tools/tools.h"
#include "tools/vigeneregroupwidget.h"
class VigenereGroupWidget;

class CoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CoreWidget(QWidget *parent = 0);

    QGridLayout *w_layout;

    VigenereGroupWidget *vige;

signals:

public slots:
    void experimentalSlot();
//protected:
//    void resizeEvent(QResizeEvent *event);
};

#endif // COREWIDGET_H