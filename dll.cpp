#include "QLibrary"
#include "dll.h"
#include "qdebug.h"
#include "mwidget.h"
#include "QProcess"

#define CONTROLLER_BX_5E1      0x0154
#define SEND_MODE_NETWORK      2
#define SCREEN_BAUD            57600
#define Flicker                0
#define FRAME_MULI_COLOR_COUNT 47
#define RUN_MODE_CYCLE_SHOW    0
#define SCREEN_NO              1

Dll::Dll()
{}

void Dll::loadLibrary(int screen_width,int screen_height,int ip_port,QString ip,int screen_num)
{
    //QProcess::startDetached(".\\communicate_first.exe",QStringList());

}


void Dll::updateText()
{
   // QLibrary *lib = new QLibrary(QString("LedDynamicArea.dll"));
    //FUN7 DeleteScreenDynamicAreaFile = (FUN7)lib->resolve("DeleteScreenDynamicAreaFile");

}




