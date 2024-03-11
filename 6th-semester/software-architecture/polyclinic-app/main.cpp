#include "polyclinicapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolyclinicApp w;
    w.show();
    return a.exec();
}
