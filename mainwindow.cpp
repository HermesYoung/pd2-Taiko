#include<QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"demo.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuButton->hide();
    ui->mapList->hide();
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
{

    QString map_path = ":/demo/maps/demo/notes.tnt";
     beatmap map(map_path);
demo *play=new demo();
play->setMap(map);
play->setlength(1500);
play->resize(this->size());
play->show();
}


void MainWindow::start_game(QString name)
{

    QString map_path = ":/map/maps/map/"+name+"/notes.tnt";
     beatmap map(map_path);
demo *play=new demo();
play->setMap(map);
play->setlength(map.length);
play->resize(this->size());
play->show();
}

void MainWindow::on_playButton_2_clicked()
{
    hide_button();
    ui->menuButton->show();
    ui->mapList->show();
    ui->mapList->setFocus();
    QDir dir_map(":/map/maps/map/");
 ui->mapList->clear();
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
