#ifndef DIALOGPOUBELLES_H
#define DIALOGPOUBELLES_H
#include "ui_dialogpoubelles.h"
#include "QLineEdit"
#include <QDialog>

namespace Ui {
class Dialogpoubelles;
}

class Dialogpoubelles : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogpoubelles(QWidget *parent = nullptr);
    ~Dialogpoubelles();

private slots:

    void on_pushButton_clicked();

    void on_pushButtonenregistrer_clicked();

private:
    Ui::Dialogpoubelles *ui;
};

#endif // DIALOGPOUBELLES_H
