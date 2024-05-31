#ifndef POLYCLINIC_APP_CLIENT_CLIENT_H_
#define POLYCLINIC_APP_CLIENT_CLIENT_H_

#include <QObject>
#include <QTcpSocket>

#include "common/UserType.h"
#include "common/data/LoginInputData.h"
#include "common/data/PatientData.h"
#include "common/data/PatientBriefData.h"
#include "common/data/PatientSearchData.h"
#include "common/data/DoctorScheduleData.h"
#include "common/data/DoctorSlotData.h"
#include "common/data/AppointmentData.h"
#include "common/data/RegistratorData.h"
#include "common/data/DoctorData.h"
#include "common/data/AppointmentFullData.h"
#include "common/data/MedicalRecordData.h"

namespace polyclinic
{
class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject* parent = nullptr);

    void connectToServer();

    void sendLoginRequest(const LoginInputData& inputData);
    void sendPatientRegistrationRequest(const PatientData& data);
    void sendGetAllPatientBriefDataRequest();
    void sendGetPatientBriefDataRequest(const PatientSearchData& data);
    void sendGetPatientInfoRequest(int id);
    void sendUpdatePatientInfoRequest(const PatientData& data, int id);
    void sendGetDoctorsBySpecializationRequest(const QString& specialization);
    void sendGetDoctorSlotsRequest(int doctorId, const QDate& date);
    void sendDeleteSlotRequest(int slotId);
    void sendDeleteDayOfSlotsRequest(int doctorId, const QDate& date);
    void sendAddSlotRequest(int doctorId, const QDate& date, const QTime& startTime);
    void sendAddDayOfSlotsRequest(int doctorId, const QDate& date);
    void sendAddAppointmentRequest(const AppointmentData& data);
    void sendAddRegistratorRequest(const RegistratorData& data);
    void sendAddDoctorRequest(const DoctorData& data);
    void sendGetDoctorAppointmentsRequest(const QDate& date, int doctorId);
    void sendAddMedicalRecordRequest(const MedicalRecordData& data);

signals:
    void loginResult(std::pair<UserType, int> data);
    void patientRegistrationResult(bool success);
    void getAllPatientsBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientInfoResult(const PatientData& data);
    void updatePatientInfoResult(bool success);
    void getDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data);
    void getDoctorSlotsResult(const std::vector<DoctorSlotData>& data);
    void deleteSlotResult(bool success);
    void deleteDayOfSlotsResult(bool success);
    void addSlotResult(bool success);
    void addDayOfSlotsResult(bool success);
    void addAppointmentResult(bool success);
    void addRegistratorResult(bool success);
    void addDoctorResult(bool success);
    void getDoctorAppointmentsResult(const std::vector<AppointmentFullData>& data);
    void addMedicalRecordResult(bool success);

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    void processLoginResult(const QJsonObject& response);
    void processPatientRegistrationResult(const QJsonObject& response);
    void processGetAllPatientBriefDataResult(const QJsonObject& response);
    void processGetPatientBriefDataResult(const QJsonObject& response);
    void processGetPatientInfoResult(const QJsonObject& response);
    void processUpdatePatientInfoResult(const QJsonObject& response);
    void processGetDoctorsBySpecializationResult(const QJsonObject& response);
    void processGetDoctorSlotsResult(const QJsonObject& response);
    void processDeleteSlotResult(const QJsonObject& response);
    void processDeleteDayOfSlotsResult(const QJsonObject& response);
    void processAddSlotResult(const QJsonObject& response);
    void processAddDayOfSlotsResult(const QJsonObject& response);
    void processAddAppointmentResult(const QJsonObject& response);
    void processAddRegistratorResult(const QJsonObject& response);
    void processAddDoctorResult(const QJsonObject& response);
    void processGetDoctorAppointmentsResult(const QJsonObject& response);
    void processAddMedicalRecordResult(const QJsonObject& response);

private:
    QTcpSocket* m_socket{};
};
}

#endif
