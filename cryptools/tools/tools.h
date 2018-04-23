#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QStringList>
#include <QChar>
#include <QCharRef>
#include <QList>
#include <QStringList>
#include <QDebug>
#include <algorithm>

class tools
{
public:
    enum direction
    {
        Column, Row, Grid
    };
};

QString caesarEncrypt(QString text, int shift);
QString caesarDecrypt(QString text, int shift);

QString vigenereEncrypt(QString text, QString key, bool alphabetOnly = true);
QString vigenereDecrypt(QString text, QString key, bool alphabetOnly = true);
QString vigenereShifts(QString key, bool alphabetOnly = true);

QString permutationEncrypt(tools::direction dir, QString text, QString key);

#endif // TOOLS_H
