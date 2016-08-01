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

static int SCREEN_WIDTH = 80;
static int SCREEN_HEIGHT = 32;
static char* SCREEN_SOCKETIP = "192.168.0.15";
static int SCREEN_SOCKETPORT = 5005;

Dll::Dll()
{}

void Dll::loadLibrary(Dll *dll)
{
    int tmp;
 QLibrary *lib = new QLibrary(QString("LedDynamicArea.dll"));

 if (lib->load()){
     qDebug()<<"load ok";

     volatile FUN1 Initialize = (FUN1)lib->resolve("Initialize");
     if(Initialize)
         tmp = Initialize();
     qDebug() <<"tmp0" << tmp;

      volatile FUN2 AddScreen_Dynamic = (FUN2)lib->resolve("AddScreen_Dynamic");
      if(AddScreen_Dynamic)
          tmp = AddScreen_Dynamic(
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
      qDebug() <<"tmp1" << tmp;
     volatile FUN3 AddScreenDynamicArea =  (FUN3)lib->resolve("AddScreenDynamicArea");
     if(AddScreenDynamicArea)
         tmp = AddScreenDynamicArea(
                     1,                  // 设置屏号 ，与第一步通讯模式中的屏号相同
                     1,                  // 动态区域编号0~4
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
     qDebug() <<"tmp2" << tmp;
    volatile FUN4 AddScreenDynamicAreaFile = (FUN4)lib->resolve("AddScreenDynamicAreaFile");
    if(AddScreenDynamicAreaFile)
        tmp = AddScreenDynamicAreaFile(
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
    qDebug() <<"tmp3" << tmp;
#if 0
     FUN1 mUninitialize = (FUN1)lib.resolve("Uninitialize");;
     FUN2 mAddScreen_Dynamic;
     FUN3 mAddScreenDynamicArea;
     FUN4 mAddScreenDynamicAreaFile;
     FUN5 mSendDynamicAreaInfoCommand;
     FUN6 mAddScreenDynamicAreaText;

     dll->mInitialize =(FUN1)lib.resolve("Initialize");
     dll->mUninitialize =(FUN1)lib.resolve("Uninitialize");
     dll->mAddScreen_Dynamic = (FUN2)lib.resolve("AddScreen_Dynamic");
     dll->mAddScreenDynamicArea = (FUN3)lib.resolve("AddScreenDynamicArea");
     dll->mAddScreenDynamicAreaFile = (FUN4)lib.resolve("AddScreenDynamicAreaFile");
     dll->mSendDynamicAreaInfoCommand = (FUN5)lib.resolve("SendDynamicAreaInfoCommand");
     dll->mAddScreenDynamicAreaText = (FUN6)lib.resolve("AddScreenDynamicAreaText");
#endif
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
#if 0
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
#endif

int Dll::initScreen()
{
#if 0
    int nResult;
    this->mInitialize();
    nResult = this->
                mAddScreen_Dynamic(
                        CONTROLLER_BX_5E1,// 控制卡型号支持BX_5E系列和BX_5Q系列
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
    qDebug()<<"cao";
        /*-------------------------------------------------------------------------------
        // ONBON服务器-GPRS模式下
        nResult = lda
                .AddScreen_Dynamic(
                        CONTROLLER_BX_5E3,// 控制卡型号支持BX_5E系列和BX_5Q系列
                        SCREEN_NO,// 屏号
                        SEND_MODE_Server_2G, // 通讯模式，当前为SEND_MODE_Server_2G
                        SCREEN_WIDTH,SCREEN_HEIGHT, // 设置屏幕宽高
                        2,// 这里的2表示选择使用双基色(当为1时表示单基色、为4时表示全彩)
                        2,// 点阵类型(1表示(G+R),2表示(R+G))
                        SCREEN_COMM,// 端口号,根据自己当前的端口号设置
                        SCREEN_BAUD, // 波特率(有57600和9600)
                        "", // 网络通讯下的IP
                        5005,// 网络通讯下的端口号
                        0, // 0为固定IP模式，1为服务器模式
                        "",// 网络ID，在此模式下为空，若上一参数为1，表示服务器模式，则该参数不能为空 。
                        "192.168.1.1", //和服务器IP
                        1000, // 服务器端口
                        "admin","admin",//在ONBON服务器-3G、ONBON服务器-GPRS模式下，不能为空
                        "D:\\work\\b0110\\trunk\\code\\LedDynamicArea\\C#_Demo\\C_Sharp_Demo\\bin\\DebugcurCommandData.dat"// 文件保存
                );

                //在此模式下删除显示屏，调用函数
                 public int DeleteScreen_Dynamic(int nScreenNo);//参数为屏号
                //查询服务器设备列表，调用函数
                  QuerryServerDeviceList(int nScreenNo, byte[] pDeviceList,
                int nDeviceCount);//参数1、2、3分别为 屏号、列表、数量 ；其中(int nDeviceCount = 0;byte[] nDeviceList = new byte[100];)
                //绑定无线设备 ,调用函数
                 BindServerDevice(int nScreenNo, String pBarcode,
                String pNetworkId);//其中String pBarcode = "";String pNetworkID = "BX-NET000001";

         -------------------------------------------------------------------------------*/
        //GetErrorMessage("执行AddScreen函数,", nResult);

        // 第三步 添加动态区域

        nResult = this->mAddScreenDynamicArea(SCREEN_NO, // 设置屏号 ，与第一步通讯模式中的屏号相同
                0,// 动态区域编号0~4
                RUN_MODE_CYCLE_SHOW, // 运行模式，动态区数据循环显示；
                10,// 设置超时时间
                1,// 节目关联标志；1：所有节目都显示该动态区域；0：在指定节目中显示该动态区域，如果动态区域要独立于节目显示，则下一个参数为空。
                "", // 节目关联列表，用节目编号表示；节目编号间用","隔开,节目编号定义为LedshowTW ，
                    // 2013软件中"P***"中的"***"
                Flicker, // 边框显示特技
                0, 0, 80, 32,// 动态区域(X坐标,Y坐标,宽度,高度)
                1, // 动态区域边框显示标志；0：纯色；1：花色；255：无边框
                FRAME_MULI_COLOR_COUNT, // 动态区域边框类型,//
                                            // 纯色最小取值为FRAME_SINGLE_COLOR_COUNT；花色最大取值为：FRAME_MULI_COLOR_COUNT
                255,// 边框显示颜色；选择为纯色边框类型时该参数有效；
                1, // 边框运行特技；
                6,// 运行速度
                1// 移动步长
                );
       // GetErrorMessage("执行AddScreenDynamicArea函数,", nResult);
        qDebug()<<"cao1";
        // 第四步 动态区域文件属性

        // 添加文件

            nResult = this->mAddScreenDynamicAreaFile(SCREEN_NO, // 显示屏屏号
                0,// 动态区域编号
                "Test.txt", // 添加的信息文件名称,
                1,// 文字信息是否单行显示；0：多行显示；1：单行显示；F
                "隶书",// 字体
                12, // 字体大小
                0, // 文字信息是否粗体显示；0：正常；1：粗体显示；
                255,// 文字信息显示颜色
                4, // 动态区域信息运行显示特技，当前为静止显示，其他显示见函数声明
                8,// 运行速度
                0// /保留时间
                );

            qDebug()<<"cao2";
            //GetErrorMessage("执行AddScreenDynamicAreaFile函数, ", nResult);
        /*
         *
            //添加文本信息
            nResult = lda.AddScreenDynamicAreaText(SCREEN_NO, // 显示屏屏号
                0,// 动态区域编号
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
                GetErrorMessage("执行AddScreenDynamicAreaText函数, ", nResult);
        */

        // 删除文件
        // nResult = lda.DeleteScreenDynamicAreaFile(SCREEN_NO, 0
        // , 0//动态区域的指定文件的文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
        // );
        // GetErrorMessage("执行DeleteScreenDynamicAreaFile函数, ", nResult);
#endif
}


