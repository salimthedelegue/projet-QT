#include "quantite.h"
#include "QDebug"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlRecord>
#include <QString>
#include<QPainter>
#include <QPrinter>
#include<QTableView>
#include<QDate>

quantite::quantite(QString type, QString provenance, float poids)
{
    this->typeqnt=type;
    this->provenance=provenance;
    this->poids=poids;

}
bool quantite::enregistrer_quantite(quantite * qnt)
{
QSqlQuery query;
QString str= "insert into DECHARGE (poids,provenance,typeqnt) values("+QString::number( qnt->getpoids())+",'"+qnt->getprovenance()+"','"+qnt->gettype()+"')" ;
qDebug()<<str;
qDebug()<< "insert into DECHARGE (poids,provenance,typeqnt) values("+QString::number( qnt->getpoids())+",'"+qnt->getprovenance()+"','"+qnt->gettype()+"')";
bool res1 = query.exec(str);
return res1;
}
QSqlQueryModel * quantite::afficher_quantite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DECHARGE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("typeqnt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_QUANTITE"));


    return model;
}
QSqlQueryModel * quantite::Afficher(QString tripar, QString type_tri)
{ QString selected_Tritype=(type_tri=="croissant")?"asc":"desc"; //the conditional operator or ternary(the operator ?:)
   // if(Type_Tri=="decroissant")comboBox_Tri="desc";
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DECHARGE order by("+tripar+") "+selected_Tritype);
qDebug()<<"select * from DECHARGE order by("+tripar+") "+selected_Tritype;
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPEQNT"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROVENANCE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_QUANTITE"));

       return model;

}
QSqlQueryModel * quantite::rechercher_quantite(int Id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from DECHARGE where Id_qunatite ="+QString::number(Id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_QUANTITE"));
    return model;
}
quantite::quantite(int ID_quantite)
{
    this->ID_quantite=ID_quantite;}
int quantite::Rechercheq(int id)
{

   QSqlQuery query;
    int test=0;
    query.exec("select * from DECHARGE where ID_QUANTITE="+QString::number(id));

    while(query.next())
        test++;

    return(test);
}


void quantite::Supprimerq(int id)
{QSqlQuery query;
    query.exec("delete from DECHARGE where(ID_QUANTITE="+QString::number(id)+")");
}
void quantite::Modifierq()
{QSqlQuery query;
    query.exec("update DECHARGE Set poids="+QString::number(getpoids())+",provenance='"+getprovenance()+"',typeqnt='"+gettype()+"'  where(ID_QUANTITE="+QString::number(getId())+")");
qDebug()<<"update DECHARGE Set poids="+QString::number(getpoids())+",provenance='"+getprovenance()+"',typeqnt='"+gettype()+"'  where(ID_QUANTITE="+QString::number(getId())+")";
}

QSqlQueryModel * quantite::afficher_quantiteRech(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from DECHARGE where ID_QUANTITE ="+QString::number(id);
    qDebug()<<"select * from DECHARGE where ID_QUANTITE ="+QString::number(id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("typeqnt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_QUANTITE"));
    /*
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DECHARGE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("typeqnt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROVENANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_QUANTITE"));

*/

    return model;
}
quantite* quantite:: getQuantiteParId(int id){
    QSqlQuery query;

        query.exec("Select * from POUBELLE where(ID_QUANTITE="+QString::number(id)+")");
        QSqlRecord rec = query.record();
            quantite* q= new quantite();

                    while (query.next())
                    {
                       // qDebug() << query.value(nameCol).toString(); // output all names
                    //qDebug()<<"Select * from DECHARGE where(ID_QUANTITE="+QString::number(id)+")";
                   q->setPoids( query.value(rec.indexOf("POIDS")).toFloat());
                   q->setprovenance( query.value(rec.indexOf("PROVENANCE")).toString());
                    q->setType( query.value(rec.indexOf("typeqnt")).toString());
                     q->setID_qunatite(query.value(rec.indexOf("ID_QUANTITE")).toInt());


                    }
                    return q;

}
float quantite::TrouverPoids(int id)
{ QSqlQuery query;
    float result;
    query.exec("Select * from DECHARGE where(ID_QUANTITE="+QString::number(id)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("POIDS"); // index of the field "name"
    while (query.next())
    {
       // qDebug() << query.value(nameCol).toString(); // output all names
    //qDebug()<<"Select * from Poubelle where(ID_QUANTITE="+QString::number(idp)+")";
    result=query.value(nameCol).toFloat();
    }

    return(result);

}
QString quantite::TrouverProvenance(int id)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from DECHARGE where(ID_QUANTITE="+QString::number(id)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("PROVENANCE"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);
}
QString quantite::Trouvertype(int id)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from DECHARGE where(ID_QUANTITE="+QString::number(id)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("typeqnt"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);
}
