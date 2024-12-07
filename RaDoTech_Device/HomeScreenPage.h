#ifndef HOMESCREENPAGE_H
#define HOMESCREENPAGE_H

#include "User.h"
#include <QDialog>
#include <QString>
#include <QTimer>
#include <map>
#include <string>
using namespace std;
namespace Ui {
class HomeScreenPage;
}

class HomeScreenPage : public QDialog
{
    Q_OBJECT

public:
    explicit HomeScreenPage(QWidget *parent = nullptr);
    ~HomeScreenPage();
    void setUser(User* user);
    void setaNewReading(map<string, int>, map<string, string>);
    void addEndOfScan(int, int, int, int, int, int, int);

signals:
    void logoutButtonClicked();
    void measureNowButtonClicked();
private slots:
    void previousClicked();
    void latestClicked();

private:
    Ui::HomeScreenPage *ui;
    User* user = new User();
    int prevScansIndex;
};

#endif // HOMESCREENPAGE_H
