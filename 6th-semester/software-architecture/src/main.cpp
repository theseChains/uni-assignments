#include "View/ApplicationView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application{ argc, argv };
    ApplicationView window{};
    window.show();
    return application.exec();
}
