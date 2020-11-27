#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"

Dialogdecharge::Dialogdecharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdecharge)
{
    ui->setupUi(this);
}

Dialogdecharge::~Dialogdecharge()
{
    delete ui;
}
