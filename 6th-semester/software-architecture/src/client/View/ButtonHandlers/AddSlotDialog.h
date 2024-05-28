#ifndef POLYCLINIC_APP_CLIENT_BUTTONHANDLERS_ADDSLOTDIALOG_H_
#define POLYCLINIC_APP_CLIENT_BUTTONHANDLERS_ADDSLOTDIALOG_H_

#include <QDialog>
#include <QTimeEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

namespace polyclinic
{
class AddSlotDialog : public QDialog {
    Q_OBJECT

public:
    AddSlotDialog(QWidget* parent = nullptr);

    QTime selectedTime() const;

private slots:
    void validateTime();

private:
    QTimeEdit* m_timeEdit{};
    QPushButton* m_okButton{};
    QLabel* m_instructionLabel{};
};
}

#endif
