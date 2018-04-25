#ifndef RSAWIDGET_H
#define RSAWIDGET_H

#include <QGroupBox>

namespace Ui {
class rsaWidget;
}

class rsaWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit rsaWidget(QWidget *parent = 0);
    ~rsaWidget();

private:
    Ui::rsaWidget *ui;
};

#endif // RSAWIDGET_H
