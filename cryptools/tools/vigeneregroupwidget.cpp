#include "vigeneregroupwidget.h"

VigenereGroupWidget::VigenereGroupWidget(QWidget *parent) : QGroupBox("Vigenere", parent)
{
    vigenereLayout = new QGridLayout(this);
    vigenereInputText = new QTextEdit(this);
    vigenereKeyLine = new QLineEdit(this);
    vigenereOutputText = new QTextEdit(this);
    encryptButtonVigenere = new QPushButton("Encrypt", this);
    decryptButtonVigenere = new QPushButton("Decrypt", this);
    vigenereShowKeyCheckBox = new QCheckBox("Display the key", this);
    vigenereAlphabetOnlyCheckBox = new QCheckBox("Limit to alphabet", this);
    vigenereShowShiftsCheckBox = new QCheckBox("Show the key shifts", this);
    vigenereShiftsLine = new QLineEdit(this);

//    encryptButtonVigenere->setStyleSheet("QPushButton {border: 1px solid #aaaaaa; border-radius: 3px; "
//                                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde);}"
//                                         "QPushButton:hover {"
//                                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #eaebee);}"
//                                         "QPushButton:pressed {"
//                                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}"
//                                         "QPushButton:default {border-color: navy;}");

    vigenereKeyLine->setEchoMode(QLineEdit::Password);

    vigenereInputText->setPlaceholderText("Input");
    vigenereKeyLine->setPlaceholderText("Encryption key");
    vigenereOutputText->setPlaceholderText("Output");
    vigenereOutputText->setReadOnly(true);
    vigenereShiftsLine->setReadOnly(true);
    vigenereAlphabetOnlyCheckBox->setChecked(true);

    vigenereShowShiftsCheckBox->setEnabled(false);
    vigenereShiftsLine->hide();

    vigenereLayout->addWidget(vigenereInputText, 0, 0, 2, 2);
    vigenereLayout->addWidget(vigenereShowKeyCheckBox, 2, 0, 1, 1);
    vigenereLayout->addWidget(vigenereAlphabetOnlyCheckBox, 3, 0, 1, 1);
    vigenereLayout->addWidget(vigenereShowShiftsCheckBox, 3, 1, 1, 1);
    vigenereLayout->addWidget(vigenereShiftsLine, 4, 0, 1, 2);
    vigenereLayout->addWidget(vigenereKeyLine, 2, 1, 1, 1);
    vigenereLayout->addWidget(encryptButtonVigenere, 5, 0, 1, 1);
    vigenereLayout->addWidget(decryptButtonVigenere, 5, 1, 1, 1);
    vigenereLayout->addWidget(vigenereOutputText, 6, 0, 2, 2);

    setLayout(vigenereLayout);


    connect(vigenereShowKeyCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateVigenereKeyLine()));
    connect(encryptButtonVigenere, SIGNAL(clicked(bool)), this, SLOT(vigenereEncryptSlot()));
    connect(decryptButtonVigenere, SIGNAL(clicked(bool)), this, SLOT(vigenereDecryptSlot()));
    connect(vigenereShowShiftsCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateShiftState()));
    connect(vigenereKeyLine, SIGNAL(textEdited(QString)), this, SLOT(updateShiftLine()));
    connect(vigenereAlphabetOnlyCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateShiftLine()));
}

void VigenereGroupWidget::vigenereEncryptSlot()
{
    if ((vigenereInputText->toPlainText().isEmpty() == false) && (vigenereKeyLine->text().isEmpty() == false))
        vigenereOutputText->setPlainText(vigenereEncrypt(vigenereInputText->toPlainText(), vigenereKeyLine->text(), vigenereAlphabetOnlyCheckBox->isChecked()));
}

void VigenereGroupWidget::vigenereDecryptSlot()
{
    if ((vigenereInputText->toPlainText().isEmpty() == false) && (vigenereKeyLine->text().isEmpty() == false))
        vigenereOutputText->setPlainText(vigenereDecrypt(vigenereInputText->toPlainText(), vigenereKeyLine->text(), vigenereAlphabetOnlyCheckBox->isChecked()));
}

void VigenereGroupWidget::updateVigenereKeyLine()
{
    if (vigenereShowKeyCheckBox->isChecked()){
        vigenereKeyLine->setEchoMode(QLineEdit::Normal);
        vigenereShowShiftsCheckBox->setEnabled(true); //Allows use of the shift options
    }
    else {
        vigenereKeyLine->setEchoMode(QLineEdit::Password);
        vigenereShowShiftsCheckBox->setEnabled(false); //Forbids use of the shift options
        vigenereShowShiftsCheckBox->setChecked(false);
    }
    updateShiftLine();
}

void VigenereGroupWidget::updateShiftLine()
{
    if (vigenereShiftsLine->isHidden())
        return;
    vigenereShiftsLine->setText(vigenereShifts(vigenereKeyLine->text(), vigenereAlphabetOnlyCheckBox->isChecked()));
}

void VigenereGroupWidget::updateShiftState()
{
    if (vigenereShowShiftsCheckBox->isChecked()){
        vigenereShiftsLine->show();
        updateShiftLine();}
    else
        vigenereShiftsLine->hide();
}

void VigenereGroupWidget::unselect_output()
{
    QTextCursor m_cursor;
    m_cursor.setPosition(0);
    vigenereOutputText->setTextCursor(m_cursor);
    vigenereInputText->setTextCursor(m_cursor);
}
