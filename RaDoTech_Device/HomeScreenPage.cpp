#include "HomeScreenPage.h"
#include "ui_HomeScreenPage.h"

HomeScreenPage::HomeScreenPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeScreenPage)
{
    ui->setupUi(this);
    connect(ui->logoutButton, &QPushButton::clicked, this, [=]() {
        emit logoutButtonClicked();
        ui->textBrowser->setText("");
    });
    connect(ui->MeasureNowButton, &QPushButton::clicked, this, [=](){
        emit measureNowButtonClicked();
        ui->textBrowser->setText("");
    });
    connect(ui->Previous, SIGNAL(released()), this, SLOT(previousClicked()));;
    connect(ui->latest, SIGNAL(released()), this, SLOT(latestClicked()));;

    QTimer* timer1 = new QTimer(this);

    connect(timer1, &QTimer::timeout, this, [=]() { ui->Name_Display->setText(QString::fromStdString(user->getFirstName()) +" "+ QString::fromStdString(user->getLastName())); });

    timer1->start(100); // Run every 100 ms (0.1 second)
    prevScansIndex = 0;
}

void HomeScreenPage::setUser(User* user){
    this->user=user;
}

HomeScreenPage::~HomeScreenPage()
{
    delete ui;
}
void HomeScreenPage::setaNewReading(map<string, int> r, map<string, string> analysis){
    //  TBC
   user->addReading(r, analysis);
   prevScansIndex = user->getScansNum()-1;
}

void HomeScreenPage::addEndOfScan(int temp, int pressure1L, int pressure2L, int pressure1R, int pressure2R, int heartRate, int currentWeight){
    vector<int> r;
    r.push_back(temp);
    r.push_back(pressure1L);
    r.push_back(pressure2L);
    r.push_back(pressure1R);
    r.push_back(pressure2R);
    r.push_back(heartRate);
    r.push_back(currentWeight);

    user->addNote(r);
}

void HomeScreenPage::previousClicked(){
    if(user->getScansNum()==0){return;}
    if(prevScansIndex<0){
        prevScansIndex = user->getScansNum()-1;
    }
    map<string, string> analysis = user->getAnalysis(prevScansIndex);
    map<string, int> scan = user->getScan(prevScansIndex);
    vector<int> notes = user->getNotes(prevScansIndex);
    ui->textBrowser->setText("");
    ui->textBrowser->insertPlainText("Lungs: " + QString::fromStdString(analysis["Lung"]) + "\n");
    ui->textBrowser->insertPlainText("Pericardium: " + QString::fromStdString(analysis["Pericardium"]) + "\n");
    ui->textBrowser->insertPlainText("Heart: " + QString::fromStdString(analysis["Heart"]) + "\n");
    ui->textBrowser->insertPlainText("Small Intestine: " + QString::fromStdString(analysis["Small intestine"]) + "\n");
    ui->textBrowser->insertPlainText("Lymph: " + QString::fromStdString(analysis["Lymph"]) + "\n");
    ui->textBrowser->insertPlainText("Large Intestine: " + QString::fromStdString(analysis["Large Intestine"]) + "\n");
    ui->textBrowser->insertPlainText("Pancreas: " + QString::fromStdString(analysis["Pancreas"]) + "\n");
    ui->textBrowser->insertPlainText("Liver: " + QString::fromStdString(analysis["Liver"]) + "\n");
    ui->textBrowser->insertPlainText("Kidney: " + QString::fromStdString(analysis["Kidney"]) + "\n");
    ui->textBrowser->insertPlainText("Bladder: " + QString::fromStdString(analysis["Bladder"]) + "\n");
    ui->textBrowser->insertPlainText("Gall Gladder: " + QString::fromStdString(analysis["Gall Bladder"]) + "\n");
    ui->textBrowser->insertPlainText("Stomach: " + QString::fromStdString(analysis["Stomach"]) + "\n");
    ui->textBrowser->insertPlainText("---------------- \n");
    ui->textBrowser->insertPlainText("H1 Value: " + QString::number(scan["H1"])+ "\n");
    ui->textBrowser->insertPlainText("H2 Value: " + QString::number(scan["H2"])+ "\n");
    ui->textBrowser->insertPlainText("H3 Value: " + QString::number(scan["H3"])+ "\n");
    ui->textBrowser->insertPlainText("H4 Value: " + QString::number(scan["H4"])+ "\n");
    ui->textBrowser->insertPlainText("H5 Value: " + QString::number(scan["H5"])+ "\n");
    ui->textBrowser->insertPlainText("H6 Value: " + QString::number(scan["H6"])+ "\n");
    ui->textBrowser->insertPlainText("F1 Value: " + QString::number(scan["F1"])+ "\n");
    ui->textBrowser->insertPlainText("F2 Value: " + QString::number(scan["F2"])+ "\n");
    ui->textBrowser->insertPlainText("F3 Value: " + QString::number(scan["F3"])+ "\n");
    ui->textBrowser->insertPlainText("F4 Value: " + QString::number(scan["F4"])+ "\n");
    ui->textBrowser->insertPlainText("F5 Value: " + QString::number(scan["F5"])+ "\n");
    ui->textBrowser->insertPlainText("F6 Value: " + QString::number(scan["F6"])+ "\n");
    ui->textBrowser->insertPlainText("---------------- \n");
    ui->textBrowser->insertPlainText("Body Temperature: " + QString::number(notes[0])+ "\n");
    ui->textBrowser->insertPlainText("Blood Pressure left hand: " + QString::number(notes[1])+"/"+QString::number(notes[2])+ "\n");
    ui->textBrowser->insertPlainText("Blood Pressure right hand: " + QString::number(notes[3])+"/"+QString::number(notes[4])+ "\n");
    ui->textBrowser->insertPlainText("Heart Rate Temperature: " + QString::number(notes[5])+ "\n");
    ui->textBrowser->insertPlainText("Current Weight: " + QString::number(notes[6])+ "\n");
    prevScansIndex--;
}

void HomeScreenPage::latestClicked(){
    if(user->getScansNum()==0){return;}
    int index = user->getScansNum()-1;
    map<string, string> analysis = user->getAnalysis(index);
    map<string, int> scan = user->getScan(index);
    vector<int> notes = user->getNotes(index);
    ui->textBrowser->setText("");
    ui->textBrowser->insertPlainText("Lungs: " + QString::fromStdString(analysis["Lung"]) + "\n");
    ui->textBrowser->insertPlainText("Pericardium: " + QString::fromStdString(analysis["Pericardium"]) + "\n");
    ui->textBrowser->insertPlainText("Heart: " + QString::fromStdString(analysis["Heart"]) + "\n");
    ui->textBrowser->insertPlainText("Small Intestine: " + QString::fromStdString(analysis["Small intestine"]) + "\n");
    ui->textBrowser->insertPlainText("Lymph: " + QString::fromStdString(analysis["Lymph"]) + "\n");
    ui->textBrowser->insertPlainText("Large Intestine: " + QString::fromStdString(analysis["Large Intestine"]) + "\n");
    ui->textBrowser->insertPlainText("Pancreas: " + QString::fromStdString(analysis["Pancreas"]) + "\n");
    ui->textBrowser->insertPlainText("Liver: " + QString::fromStdString(analysis["Liver"]) + "\n");
    ui->textBrowser->insertPlainText("Kidney: " + QString::fromStdString(analysis["Kidney"]) + "\n");
    ui->textBrowser->insertPlainText("Bladder: " + QString::fromStdString(analysis["Bladder"]) + "\n");
    ui->textBrowser->insertPlainText("Gall Gladder: " + QString::fromStdString(analysis["Gall Bladder"]) + "\n");
    ui->textBrowser->insertPlainText("Stomach: " + QString::fromStdString(analysis["Stomach"]) + "\n");
    ui->textBrowser->insertPlainText("---------------- \n");
    ui->textBrowser->insertPlainText("H1 Value: " + QString::number(scan["H1"])+ "\n");
    ui->textBrowser->insertPlainText("H2 Value: " + QString::number(scan["H2"])+ "\n");
    ui->textBrowser->insertPlainText("H3 Value: " + QString::number(scan["H3"])+ "\n");
    ui->textBrowser->insertPlainText("H4 Value: " + QString::number(scan["H4"])+ "\n");
    ui->textBrowser->insertPlainText("H5 Value: " + QString::number(scan["H5"])+ "\n");
    ui->textBrowser->insertPlainText("H6 Value: " + QString::number(scan["H6"])+ "\n");
    ui->textBrowser->insertPlainText("F1 Value: " + QString::number(scan["F1"])+ "\n");
    ui->textBrowser->insertPlainText("F2 Value: " + QString::number(scan["F2"])+ "\n");
    ui->textBrowser->insertPlainText("F3 Value: " + QString::number(scan["F3"])+ "\n");
    ui->textBrowser->insertPlainText("F4 Value: " + QString::number(scan["F4"])+ "\n");
    ui->textBrowser->insertPlainText("F5 Value: " + QString::number(scan["F5"])+ "\n");
    ui->textBrowser->insertPlainText("F6 Value: " + QString::number(scan["F6"])+ "\n");
    ui->textBrowser->insertPlainText("---------------- \n");
    ui->textBrowser->insertPlainText("Body Temperature: " + QString::number(notes[0])+ "\n");
    ui->textBrowser->insertPlainText("Blood Pressure left hand: " + QString::number(notes[1])+"/"+QString::number(notes[2])+ "\n");
    ui->textBrowser->insertPlainText("Blood Pressure right hand: " + QString::number(notes[3])+"/"+QString::number(notes[4])+ "\n");
    ui->textBrowser->insertPlainText("Heart Rate Temperature: " + QString::number(notes[5])+ "\n");
    ui->textBrowser->insertPlainText("Current Weight: " + QString::number(notes[6])+ "\n");

}
