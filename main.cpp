#include "mainwindow.h"
#include "hldemo.h"

#include <stdio.h>
#include <string>

#include <QApplication>

using namespace HLDemo;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
    DemoInfo info;
    DemoInfoReturnCode c = getDemoInfo("/home/rasmus/.local/share/Steam/steamapps/common/Team Fortress 2/tf/autodemos/2020-04-13_21-28-23.dem", info);
    printf("Return code: %d\n", c);
    printf("Map name: %s\n", info.mapName.c_str());
    printf("Client name: %s\n", info.clientName.c_str());
    printf("Server name: %s\n", info.serverName.c_str());
    printf("File path: %s\n", info.fileName.c_str());
    printf("Playback time: %f\n", info.playbackTime);
    printf("#Ticks: %d\n", info.numTicks);
    return 0;
}
