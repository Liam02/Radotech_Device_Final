#include "EnterAccountPage.h"
#include "ui_EnterAccountPage.h"

EnterAccountPage::EnterAccountPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterAccountPage)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, [=]() {emit backButtonClicked();});
    connect(ui->Sign_In, &QPushButton::clicked, this, [=](){
        signInButtonClicked(ui->Email_Input->text().toStdString(), ui->Password_Input->text().toStdString());
    });
}

void EnterAccountPage::wrongEmailOrPassword(){
    ui->errorText->setText("Wrong email or password");
    ui->errorText->setStyleSheet("QLabel { color : red; }");
}

void EnterAccountPage::resetPage(){
    for (QLineEdit* lineEdit : this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
    ui->errorText->clear();
}

EnterAccountPage::~EnterAccountPage()
{
    delete ui;
}
