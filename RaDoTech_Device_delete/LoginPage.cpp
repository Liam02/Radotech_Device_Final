#include "LoginPage.h"
#include "ui_LoginPage.h"

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->Create_Profile, &QPushButton::clicked, this, [this]() {
        emit CreateButtonClicked();  // Directly emit the custom signal
    });
    connect(ui->Enter, &QPushButton::clicked, this, [this]() {
        emit EnterButtonClicked();  // Directly emit the custom signal
    });
}

void LoginPage::tooManyAccounts(){
    ui->errorText->setText("Too many accounts");
    ui->errorText->setStyleSheet("QLabel { color : blue; }");
}

LoginPage::~LoginPage()
{
    delete ui;
}
