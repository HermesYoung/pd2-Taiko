#include<QDebug>
#include<QWidget>
#include "demo.h"
#include"mainwindow.h"
QLabel *labelTable[100];
int labelType[100];
QLabel *timerLabel;
QLabel *scoreLabel;
QLabel *comboLabel;
QLabel *pauseLabel;
QLabel *mobLabel = NULL;
 QLabel *panelLabel;
demo::demo(QWidget *parent) : QWidget(parent),beats("")
{
    QPixmap bkgd(":/images/images/background.jpg");
    bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgd);
   this->setPalette(palette);
    QPixmap panel(":/images/images/panel.png");
        panelLabel = new QLabel(this);
        panelLabel->setPixmap(panel);
        panelLabel->setGeometry(0, 149, 800, 179);
        panelLabel->show();

        QPixmap hit_don_left_pic(":/images/images/hit_don_left.png");
        hit_don_left_label = new QLabel(this);
        hit_don_left_label->setPixmap(hit_don_left_pic);
        hit_don_left_label->setGeometry(0, 150, 153, 178);
        hit_don_left_label->show();
        hit_don_left_label->setVisible(false);

        QPixmap hit_don_right_pic(":/images/images/hit_don_right.png");
        hit_don_right_label = new QLabel(this);
        hit_don_right_label->setPixmap(hit_don_right_pic);
        hit_don_right_label->setGeometry(0, 150, 153, 178);
        hit_don_right_label->show();
        hit_don_right_label->setVisible(false);

        QPixmap hit_katsu_left_pic(":/images/images/hit_katsu_left.png");
        hit_katsu_left_label = new QLabel(this);
        hit_katsu_left_label->setPixmap(hit_katsu_left_pic);
        hit_katsu_left_label->setGeometry(0, 138, 153, 178);
        hit_katsu_left_label->show();
        hit_katsu_left_label->setVisible(false);

        QPixmap hit_katsu_right_pic(":/images/images/hit_katsu_right.png");
        hit_katsu_right_label = new QLabel(this);
        hit_katsu_right_label->setPixmap(hit_katsu_right_pic);
        hit_katsu_right_label->setGeometry(0, 138, 153, 178);
        hit_katsu_right_label->show();
        hit_katsu_right_label->setVisible(false);

        QPixmap dongOkPic(":/images/images/dongOk.png");
        dongOkLabel = new QLabel(this);
        dongOkLabel->setPixmap(dongOkPic);
        dongOkLabel->setGeometry(85, 120, 204, 191);
        dongOkLabel->show();
        dongOkLabel->setVisible(false);

        QPixmap katsuOkPic(":/images/images/katsuOk.png");
        katsuOkLabel = new QLabel(this);
        katsuOkLabel->setPixmap(katsuOkPic);
        katsuOkLabel->setGeometry(90, 120, 204, 191);
        katsuOkLabel->show();
        katsuOkLabel->setVisible(false);

        QPixmap scorePic(":/images/images/~scorePic.png");
        scorePicLabel = new QLabel(this);
        scorePicLabel->setPixmap(scorePic);
        scorePicLabel->setGeometry(-100, -20, 485, 240);
        scorePicLabel->show();
        scorePicLabel->setVisible(false);

        QPixmap dong(":/images/images/dong.png");
        for (int i = 0; i < 100; i++)
        {
            QLabel *label = new QLabel(this);
            label->setPixmap(dong);
            label->setGeometry(i * 60, 175, 80, 80);
            label->show();
            labelTable[i] = label;
            label->setVisible(false);
        }
        retry= new QPushButton(this);
        retry->setGeometry(160,200,500,100);
        retry->setText("Retry");
        retry->setStyleSheet("* {font-size: 32px;}");
        retry->hide();
        connect(retry,SIGNAL(clicked()),this,SLOT(try_again()));

        toMain=new QPushButton(this);
        toMain->setGeometry(160,300,500,100);
        toMain->setText("Return to main menu");
        toMain->setStyleSheet("* {font-size: 32px;}");
        toMain->hide();
        connect(toMain,SIGNAL(clicked()),this,SLOT(to_main()));

        scoreLabel = new QLabel(this);
        scoreLabel->setGeometry(60, 0, 200, 200);
        scoreLabel->setText("Score: 0");
        scoreLabel->setStyleSheet("* {font-size: 32px;}");
        scoreLabel->show();

        comboLabel = new QLabel(this);
        comboLabel->setGeometry(360, 0, 200, 200);
        comboLabel->setText("Combo: 0");
        comboLabel->setStyleSheet("* {font-size: 32px;}");
        comboLabel->show();

        timerLabel = new QLabel(this);
        timerLabel->setGeometry(600,0, 200, 200);
        timerLabel->setText("Timer: 30");
        timerLabel->setStyleSheet("* {font-size: 32px;}");
        timerLabel->show();

        pauseLabel = new QLabel(this);
        pauseLabel->setGeometry(60, 400, 800, 200);
        pauseLabel->setText("Pause Press P to continue");
        pauseLabel->setStyleSheet("* {font-size: 32px;}");
        pauseLabel->hide();
        pressing_don = false;
        pressing_katsu = false;





        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->setInterval(20);
        timer->start();

        setFocus();
        update_counter = 0;

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
    scorePicLabel->setVisible(false);
}
void demo::keyPressEvent(QKeyEvent *event)
{
    if(pause_state==0){
    if ((event->key() == Qt::Key_G) || (event->key() == Qt::Key_H))
        {
            qDebug() << "1 " << update_counter << " 0";


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

            for (int i = 0; i < 100; i++)
            {
                QLabel *label = labelTable[i];
                if (label->isVisible())
                {
                    QRect geom = labelTable[i]->geometry();
                    if (geom.x() > 100 && geom.x() < 180 && (labelType[i] == 1))
                    {
                        label->setVisible(false);
                        dongOkLabel->setVisible(true);
                        scorePicLabel->setVisible(true);

                        QTimer::singleShot(200, this, SLOT(hideDongOrKatsuOk()));
                        int x = geom.x();
                        if (x > 120 && x < 170)
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
        if ((event->key() == Qt::Key_F) || (event->key() == Qt::Key_J))
        {
            qDebug() << "2 " << update_counter << " 0";


            if (event->key() == Qt::Key_F)
            {
                hit_katsu_left_label->setVisible(true);
                QTimer::singleShot(200, this, SLOT(hideKatsuLeft()));
            }
            else
            {
                hit_katsu_right_label->setVisible(true);
                QTimer::singleShot(200, this, SLOT(hideKatsuRight()));
            }
            for (int i = 0; i < 100; i++)
            {
                QLabel *label = labelTable[i];
                if (label->isVisible())
                {
                    QRect geom = labelTable[i]->geometry();
                    if (geom.x() > 100 && geom.x() < 180 && (labelType[i] == 2))
                    {
                        label->setVisible(false);
                        katsuOkLabel->setVisible(true);
                        scorePicLabel->setVisible(true);

                        QTimer::singleShot(200, this, SLOT(hideDongOrKatsuOk()));
                        int x = geom.x();
                        if (x > 120 && x < 170)
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
        }}
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

}
void demo::setMap(beatmap new_map)
{
    beats=new_map;
}
void demo::update()
{
    bgm->setVolume(50);
    bgm->play();


    if(update_counter==length)
    {hide_all();
        timer->stop();
retry->show();
toMain->show();
bgm->stop();
    }
    if(update_counter%50==0)
    {
        timer_count--;

    }
    if (beats.notes[current_note].start_time == update_counter)//add new label
        {
            QLabel *label = labelTable[ current_label % 100 ];

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
            labelType[current_label % 100] = beats.notes[current_note].key;

            label->setGeometry(700, 175, 80, 80);
            label->setVisible(true);
            current_label += 1;
            current_note += 1;
        }

        for (int i = 0; i < 100; i++)//delete label
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
}
void demo::show_all()
{
panelLabel->show();

}
void demo::hide_all()
{
    for (int i = 0; i < 100; i++)//delete label
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
    current_label=0;
    current_note=0;
    timer_count=length*20/1000+1;
    score=0;
    combo=0;
    update_counter=0;
    timer->start();
    retry->hide();
    toMain->hide();
     pauseLabel->hide();
     bgm->stop();
     bgm->play();
}
void demo::to_main(){
    MainWindow *a =new MainWindow(this);

    a->show();
    this->hide();
}
void demo::setlength(int t)
{
    length=t;
    timer_count=t*20/1000+1;
}
void demo::setMusic(QMediaPlayer *music)
{
bgm=music;

}
