#include "updatescreenthread.h"
#include "qdebug.h"
#include "QProcess"

UpdateScreenThread::UpdateScreenThread()
{
}

void UpdateScreenThread::run()
{

    QProcess::startDetached(".\\communicate.exe",QStringList());

}
