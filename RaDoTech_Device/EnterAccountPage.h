#ifndef ENTERACCOUNTPAGE_H
#define ENTERACCOUNTPAGE_H

#include <QDialog>

#include <string>
using namespace std;

namespace Ui {
class EnterAccountPage;
}

class EnterAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit EnterAccountPage(QWidget *parent = nullptr);
    ~EnterAccountPage();
    void wrongEmailOrPassword();
    void resetPage();

signals:
    void backButtonClicked();
    void signInButtonClicked(string email, string password);

private:
    Ui::EnterAccountPage *ui;
};

#endif // ENTERACCOUNTPAGE_H
