#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"demo.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void hide_button();
    void show_button();
private slots:
    void on_exitButton_clicked();

    void on_playButton_clicked();


private:
    Ui::MainWindow *ui;
 void start_demogame();
};

#endif // MAINWINDOW_H
