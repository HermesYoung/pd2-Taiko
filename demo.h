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
    void setname(QString);
    QString mname;
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

void setmname(QString);
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
  void change_baground_in_game(int);
private:
  int pos;

QLabel* debuger;
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
       int pre;
beatmap beats;
QMediaPlayer *bgm;
       int combo;
       int score;
  long  int timer_count;

       int update_counter;
 int length;
 int delay;
 int mxcombo;
 int v;
 QLabel *labelTable[1000];
 int labelType[1000];
 QLabel *timerLabel;
 QLabel *scoreLabel;
 QLabel *comboLabel;
 QLabel *pauseLabel;
  QLabel *panelLabel;
  QLabel* coverLabel;
  QLabel*volumeLabel;
};

#endif // DEMO_H
