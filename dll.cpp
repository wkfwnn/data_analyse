#include "QLibrary"
#include "dll.h"
#include "qdebug.h"
#include "mwidget.h"

#define CONTROLLER_BX_5E1      0x154
#define SEND_MODE_NETWORK      2
#define SCREEN_COMM            "COM1"
#define SCREEN_BAUD            57600
#define Flicker                0
#define FRAME_MULI_COLOR_COUNT 47
#define RUN_MODE_CYCLE_SHOW    0
#define SCREEN_NO              1

Dll::Dll()
{}

void Dll::loadLibrary(int screen_width,int screen_height,int ip_port,QString ip,int screen_num)
{
 int tmp;

 qDebug()<< screen_width<<screen_height<<ip_port<<ip<<screen_num;

 std::string str = ip.toStdString();
 const char* p_ip = str.c_str();
 QLibrary *mLib = new QLibrary(QString("LedDynamicArea.dll"));

 if (mLib->load()){
     qDebug()<<"load ok";

     FUN1 Initialize = (FUN1)mLib->resolve("Initialize");
     if(Initialize)
         tmp = Initialize();
     qDebug() <<"tmp0" << tmp;

      FUN2 AddScreen_Dynamic = (FUN2)mLib->resolve("AddScreen_Dynamic");
      if(AddScreen_Dynamic)
          tmp = AddScreen_Dynamic(
                      CONTROLLER_BX_5E1,
                      screen_num,
                      SEND_MODE_NETWORK,
                      screen_width,
                      screen_height,
                      2,
                      2,
                      SCREEN_COMM,
                      SCREEN_BAUD,
                      p_ip,
                      ip_port,
                      0,
                      "",
                      "",
                      "",
                      1000,
                      "",
                      "",
                      "E:\\wkf\\common.dat"
                      );
      qDebug() <<"tmp1" << tmp;
     FUN3 AddScreenDynamicArea =  (FUN3)mLib->resolve("AddScreenDynamicArea");
     if(AddScreenDynamicArea)
         tmp = AddScreenDynamicArea(
                     screen_num,                  // 设置屏号 ，与第一步通讯模式中的屏号相同
                     1,                  // 动态区域编号0~4
                     RUN_MODE_CYCLE_SHOW, // 运行模式，动态区数据循环显示；
                     10,// 设置超时时间
                     1,// 节目关联标志；1：所有节目都显示该动态区域；0：在指定节目中显示该动态区域，如果动态区域要独立于节目显示，则下一个参数为空。
                     "", // 节目关联列表，用节目编号表示；节目编号间用","隔开,节目编号定义为LedshowTW ，// 2013软件中"P***"中的"***"
                     Flicker, // 边框显示特技
                     0, 0, screen_width, screen_height,// 动态区域(X坐标,Y坐标,宽度,高度)
                     1, // 动态区域边框显示标志；0：纯色；1：花色；255：无边框
                     FRAME_MULI_COLOR_COUNT, // 动态区域边框类型,//
                                                 // 纯色最小取值为FRAME_SINGLE_COLOR_COUNT；花色最大取值为：FRAME_MULI_COLOR_COUNT
                     255,// 边框显示颜色；选择为纯色边框类型时该参数有效；
                     1, // 边框运行特技；
                     6,// 运行速度
                     1// 移动步长
                     );
     qDebug() <<"tmp2" << tmp;
#if 0
    FUN4 AddScreenDynamicAreaFile = (FUN4)mLib->resolve("AddScreenDynamicAreaFile");
    if(AddScreenDynamicAreaFile)
        tmp = AddScreenDynamicAreaFile(
                    screen_num, // 显示屏屏号
                    1,// 动态区域编号
                    "Test.txt", // 添加的信息文件名称,
                    1,// 文字信息是否单行显示；0：多行显示；1：单行显示
                    "隶书",// 字体
                    12, // 字体大小
                    0, // 文字信息是否粗体显示；0：正常；1：粗体显示；
                    255,// 文字信息显示颜色
                    4, // 动态区域信息运行显示特技，当前为静止显示，其他显示见函数声明
                    8,// 运行速度
                    0// /保留时间
                    );
#endif

    FUN6 AddScreenDynamicAreaText = (FUN6)mLib->resolve("AddScreenDynamicAreaText");
    if(AddScreenDynamicAreaText){
       tmp = AddScreenDynamicAreaText(
                   screen_num,
                   1,// 动态区域编号
                   "Test", // 添加的文本信息
                   0,// 文字信息是否单行显示；0：多行显示；1：单行显示；
                   "宋体",// 字体
                   12, // 字体大小
                   0, // 文字信息是否粗体显示；0：正常；1：粗体显示；
                   255,// 文字信息显示颜色
                   2, // 动态区域信息运行显示特技，当前为静止显示，其他显示见函数声明
                   8,// 运行速度
                   5// /保留时间
                   );
    }


    qDebug() <<"tmp3" << tmp;

    //FUN5 mSendDynamicAreaInfoCommand = (FUN5)mLib->resolve("SendDynamicAreaInfoCommand");
#if 0
     FUN1 mUninitialize = (FUN1)mLib.resolve("Uninitialize");;
     FUN2 mAddScreen_Dynamic;
     FUN3 mAddScreenDynamicArea;
     FUN4 mAddScreenDynamicAreaFile;
     FUN5 mSendDynamicAreaInfoCommand;
     FUN6 mAddScreenDynamicAreaText;

     dll->mInitialize =(FUN1)mLib.resolve("Initialize");
     dll->mUninitialize =(FUN1)mLib.resolve("Uninitialize");
     dll->mAddScreen_Dynamic = (FUN2)mLib.resolve("AddScreen_Dynamic");
     dll->mAddScreenDynamicArea = (FUN3)mLib.resolve("AddScreenDynamicArea");
     dll->mAddScreenDynamicAreaFile = (FUN4)mLib.resolve("AddScreenDynamicAreaFile");

     dll->mAddScreenDynamicAreaText = (FUN6)mLib.resolve("AddScreenDynamicAreaText");
     mLib->unload()
     delete mLib;
#endif
 }else{
     qDebug()<<"load fail";

 }
}

void Dll::updateText()
{
   // QLibrary *lib = new QLibrary(QString("LedDynamicArea.dll"));
    //FUN7 DeleteScreenDynamicAreaFile = (FUN7)lib->resolve("DeleteScreenDynamicAreaFile");

}




