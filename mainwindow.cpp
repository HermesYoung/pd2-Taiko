
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"demo.h"
#include<QUrl>
#include<cstdlib>
#include<ctime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuButton->hide();
    ui->mapList->hide();
ui->menuBar->hide();
ui->offset_box->hide();
ui->label->hide();
ui->delay->hide();
ui->label_2->hide();
    QDir setting(QDir::currentPath());
    setting.mkdir("songs");
    QPixmap bkgd(":/images/images/title.png");
    bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgd);
   this->setPalette(palette);
    QDir dir_map;
    QString map_path=dir_map.currentPath()+"/songs";


dir_map.setPath(map_path);
 ui->mapList->addItems(dir_map.entryList(QDir::Dirs|QDir::NoDotAndDotDot));
 if(ui->mapList->count()>0)
     ui->mapList->setCurrentItem(ui->mapList->item(0));
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


}
void MainWindow::start_demogame()
{QString bgm_path="qrc:/map/maps/map/songa/song.mp3";
    QMediaPlayer *music= new QMediaPlayer(this);
    music->setMedia(QUrl(bgm_path));
srand(time(NULL));

     beatmap map("");
     for(int i=0;i<10000;i++)
     {

         map.notes[i].start_time=i*300;
         map.notes[i].bg=0;
         map.notes[i].key=rand()%2+1;
     }

demo *play=new demo(this);
play->setMap(map);
play->setdelay(1120);
play->setMusic(music);
play->setlength(30000);
play->show();

}


void MainWindow::start_game(QString name)
{QDir dir_map;
QDir temp;
    QString bgm_path=dir_map.currentPath()+"/songs/"+name+"/song.mp3";
QString bg_path=dir_map.currentPath()+"/songs/"+name;
QMediaPlayer *music= new QMediaPlayer(this);
music->setMedia(QUrl::fromLocalFile(bgm_path));
QString map_path=dir_map.currentPath()+"/songs/"+name+"/notes.tnt";
     beatmap map(map_path);
     map.delay=ui->delay->value();
     int i;
         for (i=0;i<10000;i++)
         {
         map.notes[i].start_time=((map.notes[i].start_time-map.delay)*1000)/(1000+ui->offset_box->value())+map.delay;

         }
         map.length=((map.length-map.delay)*1000)/(1000+ui->offset_box->value())+map.delay;
demo *play=new demo(this);
play->setMap(map);
play->setlength(map.length);
play->setMusic(music);

    QString bg=dir_map.currentPath()+"/songs/"+name+"/bg.jpg";
temp.setPath(bg);
 QPalette palette;
    if(temp.exists(bg))
    {
        QPixmap gbkgd;
        gbkgd.load(bg);
        gbkgd=gbkgd.scaled(this->size(),Qt::IgnoreAspectRatio);

        palette.setBrush(QPalette::Background,gbkgd);

    }
    else
    {
        QPixmap gdbkgd(":/images/images/background.jpg");



        gdbkgd=gdbkgd.scaled(this->size(),Qt::IgnoreAspectRatio);

        palette.setBrush(QPalette::Background,gdbkgd);


    }
    this->setPalette(palette);


    play->setdelay(map.delay);
play->setname(name);


play->show();


}

void MainWindow::on_playButton_2_clicked()
{
    hide_button();
    ui->menuButton->show();
    ui->mapList->show();
    ui->mapList->setFocus();
    ui->mapList->clear();
    ui->offset_box->show();
    ui->label->show();
    ui->delay->show();
    ui->label_2->show();
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
    ui->offset_box->hide();
    ui->label->hide();
    ui->delay->hide();
    ui->label_2->hide();

}

void MainWindow::on_mapList_itemDoubleClicked()
{   ui->menuButton->hide();
    ui->mapList->hide();
    start_game(ui->mapList->currentItem()->text());

}
void MainWindow::showlist()
{
    ui->mapList->show();
    ui->menuButton->show();
}
void MainWindow::setbg()
{
    QPixmap bkgd(":/images/images/title.png");
    bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgd);
   this->setPalette(palette);
    ui->label->show();
    ui->label_2->show();
    ui->offset_box->show();
    ui->delay->show();
}
