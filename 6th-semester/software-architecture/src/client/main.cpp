#include "View/ApplicationView.h"

#include <QApplication>
#include <QFile>
#include <QTcpSocket>

int main(int argc, char* argv[])
{
    QApplication application{ argc, argv };

    QFile styleSheetFile{ "../res/darkstyle.qss" };
    styleSheetFile.open(QFile::ReadOnly);
    application.setStyleSheet(QLatin1String{ styleSheetFile.readAll() });

    polyclinic::ApplicationView view{};
    view.show();

    return application.exec();
}
