#ifndef QUANTITE_H
#define QUANTITE_H

#include<QString>
#include<QDialog>
#include<iostream>
using namespace std;
#include<QSqlTableModel>
class quantite
{

protected:
    int ID_quantite;
    QString typeqnt ;
    QString provenance ;
    int poids ;
public:
    quantite(){};
    quantite(int);

    quantite(QString type,  QString provenance, float poids);
    int getId(){return ID_quantite;}
       QString gettype(){ return typeqnt;}
       QString getprovenance(){ return provenance;}
       int getpoids() {return poids;}
       void setprovenance(QString provenance){this->provenance=provenance;}
       void setType(QString typeqnt){this->typeqnt=typeqnt;}
       void setPoids(int poids){this->poids=poids;}
       void setID_qunatite(int ID_quantite){this->ID_quantite=ID_quantite;}
       bool enregistrer_quantite(quantite *qnt);
       virtual QSqlQueryModel * afficher_quantite();
       QSqlQueryModel * rechercher_quantite(int Id);
       QSqlQueryModel * Afficher(QString tripar,QString Type_Tri);
     bool supprimer_quantite(int Id);
      virtual QSqlQueryModel * afficher_quantiteRech(int id);

     int Rechercheq(int);
     void Supprimerq(int);
     void Modifierq();
     void ajouterpoubelleq();
     float TrouverPoids(int);
     QString TrouverProvenance(int);
     QString Trouvertype(int);
public :static quantite *getQuantiteParId(int);
};

#endif // QUANTITE_H
