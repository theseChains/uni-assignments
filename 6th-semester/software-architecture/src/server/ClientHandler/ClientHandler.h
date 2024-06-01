#ifndef POLYCLINIC_APP_SERVER_CLIENTHANDLER_H_
#define POLYCLINIC_APP_SERVER_CLIENTHANDLER_H_

#include <QThread>
#include <QTcpSocket>

#include "server/DatabaseHandler/DatabaseHandler.h"

namespace polyclinic
{
class ClientHandler : public QThread
{
    Q_OBJECT

public:
    explicit ClientHandler(qintptr socketDescriptor, QObject* parent = nullptr);
    ~ClientHandler();

signals:
    void finished();

protected:
    void run() override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    void processLoginRequest(const QJsonObject& request);
    void processPatientRegistrationRequest(const QJsonObject& request);
    void processGetAllPatientBriefDataRequest();
    void processGetPatientBriefDataRequest(const QJsonObject& request);
    void processGetPatientInfoRequest(const QJsonObject& request);
    void processUpdatePatientInfoRequest(const QJsonObject& request);
    void processGetDoctorsBySpecializationRequest(const QJsonObject& request);
    void processGetDoctorSlotsRequest(const QJsonObject& request);
    void processDeleteSlotRequest(const QJsonObject& request);
    void processDeleteDayOfSlotsRequest(const QJsonObject& request);
    void processAddSlotRequest(const QJsonObject& request);
    void processAddDayOfSlotsRequest(const QJsonObject& request);
    void processAddAppointmentRequest(const QJsonObject& request);
    void processAddRegistratorRequest(const QJsonObject& request);
    void processAddDoctorRequest(const QJsonObject& request);
    void processGetDoctorAppointmentsRequest(const QJsonObject& request);
    void processAddMedicalRecordRequest(const QJsonObject& request);
    void processGetOutpatientCardsRequest(const QJsonObject& request);
    void processGetMedicalRecordsRequest(const QJsonObject& request);

private:
    qintptr m_socketDescriptor{};
    QTcpSocket* m_socket{};
    DatabaseHandler m_databaseHandler{};
};
}

#endif
