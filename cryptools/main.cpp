#include "root.h"
#include <QApplication>
#include <QFontDatabase>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase fdb;
    root w;

    QFile File(":/tools/style.css");
    File.open(QIODevice::ReadOnly);
    QString ss = File.readAll();

    //w.setStyleSheet(ss);
    w.show();

    return a.exec();
}
