#ifndef POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_
#define POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_

#include <QMainWindow>

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

private:
    bool loginIsValid();
    void navigateToPage(const QString& objectName);

private:
    ApplicationController& m_controller;
    Ui::ApplicationViewUi* m_ui;
};
}

#endif
