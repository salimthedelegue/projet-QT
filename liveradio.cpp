#include "liveradio.h"
#include "ui_liveradio.h"


liveradio::liveradio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::liveradio)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer(this);          // Initialize the player
    m_player->setMedia(QUrl("http://rtstream.tanitweb.com/nationale"));//Set the default playing stream
    m_player->setVolume(70);                    // Set the volume for playing tracks
    ui->volumedial->setValue(70);

    // connect the control buttons to the control slots
    connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
    connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);

}

liveradio::~liveradio()
{
    delete ui;
    delete m_player;
}

void liveradio::on_volumedial_valueChanged(int value)
{
    m_player->setVolume(value);//adjust player volume
    QString vol = QString::number(value);//convert volume value integer to string
    ui->volumeLabel->setText("Volume : "+vol+"%");//display current volume
}

void liveradio::on_IfmButton_clicked()
{
    m_player->stop();//stop current playback
    m_player->setMedia(QUrl("https://live.ifm.tn/radio/8000/ifmlive?1585267848"));//set new stream url
    m_player->play();//start playing selected channel
    ui->statuslabel->setText("Now Playing : IFM");//
}

void liveradio::on_ShemsButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("https://stream6.tanitweb.com/shems"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Shems FM");
}


void liveradio::on_JawharaButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("https://streaming2.toutech.net/jawharafm"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Jawhara FM");
}

void liveradio::on_JeunesButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://rtstream.tanitweb.com/jeunes"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Jeunes FM");
}

void liveradio::on_MonastirButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://rtstream.tanitweb.com/monastir"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Monastir");
}

void liveradio::on_NationalButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://rtstream.tanitweb.com/nationale"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Radio National");
}

