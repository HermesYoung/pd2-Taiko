#ifndef BEATMAP_H
#define BEATMAP_H
#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "note.h"

class beatmap
{
public:
    beatmap(QString address);
    note notes[10000];
        int length;
        int delay;
private:
        QString address;
            QFile *file;
            QTextStream *in;
};

#endif // BEATMAP_H
