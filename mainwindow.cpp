#include<QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"demo.h"
#include<QUrl>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuButton->hide();
    ui->mapList->hide();

    QDir setting(QDir::currentPath());
    setting.mkdir("songs");
    QPixmap bkgd(":/images/images/title.png");
    bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgd);
   this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::hide_button()
{
    ui->playButton->hide();
    ui->exitButton->hide();
    ui->playButton_2->hide();
}
void MainWindow::show_button()
{
    ui->playButton->show();
    ui->exitButton->show();
    ui->playButton_2->show();
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}

void MainWindow::on_playButton_clicked()
{
    hide_button();
 start_demogame();
this->hide();

}
void MainWindow::start_demogame()
{QString bgm_path="qrc:/map/maps/map/songa/song.mp3";
    QMediaPlayer *music= new QMediaPlayer(this);
    music->setMedia(QUrl(bgm_path));

    QString map_path = ":/demo/maps/demo/notes.tnt";
     beatmap map(map_path);
demo *play=new demo();
play->setMap(map);
play->setMusic(music);
play->setlength(30);
play->resize(this->size());
play->show();
}


void MainWindow::start_game(QString name)
{QDir dir_map;
    QString bgm_path=dir_map.currentPath()+"/songs/"+name+"/song.mp3";

QMediaPlayer *music= new QMediaPlayer(this);
music->setMedia(QUrl::fromLocalFile(bgm_path));
QString map_path=dir_map.currentPath()+"/songs/"+name+"/notes.tnt";
     beatmap map(map_path);
demo *play=new demo();
play->setMap(map);
play->setlength(map.length);
play->setMusic(music);
play->setdelay(map.delay);
play->resize(this->size());
play->show();
}

void MainWindow::on_playButton_2_clicked()
{
    hide_button();
    ui->menuButton->show();
    ui->mapList->show();
    ui->mapList->setFocus();
    ui->mapList->clear();
    QDir dir_map;
    QString map_path=dir_map.currentPath()+"/songs";


dir_map.setPath(map_path);
 ui->mapList->addItems(dir_map.entryList(QDir::Dirs|QDir::NoDotAndDotDot));
 if(ui->mapList->count()>0)
     ui->mapList->setCurrentItem(ui->mapList->item(0));

}

void MainWindow::on_menuButton_clicked()
{
    show_button();
    ui->menuButton->hide();
    ui->mapList->hide();

}

void MainWindow::on_mapList_itemDoubleClicked()
{
    ui->mapList->hide();
    start_game(ui->mapList->currentItem()->text());
    this->hide();
}
