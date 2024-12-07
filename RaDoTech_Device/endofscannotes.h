#ifndef ENDOFSCANNOTES_H
#define ENDOFSCANNOTES_H

#include <QWidget>

namespace Ui {
class endOfScanNotes;
}

class endOfScanNotes : public QWidget
{
    Q_OBJECT

public:
    explicit endOfScanNotes(QWidget *parent = nullptr);
    ~endOfScanNotes();

private:
    Ui::endOfScanNotes *ui;


signals:
    void sendNotesToUser(int temp, int pressure1L, int pressure2L, int pressure1R, int pressure2R, int heartRate, int currentWeight);

};

#endif // ENDOFSCANNOTES_H
