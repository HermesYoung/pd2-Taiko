#include "beatmap.h"
using namespace std;
const int infinity = 31415926;
beatmap::beatmap(QString address): address(address)
{
    file = new QFile(address);
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        in = new QTextStream(file);

        QString line = "";

        line = in->readLine();
        sscanf(line.toLatin1(), "length: %d delay: %d", &length,&delay);
        int count = 0;
            while ( 1 )
            {
                line = in->readLine();
                if (line.isEmpty())
                    break;
                int type;
                int time;
                int bg;
                sscanf(line.toLatin1(), "%d %d %d", &type, &time, &bg);
                notes[count].key = type;
                notes[count].start_time = time;
                notes[count].bg = bg;
                count += 1;
            }
}
