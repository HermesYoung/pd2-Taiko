#include<QWidget>
#include "demo.h"
#include"mainwindow.h"
#include<QDir>

QLabel *labelTable[1000];
int labelType[1000];
QLabel *timerLabel;
QLabel *scoreLabel;
QLabel *comboLabel;
QLabel *pauseLabel;
 QLabel *panelLabel;
 QLabel* coverLabel;
 QLabel*volumeLabel;
demo::demo(QWidget *parent) : QWidget(parent),beats("")
{QPixmap cover(":/images/images/bgcover.PNG");
    coverLabel = new QLabel(parentWidget());
    coverLabel->setPixmap(cover);
    coverLabel->setGeometry(100, -50, 800, 300);
    coverLabel->show();
    QPixmap panel(":/images/images/panel.png");
        panelLabel = new QLabel(parentWidget());
        panelLabel->setPixmap(panel);
        panelLabel->setGeometry(0, 149, 800, 179);
        panelLabel->show();

v=50;
        QPixmap hit_don_left_pic(":/images/images/hit_don_left.png");
        hit_don_left_label = new QLabel(parentWidget());
        hit_don_left_label->setPixmap(hit_don_left_pic);
        hit_don_left_label->setGeometry(0, 150, 153, 178);
        hit_don_left_label->show();
        hit_don_left_label->setVisible(false);

        QPixmap hit_don_right_pic(":/images/images/hit_don_right.png");
        hit_don_right_label = new QLabel(parentWidget());
        hit_don_right_label->setPixmap(hit_don_right_pic);
        hit_don_right_label->setGeometry(0, 150, 153, 178);
        hit_don_right_label->show();
        hit_don_right_label->setVisible(false);

        QPixmap hit_katsu_left_pic(":/images/images/hit_katsu_left.png");
        hit_katsu_left_label = new QLabel(parentWidget());
        hit_katsu_left_label->setPixmap(hit_katsu_left_pic);
        hit_katsu_left_label->setGeometry(0, 138, 153, 178);
        hit_katsu_left_label->show();
        hit_katsu_left_label->setVisible(false);

        QPixmap hit_katsu_right_pic(":/images/images/hit_katsu_right.png");
        hit_katsu_right_label = new QLabel(parentWidget());
        hit_katsu_right_label->setPixmap(hit_katsu_right_pic);
        hit_katsu_right_label->setGeometry(0, 138, 153, 178);
        hit_katsu_right_label->show();
        hit_katsu_right_label->setVisible(false);

        QPixmap dongOkPic(":/images/images/dongOk.png");
        dongOkLabel = new QLabel(parentWidget());
        dongOkLabel->setPixmap(dongOkPic);
        dongOkLabel->setGeometry(85, 120, 204, 191);
        dongOkLabel->show();
        dongOkLabel->setVisible(false);

        QPixmap katsuOkPic(":/images/images/katsuOk.png");
        katsuOkLabel = new QLabel(parentWidget());
        katsuOkLabel->setPixmap(katsuOkPic);
        katsuOkLabel->setGeometry(90, 120, 204, 191);
        katsuOkLabel->show();
        katsuOkLabel->setVisible(false);


        QPixmap dong(":/images/images/dong.png");
        for (int i = 0; i < 1000; i++)
        {
            QLabel *label = new QLabel(parentWidget());
            label->setPixmap(dong);
            label->setGeometry(i * 60, 175, 80, 80);
            label->show();
            labelTable[i] = label;
            label->setVisible(false);
        }
        retry= new QPushButton(parentWidget());
        retry->setGeometry(160,200,500,100);
        retry->setText("Retry");
        retry->setStyleSheet("* {font-size: 32px;}");
        retry->hide();
        connect(retry,SIGNAL(clicked()),this,SLOT(try_again()));

        toMain=new QPushButton(parentWidget());
        toMain->setGeometry(160,300,500,100);
        toMain->setText("Return to main menu");
        toMain->setStyleSheet("* {font-size: 32px;}");
        toMain->hide();
        connect(toMain,SIGNAL(clicked()),this,SLOT(to_main()));
        connect(toMain,SIGNAL(clicked()),parentWidget(),SLOT(showlist()));
         connect(toMain,SIGNAL(clicked()),parentWidget(),SLOT(setbg()));
        scoreLabel = new QLabel(parentWidget());
        scoreLabel->setGeometry(100, 0, 200, 200);
        scoreLabel->setText("Score: 0");
        scoreLabel->setStyleSheet("* {font-size: 32px;}");
        scoreLabel->show();

        comboLabel = new QLabel(parentWidget());
        comboLabel->setGeometry(350, 0, 200, 200);
        comboLabel->setText("Combo: 0");
        comboLabel->setStyleSheet("* {font-size: 32px;}");
        comboLabel->show();

        volumeLabel =new QLabel(parentWidget());
        volumeLabel->setGeometry(580,40,200,200);
        volumeLabel->setText("Volume: "+QString::number(v));
        volumeLabel->setStyleSheet("* {font-size: 32px;}");
        volumeLabel->show();

        maxComboLabel =new QLabel(parentWidget());
        maxComboLabel->setGeometry(100,40,200,200);
        maxComboLabel->setText("Max Combo: 0");
        maxComboLabel->setStyleSheet("* {font-size: 32px;}");
        maxComboLabel->show();

        timerLabel = new QLabel(parentWidget());
        timerLabel->setGeometry(580,0, 200, 200);
        timerLabel->setText("Timer: 30");
        timerLabel->setStyleSheet("* {font-size: 32px;}");
        timerLabel->show();

        pauseLabel = new QLabel(parentWidget());
        pauseLabel->setGeometry(100, -40, 800, 200);
        pauseLabel->setText("Pause Press P to continue");
        pauseLabel->setStyleSheet("* {font-size: 32px;}");
        pauseLabel->hide();


        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->setInterval(10);
        timer->start();
don->setMedia(QUrl("qrc:/se/com_don.mp3"));
don->setVolume(50);
katsu->setMedia(QUrl("qrc:/se/com_katsu.mp3"));
katsu->setVolume(50);
        parentWidget()->setFocus();
        this->setFocus();
        update_counter = 0;
mxcombo=0;
        current_note = 0;
        current_label = 0;
pause_state=0;
        score = 0;
        combo = 0;

}

void demo::hideDonLeft()
{
    hit_don_left_label->setVisible(false);
 }

void demo::hideDonRight()
{
    hit_don_right_label->setVisible(false);

}

void demo::hideKatsuLeft()
{
    hit_katsu_left_label->setVisible(false);

}

void demo::hideKatsuRight()
{
    hit_katsu_right_label->setVisible(false);
}

void demo::hideDongOrKatsuOk()
{
    dongOkLabel->setVisible(false);
    katsuOkLabel->setVisible(false);
}
void demo::keyPressEvent(QKeyEvent *event)
{
    if(pause_state==0){
    if ((!(event->isAutoRepeat()))&&((event->key() == Qt::Key_G) || (event->key() == Qt::Key_H)))
        {

        if(don->state()==QMediaPlayer::StoppedState)
don->play();
        else
            don->setPosition(0);

            if (event->key() == Qt::Key_G)
            {
                hit_don_left_label->setVisible(true);
                QTimer::singleShot(200, this, SLOT(hideDonLeft()));
            }
            else
            {
                hit_don_right_label->setVisible(true);
                QTimer::singleShot(200, this, SLOT(hideDonRight()));
            }

            for (int i = 0; i < 1000; i++)
            {
                QLabel *label = labelTable[i];
                if (label->isVisible())
                {
                    QRect geom = labelTable[i]->geometry();
                    if (geom.x() > 100 && geom.x() < 180 && (labelType[i] == 1))
                    {
                        label->setVisible(false);
                        dongOkLabel->setVisible(true);

                        QTimer::singleShot(200, this, SLOT(hideDongOrKatsuOk()));
                        int x = geom.x();
                        if (x > 120 && x < 160)
                        {
                            score += 100;
                        }
                        else
                        {
                            score += 70;
                        }

                        combo += 1;


                    }
                }
            }
        }
        else
        if ((!(event->isAutoRepeat()))&&((event->key() == Qt::Key_F) || (event->key() == Qt::Key_J)))
        {

            if(katsu->state()==QMediaPlayer::StoppedState)
    katsu->play();
            else
                katsu->setPosition(0);


            if (event->key() == Qt::Key_F)
            {
                hit_katsu_left_label->setVisible(true);
                QTimer::singleShot(200, this, SLOT(hideKatsuLeft()));
            }
            else
            {
                hit_katsu_right_label->setVisible(true);
                QTimer::singleShot(100, this, SLOT(hideKatsuRight()));
            }
            for (int i = 0; i < 1000; i++)
            {
                QLabel *label = labelTable[i];
                if (label->isVisible())
                {
                    QRect geom = labelTable[i]->geometry();
                    if (geom.x() > 100 && geom.x() < 180 && (labelType[i] == 2))
                    {
                        label->setVisible(false);
                        katsuOkLabel->setVisible(true);

                        QTimer::singleShot(100, this, SLOT(hideDongOrKatsuOk()));
                        int x = geom.x();
                        if (x > 120 && x < 160)
                        {
                            score += 100;
                        }
                        else
                        {
                            score += 70;
                        }

                        combo += 1;


                    }
                }
            }
        }

  }
        if(event->key()==Qt::Key_P)
        {
        if(pause_state==0)
        {
            pause();
        }
        else
        {
            conti();
        }
        }
        if(!(event->isAutoRepeat())&&(event->key()==Qt::Key_F1))
        {
            if(coverLabel->isVisible())
            {
                coverLabel->hide();
                volumeLabel->setText("Volume: "+QString::number(v));
            }
            else
            {
                coverLabel->show();

            }
        }
        if(!(event->isAutoRepeat())&&(event->key()==Qt::Key_F2))
        {if(v<100)
            v+=1;
            bgm->setVolume(v);
            volumeLabel->setText("Volume: "+QString::number(v));
        }
        else if(!(event->isAutoRepeat())&&(event->key()==Qt::Key_F3))
        {
            if(v>0)
            v-=1;
            bgm->setVolume(v);
            volumeLabel->setText("Volume: "+QString::number(v));
        }


}
void demo::setMap(beatmap new_map)
{
    beats=new_map;
}
void demo::update()
{
    change_baground_in_game(beats.notes[current_note].bg);
if(update_counter==delay)
{
    bgm->setVolume(v);
    bgm->play();
}
    if(update_counter==length)
    {hide_all();
coverLabel->show();
        pauseLabel->hide();
       comboLabel->hide();
        timer->stop();
retry->show();
toMain->show();
bgm->stop();
    }
    if(update_counter%100==0)
    {
        timer_count--;

    }
    if (beats.notes[current_note].start_time == update_counter)//add new label
        {
            QLabel *label = labelTable[ current_label % 1000 ];

            if (beats.notes[current_note].key == 1)
            {
                QPixmap dong(":/images/images/dong.png");
                label->setPixmap(dong);
            }
            else if (beats.notes[current_note].key == 2)
            {
                QPixmap katsu(":/images/images/katsu.png");
                label->setPixmap(katsu);
            }
            else
            {QPixmap nonote("");
                label->setPixmap(nonote);
            }
            labelType[current_label % 1000] = beats.notes[current_note].key;

            label->setGeometry(700, 175, 80, 80);
            label->setVisible(true);
            current_label += 1;
            current_note += 1;
        }

        for (int i = 0; i < 1000; i++)//delete label
        {
            QLabel *label = labelTable[i];
            if (label->isVisible())
            {
                QRect geom = labelTable[i]->geometry();
                if (geom.x() < 20)
                {
                    label->setVisible(false);



                    combo = 0;
                }
                geom.adjust(-4, 0, -4, 0);
                labelTable[i]->setGeometry(geom);
            }
        }
if(combo>mxcombo)
    mxcombo=combo;
maxComboLabel->setText("Max Combo: "+QString::number(mxcombo));
        scoreLabel->setText("Score: " + QString::number(score));
        comboLabel->setText("Combo: " + QString::number(combo));
timerLabel->setText("Timer: "+QString::number(timer_count));
        update_counter++;
    }
void demo::pause()
{bgm->pause();

    pause_state=1;
    timer->stop();
    pauseLabel->show();
    retry->show();
    toMain->show();
}
void demo::conti()
{bgm->play();
    pause_state=0;
    timer->start();
    pauseLabel->hide();
    retry->hide();
    toMain->hide();
    coverLabel->hide();
}
void demo::show_all()
{
panelLabel->show();

}
void demo::hide_all()
{
    for (int i = 0; i < 1000; i++)//delete label
    {
        QLabel *label = labelTable[i];
        if (label->isVisible())
        {
            label->setVisible(false);
            }

        }

    panelLabel->hide();
}
void demo::try_again()
{show_all();
    setFocus();
    current_label=0;
    current_note=0;
    timer_count=length/100+1;
    score=0;
    combo=0;
    update_counter=0;
    mxcombo=0;
    timer->start();
    retry->hide();
    toMain->hide();

     pauseLabel->hide();
     bgm->stop();
          pause_state=0;
          comboLabel->setText("Combo: 0");
          comboLabel->show();
     for (int i = 0; i < 1000; i++)//delete label
     {
         QLabel *label = labelTable[i];
         if (label->isVisible())
         {
             label->setVisible(false);
             }

         }
}
void demo::to_main(){
coverLabel->hide();
    comboLabel->hide();
    scoreLabel->hide();
    maxComboLabel->hide();
    retry->hide();
    toMain->hide();
    panelLabel->hide();
    timerLabel->hide();
    pauseLabel->hide();
    volumeLabel->hide();
    for (int i = 0; i < 1000; i++)//delete label
    {
        QLabel *label = labelTable[i];
        if (label->isVisible())
        {
            label->setVisible(false);
            }

        }
    delete this;

}
void demo::setlength(int t)
{
    length=t;
    timer_count=t/100+1;
}
void demo::setMusic(QMediaPlayer *music)
{
bgm=music;

}
void demo::setdelay(int d)
{
    delay=d;
}
void demo::setmname(QString name)
{
    mname=name;
}
void demo::change_baground_in_game(int i)
{  QDir temp;
    QDir dir_map;
    QString bg=dir_map.currentPath()+"/songs/"+mname+"/bg"+QString::number(i)+".jpg";
    temp.setPath(bg);
     QPalette palette;
     if(update_counter==0){
         bg=dir_map.currentPath()+"/songs/"+mname+"/bg.jpg";
     }
     if(temp.exists(bg))
    {
        QPixmap gbkgd;
        gbkgd.load(bg);
        gbkgd=gbkgd.scaled(parentWidget()->size(),Qt::IgnoreAspectRatio);

        palette.setBrush(QPalette::Background,gbkgd);

        parentWidget()->setPalette(palette);
    }

}
void demo::setname(QString name)
{
    mname=name;
}
