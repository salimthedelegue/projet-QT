#include "stats.h"
#include "ui_stats.h"

stats::stats(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}
