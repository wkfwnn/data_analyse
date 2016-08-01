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


Dll::Dll()
{}

void Dll::loadLibrary(Dll *dll)
{
 QLibrary lib("LedDynamicArea.dll");
 if (lib.load()){
     qDebug()<<"load ok";
     dll->mInitialize =(FUN1)lib.resolve("Initialize");
     dll->mUninitialize =(FUN1)lib.resolve("Uninitialize");
     dll->mAddScreen_Dynamic = (FUN2)lib.resolve("AddScreen_Dynamic");
     dll->mAddScreenDynamicArea = (FUN3)lib.resolve("AddScreenDynamicArea");
     dll->mAddScreenDynamicAreaFile = (FUN4)lib.resolve("AddScreenDynamicAreaFile");
     dll->mSendDynamicAreaInfoCommand = (FUN5)lib.resolve("SendDynamicAreaInfoCommand");
     dll->mAddScreenDynamicAreaText = (FUN6)lib.resolve("AddScreenDynamicAreaText");
     //qDebug()<<dll->mInitialize<<dll->mAddScreen_Dynamic<<dll->mAddScreenDynamicArea << dll->mAddScreenDynamicAreaFile
       //     <<dll->mSendDynamicAreaInfoCommand <<dll->mAddScreenDynamicAreaText <<dll->mUninitialize ;
 }else{
     qDebug()<<"load fail";

 }
}
#if 0
int Dll::initScreen(int screen_num,int screen_width, int screen_height,
                    string ip,int ip_port)
{
    int tmp;
/*step 1*/
    tmp = this->mInitialize();

/*step 2*/
    tmp = this->mAddScreen_Dynamic(
                CONTROLLER_BX_5E1,
                1,
                SEND_MODE_NETWORK,
                67,
                23,
                2,
                2,
                SCREEN_COMM,
                SCREEN_BAUD,
                "192.168.33.4",
                10050,
                0,
                "",
                "",
                "",
                1000,
                "",
                "",
                "E:\\wkf\\common.dat"
                );
#if 1

/*step 3*/
   tmp  = this->mAddScreenDynamicArea(
                    1, // 设置屏号 ，与第一步通讯模式中的屏号相同
                    0,                  // 动态区域编号0~4
                    RUN_MODE_CYCLE_SHOW, // 运行模式，动态区数据循环显示；
                    10,// 设置超时时间
                    1,// 节目关联标志；1：所有节目都显示该动态区域；0：在指定节目中显示该动态区域，如果动态区域要独立于节目显示，则下一个参数为空。
                    "", // 节目关联列表，用节目编号表示；节目编号间用","隔开,节目编号定义为LedshowTW ，
                        // 2013软件中"P***"中的"***"
                    Flicker, // 边框显示特技
                    0, 0, 67, 23,// 动态区域(X坐标,Y坐标,宽度,高度)
                    1, // 动态区域边框显示标志；0：纯色；1：花色；255：无边框
                    FRAME_MULI_COLOR_COUNT, // 动态区域边框类型,//
                                                // 纯色最小取值为FRAME_SINGLE_COLOR_COUNT；花色最大取值为：FRAME_MULI_COLOR_COUNT
                    255,// 边框显示颜色；选择为纯色边框类型时该参数有效；
                    1, // 边框运行特技；
                    6,// 运行速度
                    1// 移动步长
                    );
#endif

#if 0

/*step 4*/
    tmp = this->mAddScreenDynamicAreaText(
                1, // 显示屏屏号
                0,// 动态区域编号
                "nihao", // 添加的文本信息
                0,// 文字信息是否单行显示；0：多行显示；1：单行显示；
                "宋体",// 字体
                12, // 字体大小
                0, // 文字信息是否粗体显示；0：正常；1：粗体显示；
                255,// 文字信息显示颜色
                2, // 动态区域信息运行显示特技，当前为静止显示，其他显示见函数声明
                8,// 运行速度
                5// /保留时间
                );
#endif
    return tmp;

}
#endif

int Dll::initScreen()
{
    int tmp;
    //string ip = "192.168.33.40";

    //string null = "";
    //string path = "E:\\wkf\\common.dat";
/*step 1*/
    tmp = this->mInitialize();
    qDebug()<<"step 1";
#if 1
/*step 2*/
    tmp = this->mAddScreen_Dynamic(
                CONTROLLER_BX_5E1,
                1,
                SEND_MODE_NETWORK,
                80,
                40,
                2,
                2,
                SCREEN_COMM,
                SCREEN_BAUD,
                "192.45.34.23",
                9000,
                0,
                "",
                "",
                "",
                1000,
                "",
                "",
                "haha.dat"
                );
    qDebug()<<"step 2";
#endif


#if 1
/*step 3*/
   tmp  = this->mAddScreenDynamicArea(
                    1,
                    1,
                    RUN_MODE_CYCLE_SHOW,
                    10,
                    1,
                    "",
                    Flicker,
                    0, 0, 80, 40,
                    1,
                    FRAME_MULI_COLOR_COUNT,
                    255,
                    1,
                    6,
                    1
                    );
#endif
    qDebug()<<"step 3";

    tmp = this->mAddScreenDynamicAreaFile(
                1, // 显示屏屏号
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
     qDebug()<<"step 4";
     return tmp;

}

