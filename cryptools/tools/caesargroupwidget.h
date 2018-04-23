#ifndef CAESARGROUPWIDGET_H
#define CAESARGROUPWIDGET_H

#include <QGroupBox>
#include "tools.h"

namespace Ui {
class caesarGroupWidget;
}

class caesarGroupWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit caesarGroupWidget(QWidget *parent = 0);
    ~caesarGroupWidget();

private:
    Ui::caesarGroupWidget *ui;
public slots:
    void on_showShiftCheckBox_stateChanged();
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();
};

#endif // CAESARGROUPWIDGET_H
