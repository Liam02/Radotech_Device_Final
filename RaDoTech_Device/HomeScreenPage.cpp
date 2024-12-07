#include "HomeScreenPage.h"
#include "ui_HomeScreenPage.h"

HomeScreenPage::HomeScreenPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeScreenPage)
{
    ui->setupUi(this);
    connect(ui->logoutButton, &QPushButton::clicked, this, [=]() {emit logoutButtonClicked();});

    QTimer* timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, [=]() { ui->Name_Display->setText(QString::fromStdString(user->getFirstName()) +" "+ QString::fromStdString(user->getLastName())); });
    timer1->start(100); // Run every 100 ms (0.1 second)


    ui->recharge->setVisible(false);
    ui->lowBatteryWarning->setVisible(false);

    connect(ui->recharge, &QPushButton::clicked, this, [=]() {emit ;});

}

void HomeScreenPage::setUser(User* user){
    this->user=user;
}

void HomeScreenPage::setBattery(Battery* battery){
    this->battery=battery;
    QTimer* batteryTimer = new QTimer(this);
    connect(batteryTimer, SIGNAL(timeout()), this, SLOT(handleBattery()));
    batteryTimer->start(10000);


}

void HomeScreenPage::handleBattery(){
    battery->depleteBattery();
    ui->batteryBar->setValue(battery->getBattery());

    if(battery->checkLowBattery()){
        ui->batteryBar->setPalette((QPalette::Highlight, Qt::red));
        ui->recharge->setVisible(true);
        ui->lowBatteryWarning->setVisible(true);
        connect(ui->recharge, &QPushButton::clicked, this, [=]() {emit battery->recharge();});

    }else{
        ui->recharge->setVisible(false);
        ui->lowBatteryWarning->setVisible(false);
    }

    if(battery->getBattery() < 0){
        ui->Name_Display->setText("Powering down...");
        QApplication::quit();
    }


    ui->batteryBar->setValue(battery->getBattery());
}

HomeScreenPage::~HomeScreenPage()
{
    delete ui;
}
