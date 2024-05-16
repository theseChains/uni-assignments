#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_

#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class RegistratorButtonsHandler : public QObject
{
    Q_OBJECT

public:
    RegistratorButtonsHandler() = default;

    void setUi(Ui::ApplicationViewUi* ui);
    void connectButtonsToSlots();

private slots:
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
    int m_lastClientStackedWidgetIndex{};
};
}

#endif
