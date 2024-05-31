#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_ADMINISTRATORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_ADMINISTRATORBUTTONSHANDLER_H_

#include <QtCore>

#include "client/Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class AdministratorButtonsHandler : public QObject
{
    Q_OBJECT

public:
    explicit AdministratorButtonsHandler(Client* client, QObject* parent = nullptr);

    void setUi(Ui::ApplicationViewUi* ui);

    void connectButtonsToSlots();

private slots:
    void onRegisterRegistratorButtonClicked();
    void onRegistratorRegistrationResult(bool success);

    void onRegisterDoctorButtonClicked();
    void onDoctorRegistrationResult(bool success);

private:
    Ui::ApplicationViewUi* m_ui{};
    Client* m_client{};
};
}

#endif
