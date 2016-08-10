#include "updatescreenthread.h"
#include "qdebug.h"
#include "QLibrary"
#include "dll.h"
#include "QProcess"

static QLibrary * lib = new QLibrary(QString("LedDynamicArea.dll"));
UpdateScreenThread::UpdateScreenThread(int screen_num)
{
    mScreenNum = screen_num;
}

void UpdateScreenThread::run()
{
    int tmp;
#if 0
    if(lib->load()){
       FUN7 DeleteScreenDynamicAreaFile = (FUN7)lib->resolve("DeleteScreenDynamicAreaFile");
       if(DeleteScreenDynamicAreaFile){
           tmp = DeleteScreenDynamicAreaFile(mScreenNum, 0,0);
           qDebug()<<"THread"<<tmp;
        }
       FUN4 AddScreenDynamicAreaFile = (FUN4)lib->resolve("AddScreenDynamicAreaFile");
       if(AddScreenDynamicAreaFile)
           tmp = AddScreenDynamicAreaFile(
                       mScreenNum, // 显示屏屏号
                       0,          // 动态区域编号
                       "Test.txt", // 添加的信息文件名称,
                       0,         // 文字信息是否单行显示；0：多行显示；1：单行显示
                       "宋体",    // 字体
                       12,       // 字体大小
                       0,       // 文字信息是否粗体显示；0：正常；1：粗体显示；
                       255,    // 文字信息显示颜色
                       4,     // 动态区域信息运行显示特技，当前为静止显示，其他显示见函数声明
                       8,    // 运行速度
                       0   // /保留时间
                       );
            qDebug()<<"THread1"<<tmp;

        FUN5 SendDynamicAreaInfoCommand = (FUN5)lib->resolve("SendDynamicAreaInfoCommand");
        if(SendDynamicAreaInfoCommand){
            tmp = SendDynamicAreaInfoCommand(mScreenNum,0);
            qDebug()<<"THread2"<<tmp;
        }
    }
    lib->unload();
         QObject *parent;
         QString program = ".\communicate.exe";
         QStringList arguments;
         arguments << "-style" << "fusion";

         QProcess *myProcess = new QProcess(parent);
         myProcess->start(program, arguments);


         QProcess process;
         process.setCreateProcessArgumentsModifier([] (QProcess::CreateProcessArguments *args)
         {
             args->flags |= CREATE_NEW_CONSOLE;
             args->startupInfo->dwFlags &= ~STARTF_USESTDHANDLES;
             args->startupInfo->dwFlags |= STARTF_USEFILLATTRIBUTE;
             args->startupInfo->dwFillAttribute = BACKGROUND_BLUE | FOREGROUND_RED
                                                | FOREGROUND_INTENSITY;
         });
         process.start("C:\\Windows\\System32\\cmd.exe", QStringList() << "/k" << "title" << "The Child Process");
         #endif
   QProcess::startDetached(".\\communicate.exe",QStringList());
    //delete lib;
}
