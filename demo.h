#ifndef DEMO_H
#define DEMO_H
#include<QTimer>
#include <QWidget>
#include<QtMultimedia/QMediaPlayer>
#include<QLabel>
#include<QKeyEvent>
#include<QShortcut>
#include<QPushButton>
#include"beatmap.h"
#include"mainwindow.h"
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
 void setMusic(QMediaPlayer*);
 int pause_state;
 void show_all();
 void hide_all();
void setlength(int);
void setdelay(int);

signals:

public slots:

private slots:
void try_again();
void to_main();
void update();
   void hideDonLeft();
   void hideDonRight();
   void hideKatsuLeft();
   void hideKatsuRight();
   void hideDongOrKatsuOk();

private:

QMediaPlayer *don= new QMediaPlayer();
QMediaPlayer*katsu=new QMediaPlayer();
   QPushButton *retry;
QPushButton *toMain;
QLabel *hit_don_left_label;
   QLabel *hit_don_right_label;
   QLabel *hit_katsu_left_label;
   QLabel *hit_katsu_right_label;
   QLabel *dongOkLabel;
   QLabel *katsuOkLabel;
   QLabel *scorePicLabel;
   QLabel*maxComboLabel;
   int current_note;
       int current_label;
beatmap beats;
QMediaPlayer *bgm;
       int combo;
       int score;
  long  int timer_count;
       bool pressing_don;
       bool pressing_katsu;
       int update_counter;
 int length;
 int delay;
 int mxcombo;
};

#endif // DEMO_H
