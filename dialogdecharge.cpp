#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include <QPixmap>
#include <QLabel>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "QLineEdit"
#include <QDialog>
#include<QPainter>
#include <QPrinter>
#include<QTableView>
#include<QDate>
#include <QIntValidator>
#include <QRegExpValidator>
#include<QRegularExpressionValidator>
#include<QString>
#include<QRadioButton>
#include"quantite.h"
#include<iostream>

Dialogdecharge::Dialogdecharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdecharge)
{
    ui->setupUi(this);
    //REGULAR EXP
    QRegExp poids("[1-9][0-9]*");
    //QRegExpValidator *valipoids=new QRegExpValidator(poids,this);
   // ui->lineEdit_poids->setValidator(valipoids);
   // QRegExp provenance("^[a-zA-Z]+(\\s[a-zA-Z]+)?$");
   // QRegExpValidator *valiprovenance=new QRegExpValidator(provenance,this);
   // ui->lineEdit_proven->setValidator(valiprovenance);
    QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
    ui->label_dechajout->setPixmap(pix.scaled(1366,768));
    ui->label_BackSupDech->setPixmap(pix.scaled(1366,768));
    ui->label_backhistdech->setPixmap(pix.scaled(1366,768));
}

Dialogdecharge::~Dialogdecharge()
{
    delete ui;
}

void Dialogdecharge::on_pushButtonAnnulerDech_clicked()
{
    ui->lineEdit_poids->setText("");
    ui->lineEdit_proven->setText("");
    this->ui->comboBox_type->clear();

}

void Dialogdecharge::on_pushButtonEnregDech_clicked()
{     QString typeqnt=ui->comboBox_type->currentText();
      QString provenance= ui->lineEdit_proven->text();
     float poids=ui->lineEdit_poids->text().toInt();
       quantite*qnt = new quantite(typeqnt,provenance,poids);
         // controle de saisie
         bool isInputsValid=true;
         QRegularExpression poi_Exp;

         poi_Exp.setPattern(R"([1-9][0-9]*)");
         if((poids==NULL) || (!poi_Exp.match(QString::number(poids)).hasMatch())){
             isInputsValid=false;
             ui->lineEdit_poids->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->lineEdit_poids->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%; ");
         }
         QRegularExpression Provenance_Exp;

           Provenance_Exp.setPattern(R"(^2[0-5]{1},rue [a-z]{4,}$)");
           if((provenance!="") && !Provenance_Exp.match((provenance)).hasMatch()){
             isInputsValid=false;
             ui->lineEdit_proven->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->lineEdit_proven->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%;");
         }

           //compare return 0 if str1=str2
         if(QString::compare(typeqnt, "Veuiller choisir", Qt::CaseInsensitive)==0){
             isInputsValid=false;

             ui->comboBox_type->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->comboBox_type->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%;");
         }


         //
         if(isInputsValid==true){
             if (qnt->enregistrer_quantite(qnt))
                             QMessageBox::information(0, qApp->tr("Enregistrer"),
                                 qApp->tr("Une nouvelle quantite est ajoutée"), QMessageBox::Ok);
                         else
                             QMessageBox::critical(0, qApp->tr("Enregistrer"),
                                 qApp->tr("Problème d'enregistrement"), QMessageBox::Cancel);
         }
         else{
             QMessageBox::critical(0, qApp->tr("Invalid inputs"),
                 qApp->tr("Please  verif inputs "), QMessageBox::Cancel);
         }
}


void Dialogdecharge::on_pushButtonsupmoddech_clicked()
{
    bool rdsu,rdmo;

    rdsu=ui->radioButtonSupprimer->isChecked();
    rdmo=ui->radioButtonModifer->isChecked();
QString lineEdit_Provenancesupmod,comboBox_typesupmod;
int id=ui->lineEditId->text().toInt();

ui->lineEdit_Provenancesupmod->text();
ui->comboBox_typesupmod->currentText();
ui->lineEditPoidssupmod->text().toInt();
quantite *S =new quantite(id);
quantite *M =new quantite(id);

if(rdsu)

{if(S->Rechercheq(id)==1)
    {


        S->Supprimerq(id);
        QMessageBox::warning(this,"Information","La quantite est Supprime");
    }}

    else if(rdmo){
    if(S->Rechercheq(id)==1)
    { M->setID_qunatite(id);
        M->setPoids(ui->lineEditPoidssupmod->text().toInt());
        M->setprovenance(ui->lineEdit_Provenancesupmod->text());
        M->setType(ui->comboBox_typesupmod->currentText());

        M->Modifierq();
        QMessageBox::warning(this,"Information","la quantite est modifie");
    }}

}


void Dialogdecharge::on_radioButtonModifer_clicked()
{
    ui->label_ID->setVisible(true);
        ui->lineEditId->setVisible(true);
        {int id=ui->lineEditId->text().toInt();
            quantite * S=new quantite(id);
            if(S->Rechercheq(id)==1)
        {

                ui->label_provsupmod->setVisible(true);
                ui->lineEdit_Provenancesupmod->setVisible(true);
                ui->label_typesupmod->setVisible(true);
                ui->comboBox_typesupmod->setVisible(true);
                ui->label_poidssupmod->setVisible(true);
                ui->lineEditPoidssupmod->setVisible(true);


                 ui->comboBox_typesupmod->setEnabled(true);
                 ui->lineEdit_Provenancesupmod->setEnabled(true);
                  ui->lineEditPoidssupmod->setEnabled(true);

        }
            else{ui->label_typesupmod->setVisible(true);
                ui->comboBox_typesupmod->setVisible(true);
                ui->label_poidssupmod->setVisible(true);
                ui->lineEditPoidssupmod->setVisible(true);
                ui->label_provsupmod->setVisible(true);
                ui->lineEdit_Provenancesupmod->setVisible(true);


                 ui->comboBox_typesupmod->setEnabled(false);
                 ui->lineEditPoidssupmod->setEnabled(false);
                  ui->lineEdit_Provenancesupmod->setEnabled(false);

                    ui->pushButtonsupmoddech->setEnabled(false);

                }

                ui->pushButtonsupmoddech->setText("Modifier");

        }

}

void Dialogdecharge::on_radioButtonSupprimer_clicked()
{
    int id=ui->lineEditId->text().toInt();
            quantite * S=new quantite(id);
            ui->comboBox_typesupmod->setVisible(false);
            ui->lineEditPoidssupmod->setVisible(false);
             ui->lineEdit_Provenancesupmod->setVisible(false);


             ui->label_typesupmod->setVisible(false);
             ui->label_poidssupmod->setVisible(false);
             ui->label_provsupmod->setVisible(false);


            if(S->Rechercheq(id)==1)
        {ui->lineEditPoidssupmod->setVisible(false);

        ui->label_poidssupmod->setVisible(false);
        ui->pushButtonsupmoddech->setEnabled(true);}

        ui->pushButtonsupmoddech->setText("Supprimer");

}

void Dialogdecharge::on_pushButtonValider_clicked()
{
    int id= ui ->lineEditId->text().toInt();
              quantite * A=new quantite(id);
       if(A->Rechercheq(id)==1)
   {QMessageBox::information(this,"Information"," quantite trouvee  ");

               ui->lineEdit_Provenancesupmod->setEnabled(true);
               ui->lineEditPoidssupmod->setEnabled(true);
               ui->comboBox_typesupmod->setEnabled(true);
               ui->pushButtonsupmoddech->setEnabled(true);



       }
      else {QMessageBox::critical(this,"Erreur "," quantite non trouvee ! ");
           ui->lineEdit_Provenancesupmod->setEnabled(false);
           ui->comboBox_typesupmod->setEnabled(false);
           ui->lineEditPoidssupmod->setEnabled(false);

               ui->pushButtonsupmoddech->setEnabled(false);

   }

}

void Dialogdecharge::on_lineEditId_textChanged(const QString &arg1)
{
    int id=ui->lineEditId->text().toInt();quantite * A=new quantite(id);

     if(A->Rechercheq(id)==0)
     {
         ui->lineEditId->setStyleSheet("background: red ");
         ui->lineEdit_Provenancesupmod->setVisible(false);
         ui->lineEditPoidssupmod->setVisible(false);
         ui->comboBox_typesupmod->setVisible(false);
         ui->label_typesupmod->setVisible(false);
         ui->label_poidssupmod->setVisible(false);
         ui->label_provsupmod->setVisible(false);

         ui->pushButtonsupmoddech->setText("identifiant incorrect !!");
         ui->pushButtonsupmoddech->setEnabled(false);
ui->lineEdit_Provenancesupmod->setEnabled(false);
        }
     else
     {quantite *quantiteFromDB =quantite ::getQuantiteParId(id);


         ui->lineEditPoidssupmod->setText(QString::number(quantiteFromDB->getpoids()));
         ui->lineEdit_Provenancesupmod->setText(qnt.TrouverProvenance(id));
         ui->comboBox_typesupmod->currentText()=qnt.Trouvertype(id);
         ui->comboBox_typesupmod->setCurrentIndex(ui->comboBox_typesupmod->findText(quantiteFromDB->gettype()));//CurrentText(pubelleFromDB->getetat());



         ui->lineEditId->setStyleSheet("background: white ");
        ui->pushButtonsupmoddech->setEnabled(false);

        if(ui->radioButtonModifer->isChecked()){
             ui->lineEditPoidssupmod->setVisible(true);
             ui->lineEdit_Provenancesupmod->setVisible(true);
             ui->lineEditPoidssupmod->setVisible(true);



             ui->label_typesupmod->setVisible(true);
             ui->label_poidssupmod->setVisible(true);
             ui->label_provsupmod->setVisible(true);
             ui->lineEditPoidssupmod->setVisible(true);
             ui->lineEdit_Provenancesupmod->setVisible(true);
             ui->comboBox_typesupmod->setVisible(true);

                 ui->pushButtonsupmoddech->setText("Modifier");
                 ui->pushButtonsupmoddech->setEnabled(true);
         }
         if(ui->radioButtonSupprimer->isChecked()){ ui->lineEditPoidssupmod->setVisible(true);
             ui->lineEditPoidssupmod->setVisible(false);
             ui->label_poidssupmod->setVisible(false);
             ui->lineEdit_Provenancesupmod->setVisible(false);
             ui->label_provsupmod->setVisible(false);
              ui->comboBox_typesupmod->setVisible(false);
              ui->label_typesupmod->setVisible(false);

              ui->pushButtonsupmoddech->setEnabled(true);
         ui->pushButtonsupmoddech->setText("Supprimer");


         }
         if(!(ui->radioButtonModifer->isChecked())&&!(ui->radioButtonSupprimer->isChecked()))ui->pushButtonsupmoddech->setText("Choisir une Option");
     }


}

void Dialogdecharge::on_pushButtonrechdech_clicked()
{quantite *tmpCl2= new quantite();
        QString idRech1=ui->lineEdit_Rechquantite->text();
            if (idRech1=="")
            {
                QMessageBox::critical(0, qApp->tr("recherche"),
                    qApp->tr("Veuillez introduire un ID"), QMessageBox::Cancel);
            }
            else
            {
                int id =ui->lineEdit_Rechquantite->text().toInt();
                    QSqlQueryModel *model =tmpCl2->afficher_quantiteRech(id);
                   int idRechResult1 = model->data(model->index(0,3)).toInt();
                    if(id == idRechResult1)
                    {   ui->tableViewRech->setModel(model);
                    }
                     else
                    { ui->tableViewRech->setModel(NULL);
                        QMessageBox::critical(0, qApp->tr("Recherche"),
                            qApp->tr("quantite non trouvee"), QMessageBox::Cancel);
                    }
            }
}


void Dialogdecharge::on_pushButtonAfficherDech_clicked()
{quantite *tmpCl1= new quantite();
    QString t=ui->comboBox_tripar->currentText();
    QString ty=ui->comboBox_typetri->currentText();
 QSqlQueryModel *model =tmpCl1->Afficher(t,ty);
 qDebug()<<"total rows" <<model->rowCount();
    ui->tableViewAfficher->setModel(model);
}

