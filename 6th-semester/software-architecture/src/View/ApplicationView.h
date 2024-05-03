#ifndef POLYCLINICAPP_H
#define POLYCLINICAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

class ApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationView(QWidget *parent = nullptr);
    ~ApplicationView();

private slots:
    void onLoginButtonClicked();

private:
    bool loginIsValid();
    void navigateToPage(const QString& objectName);

private:
    Ui::ApplicationViewUi* m_ui;
};

#endif // POLYCLINICAPP_H
