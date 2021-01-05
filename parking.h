#ifndef PARKING_H
#define PARKING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Parking
{
private:
    int reff;
    QString adresse;
    int nb_place;
    QString nom;

public:
    Parking();
    Parking(int,QString,QString,int);
    int getRefference(){return reff;}
    QString getAdresse(){return adresse;}
    int getNombrePlace(){return nb_place;}
    QString getNom(){return nom;}
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    bool rechercher(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_reff();
    QSqlQueryModel * tri_Adresse();
    QSqlQueryModel * tri_nb_place();
    QSqlQueryModel *chercher(int);
};

#endif // PARKING_H
