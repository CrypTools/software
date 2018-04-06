#ifndef BASICPERMUTATIONGROUPWIDGET_H
#define BASICPERMUTATIONGROUPWIDGET_H

#include <QMessageBox>
#include <QGroupBox>
#include "tools.h"
class tools;

namespace Ui {
class BasicPermutationGroupWidget;
}

class BasicPermutationGroupWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit BasicPermutationGroupWidget(QWidget *parent = 0);
    ~BasicPermutationGroupWidget();

private:
    Ui::BasicPermutationGroupWidget *ui;
public slots:
    void on_showKeyCheckBox_stateChanged();
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();
    void on_advancedCheckBox_stateChanged();
};

#endif // BASICPERMUTATIONGROUPWIDGET_H
