#include "Controller/ApplicationController.h"
#include "Model/ApplicationModel.h"
#include "View/ApplicationView.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication application{ argc, argv };

    QFile styleSheetFile{ "../res/darkstyle.qss" };
    styleSheetFile.open(QFile::ReadOnly);
    application.setStyleSheet(QLatin1String{ styleSheetFile.readAll() });

    polyclinic::ApplicationModel model{};
    polyclinic::ApplicationController controller{ model };
    polyclinic::ApplicationView view{ controller };
    view.show();

    return application.exec();
}
