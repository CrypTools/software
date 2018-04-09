#ifndef VIGENEREGROUPWIDGET_H
#define VIGENEREGROUPWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QTextCursor>
#include "tools.h"

class VigenereGroupWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit VigenereGroupWidget(QWidget *parent = 0);

    QGridLayout *vigenereLayout;

    QTextEdit *vigenereInputText;
    QTextEdit *vigenereOutputText;
    QLineEdit *vigenereKeyLine;
    QPushButton *decryptButtonVigenere;
    QPushButton *encryptButtonVigenere;
    QCheckBox *vigenereShowKeyCheckBox;
    QCheckBox *vigenereAlphabetOnlyCheckBox;
    QCheckBox *vigenereShowShiftsCheckBox;
    QLineEdit *vigenereShiftsLine;

signals:

public slots:
    void unselect_output();
    void vigenereEncryptSlot();
    void vigenereDecryptSlot();
    void updateVigenereKeyLine();
    void updateShiftLine();
    void updateShiftState();
};

#endif // VIGENEREGROUPWIDGET_H
