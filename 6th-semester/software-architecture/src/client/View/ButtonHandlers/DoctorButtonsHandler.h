#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_DOCTORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_DOCTORBUTTONSHANDLER_H_

#include <QtCore>

#include "client/Client.h"
#include "common/data/MedicalRecordData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class DoctorButtonsHandler : public QObject
{
    Q_OBJECT

public:
    explicit DoctorButtonsHandler(Client* client, QObject* parent = nullptr);

    void setUi(Ui::ApplicationViewUi* ui);
    void setUserId(int id);

    void connectButtonsToSlots();

private slots:
    void onShowAppointedPatientsButtonClicked();
    void onGetDoctorAppointmentsResult(const std::vector<AppointmentFullData>& data);

    void onOpenNewMedicalRecordButtonClicked();
    void onBackToAppointedClientsButtonClicked();

    void onSaveMedRecordButtonClicked();
    void onAddMedicalRecordResult(bool success);

    void onSearchOutpatientCardsButtonClicked();
    void onGetOutpatientCardsResult(const std::vector<OutpatientCardData>& data);

    void onOpenOutpatientCardButtonClicked();
    void onGetMedicalRecordsResult(const std::vector<MedicalRecordData>& data);

    void onOpenMedicalRecordButtonClicked();
    void onGetMedicalRecordDataResult(const MedicalRecordData& data);

    void onEditMedRecordButtonClicked();
    void onUpdateMedicalRecordResult(bool success);

    void onBackToOutpatientCardsListButtonClicked();
    void onBackToListOfMedRecordsButtonClicked();

private:
    void fillAppointmentsTable(const std::vector<AppointmentFullData>& data);
    void fillOutpatientCardsTable(const std::vector<OutpatientCardData>& data);
    void fillMedicalRecordsTable(const std::vector<MedicalRecordData>& data);

private:
    Ui::ApplicationViewUi* m_ui{};
    Client* m_client{};

    int m_currentPatientId{};
    int m_currentMedRecordId{};
    int m_doctorId{};
};
}

#endif
