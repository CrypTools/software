#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QStringList>
#include <QChar>
#include <QCharRef>
#include <QDebug>

QString caesarEncrypt(QString text, int shift);
QString caesarDecrypt(QString text, int shift);

QString vigenereEncrypt(QString text, QString key, bool alphabetOnly = true);
QString vigenereDecrypt(QString text, QString key, bool alphabetOnly = true);
QString vigenereShifts(QString key, bool alphabetOnly = true);

#endif // TOOLS_H
