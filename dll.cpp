#include "QLibrary"
#include "dll.h"
#include "qdebug.h"

#define CONTROLLER_BX_5E1 0x0154


void Dll::loadLibrary(Dll *dll)
{
 QLibrary lib("LedDynamicArea.dll");
 if (lib.load()){
     dll->mInitialize =(FUN1)lib.resolve("Initialize");
     dll->mUninitialize =(FUN1)lib.resolve("Uninitialize");
     qDebug()<<"load ok";
     qDebug()<<mInitialize();
     dll->mAddScreen_Dynamic = (FUN2)lib.resolve("AddScreen_Dynamic");
     dll->mAddScreenDynamicArea = (FUN3)lib.resolve("AddScreenDynamicArea");
     dll->mAddScreenDynamicAreaFile = (FUN4)lib.resolve("AddScreenDynamicAreaFile");
     dll->mSendDynamicAreaInfoCommand = (FUN5)lib.resolve("SendDynamicAreaInfoCommand");

     //dll->mAddScreen_Dynamic();

 }
}

int Dll::initScreen(QHash<QString,QString>)
{

}
#if 0
AddScreen_Dynamic(
                        CONTROLLER_BX_5E3,// 控制卡型号支持BX_5E系列和BX_5Q系列
                        SCREEN_NO,// 屏号
                        SEND_MODE_NETWORK, // 通讯模式，当前为网络通讯
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT, // 设置屏幕宽高
                        2,// 这里的2表示选择使用双基色(当为1时表示单基色、为4时表示全彩)
                        2,// 点阵类型(1表示(G+R),2表示(R+G))
                        SCREEN_COMM,// 端口号,根据自己当前的端口号设置
                        SCREEN_BAUD, // 波特率(有57600和9600)
                        SCREEN_SOCKETIP, // 网络通讯下的IP
                        SCREEN_SOCKETPORT,// 网络通讯下的端口号
                        0, // 0为固定IP模式，1为服务器模式
                        "",//设备条形码，用于服务器模式和中转服务器
                        "",// 网络ID，在此模式下为空，若上一参数为1，表示服务器模式，则该参数不能为空 。
                        "", // 服务器IP，在此模式下为空，
                        1000, // 服务器端口
                        "",
                        "",// 用户和密码，在此模式下默认为空，在ONBON服务器-3G、ONBON服务器-GPRS模式下，不能为空
                        "D:\\work\\b0110\\trunk\\code\\LedDynamicArea\\LedDynamicAreaJAVA\\bin\\com\\java\\demoDebugcurCommandData.dat"// 文件保存
                );
#endif



