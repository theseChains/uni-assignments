#include "Controller/ApplicationController.h"
#include "Model/ApplicationModel.h"
#include "View/ApplicationView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application{ argc, argv };

    polyclinic::ApplicationModel model{};
    polyclinic::ApplicationController controller{ model };
    polyclinic::ApplicationView view{ controller };
    view.show();

    return application.exec();
}
