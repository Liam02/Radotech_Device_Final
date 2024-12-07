#ifndef MEASURINGPAGE_H
#define MEASURINGPAGE_H

#include <QDialog>
#include <map>
#include <string>
using namespace std;
namespace Ui {
class MeasuringPage;
}

class MeasuringPage : public QDialog
{
    Q_OBJECT

public:
    explicit MeasuringPage(QWidget *parent = nullptr);
    int checkOtherSide(string ,int );
    ~MeasuringPage();
    void performScan();

private:
    Ui::MeasuringPage *ui;
    map<string, int> readings;
    map<string, string> analysis;
    bool finished;
    int index;
private slots:
    void nextButtonisClicked();
    void backButtonisClicked();
    void saveButtonisClicked();
signals:
    void backButtonClicked();
    void saveButtonClicked();
    void sendReadingToUser(map<string, int>, map<string, string>);

};

#endif // MEASURINGPAGE_H
