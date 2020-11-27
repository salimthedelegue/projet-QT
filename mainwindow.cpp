#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
        QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
        ui->labelback_menu->setPixmap(pix.scaled(1366,768));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonpoubelles_clicked()
{

     Dialogpoubelles dialogpoubelles;
     dialogpoubelles.setModal(true);
     dialogpoubelles.exec();

}
