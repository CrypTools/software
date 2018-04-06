#include "root.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase fdb;
    root w;
    w.show();

    return a.exec();
}
