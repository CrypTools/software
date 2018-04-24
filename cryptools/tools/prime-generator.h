#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <gmpxx.h>
#include <QDebug>
using namespace std;
#define MOD_RAND 2100000000

//Qt is needed for the signals
#include <QObject>

class generator: public QObject
{
    Q_OBJECT
public:
    bool running;
public slots:
    void primeGenerator(int number, int minLenght, mpz_class* resultArray);
signals:
    void numberTested();
    void finished();
};

#endif // PRIMEGENERATOR_H
