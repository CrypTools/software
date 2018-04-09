/********************************************************************************
** Form generated from reading UI file 'basicpermutationgroupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICPERMUTATIONGROUPWIDGET_H
#define UI_BASICPERMUTATIONGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BasicPermutationGroupWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *inputText;
    QCheckBox *showKeyCheckBox;
    QLineEdit *keyLine;
    QComboBox *directionComboBox;
    QCheckBox *advancedCheckBox;
    QComboBox *inputWritingDir;
    QComboBox *outputReadingDir;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QTextEdit *outputText;

    void setupUi(QGroupBox *BasicPermutationGroupWidget)
    {
        if (BasicPermutationGroupWidget->objectName().isEmpty())
            BasicPermutationGroupWidget->setObjectName(QStringLiteral("BasicPermutationGroupWidget"));
        BasicPermutationGroupWidget->resize(409, 411);
        gridLayout = new QGridLayout(BasicPermutationGroupWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        inputText = new QTextEdit(BasicPermutationGroupWidget);
        inputText->setObjectName(QStringLiteral("inputText"));

        gridLayout->addWidget(inputText, 0, 0, 1, 2);

        showKeyCheckBox = new QCheckBox(BasicPermutationGroupWidget);
        showKeyCheckBox->setObjectName(QStringLiteral("showKeyCheckBox"));

        gridLayout->addWidget(showKeyCheckBox, 1, 0, 1, 1);

        keyLine = new QLineEdit(BasicPermutationGroupWidget);
        keyLine->setObjectName(QStringLiteral("keyLine"));
        keyLine->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(keyLine, 1, 1, 1, 1);

        directionComboBox = new QComboBox(BasicPermutationGroupWidget);
        directionComboBox->addItem(QString());
        directionComboBox->addItem(QString());
        directionComboBox->addItem(QString());
        directionComboBox->setObjectName(QStringLiteral("directionComboBox"));

        gridLayout->addWidget(directionComboBox, 2, 0, 1, 1);

        advancedCheckBox = new QCheckBox(BasicPermutationGroupWidget);
        advancedCheckBox->setObjectName(QStringLiteral("advancedCheckBox"));

        gridLayout->addWidget(advancedCheckBox, 2, 1, 1, 1);

        inputWritingDir = new QComboBox(BasicPermutationGroupWidget);
        inputWritingDir->addItem(QString());
        inputWritingDir->addItem(QString());
        inputWritingDir->setObjectName(QStringLiteral("inputWritingDir"));

        gridLayout->addWidget(inputWritingDir, 3, 0, 1, 1);

        outputReadingDir = new QComboBox(BasicPermutationGroupWidget);
        outputReadingDir->addItem(QString());
        outputReadingDir->addItem(QString());
        outputReadingDir->setObjectName(QStringLiteral("outputReadingDir"));

        gridLayout->addWidget(outputReadingDir, 3, 1, 1, 1);

        encryptButton = new QPushButton(BasicPermutationGroupWidget);
        encryptButton->setObjectName(QStringLiteral("encryptButton"));

        gridLayout->addWidget(encryptButton, 4, 0, 1, 1);

        decryptButton = new QPushButton(BasicPermutationGroupWidget);
        decryptButton->setObjectName(QStringLiteral("decryptButton"));

        gridLayout->addWidget(decryptButton, 4, 1, 1, 1);

        outputText = new QTextEdit(BasicPermutationGroupWidget);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setReadOnly(true);

        gridLayout->addWidget(outputText, 5, 0, 1, 2);


        retranslateUi(BasicPermutationGroupWidget);

        QMetaObject::connectSlotsByName(BasicPermutationGroupWidget);
    } // setupUi

    void retranslateUi(QGroupBox *BasicPermutationGroupWidget)
    {
        BasicPermutationGroupWidget->setWindowTitle(QApplication::translate("BasicPermutationGroupWidget", "GroupBox", nullptr));
        BasicPermutationGroupWidget->setTitle(QApplication::translate("BasicPermutationGroupWidget", "Permutation", nullptr));
        inputText->setPlaceholderText(QApplication::translate("BasicPermutationGroupWidget", "Input", nullptr));
        showKeyCheckBox->setText(QApplication::translate("BasicPermutationGroupWidget", "Show key", nullptr));
        keyLine->setPlaceholderText(QApplication::translate("BasicPermutationGroupWidget", "Key", nullptr));
        directionComboBox->setItemText(0, QApplication::translate("BasicPermutationGroupWidget", "Column permutation", nullptr));
        directionComboBox->setItemText(1, QApplication::translate("BasicPermutationGroupWidget", "Row permutation", nullptr));
        directionComboBox->setItemText(2, QApplication::translate("BasicPermutationGroupWidget", "Grid permutation (both)", nullptr));

        advancedCheckBox->setText(QApplication::translate("BasicPermutationGroupWidget", "Show advanced options", nullptr));
        inputWritingDir->setItemText(0, QApplication::translate("BasicPermutationGroupWidget", "Write to rows", nullptr));
        inputWritingDir->setItemText(1, QApplication::translate("BasicPermutationGroupWidget", "Write to columns", nullptr));

        outputReadingDir->setItemText(0, QApplication::translate("BasicPermutationGroupWidget", "Read from rows", nullptr));
        outputReadingDir->setItemText(1, QApplication::translate("BasicPermutationGroupWidget", "Read from columns", nullptr));

        encryptButton->setText(QApplication::translate("BasicPermutationGroupWidget", "Encrypt", nullptr));
        decryptButton->setText(QApplication::translate("BasicPermutationGroupWidget", "Decrypt", nullptr));
        outputText->setPlaceholderText(QApplication::translate("BasicPermutationGroupWidget", "Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasicPermutationGroupWidget: public Ui_BasicPermutationGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICPERMUTATIONGROUPWIDGET_H
