#include "radio.h"
#include "ui_radio.h"

radio::radio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::radio)
{
    ui->setupUi(this);
}

radio::~radio()
{
    delete ui;
}
