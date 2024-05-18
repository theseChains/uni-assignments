#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_ADMINISTRATORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_ADMINISTRATORBUTTONSHANDLER_H_

#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class AdministratorButtonsHandler
{
public:
    AdministratorButtonsHandler() = default;

private:
    Ui::ApplicationViewUi* m_ui;
};
}

#endif
