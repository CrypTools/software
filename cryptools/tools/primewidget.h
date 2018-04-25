#ifndef PRIMEWIDGET_H
#define PRIMEWIDGET_H

#include <QDialog>
#include <QThread>
#include <QDebug>
#include <QAbstractButton>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <gmpxx.h>

#include "prime-generator.h"
class generator;

namespace Ui {
class primeWidget;
}

class primeWidget : public QDialog
{
    Q_OBJECT

public:
    explicit primeWidget(QWidget *parent = 0);
    ~primeWidget();

private:
    Ui::primeWidget *ui;
    QThread calcThread;
    generator *generatorInst;
    mpz_class results[2147000];
    int c, numbers, lenght;
    QString plaintext;
public slots:
    void on_checkBox_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_buttonBox_clicked(QAbstractButton *button);
    void whenFinished();
    void testLog();
signals:
    void startCalc(int number, int lenght, mpz_class *results);
};

#endif // PRIMEWIDGET_H
