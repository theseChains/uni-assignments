#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_

#include <QtCore>

#include "client/Facade/Facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class RegistratorButtonsHandler : public QObject
{
    Q_OBJECT

public:
    RegistratorButtonsHandler(Facade* facade);

    void setUi(Ui::ApplicationViewUi* ui);
    void connectButtonsToSlots();

private slots:
    void onRegisterPatientButtonClicked();
    void onPatientRegistration(bool success);

    void onOpenClientInfoButtonClicked();
    void onFindClientsButtonClicked();
    void onBackToSearchButtonClicked();
    void onBackToClientTableButtonClicked();
    void onClientPageTalonButtonClicked();
    void onClientTableTalonButtonClicked();
    void onBackFromTalonButtonClicked();
    void onTalonPageEditScheduleButtonClicked();

private:
    std::vector<std::array<QString, 4>> findClients();
    void fillTableWithData(const std::vector<std::array<QString, 4>>& data);

private:
    Ui::ApplicationViewUi* m_ui;
    Facade* m_facade;
    int m_lastClientStackedWidgetIndex{};
};
}

#endif
