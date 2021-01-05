#ifndef DIALOGDECHARGE_H
#define DIALOGDECHARGE_H

#include <QDialog>
#include "QLineEdit"
#include <QDialog>
#include<quantite.h>

namespace Ui {
class Dialogdecharge;
}

class Dialogdecharge : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogdecharge(QWidget *parent = nullptr);
    ~Dialogdecharge();

private slots:
    void on_pushButtonAnnulerDech_clicked();

    void on_pushButtonEnregDech_clicked();

    void on_pushButtonsupmoddech_clicked();

    void on_radioButtonModifer_clicked();

    void on_radioButtonSupprimer_clicked();

    void on_pushButtonValider_clicked();

    void on_lineEditId_textChanged(const QString &arg1);

    void on_pushButtonrechdech_clicked();

    void on_pushButtonAfficherDech_clicked();

private:
    Ui::Dialogdecharge *ui;
    quantite qnt;
};

#endif // DIALOGDECHARGE_H
