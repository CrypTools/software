/********************************************************************************
** Form generated from reading UI file 'caesargroupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAESARGROUPWIDGET_H
#define UI_CAESARGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_caesarGroupWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *inputText;
    QCheckBox *showShiftCheckBox;
    QLineEdit *shiftLineEdit;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QTextEdit *outputText;

    void setupUi(QGroupBox *caesarGroupWidget)
    {
        if (caesarGroupWidget->objectName().isEmpty())
            caesarGroupWidget->setObjectName(QStringLiteral("caesarGroupWidget"));
        caesarGroupWidget->resize(400, 300);
        gridLayout = new QGridLayout(caesarGroupWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        inputText = new QTextEdit(caesarGroupWidget);
        inputText->setObjectName(QStringLiteral("inputText"));

        gridLayout->addWidget(inputText, 0, 0, 1, 2);

        showShiftCheckBox = new QCheckBox(caesarGroupWidget);
        showShiftCheckBox->setObjectName(QStringLiteral("showShiftCheckBox"));

        gridLayout->addWidget(showShiftCheckBox, 1, 0, 1, 1);

        shiftLineEdit = new QLineEdit(caesarGroupWidget);
        shiftLineEdit->setObjectName(QStringLiteral("shiftLineEdit"));
        shiftLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(shiftLineEdit, 1, 1, 1, 1);

        encryptButton = new QPushButton(caesarGroupWidget);
        encryptButton->setObjectName(QStringLiteral("encryptButton"));

        gridLayout->addWidget(encryptButton, 2, 0, 1, 1);

        decryptButton = new QPushButton(caesarGroupWidget);
        decryptButton->setObjectName(QStringLiteral("decryptButton"));

        gridLayout->addWidget(decryptButton, 2, 1, 1, 1);

        outputText = new QTextEdit(caesarGroupWidget);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setReadOnly(true);

        gridLayout->addWidget(outputText, 3, 0, 1, 2);


        retranslateUi(caesarGroupWidget);

        QMetaObject::connectSlotsByName(caesarGroupWidget);
    } // setupUi

    void retranslateUi(QGroupBox *caesarGroupWidget)
    {
        caesarGroupWidget->setWindowTitle(QApplication::translate("caesarGroupWidget", "GroupBox", nullptr));
        caesarGroupWidget->setTitle(QApplication::translate("caesarGroupWidget", "Caesar", nullptr));
        inputText->setPlaceholderText(QApplication::translate("caesarGroupWidget", "Input", nullptr));
        showShiftCheckBox->setText(QApplication::translate("caesarGroupWidget", "Show shift value", nullptr));
        shiftLineEdit->setPlaceholderText(QApplication::translate("caesarGroupWidget", "Shift", nullptr));
        encryptButton->setText(QApplication::translate("caesarGroupWidget", "Encrypt", nullptr));
        decryptButton->setText(QApplication::translate("caesarGroupWidget", "Decrypt", nullptr));
        outputText->setPlaceholderText(QApplication::translate("caesarGroupWidget", "Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class caesarGroupWidget: public Ui_caesarGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAESARGROUPWIDGET_H
