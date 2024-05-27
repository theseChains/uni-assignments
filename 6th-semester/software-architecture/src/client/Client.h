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

signals:
    void loginResult(UserType userType);
    void patientRegistrationResult(bool success);
    void getAllPatientsBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientBriefDataResult(const std::vector<PatientBriefData>& data);
    void getPatientInfoResult(const PatientData& data);
    void updatePatientInfoResult(bool success);
    void getDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data);

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

private:
    QTcpSocket* m_socket{};
};
}

#endif
