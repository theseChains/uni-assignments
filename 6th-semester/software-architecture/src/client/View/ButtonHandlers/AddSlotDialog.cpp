#include "client/View/ButtonHandlers/AddSlotDialog.h"

#include <QMessageBox>

namespace polyclinic
{
AddSlotDialog::AddSlotDialog(QWidget* parent) : QDialog{ parent } {
    setWindowTitle("Add Slot");
    setFixedSize({ 125, 75 });

    QVBoxLayout* layout{ new QVBoxLayout{ this } };

    timeEdit = new QTimeEdit{ this };
    timeEdit->setDisplayFormat("HH:mm");
    timeEdit->setTimeRange(QTime{ 9, 0 }, QTime{ 17, 0 });
    timeEdit->setTime(QTime{ 9, 0 });
    layout->addWidget(timeEdit);

    okButton = new QPushButton{ "OK", this };
    connect(okButton, &QPushButton::clicked, this, &AddSlotDialog::validateTime);
    layout->addWidget(okButton);

    setLayout(layout);
}

QTime AddSlotDialog::selectedTime() const {
    return timeEdit->time();
}

void AddSlotDialog::validateTime() {
    QTime time{ timeEdit->time() };
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
