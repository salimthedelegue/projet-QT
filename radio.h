#ifndef RADIO_H
#define RADIO_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>

namespace Ui {
class radio;
}

class radio : public QWidget
{
    Q_OBJECT

public:
    explicit radio(QWidget *parent = nullptr);
    ~radio();
private slots:

    void on_volumedial_valueChanged(int value);

    void on_IfmButton_clicked();

    void on_ShemsButton_clicked();

    void on_JawharaButton_clicked();

    void on_JeunesButton_clicked();

    void on_MonastirButton_clicked();

    void on_NationalButton_clicked();



private:
    Ui::radio *ui;
    QMediaPlayer        *m_player;
};

#endif // RADIO_H
