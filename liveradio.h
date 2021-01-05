#ifndef LIVERADIO_H
#define LIVERADIO_H

#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QWidget>

namespace Ui {
class liveradio;
}

class liveradio : public QWidget
{
    Q_OBJECT

public:
    explicit liveradio(QWidget *parent = nullptr);
    ~liveradio();
private slots:

    void on_volumedial_valueChanged(int value);

    void on_IfmButton_clicked();

    void on_ShemsButton_clicked();

    void on_JawharaButton_clicked();

    void on_JeunesButton_clicked();

    void on_MonastirButton_clicked();

    void on_NationalButton_clicked();

private:
    Ui::liveradio *ui;
    QMediaPlayer        *m_player;

};

#endif // LIVERADIO_H
