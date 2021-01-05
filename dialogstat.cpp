#include "dialogstat.h"
#include "ui_dialogstat.h"
#include"poubelle.h"
// Manages the applications main settings like
// widget initialization
#include <QApplication>

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

Dialogstat::Dialogstat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogstat)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    series->append("Vides",poubelle::countlines("Vide"));
    series->append("Pleines",poubelle::countlines("Pleine"));
    series->append("Hors service",poubelle::countlines("Hors service"));

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

    chart->legend()->setVisible(false);
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for(auto slice : series->slices())
    slice->setLabel(slice->label()+" : "+QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout->addWidget(chartView);
}

Dialogstat::~Dialogstat()
{
    delete ui;
}
