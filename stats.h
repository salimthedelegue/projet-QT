#ifndef STATS_H
#define STATS_H
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class stats; }
QT_END_NAMESPACE

namespace Ui {
class stats;
}

class stats : public QMainWindow
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    ~stats();

private:
    Ui::stats *ui;
};

#endif // STATS_H
