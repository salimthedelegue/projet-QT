#ifndef DIALOGDECHARGE_H
#define DIALOGDECHARGE_H

#include <QDialog>

namespace Ui {
class Dialogdecharge;
}

class Dialogdecharge : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogdecharge(QWidget *parent = nullptr);
    ~Dialogdecharge();

private:
    Ui::Dialogdecharge *ui;
};

#endif // DIALOGDECHARGE_H
