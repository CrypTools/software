#include "tools.h"

QString caesarEncrypt(QString text, int shift)
{
    text = text.toLower();  //LOWERCASE
    for (int i=0; i<text.length(); ++i){
        if (!text[i].isLetter()) //CHECKS IF TEXT BELONG TO ALPHABET
            return "##NON ALPHABET##";
        text[i] = QChar::fromLatin1((int(text[i].toLatin1()) - 97 + shift +26) % 26 + 97);  //ALPHABET VALUE += SHIFT

    }
    return text;
}

QString caesarDecrypt(QString text, int shift)
{
    QString debugLetter = "o";

    text = text.toLower();  //LOWERCASE

    for (int i=0; i<text.length(); ++i){
        if (!text[i].isLetter())  //CHECKS IF TEXT BELONG TO ALPHABET
            return "##NON ALPHABET##";

        debugLetter[0] = text[i];
        qDebug() << "Avant: i = " + QString::number(i) + "; Shift = " + QString::number(shift) + "; Lettre = " + debugLetter;
        qDebug() << "Calcul: " + QString::number(int(text[i].toLatin1()) - 97) + " + " + QString::number(shift) + " % 26 = " + QString::number((int(text[i].toLatin1()) - 97 - shift) % 26);

        text[i] = QChar::fromLatin1((((int(text[i].toLatin1()) - 97 - shift + 26) % 26) + 97));  //ALPHABET VALUE -= SHIFT

        debugLetter[0] = text[i];
        qDebug() << "Après: i = " + QString::number(i) + "; nouveau code = " + QString::number((((int(text[i].toLatin1()) - 97 - shift) % 26) + 97)) + "; Lettre = " + debugLetter;

    }
    return text;
}

QString vigenereEncrypt(QString text, QString key, bool alphabetOnly)
{
/*
AlphabetOnly = true (default) : argument must be alphabet, and it will only output alphabet text.
AlphabetOnly = false : argument can be anything and it will in most cases output unreadable stuff.
*/
    if (alphabetOnly)
        text = text.toLower(); //LOWERCASE

    switch (alphabetOnly)
    {
    case true:
        for (int i=0; i<text.length(); ++i){
            if (!text[i].isLetter())
                return "##NON ALPHABET##";
            text[i] = QChar::fromLatin1((int(text[i].toLatin1()) - 97 + int(key[i%key.length()].toLatin1()) - 97 + 1 +26) % 26 + 97); //operation
        }
        break;

    case false:
        for (int i=0; i<text.length(); ++i){
            text[i] = QChar::fromLatin1(int(text[i].toLatin1()) + int(key[i%key.length()].toLatin1())); //operation
        }
        break;
    }

    return text;
}

QString vigenereDecrypt(QString text, QString key, bool alphabetOnly)
{
/*
AlphabetOnly = true (default) : argument must be alphabet, and it will only output alphabet text.
AlphabetOnly = false : argument can be anything and it will in most cases output unreadable stuff.
*/
    QString debugLetter = "o";


    switch (alphabetOnly)
    {
    case true:
        for (int i=0; i<text.length(); ++i){
            debugLetter[0] = text[i];
            qDebug() << "Avant: i = " + QString::number(i) + "; Lettre = " + debugLetter;
            qDebug() << "Calcul: " + QString::number(int(text[i].toLatin1()) - 97+104) + " - " + QString::number(int(key[i%key.length()].toLatin1())-97) + " % 26 = " + QString::number(((int(text[i].toLatin1()) - 97 - int(key[i%key.length()].toLatin1()) + 97 + 1 + 104) % 26));

            text[i] = QChar::fromLatin1((int(text[i].toLatin1()) - int(key[i%key.length()].toLatin1()) - 1 +26) % 26 + 97); //operation

            if (!text[i].isLetter())
                return "##NON ALPHABET##";

            debugLetter[0] = text[i];
            qDebug() << "Après: i = " + QString::number(i) + "; nouveau code = " + QString::number((int(text[i].toLatin1()) - 97 - int(key[i%key.length()].toLatin1()) + 97 + 1 + 104)) + "; Lettre = " + debugLetter;

        }
        break;

    case false:
        for (int i=0; i<text.length(); ++i){
            text[i] = QChar::fromLatin1(int(text[i].toLatin1()) - int(key[i%key.length()].toLatin1())); //operation
        }
        break;
    }

    return text;
}

QString vigenereShifts(QString key, bool alphabetOnly)
{
    QString shifts = "";
    if (alphabetOnly){
        key = key.toLower();
        for (int i=0; i<key.length(); ++i){
            if (!(key[i].isLetter()))
                return "##NON ALPHABET##";
            shifts.append(QString(QString::number(int(key[i].toLatin1()-96)) + " - "));
        }
    }
    else
        for (int i=0; i<key.length(); ++i)
            shifts.append(QString::number(int(key[i].toLatin1())) + " - ");
    return shifts.remove(shifts.length()-3, 3);
}
