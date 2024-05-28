#include "client/View/ButtonHandlers/AddSlotDialog.h"

#include <QMessageBox>

namespace polyclinic
{
AddSlotDialog::AddSlotDialog(QWidget* parent) : QDialog{ parent } {
    setWindowTitle("Add Slot");
    setFixedSize({ 140, 95 });

    QVBoxLayout* layout{ new QVBoxLayout{ this } };

    m_instructionLabel = new QLabel{ "Время начала:", this };
    layout->addWidget(m_instructionLabel);

    m_timeEdit = new QTimeEdit{ this };
    m_timeEdit->setDisplayFormat("HH:mm");
    m_timeEdit->setTimeRange(QTime{ 9, 0 }, QTime{ 17, 0 });
    m_timeEdit->setTime(QTime{ 9, 0 });
    layout->addWidget(m_timeEdit);

    m_okButton = new QPushButton{ "OK", this };
    connect(m_okButton, &QPushButton::clicked, this, &AddSlotDialog::validateTime);
    layout->addWidget(m_okButton);

    setLayout(layout);
}

QTime AddSlotDialog::selectedTime() const {
    return m_timeEdit->time();
}

void AddSlotDialog::validateTime() {
    QTime time{ m_timeEdit->time() };
    int minutes{ time.minute() };

    if (((time >= QTime{ 9, 0 } &&
        time < QTime{ 12, 0 }) || (time >= QTime{ 13, 0 } &&
        time <= QTime{ 17, 0 })) && (minutes % 10 == 0)) {
        accept();
    } else {
        QMessageBox::warning(this, "Invalid Time",
                "Пожалуйста выберите время в промежутке с 09:00-12:00 или 13:00-17:00 с интервалами в 10 минут.");
    }
}
}
