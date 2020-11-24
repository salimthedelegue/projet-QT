#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include "parking.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmpVehicule.afficher());
    ui->tableView->setModel(tmpParking.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_GestionVehicules_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_GestionParking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Logout_clicked()
{
    close();
}

void MainWindow::on_Ajouter_Vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int i= ui->lineEditId->text().toInt();
    QString D =ui->lineEditDate->text();
    QString Mat =ui->lineEditMatricule->text();
    QString Marq = ui->lineEditMarque->text();
    QString T = ui->lineEditType->text();
    Vehicule V(i,D,Mat,Marq,T);
    bool test=V.ajouter();
    if (test)
    {
       QMessageBox::information(nullptr,QObject::tr("Ajout vehicule"),
                                QObject::tr("Vehicule ajouté.\n"
                                            "Click to exit"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_Vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int i= ui->lineEditId_2->text().toInt();
    QString D =ui->lineEditDate_2->text();
    QString Mat =ui->lineEditMatricule_2->text();
    QString Marq = ui->lineEditMarque_2->text();
    QString T = ui->lineEditType_2->text();
    Vehicule V(i,D,Mat,Marq,T);
    bool test=V.modifier();
    if (test)
    {
       QMessageBox::information(nullptr,QObject::tr("Modifier vehicule"),
                                QObject::tr("Vehicule modifié.\n"
                                            "Click to exit"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Supprimer_vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int id= ui->Reff->text().toInt();
    bool test=tmpVehicule.supprimer(id);
    if(test)

        QMessageBox::information(nullptr,QObject::tr("Supprimer Vehicule"),
                                 QObject::tr("Vehicule suprimé.\n"
                                             "Click to exit"),QMessageBox::Cancel);
}

void MainWindow::on_Return_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Ajouter_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int R =ui->lineEditreff->text().toInt();
    QString A =ui->lineEditAdresse->text();
    int nb = ui->lineEditNbplace->text().toInt();
    QString n= ui->lineEditNom->text();

    Parking P(R,n,A,nb);
    bool test=P.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("Ajout parking"),
                                 QObject::tr("parking ajouté.\n"
                                             "Click to exit"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Modifier_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int R =ui->lineEditreff_2->text().toInt();
    QString A =ui->lineEditAdresse_2->text();
    int nb = ui->lineEditNbplace_2->text().toInt();
    QString n= ui->lineEditNom_2->text();

    Parking P(R,n,A,nb);
    bool test=P.modifier();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("Modifier parking"),
                                 QObject::tr("parking modifié.\n"
                                             "Click to exit"), QMessageBox::Cancel);
    }
}

void MainWindow::on_Supprimer_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int ref= ui->lineEditreff_3->text().toInt();
    bool test=tmpParking.supprimer(ref);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer parking"),
                                 QObject::tr("Parking suprimé.\n"
                                             "Click to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_Return1_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}
