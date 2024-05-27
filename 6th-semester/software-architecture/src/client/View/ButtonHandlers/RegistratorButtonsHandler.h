#ifndef POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_
#define POLYCLINIC_APP_VIEW_BUTTONHANDLERS_REGISTRATORBUTTONSHANDLER_H_

#include <QObject>
#include <QString>

#include <optional>

#include "client/Client.h"
#include "common/data/PatientSearchData.h"
#include "common/data/PatientData.h"
#include "common/data/DoctorScheduleData.h"
#include "common/data/DoctorSlotData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class RegistratorButtonsHandler : public QObject
{
    Q_OBJECT

public:
    explicit RegistratorButtonsHandler(Client* client, QObject* parent = nullptr);

    void setUi(Ui::ApplicationViewUi* ui);
    void connectButtonsToSlots();

signals:
    void errorOccurred(const QString& message);

private slots:
    void onRegisterPatientButtonClicked();
    void onPatientRegistration(bool success);

    void onFindAllPatientsButtonClicked();
    void onGetAllPatientBriefDataResult(const std::vector<PatientBriefData>& data);

    void onFindPatientsButtonClicked();
    void onGetPatientsBriefDataResult(const std::vector<PatientBriefData>& data);

    void onOpenPatientInfoButtonClicked();
    void onPatientInfoResult(const PatientData& data);

    void onUpdatePatientInfoButtonClicked();
    void onUpdatePatientInfoResult(bool success);

    void onSpecializationChanged();
    void onGetDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data);

    void onDoctorSlotsButtonClicked();
    void onGetDoctorSlotsResult(const std::vector<DoctorSlotData>& data);

    void onDeleteSlotButtonClicked();
    void onDeleteSlotResult(bool success);
    
    void onDeleteDayOfSlotsButtonClicked();
    void onDeleteDayOfSlotsResult(bool success);

    void onAddSlotButtonClicked();
    void onAddSlotResult(bool success);
    
    void onAddDayOfSlotsButtonClicked();
    void onAddDayOfSlotsResult(bool success);

    void onClientPageTalonButtonClicked();
    void onClientTableTalonButtonClicked();
    void onBackFromTalonButtonClicked();
    void onTalonPageEditScheduleButtonClicked();

    void onBackToSearchButtonClicked();
    void onBackToClientTableButtonClicked();

private:
    void fillTableWithData(const std::vector<PatientBriefData>& data);
    void fillSlotTable(const std::vector<DoctorSlotData>& data);

private:
    Ui::ApplicationViewUi* m_ui{};
    Client* m_client{};
    int m_lastClientStackedWidgetIndex{};
    int m_currentPatientId{};
    std::optional<PatientSearchData> m_lastSearchCriteria{};
    bool m_isSpecificSearch{};
};
}

#endif
