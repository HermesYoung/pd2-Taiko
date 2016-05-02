#ifndef DEMO_H
#define DEMO_H
#include<QTimer>
#include <QWidget>
#include<QLabel>
#include<QKeyEvent>
#include<QPushButton>
#include"beatmap.h"
class demo : public QWidget
{
    Q_OBJECT
public:
    explicit demo(QWidget *parent = 0);
QTimer *timer;
void keyPressEvent(QKeyEvent *event);
void pause();
void conti();
 void setMap(beatmap);
 int pause_state;
 void show_all();
 void hide_all();


signals:

public slots:
 void try_again();
 void to_main();
private slots:
void update();
   void hideDonLeft();
   void hideDonRight();
   void hideKatsuLeft();
   void hideKatsuRight();
   void hideDongOrKatsuOk();

private:
QPushButton *retry;
QPushButton *toMain;
QLabel *hit_don_left_label;
   QLabel *hit_don_right_label;
   QLabel *hit_katsu_left_label;
   QLabel *hit_katsu_right_label;
   QLabel *dongOkLabel;
   QLabel *katsuOkLabel;
   QLabel *scorePicLabel;
   int current_note;
       int current_label;
beatmap beats;
       int combo;
       int score;
    int timer_count=31;
       bool pressing_don;
       bool pressing_katsu;
       int update_counter;

};

#endif // DEMO_H
