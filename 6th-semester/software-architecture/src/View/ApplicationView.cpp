#include "ApplicationView.h"
#include "ui_ApplicationViewUi.h"

#include <iostream>

#include <QDebug>

#include "ViewConstants.h"

namespace polyclinic
{
ApplicationView::ApplicationView(ApplicationController& controller, QWidget* parent)
    : QMainWindow{ parent },
      m_controller{ controller },
      m_ui{ new Ui::ApplicationViewUi }
{
    m_ui->setupUi(this);
    navigateToPage(constants::kLoginPage);

    QObject::connect(m_ui->LogInButton, &QPushButton::clicked,
                     this, &ApplicationView::onLoginButtonClicked);
}

void ApplicationView::onLoginButtonClicked() {
    if (loginIsValid()) {
        navigateToPage(constants::kRegistratorPage);
    } else {
        std::cerr << "invalid login or password\n";
    }
}

bool ApplicationView::loginIsValid() {
    return true;
}

void ApplicationView::navigateToPage(const QString& objectName) {
    for (int i{ 0 }; i < m_ui->stackedWidget->count(); ++i) {
        QWidget* widget{ m_ui->stackedWidget->widget(i) };
        if (widget && widget->objectName() == objectName) {
            m_ui->stackedWidget->setCurrentIndex(i);
            return;
        }
    }

    qDebug() << "could not find page " << objectName << '\n';
}

ApplicationView::~ApplicationView()
{
    delete m_ui;
}
}
