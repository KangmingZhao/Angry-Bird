#include "mainscene.h"
#include <QApplication>
#include<QResource>
#include"config.h"
#include"start.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    start  s;
    s.show();

    return a.exec();
}
