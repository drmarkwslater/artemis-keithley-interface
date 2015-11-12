#include "keithleywindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeithleyWindow w;
    w.show();

    return a.exec();
}
