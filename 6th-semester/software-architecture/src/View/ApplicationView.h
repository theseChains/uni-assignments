#ifndef POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_
#define POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_

#include <array>
#include <vector>

#include <QMainWindow>
#include <QStackedWidget>

#include "Controller/ApplicationController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class ApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationView(ApplicationController& controller, QWidget *parent = nullptr);
    ~ApplicationView();

private slots:
    void onLoginButtonClicked();
    void onFindClientsButtonClicked();
    void onBackToSearchButtonClicked();
    void onOpenClientInfoButtonClicked();
    void onBackToClientTableButtonClicked();
    void onClientPageTalonButtonClicked();
    void onClientTableTalonButtonClicked();
    void onBackFromTalonButtonClicked();
    void onTalonPageEditScheduleButtonClicked();
    void onOpenOutpatientCardButtonClicked();

private:
    bool loginIsValid();
    bool foundClients();
    std::vector<std::array<QString, 4>> findClients();
    void fillTableWithData(const std::vector<std::array<QString, 4>>& data);
    void navigateToPage(const QString& pageName);
    bool searchStackedWidgetForPage(const QString& pageName,
                                    QStackedWidget& stackedWidget);

private:
    ApplicationController& m_controller;
    int m_lastClientStackedWidgetIndex{};
    Ui::ApplicationViewUi* m_ui;
};
}

#endif
