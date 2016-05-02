#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"demo.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->playButton->setVisible(false);
    ui->exitButton->setVisible(false);
}
void MainWindow::show_button()
{
    ui->playButton->setVisible(true);
    ui->exitButton->setVisible(true);
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
play->resize(this->size());
play->show();
}
