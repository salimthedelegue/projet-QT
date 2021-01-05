#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vehicule.h"
#include "parking.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include "statistic.h"
#include <QString>
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_GestionVehicules_clicked();

    void on_GestionParking_clicked();

    void on_Logout_clicked();

    void on_Ajouter_Vehicule_clicked();

    void on_Modifier_Vehicule_clicked();

    void on_Supprimer_vehicule_clicked();

    void on_Return_clicked();

    void on_Ajouter_Parking_clicked();

    void on_Modifier_Parking_clicked();

    void on_Supprimer_Parking_clicked();

    void on_Return1_clicked();

    void on_Recherche_Vehicule_clicked();

    void on_Recherche_Parking_clicked();

    void on_Trier_Vehicule_clicked();

    void on_Trier_Parking_clicked();

    void on_Imprimer_Parking_clicked();

    void on_Imprimer_vehicule_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_Tri_vehicule_currentTextChanged(const QString &arg1);

    void on_Actualiser_parkinng_clicked();

    void on_Actualiser_Vehicule_clicked();

    void on_Tri_Parking_currentTextChanged(const QString &arg1);

    void on_Return1_2_clicked();

    void on_Statistiques_clicked();

    void on_pushButton_clicked();


        void on_sliderprogress_sliderMoved(int position);

            void on_slidervolume_sliderMoved(int position);

            void on_pushButton_4_clicked();

            void on_pushButton_5_clicked();

            void on_positionchanged(qint64 position);

            void on_durationchanged(qint64 position);


            void on_pushButton5_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * click, *music,*player;
    Vehicule tmpVehicule;
    Parking tmpParking;
    //statistic s;
};
#endif // MAINWINDOW_H
