#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include "connexionbd.h"

Connection ::Connection()
{


}
bool Connection::createconnect()
{ bool test=false;
    QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A.");
    db.setUserName("Sana");
    db.setPassword("esprit20");
    if (db.open())
        test=true;
    return test;



}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
       ui->labelback_menu->setPixmap(pix.scaled(1366,768));
}

        /*Connection c;
        bool test=c.createconnect();
        if(!test)
    {
            QMessageBox::critical( nullptr ,QObject::tr("database isn't open")
                    ,QObject::tr("connection failed.\n"
                                "Click Cancel to exit.") ,QMessageBox::Cancel);



    }
        else{
            ui->setupUi(this);

               QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
               ui->labelback_menu->setPixmap(pix.scaled(1366,768));
        }

}*/

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



void MainWindow::on_pushButtonDecharge_clicked()
{
    Dialogdecharge dialogdecharge;
    dialogdecharge.setModal(true);
    dialogdecharge.exec();
}
/*QPieSeries *series = new QPieSeries();
    series->append("Vides",40);
    series->append("Pleines",20);
    series->append("Hors service",15);

   // Add label to 1st slice
    QPieSlice *slice0 = series->slices().at(0);

    slice0->setLabelVisible();


    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    // Add labels to rest of slices
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    //QPieSlice *slice3 = series->slices().at(3);
    //slice3->setLabelVisible();
    //QPieSlice *slice4 = series->slices().at(4);
    //slice4->setLabelVisible();

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);

    chart->setTitle("STATISTIQUES POUBELLES");
    //chart->legend()->setData();
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->legend()->setVisible(true);
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for(auto slice : series->slices())
    slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow window;

    // Set the main window widget
    window.setCentralWidget(chartView);
    window.resize(420, 300);

    window.show();
    */
