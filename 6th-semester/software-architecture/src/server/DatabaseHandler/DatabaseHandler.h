#ifndef POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_
#define POLYCLINIC_APP_SERVER_DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QString>

#include <array>
#include <tuple>
#include <vector>

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
#include "common/data/OutpatientCardData.h"

namespace polyclinic
{
class DatabaseHandler
{
public:
    DatabaseHandler();
    ~DatabaseHandler();

    bool connectToTheDatabase();

    std::pair<UserType, int> authenticateUser(const LoginInputData& loginData);
    bool registerPatient(const PatientData& data);
    std::vector<PatientBriefData> getAllPatientsBriefData();
    std::vector<PatientBriefData> getPatientBriefData(const PatientSearchData& data);
    PatientData getPatientInfo(int id);
    bool setPatientInfo(const PatientData& data, int id);
    std::vector<DoctorScheduleData> getDoctorsBySpecialization(const QString& specialization);
    std::vector<DoctorSlotData> getDoctorSlots(int doctorId, const QDate& date);
    bool deleteSlot(int slotId);
    bool deleteDayOfSlots(int doctorId, const QDate& date);
    bool addDayOfSlots(int doctorId, const QDate& date);
    bool addSlot(int doctorId, const QDate& date, const QTime& startTime);
    bool addAppointment(const AppointmentData& data);
    bool addRegistrator(const RegistratorData& data);
    bool addDoctor(const DoctorData& data);
    std::vector<AppointmentFullData> getAppointmentsForDoctor(const QDate& date, int doctorId);
    bool addNewMedicalRecord(const MedicalRecordData& data);
    std::vector<OutpatientCardData> getOutpatientCards(const PatientBriefData& data);
    std::vector<MedicalRecordData> getMedicalRecords(int patientId);
    MedicalRecordData getMedicalRecordData(int recordId);
    bool updateMedicalRecord(const MedicalRecordData& data);
    bool addRecipe(int recordId, const QString& data);

private:
    int getOutpatientCardId(int patientId);

private:
    QSqlDatabase m_database{};
    QString m_connectionName{};
};
}

#endif
