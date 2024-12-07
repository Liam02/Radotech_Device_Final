#include "endofscannotes.h"
#include "ui_endofscannotes.h"

endOfScanNotes::endOfScanNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::endOfScanNotes)
{
    ui->setupUi(this);

    connect(ui->saveButton, &QPushButton::clicked, this, [=]() {
         emit sendNotesToUser(ui->bodytemp->text().toInt(), ui->bloodpresL1->text().toInt(),
                              ui->bloodpresL2->text().toInt(), ui->bloodpresR1->text().toInt(),
                              ui->bloodpresR2->text().toInt(), ui->heartRate->text().toInt(),
                              ui->currentWeight->text().toInt());

        ui->bodytemp->setText("");
        ui->bloodpresL1->setText("");
        ui->bloodpresL2->setText("");
        ui->bloodpresR1->setText("");
        ui->bloodpresR2->setText("");
        ui->heartRate->setText("");
        ui->currentWeight->setText("");
    });

}

endOfScanNotes::~endOfScanNotes()
{
    delete ui;
}



