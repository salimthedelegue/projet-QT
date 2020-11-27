#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "QLineEdit"
#include <QDialog>
#include <QIntValidator>
#include <QRegExpValidator>

Dialogpoubelles::Dialogpoubelles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogpoubelles)
{
    ui->setupUi(this);
    QRegExp rx("[1-9][0-9]*");
    QRegExpValidator *valinumcap=new QRegExpValidator(rx,this);
    ui->lineEdit_numcap->setValidator(valinumcap);
    QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
    ui->labelbackajout->setPixmap(pix.scaled(1366,768));
    ui->labelbacsup->setPixmap(pix.scaled(1366,768));
    ui->labelbacmodif->setPixmap(pix.scaled(1366,768));


}

Dialogpoubelles::~Dialogpoubelles()
{
    delete ui;
}

void Dialogpoubelles::on_pushButton_clicked()
{
     ui->lineEdit_numcap->setText("   ");
     ui->lineEdit_long->setText("   ");
     ui->lineEdit_lat->setText("   ");
     ui->lineEdit_adr->setText("   ");
}
