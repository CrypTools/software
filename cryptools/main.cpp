#include "root.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    root w;
    w.show();

    return a.exec();
}
