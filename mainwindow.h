#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDir>
#include"demo.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void setbg();
    void hide_button();
    void show_button();
    void showlist();
private slots:
    void on_exitButton_clicked();

    void on_playButton_clicked();




    void on_playButton_2_clicked();

    void on_menuButton_clicked();

    void on_mapList_itemDoubleClicked();



private:
    Ui::MainWindow *ui;
 void start_demogame();
 void start_game(QString);


};

#endif // MAINWINDOW_H
