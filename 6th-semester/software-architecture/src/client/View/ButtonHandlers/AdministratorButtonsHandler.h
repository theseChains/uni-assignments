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

    void onSearchRegistratorsButtonClicked();
    void onGetRegistratorsResult(const std::vector<RegistratorData>& data);

    void onSearchDoctorsButtonClicked();
    void onGetDoctorsResult(const std::vector<DoctorData>& data);

    void onDeleteRegistratorButtonClicked();
    void onDeleteRegistratorResult(bool success);

    void onDeleteDoctorButtonClicked();
    void onDeleteDoctorResult(bool success);

    void onSpecializationChanged();
    void onGetDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data);

    void onDoctorOrDateChangedScheduleEdit();
    void onGetDoctorSlotsResultScheduleEdit(const std::vector<DoctorSlotData>& data);

    void onDeleteSlotButtonClicked();
    void onDeleteSlotResult(bool success);

    void onDeleteDayOfSlotsButtonClicked();
    void onDeleteDayOfSlotsResult(bool success);

    void onAddSlotButtonClicked();
    void onAddSlotResult(bool success);

    void onAddDayOfSlotsButtonClicked();
    void onAddDayOfSlotsResult(bool success);

private:
    Ui::ApplicationViewUi* m_ui{};
    Client* m_client{};
};
}

#endif
