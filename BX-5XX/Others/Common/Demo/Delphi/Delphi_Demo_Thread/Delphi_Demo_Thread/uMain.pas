unit uMain;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ScktComp, Spin, Registry, Buttons, ExtCtrls,
  uSendThread, TntStdCtrls, Check_Transit_DevList, IdStrings, RzPrgres,
  TntExtCtrls;

const
  nKardPixType      = 16;
  WM_SHOW_RESULT_MSG = WM_USER + 1;
//==============================================================================
// 用户发送信息命令表
  SEND_CMD_PARAMETER = $A1FF; //加载屏参数。
  SEND_CMD_SCREENSCAN = $A1FE; //设置扫描方式。
  SEND_CMD_SENDALLPROGRAM = $A1F0; //发送所有节目信息。
  SEND_CMD_POWERON  = $A2FF; //强制开机
  SEND_CMD_POWEROFF = $A2FE; //强制关机
  SEND_CMD_TIMERPOWERONOFF = $A2FD; //定时开关机
  SEND_CMD_CANCEL_TIMERPOWERONOFF = $A2FC; //取消定时开关机
  SEND_CMD_RESIVETIME = $A2FB; //校正时间。
  SEND_CMD_ADJUSTLIGHT = $A2FA; //亮度调整。


//==============================================================================
//==============================================================================
// 控制器通讯模式
  SEND_MODE_COMM    = 0;
  SEND_MODE_GPRS    = 1;
  SEND_MODE_NET     = 2;
  SEND_MODE_WIFI    = 4;
  SEND_MODE_Server_2G = 5;
  SEND_MODE_Server_3G = 6;
  SEND_MODE_RF      = 7;
//==============================================================================
//==============================================================================
// 通讯错误返回代码值
  RETURN_ERROR_NOSUPPORT_USB = $F6; //不支持USB模式；
  RETURN_ERROR_NO_USB_DISK = $F5; //找不到usb设备路径；
  RETURN_ERROR_AERETYPE = $F7; //区域类型错误，在添加图文区域文件时区域类型出错返回此类型错误。
  RETURN_ERROR_RA_SCREENNO = $F8; //已经有该显示屏信息。如要重新设定请先DeleteScreen删除该显示屏再添加；
  RETURN_ERROR_NOFIND_AREAFILE = $F9; //没有找到有效的区域文件(图文区域)；
  RETURN_ERROR_NOFIND_AREA = $FA; //没有找到有效的显示区域；可以使用AddScreenProgramBmpTextArea添加区域信息。
  RETURN_ERROR_NOFIND_PROGRAM = $FB; //没有找到有效的显示屏节目；可以使用AddScreenProgram函数添加指定节目
  RETURN_ERROR_NOFIND_SCREENNO = $FC; //系统内没有查找到该显示屏；可以使用AddScreen函数添加显示屏
  RETURN_ERROR_NOW_SENDING = $FD; //系统内正在向该显示屏通讯，请稍后再通讯；
  RETURN_ERROR_OTHER = $FF; //其它错误；
  RETURN_NOERROR    = 0; //没有错误

//==============================================================================

  Screen_Control    : array[0..57] of widestring =
    ('AX-UL'
    , 'AX-UT'
    , 'AX-U0'
    , 'AX-U1'
    , 'AX-U2'
    , 'AX-MT'
    , 'AX-M1'
    , 'AX-M2'
    , 'AX-M3'
    , 'AX-M4'
    , 'AX-AT'
    , 'AX-A0'


    , 'BX-5UL'
    , 'BX-5UT'
    , 'BX-5U0'
    , 'BX-5U1'
    , 'BX-5U2'
    , 'BX-5U3'
    , 'BX-5U4'
    , 'BX-5U5'
    , 'BX-5U'

    , 'BX-5MT'
    , 'BX-5M1'
    , 'BX-5M1X'
    , 'BX-5M2'
    , 'BX-5M3'
    , 'BX-5M4'

    , 'BX-5E1'
    , 'BX-5E2'
    , 'BX-5E3'

    , 'BX-5AL'
    , 'BX-5AT'
    , 'BX-5AT_WIFI'
    , 'BX-5A0'
    , 'BX-5A0_WIFI'
    , 'BX-5A1'
    , 'BX-5A1_WIFI'
    , 'BX-5A'
    , 'BX-5A2'
    , 'BX-5A2_RF'
    , 'BX-5A2_WIFI'
    , 'BX-5A3'
    , 'BX-5A4'
    , 'BX-5A4_WIFI'
    , 'BX-5A4_RF'


    , 'BX-5Q0'
    , 'BX-5Q1'
    , 'BX-5Q2'
    , 'BX-5Q0+'
    , 'BX-5Q1+'
    , 'BX-5Q2+'
    , 'BX-5QL'


    , 'BX-5QS1'
    , 'BX-5QS2'
    , 'BX-5QS'
    , 'BX-5QS1+'
    , 'BX-5QS2+'
    , 'BX-5QS+'
    );
//------------------------------------------------------------------------------
// 控制器类型列表序号
  Controller_AX_UL_Index = 0;
  Controller_AX_UT_Index = 1;
  Controller_AX_U0_Index = 2;
  Controller_AX_U1_Index = 3;
  Controller_AX_U2_Index = 4;
  Controller_AX_MT_Index = 5;
  Controller_AX_M1_Index = 6;
  Controller_AX_M2_Index = 7;
  Controller_AX_M3_Index = 8;
  Controller_AX_M4_Index = 9;
  Controller_AX_AT_Index = 10;
  Controller_AX_A0_Index = 11;

  Controller_BX_5UL_Index = 12;
  Controller_BX_5UT_Index = 13;
  Controller_BX_5U0_Index = 14;
  Controller_BX_5U1_Index = 15;
  Controller_BX_5U2_Index = 16;
  Controller_BX_5U3_Index = 17;
  Controller_BX_5U4_Index = 18;
  Controller_BX_5U5_Index = 19;
  Controller_BX_5U_Index = 20;

  Controller_BX_5MT_Index = 21;
  Controller_BX_5M1_Index = 22;
  Controller_BX_5M1X_Index = 23;
  Controller_BX_5M2_Index = 24;
  Controller_BX_5M3_Index = 25;
  Controller_BX_5M4_Index = 26;

  Controller_BX_5E1_Index = 27;
  Controller_BX_5E2_Index = 28;
  Controller_BX_5E3_Index = 29;

  Controller_BX_5AL_Index = 30;
  Controller_BX_5AT_Index = 31;
  Controller_BX_5AT_WIFI_Index = 32;
  Controller_BX_5A0_Index = 33;
  Controller_BX_5A0_WIFI_Index = 34;
  Controller_BX_5A1_Index = 35;
  Controller_BX_5A1_WIFI_Index = 36;
  Controller_BX_5A_Index = 37;
  Controller_BX_5A2_Index = 38;
  Controller_BX_5A2_RF_Index = 39;
  Controller_BX_5A2_WIFI_Index = 40;
  Controller_BX_5A3_Index = 41;
  Controller_BX_5A4_Index = 42;
  Controller_BX_5A4_RF_Index = 43;
  Controller_BX_5A4_WIFI_Index = 44;


  Controller_BX_5Q0_Index = 45;
  Controller_BX_5Q1_Index = 46;
  Controller_BX_5Q2_Index = 47;
  Controller_BX_5Q0P_Index = 48;
  Controller_BX_5Q1P_Index = 49;
  Controller_BX_5Q2P_Index = 50;
  Controller_BX_5QL_Index = 51;


  Controller_BX_5QS1_Index = 52;
  Controller_BX_5QS2_Index = 53;
  Controller_BX_5QS_Index = 54;
  Controller_BX_5QS1P_Index = 55;
  Controller_BX_5QS2P_Index = 56;
  Controller_BX_5QSP_Index = 57;


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// 控制器类型
  Controller_AX_UL  = $2055;
  Controller_AX_UT  = $2155;
  Controller_AX_U0  = $2255;
  Controller_AX_U1  = $2355;
  Controller_AX_U2  = $2455;
  Controller_AX_MT  = $2052;
  Controller_AX_M1  = $2152;
  Controller_AX_M2  = $2252;
  Controller_AX_M3  = $2352;
  Controller_AX_M4  = $2452;
  Controller_AX_AT  = $2051;
  Controller_AX_A0  = $2151;

  Controller_BX_5UL = $0855;
  Controller_BX_5UT = $0055;
  Controller_BX_5U0 = $0155;
  Controller_BX_5U1 = $0255;
  Controller_BX_5U2 = $0355;
  Controller_BX_5U3 = $0455;
  Controller_BX_5U4 = $0555;
  Controller_BX_5U5 = $0655;
  Controller_BX_5U  = $0755;

  Controller_BX_5MT = $0552;
  Controller_BX_5M1 = $0052;
  Controller_BX_5M1X = $0152;
  Controller_BX_5M2 = $0252;
  Controller_BX_5M3 = $0352;
  Controller_BX_5M4 = $0452;

  Controller_BX_5E1 = $0154;
  Controller_BX_5E2 = $0254;
  Controller_BX_5E3 = $0354;

  Controller_BX_5AL = $1851;
  Controller_BX_5AT = $0051;
  Controller_BX_5AT_WIFI = $1651;
  Controller_BX_5A0 = $0151;
  Controller_BX_5A0_WIFI = $2251;
  Controller_BX_5A1 = $0251;
  Controller_BX_5A1_WIFI = $0651;
  Controller_BX_5A  = $0951;
  Controller_BX_5A2 = $0351;
  Controller_BX_5A2_RF = $1351;
  Controller_BX_5A2_WIFI = $0751;
  Controller_BX_5A3 = $0451;
  Controller_BX_5A4 = $0551;
  Controller_BX_5A4_RF = $1551;
  Controller_BX_5A4_WIFI = $0851;

  Controller_BX_5Q0 = $0056;
  Controller_BX_5Q1 = $0156;
  Controller_BX_5Q2 = $0256;
  Controller_BX_5Q0P = $1056;
  Controller_BX_5Q1P = $1156;
  Controller_BX_5Q2P = $1256;
  Controller_BX_5QL = $1356;

  Controller_BX_5QS1 = $0157;
  Controller_BX_5QS2 = $0257;
  Controller_BX_5QS = $0357;
  Controller_BX_5QS1P = $1157;
  Controller_BX_5QS2P = $1257;
  Controller_BX_5QSP = $1357;


//------------------------------------------------------------------------------
type
  tagSendStatus = packed record //发送节目
    szMessagestr: string; //发送状态显示字符串
  end;
  PtagSendStatus = ^tagSendStatus;

type
  TFrm_Main = class(TForm)
    dlgOpen1: TOpenDialog;
    pnl1: TPanel;
    grpScreen: TGroupBox;
    Label8: TLabel;
    Label13: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label15: TLabel;
    comb_SendMode: TComboBox;
    grpComm: TGroupBox;
    Label3: TLabel;
    Label4: TLabel;
    comb_COMM: TComboBox;
    comb_Baud: TComboBox;
    grpNet: TGroupBox;
    spnedt_ScreenNo: TSpinEdit;
    spnedt_Width: TSpinEdit;
    spnedt_Height: TSpinEdit;
    comb_ScreenType: TComboBox;
    Button1: TButton;
    Button8: TButton;
    btn5: TButton;
    comb_ControlType: TComboBox;
    grpProgram: TGroupBox;
    lbl3: TLabel;
    tmr_SendProgram: TTimer;
    grpServer: TGroupBox;
    Label17: TLabel;
    edtServerIP: TEdit;
    Label18: TLabel;
    edtServerPort: TSpinEdit;
    Label19: TLabel;
    edtUserName: TEdit;
    Label20: TLabel;
    edtPassword: TEdit;
    pnl2: TPanel;
    mmo1: TMemo;
    pnl3: TPanel;
    tntpnl_Progross: TTntPanel;
    rzpbSendProgress: TRzProgressBar;
    lblMessage: TLabel;
    rdbFixIPMode: TRadioButton;
    rdbServerMode: TRadioButton;
    Label9: TLabel;
    edt_IP: TEdit;
    Label10: TLabel;
    spnedt_Port: TSpinEdit;
    edtNetworkID: TEdit;
    lblNetworkID: TLabel;
    grpGPRS: TGroupBox;
    Label21: TLabel;
    Label22: TLabel;
    edt_GprsIP: TEdit;
    edt_GprsPort: TSpinEdit;
    TntLabel44: TTntLabel;
    edt_GprsID: TEdit;
    grpInitialize: TGroupBox;
    btnInitialize: TButton;
    PageControl3: TPageControl;
    TabSheet5: TTabSheet;
    btn4: TButton;
    btn10: TButton;
    btn_USB: TButton;
    btn_Stop: TButton;
    btn_1: TButton;
    btn1: TButton;
    TabSheet6: TTabSheet;
    GroupBox4: TGroupBox;
    Button5: TButton;
    Button6: TButton;
    grp3: TGroupBox;
    btn8: TButton;
    btn9: TButton;
    grp4: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Button2: TButton;
    TrackBar1: TTrackBar;
    grp5: TGroupBox;
    Button7: TButton;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    btn2: TButton;
    PageControl2: TPageControl;
    TabSheet3: TTabSheet;
    Label16: TLabel;
    btn6: TSpeedButton;
    edt_FileName: TEdit;
    btn3: TButton;
    TabSheet4: TTabSheet;
    mmo_Text: TMemo;
    Button17: TButton;
    TabSheet2: TTabSheet;
    tabsht_Temperature: TTabSheet;
    btn_Temperature: TButton;
    tabsht_Humidity: TTabSheet;
    btn_Humidity: TButton;
    tabsht_Noise: TTabSheet;
    btn_Noise: TButton;
    GroupBox2: TGroupBox;
    Label11: TLabel;
    spnedt_curAreaOrd: TSpinEdit;
    Button3: TButton;
    GroupBox3: TGroupBox;
    Label14: TLabel;
    spnedt_curlFileOrd: TSpinEdit;
    Button4: TButton;
    GroupBox7: TGroupBox;
    lbl1: TLabel;
    spnedt_curProgramOrd: TSpinEdit;
    btn7: TButton;
    GroupBox8: TGroupBox;
    Button20: TButton;
    Button21: TButton;
    GroupBox9: TGroupBox;
    GroupBox10: TGroupBox;
    GroupBox11: TGroupBox;
    GroupBox12: TGroupBox;
    Button9: TButton;
    Button10: TButton;
    Button11: TButton;
    Button12: TButton;
    Button13: TButton;
    Button14: TButton;
    Button15: TButton;
    Button16: TButton;
    grpUninitialize: TGroupBox;
    btnUninitialize: TButton;
    btnBindWirelessDevice: TButton;
    lblTransitBarcode: TLabel;
    lblTransitNetworkId: TLabel;
    edtTransitBarcode: TEdit;
    edtTransitNetworkId: TEdit;
    btnStartServer: TButton;
    btnStopServer: TButton;
    btnStartGprs: TButton;
    btnCloseGprs: TButton;
    grpWifi: TGroupBox;
    Label12: TLabel;
    Label23: TLabel;
    lblWifiNetworkID: TLabel;
    rdbWifiFixIPMode: TRadioButton;
    rdbWifiServerMode: TRadioButton;
    edtWifiIP: TEdit;
    spnedtWifiPort: TSpinEdit;
    edtWifiNetworkID: TEdit;
    btnStartWifiServer: TButton;
    btnStopWifiServer: TButton;
    Button18: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure btn1Click(Sender: TObject);
    procedure btn2Click(Sender: TObject);
    procedure btn3Click(Sender: TObject);
    procedure btn5Click(Sender: TObject);
    procedure btn6Click(Sender: TObject);
    procedure btn4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure mmo1DblClick(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure btn7Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure btn8Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure btn9Click(Sender: TObject);
    procedure comb_SendModeChange(Sender: TObject);
    procedure comb_ControlTypeChange(Sender: TObject);
    procedure btn_USBClick(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure Button11Click(Sender: TObject);
    procedure Button13Click(Sender: TObject);
    procedure Button10Click(Sender: TObject);
    procedure Button12Click(Sender: TObject);
    procedure Button14Click(Sender: TObject);
    procedure Button15Click(Sender: TObject);
    procedure Button16Click(Sender: TObject);
    procedure btn10Click(Sender: TObject);
    procedure btn_StopClick(Sender: TObject);
    procedure tmr_SendProgramTimer(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btn_1Click(Sender: TObject);
    procedure btn_TemperatureClick(Sender: TObject);
    procedure btn_HumidityClick(Sender: TObject);
    procedure btn_NoiseClick(Sender: TObject);
    procedure btnBindWirelessDeviceClick(Sender: TObject);
    procedure rdbFixIPModeClick(Sender: TObject);
    procedure Button17Click(Sender: TObject);
    procedure btnInitializeClick(Sender: TObject);
    procedure btnUninitializeClick(Sender: TObject);
    procedure btnStartServerClick(Sender: TObject);
    procedure btnStopServerClick(Sender: TObject);
    procedure rdbWifiFixIPModeClick(Sender: TObject);
    procedure btnStartWifiServerClick(Sender: TObject);
    procedure btnStopWifiServerClick(Sender: TObject);
    procedure Button18Click(Sender: TObject);

  private
    { Private declarations }
    FileStream: Tfilestream;
  protected
    function GetScreenControlTypeValue(nControlTypeIndex: Cardinal): Cardinal; //根据控制器列表序号得到控制器类型值。
    procedure GetShowResultMsg(var Message: TMessage); message WM_SHOW_RESULT_MSG;
  public
    { Public declarations }
    function GetErrorMessage(nResult: Cardinal): string;
  end;

var
  Frm_Main          : TFrm_Main;
  hDll              : THandle;
  g_nSendMode       : Cardinal;
  SendThread        : TSendThread;
  m_bSendBusy       : Boolean; //此变量在数据更新中非常重要，请务必保留。
  CS                : TRTLCriticalSection;

{-------------------------------------------------------------------------------
  过程名:    Initialize
  初始化动态库；该函数不与显示屏通讯。
  参数:
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  Initialize         :function(): integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    Uninitialize
  释放动态库；该函数不与显示屏通讯。
  参数:
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  Uninitialize         :function(): integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreen
  向动态库中添加显示屏信息；该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
  参数:
    nControlType    :显示屏的控制器型号；详见宏定义“控制器型号定义”
        Controller_AX_UL  = $2055;
        Controller_AX_UT  = $2155;
        Controller_AX_U0  = $2255;
        Controller_AX_U1  = $2355;
        Controller_AX_U2  = $2455;
        Controller_AX_MT  = $2052;
        Controller_AX_M1  = $2152;
        Controller_AX_M2  = $2252;
        Controller_AX_M3  = $2352;
        Controller_AX_M4  = $2452;
        Controller_AX_AT  = $2051;
        Controller_AX_A0  = $2151;

        Controller_BX_5UL = $0855;
        Controller_BX_5UT = $0055;
        Controller_BX_5U0 = $0155;
        Controller_BX_5U1 = $0255;
        Controller_BX_5U2 = $0355;
        Controller_BX_5U3 = $0455;
        Controller_BX_5U4 = $0555;
        Controller_BX_5U5 = $0655;
        Controller_BX_5U  = $0755;

        Controller_BX_5MT = $0552;
        Controller_BX_5M1 = $0052;
        Controller_BX_5M1X = $0152;
        Controller_BX_5M2 = $0252;
        Controller_BX_5M3 = $0352;
        Controller_BX_5M4 = $0452;

        Controller_BX_5E1 = $0154;
        Controller_BX_5E2 = $0254;
        Controller_BX_5E3 = $0354;

        Controller_BX_5AL = $1851;
        Controller_BX_5AT = $0051;
        Controller_BX_5AT_WIFI = $1651;
        Controller_BX_5A0 = $0151;
        Controller_BX_5A0_WIFI = $2251;
        Controller_BX_5A1 = $0251;
        Controller_BX_5A1_WIFI = $0651;
        Controller_BX_5A  = $0951;
        Controller_BX_5A2 = $0351;
        Controller_BX_5A2_RF = $1351;
        Controller_BX_5A2_WIFI = $0751;
        Controller_BX_5A3 = $0451;
        Controller_BX_5A4 = $0551;
        Controller_BX_5A4_RF = $1551;
        Controller_BX_5A4_WIFI = $0851;

        Controller_BX_5Q0 = $0056;
        Controller_BX_5Q1 = $0156;
        Controller_BX_5Q2 = $0256;
        Controller_BX_5Q0P = $1056;
        Controller_BX_5Q1P = $1156;
        Controller_BX_5Q2P = $1256;
        Controller_BX_5QL = $1356;

        Controller_BX_5QS1 = $0157;
        Controller_BX_5QS2 = $0257;
        Controller_BX_5QS = $0357;
        Controller_BX_5QS1P = $1157;
        Controller_BX_5QS2P = $1257;
        Controller_BX_5QSP = $1357;

    nScreenNo       :显示屏屏号；该参数与LedshowTW 2013软件中"设置屏参"模块的"屏号"参数一致。
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      1:GPRS模式
      2:网络模式
      4:WiFi模式
      5:ONBON服务器-GPRS
      6:ONBON服务器-3G
    nWidth          :显示屏宽度 16的整数倍；最小64；BX-5E系列最小为80
    nHeight         :显示屏高度 16的整数倍；最小16；
    nScreenType     :显示屏类型；1：单基色；2：双基色；
      3：双基色；注意：该显示屏类型只有BX-4MC支持；同时该型号控制器不支持其它显示屏类型。
      4：全彩色；注意：该显示屏类型只有BX-5Q系列支持；同时该型号控制器不支持其它显示屏类型。
      5：双基色灰度；注意：该显示屏类型只有BX-5QS支持；同时该型号控制器不支持其它显示屏类型。
    nPixelMode      :点阵类型；1：R+G；2：G+R；该参数只对双基色屏有效 ；默认为2；
    nDataDA         :数据极性；，0x00：数据低有效，0x01：数据高有效；默认为0；
    nDataOE         :OE极性；  0x00：OE 低有效；0x01：OE 高有效；默认为0；
    nRowOrder       :行序模式；0：正常；1：加1行；2：减1行；默认为0；
    nDataFlow       :数据流向；0：正常；1：镜像；2：正向U型；3：反向u型；默认为0；
    nFreqPar        :扫描点频；0~6；默认为0；
    pCom            :串口名称；串口通讯模式时有效；例:COM1
    nBaud           :串口波特率：目前支持9600、57600；默认为57600；
    pSocketIP       :控制卡IP地址，网络通讯模式时有效；例:192.168.0.199；
      本动态库网络通讯模式时只支持固定IP模式，单机直连和网络服务器模式不支持。
    nSocketPort     :控制卡网络端口；网络通讯模式时有效；例：5005
    nStaticIPMode   :固定IP通讯模式：0：TCP模式 1：UDP模式
    nServerMode     :0:服务器模式未启动；1：服务器模式启动。
    pBarcode        :设备条形码
    pNetworkID      :网络ID编号
    pServerIP       :中转服务器IP地址
    nServerPort     :中转服务器网络端口
    pServerAccessUser:中转服务器访问用户名
    pServerAccessPassword:中转服务器访问密码
    pWiFiIP         :控制器WiFi模式的IP地址信息；WiFi通讯模式时有效；例:192.168.100.1
    nWiFiPort       :控制卡WiFi端口；WiFi通讯模式时有效；例：5005
    pGprsIP         :GPRS服务器IP地址
    nGprsPort       :GPRS服务器端口
    pGprsID         :GPRS编号
    pScreenStatusFile:用于保存查询到的显示屏状态参数保存的INI文件名；
      只有执行查询显示屏状态GetScreenStatus时，该参数才有效
    pCallBack :返回发送的消息和进度
                       类型为 TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreen         : function(nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode: Integer;
    nDataDA, nDataOE: Integer; nRowOrder, nDataFlow, nFreqPar: Integer; pCom: PChar; nBaud: Integer; pSocketIP: PChar;
    nSocketPort: Integer; nStaticIPMode:Integer; nServerMode: Integer; pBarcode: PChar; pNetworkID: PChar; pServerIP: PChar; nServerPort: Integer;
    pServerAccessUser: PChar; pServerAccessPassword: PChar; pWiFiIP: PChar; nWiFiPort: Integer;
    pGprsIP: PChar; nGprsPort: Integer; pGprsID: PChar; pFileName: PChar; pCallBack: TCallBackFunc): integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgram
  向动态库中指定显示屏添加节目；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramType    :节目类型；0正常节目。
    nPlayLength     :0:表示自动顺序播放；否则表示节目播放的长度；范围1~65535；单位秒
    nStartYear      :节目的生命周期；开始播放时间年份。如果为无限制播放的话该参数值为65535；如2010
    nStartMonth     :节目的生命周期；开始播放时间月份。如11
    nStartDay       :节目的生命周期；开始播放时间日期。如26
    nEndYear        :节目的生命周期；结束播放时间年份。如2011
    nEndMonth       :节目的生命周期；结束播放时间月份。如11
    nEndDay         :节目的生命周期；结束播放时间日期。如26
    nMonPlay        :节目在生命周期内星期一是否播放;0：不播放;1：播放.
    nTuesPlay       :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    nWedPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    nThursPlay      :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    bFriPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    nSatPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    nSunPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
    nStartHour      :节目在当天开始播放时间小时。如8
    nStartMinute    :节目在当天开始播放时间分钟。如0
    nEndHour        :节目在当天结束播放时间小时。如18
    nEndMinute      :节目在当天结束播放时间分钟。如0
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgram  : function(nScreenNo, nProgramType: Integer; nPlayLength: Integer;
    nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay: Integer;
    nMonPlay, nTuesPlay, nWedPlay, nThursPlay, bFriPlay, nSatPlay, nSunPlay: integer;
    nStartHour, nStartMinute, nEndHour, nEndMinute: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramBmpTextArea:
  向动态库中指定显示屏的指定节目添加图文区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的图文区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramBmpTextArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramAreaBmpTextText
  向动态库中指定显示屏的指定节目的指定图文区域添加文本；
      该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    pText           :文本
    nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
    nAlignment      :居中显示：0 居左 1居中 2 居右；
    pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
    nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
    nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
    nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
    nStunt          :显示特技。
      0x00:随机显示
      0x01:静态
      0x02:快速打出
      0x03:向左移动
      0x04:向左连移
      0x05:向上移动            3T类型控制卡无此特技
      0x06:向上连移            3T类型控制卡无此特技
      0x07:闪烁                3T类型控制卡无此特技
      0x08:飘雪
      0x09:冒泡
      0x0A:中间移出
      0x0B:左右移入
      0x0C:左右交叉移入
      0x0D:上下交叉移入
      0x0E:画卷闭合
      0x0F:画卷打开
      0x10:向左拉伸
      0x11:向右拉伸
      0x12:向上拉伸
      0x13:向下拉伸            3T类型控制卡无此特技
      0x14:向左镭射
      0x15:向右镭射
      0x16:向上镭射
      0x17:向下镭射
      0x18:左右交叉拉幕
      0x19:上下交叉拉幕
      0x1A:分散左拉
      0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
      0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
      0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
      0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
      0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
      0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
      0x21:左右闭合            3T类型控制卡无此特技
      0x22:左右对开            3T类型控制卡无此特技
      0x23:上下闭合            3T类型控制卡无此特技
      0x24:上下对开            3T类型控制卡无此特技
      0x25:向右连移
      0x26:向右连移
      0x27:向下移动            3T类型控制卡无此特技
      0x28:向下连移            3T类型控制卡无此特技
    nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
    nShowTime       :停留时间；0~65525；单位0.5秒

  返回值:           :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramAreaBmpTextText: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pText: PChar; nShowSingle: Integer; nAlignment: integer; pFontName: PChar;
    nFontSize, nBold, nFontColor: Integer; nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramAreaBmpTextFile
  向动态库中指定显示屏的指定节目的指定图文区域添加文件；
      该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    pFileName       :文件名称  支持.bmp,jpg,jpeg,rtf,txt等文件类型。
    nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
    nAlignment      :居中显示：0 居左 1居中 2 居右；
    pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
    nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
    nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
    nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
    nStunt          :显示特技。
      0x00:随机显示
      0x01:静态
      0x02:快速打出
      0x03:向左移动
      0x04:向左连移
      0x05:向上移动            3T类型控制卡无此特技
      0x06:向上连移            3T类型控制卡无此特技
      0x07:闪烁                3T类型控制卡无此特技
      0x08:飘雪
      0x09:冒泡
      0x0A:中间移出
      0x0B:左右移入
      0x0C:左右交叉移入
      0x0D:上下交叉移入
      0x0E:画卷闭合
      0x0F:画卷打开
      0x10:向左拉伸
      0x11:向右拉伸
      0x12:向上拉伸
      0x13:向下拉伸            3T类型控制卡无此特技
      0x14:向左镭射
      0x15:向右镭射
      0x16:向上镭射
      0x17:向下镭射
      0x18:左右交叉拉幕
      0x19:上下交叉拉幕
      0x1A:分散左拉
      0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
      0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
      0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
      0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
      0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
      0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
      0x21:左右闭合            3T类型控制卡无此特技
      0x22:左右对开            3T类型控制卡无此特技
      0x23:上下闭合            3T类型控制卡无此特技
      0x24:上下对开            3T类型控制卡无此特技
      0x25:向右连移
      0x26:向右连移
      0x27:向下移动            3T类型控制卡无此特技
      0x28:向下连移            3T类型控制卡无此特技
    nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
    nShowTime       :停留时间；0~65525；单位0.5秒

  返回值:           :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramAreaBmpTextFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pFileName: PChar; nShowSingle: Integer; nAlignment: integer; pFontName: PChar;
    nFontSize, nBold, nFontColor: Integer; nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramTimeArea
  向动态库中指定显示屏的指定节目添加时间区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的时间区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramTimeArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramTimeAreaFile
  向动态库中指定显示屏的指定节目的指定时间区域属性；该函数不与显示屏通讯，
  只用于动态库中的指定显示屏指定节目中指定时间区域属性信息配置。
  参数:
    nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    pInputtxt   :固定文字
    pFontName   :文字的字体
    nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
    nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
    nFontSize   :文字的大小
    nBold       :是否加粗，0为不1为是
    nItalic     :是否斜体，0为不1为是
    nUnderline  :是否下滑线，0为不1为是
    nUsetxt     :是否使用固定文字，0为不1为是
    nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
    nUseymd     :是否使用年月日，0为不1为是
    nYmdstyle   :年月日格式，详见使用说明文档的附件1
    nYmdcolor   :年月日颜色，传递颜色的10进制
    nUseweek    :是否使用星期，0为不1为是
    nWeekstyle  :星期格式，详见使用说明文档的附件1
    nWeekcolor  :星期颜色，传递颜色的10进制
    nUsehns     :是否使用时分秒，0为不1是
    nHnsstyle   :时分秒格式，详见使用说明文档的附件1
    nHnscolor   :时分秒颜色，传递颜色的10进制
    nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramTimeAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pInputtxt, pFontName: PChar;
    nSingal, nAlign, nFontSize, nBold, nItalic, nUnderline: Integer;
    nUsetxt, nTxtcolor,
    nUseymd, nYmdstyle, nYmdcolor,
    nUseweek, nWeekstyle, nWeekcolor,
    nUsehns, nHnsstyle, nHnscolor, nAutoset: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramLunarArea
  向动态库中指定显示屏的指定节目添加农历区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的农历区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramLunarArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramLunarAreaFile
  向动态库中指定显示屏的指定节目的指定农历区域属性；该函数不与显示屏通讯，
  只用于动态库中的指定显示屏指定节目中指定农历区域属性信息配置。
  参数:
    nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd		:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    pInputtxt		:固定文字
    pFontName		:文字的字体
    nSingal			:单行多行，0为单行 1为多行，单行模式下nAlign不起作用
    nAlign			:文字对齐模式，对多行有效，0为左1为中2为右
    nFontSize		:文字的大小
    nBold				:是否加粗，0为不1为是
    nItalic			:是否斜体，0为不1为是
    nUnderline	:是否下滑线，0为不1为是
    nUsetxt			:是否使用固定文字，0为不1为是
    nTxtcolor		:固定文字颜色，传递颜色的10进制
    nUseyear		:是否使用天干，0为不1为是  （辛卯兔年）
    nYearcolor	:天干颜色，传递颜色的10进制
    nUsemonth		:是否使用农历，0为不1为是  （九月三十）
    nMonthcolor	:农历颜色，传递颜色的10进制
    nUsesolar		:是否使用节气，0为不1是
    nSolarcolor	:节气颜色，传递颜色的10进制
    nAutoset		:是否自动设置大小对应宽度，0为不1为是（默认不使用）
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramLunarAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pInputtxt, pFontName: PChar;
    nSingal, nAlign, nFontSize, nBold, nItalic, nUnderline: Integer;
    nUsetxt, nTxtcolor, nUseyear, nYearcolor, nUsemonth, nMonthcolor,
    nUsesolar, nSolarcolor, nAutoset: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramClockArea
  向动态库中指定显示屏的指定节目添加表盘区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的表盘区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramClockArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramClockAreaFile
  向动态库中指定显示屏的指定节目的指定表盘区域属性；该函数不与显示屏通讯，
  只用于动态库中的指定显示屏指定节目中指定表盘区域属性信息配置。
  参数:
    nScreenNo			:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd 	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd			:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    nusetxt				:是否使用固定文字 0为不1为是
    nusetime			:是否使用年月日时间 0为不1为是
    nuseweek			:是否使用星期 0为不1为是
    ntimeStyle		:年月日时间格式，参考时间区的表格说明
    nWeekStyle		:星期时间格式，参考时间区的表格说明
    ntxtfontsize	:固定文字的字大小
    ntxtfontcolor	:固定文字的颜色；传递颜色的10进制;红255绿65280黄65535
    ntxtbold			:固定文字是否加粗 0为不1为是
    ntxtitalic		:固定文字是否斜体 0为不1为是
    ntxtunderline	:固定文字是否下划线 0为不1为是
    txtleft				:固定文字在表盘区域中的X坐标
    txttop				:固定文字在表盘区域中的Y坐标
    ntimefontsize	:年月日文字的字大小
    ntimefontcolor:年月日文字的颜色； 传递颜色的10进制
    ntimebold			:年月日文字是否加粗 0为不1为是
    ntimeitalic		:年月日文字是否斜体 0为不1为是
    ntimeunderline:年月日文字是否下划线 0为不1为是
    timeleft			:年月日文字在表盘区域中的X坐标
    timetop				:年月日文字在表盘区域中的X坐标
    nweekfontsize	:星期文字的字大小
    nweekfontcolor:星期文字的颜色；传递颜色的10进制
    nweekbold			:星期文字是否加粗 0为不1为是
    nweekitalic		:星期文字是否斜体 0为不1为是
    nweekunderline:星期文字是否下划线 0为不1为是
    weekleft			:星期文字在表盘区域中的X坐标
    weektop				:星期文字在表盘区域中的X坐标
    nclockfontsize:表盘文字的字大小
    nclockfontcolor:表盘文字的颜色；传递颜色的10进制
    nclockbold		:表盘文字是否加粗 0为不1为是
    nclockitalic	:表盘文字是否斜体 0为不1为是
    nclockunderline:表盘文字是否下划线 0为不1为是
    clockcentercolor:表盘中心颜色；传递颜色的10进制
    mhrdotstyle		:3/6/9时点类型 0线形1圆形2方形3数字4罗马
    mhrdotsize		:3/6/9时点尺寸 0-8
    mhrdotcolor		:3/6/9时点颜色；传递颜色的10进制
    hrdotstyle		:3/6/9外的时点类型  0线形1圆形2方形3数字4罗马
    hrdotsize			:3/6/9外的时点尺寸 0-8
    hrdotcolor		:3/6/9外的时点颜色；传递颜色的10进制
    mindotstyle		:分钟点类型  0线形1圆形2方形
    mindotsize		:分钟点尺寸 0-1
    mindotcolor		:分钟点颜色；传递颜色的10进制
    hrhandsize		:时针尺寸 0-8
    hrhandcolor		:时针颜色；传递颜色的10进制
    minhandsize		:分针尺寸 0-8
    minhandcolor	:分针颜色；传递颜色的10进制
    sechandsize		:秒针尺寸 0-8
    sechandcolor	:秒针颜色；传递颜色的10进制
    nAutoset			:自适应位置设置，0为不1为是 如果为1，那txtleft/txttop/ weekleft/weektop/timeleft/timetop需要自己设坐标值
    btxtcontent		:固定文字信息
    btxtfontname	:固定文字字体
    btimefontname	:时间文字字体
    bweekfontname	:星期文字字体
    bclockfontname:表盘文字字体
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramClockAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    nusetxt, nusetime, nuseweek, ntimeStyle, nWeekStyle,
    ntxtfontsize, ntxtfontcolor, ntxtbold, ntxtitalic, ntxtunderline, txtleft, txttop,
    ntimefontsize, ntimefontcolor, ntimebold, ntimeitalic, ntimeunderline, timeleft, timetop,
    nweekfontsize, nweekfontcolor, nweekbold, nweekitalic, nweekunderline, weekleft, weektop,
    nclockfontsize, nclockfontcolor, nclockbold, nclockitalic, nclockunderline,
    clockcentersize, clockcentercolor, mhrdotstyle, mhrdotsize, mhrdotcolor,
    hrdotstyle, hrdotsize, hrdotcolor, mindotstyle, mindotsize, mindotcolor,
    hrhandsize, hrhandcolor, minhandsize, minhandcolor, sechandsize, sechandcolor, nAutoset: integer;
    btxtcontent, btxtfontname, btimefontname, bweekfontname, bclockfontname: pchar): Integer; stdcall;

  AddScreenProgramChroArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;

 {-------------------------------------------------------------------------------
  过程名:    AddScreenProgramChroAreaFile
  向动态库中指定显示屏的指定节目的指定计时区域属性；该函数不与显示屏通讯，
  只用于动态库中的指定显示屏指定节目中指定计时区域属性信息配置。
  参数:
    nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。

    pInputtxt   :固定文字
    pDaystr    :天单位
    pHourstr   :小时单位
    pMinstr    :分钟单位
    pSecstr    :秒单位
    pFontName   :文字的字体
    nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
    nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
    nFontSize   :文字的大小
    nBold       :是否加粗，0为不1为是
    nItalic     :是否斜体，0为不1为是
    nUnderline  :是否下滑线，0为不1为是
    nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
    nFontcolor  :计时显示颜色，传递颜色的10进制 红255 绿65280 黄65535

    nShowstr     :是否显示单位，对应于所有的天，时，分，秒单位
    nShowAdd     :是否计时累加显示 默认是累加的
    nUsetxt     :是否使用固定文字，0为不1为是
    nUseDay     :是否使用天，0为不1为是
    nUseHour    :是否使用小时，0为不1为是
    nUseMin     :是否使用分钟，0为不1为是
    nUseSec     :是否使用秒，0为不1为是

    nDayLength     :天显示位数    默认为0 自动
    nHourLength    :小时显示位数  默认为0 自动
    nMinLength     :分显示位数    默认为0 自动
    nSecLength     :秒显示位数    默认为0 自动

    EndYear     :目标年值
    EndMonth   :目标月值
    EndDay     :目标日值
    EndHour    :目标时值
    EndMin     :目标分值
    EndSec     :目标秒值


    nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}

  AddScreenProgramChroAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pInputtxt, pDaystr, pHourstr, pMinstr, pSecstr, pFontName: PChar;
    nSingal, nAlign, nFontSize, nBold, nItalic, nUnderline,
    nTxtcolor, nFontcolor,
    nShowstr, nShowAdd, nUseTxt, nUseDay, nUseHour, nUseMin, nUseSec,
    nDayLength, nHourLength, nMinLength, nSecLength,
    EndYear, EndMonth, EndDay, EndHour, EndMin, EndSec,
    nAutoset: Integer): Integer; stdcall;



{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramTemperatureArea
  向动态库中指定显示屏的指定节目添加温度区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目中的温度区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
    nSensorType     :温度传感器类型；
      0:"Temp sensor S-T1";
      1:"Temp and hum sensor S-RHT 1";
      2:"Temp and hum sensor S-RHT 2"
    nTemperatureUnit:温度显示单位；0:摄氏度(℃);1:华氏度(℉);2:摄氏度(无)
    nTemperatureMode:温度显示模式；0:整数型；1:小数型。
    nTemperatureUnitScale:温度单位显示比例；50~100;默认为100.
    nTemperatureValueWidth:温度数值字符显示宽度；
    nTemperatureCorrectionPol:温度值误差修正值极性；0；正；1：负
    nTemperatureCondition:温度值误差修正值；
    nTemperatureThreshPol:温度阈值条件；0:表示小于此值触发事情;1:表示大于此值触发条件
    nTemperatureThresh:温度阈值
    nTemperatureColor:正常温度颜色
    nTemperatureErrColor:温度超过阈值时显示的颜色
    pStaticText     :温度区域前缀固定文本;该参数可为空
    pStaticFont     :字体名称；支持当前操作系统已经安装的矢量字库；
    nStaticSize     :字体字号；支持当前操作系统的字号；
    nStaticColor    :字体颜色；
    nStaticBold     :字体粗体；支持1：粗体；0：正常；
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramTemperatureArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer;
    nSensorType,
    nTemperatureUnit,
    nTemperatureMode,
    nTemperatureUnitScale,
    nTemperatureValueWidth,
    nTemperatureCorrectionPol,
    nTemperatureCondition,
    nTemperatureThreshPol,
    nTemperatureThresh,
    nTemperatureColor,
    nTemperatureErrColor: Integer;
    pStaticText,
    pStaticFont: pChar;
    nStaticSize,
    nStaticColor,
    nStaticBold: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramHumidityArea
  向动态库中指定显示屏的指定节目添加湿度区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目中的湿度区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
    nSensorType     :湿度传感器类型；
      0:"Temp and hum sensor S-RHT 1";
      1:"Temp and hum sensor S-RHT 2"
    nHumidityUnit   :湿度显示单位；0:相对湿度(%RH);1:相对湿度(无)
    nHumidityMode   :湿度显示模式；0:整数型；1:小数型。
    nHumidityUnitScale:湿度单位显示比例；50~100;默认为100.
    nHumidityValueWidth:湿度数值字符显示宽度；
    nHumidityConditionPol:湿度值误差修正值极性；0；正；1：负
    nHumidityCondition:湿度值误差修正值；
    nHumidityThreshPol:湿度阈值条件；0:表示小于此值触发事情;1:表示大于此值触发条件
    nHumidityThresh :湿度阈值
    nHumidityColor  :正常湿度颜色
    nHumidityErrColor:湿度超过阈值时显示的颜色
    pStaticText     :湿度区域前缀固定文本;该参数可为空
    pStaticFont     :字体名称；支持当前操作系统已经安装的矢量字库；
    nStaticSize     :字体字号；支持当前操作系统的字号；
    nStaticColor    :字体颜色；
    nStaticBold     :字体粗体；支持1：粗体；0：正常；
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramHumidityArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer;
    nSensorType,
    nHumidityUnit,
    nHumidityMode,
    nHumidityUnitScale,
    nHumidityValueWidth,
    nHumidityConditionPol,
    nHumidityCondition,
    nHumidityThreshPol,
    nHumidityThresh,
    nHumidityColor,
    nHumidityErrColor: Integer;
    pStaticText,
    pStaticFont: pChar;
    nStaticSize,
    nStaticColor,
    nStaticBold: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenProgramNoiseArea
  向动态库中指定显示屏的指定节目添加噪声区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目中的噪声区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
    nSensorType     :噪声传感器类型；
      0:"I-声级仪";
      1:"II-声级仪"
    nNoiseUnit      :噪声显示单位；0:相对湿度(%RH);1:相对湿度(无)
    nNoiseMode      :噪声显示模式；0:整数型；1:小数型。
    nNoiseUnitScale :噪声单位显示比例；50~100;默认为100.
    nNoiseValueWidth:噪声数值字符显示宽度；
    nNoiseConditionPol:噪声值误差修正值极性；0；正；1：负
    nNoiseCondition :噪声值误差修正值；
    nNoiseThreshPol :噪声阈值条件；0:表示小于此值触发事情;1:表示大于此值触发条件
    nNoiseThresh    :噪声阈值
    nNoiseColor     :正常噪声颜色
    nNoiseErrColor  :噪声超过阈值时显示的颜色
    pStaticText     :噪声区域前缀固定文本;该参数可为空
    pStaticFont     :字体名称；支持当前操作系统已经安装的矢量字库；
    nStaticSize     :字体字号；支持当前操作系统的字号；
    nStaticColor    :字体颜色；
    nStaticBold     :字体粗体；支持1：粗体；0：正常；
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenProgramNoiseArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer;
    nSensorType,
    nNoiseUnit,
    nNoiseMode,
    nNoiseUnitScale,
    nNoiseValueWidth,
    nNoiseConditionPol,
    nNoiseCondition,
    nNoiseThreshPol,
    nNoiseThresh,
    nNoiseColor,
    nNoiseErrColor: Integer;
    pStaticText,
    pStaticFont: pChar;
    nStaticSize,
    nStaticColor,
    nStaticBold: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    DeleteScreen
  删除指定显示屏信息，删除显示屏成功后会将该显示屏下所有节目信息从动态库中删除。
  该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  DeleteScreen      : function(nScreenNo: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    DeleteScreenProgram
  删除指定显示屏指定节目，删除节目成功后会将该节目下所有区域信息删除。
  该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  DeleteScreenProgram: function(nScreenNo, nProgramOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    DeleteScreenProgramArea
  删除指定显示屏指定节目的指定区域，删除区域成功后会将该区域下所有信息删除。
  该函数不与显示屏通讯，只用于动态库中指定显示屏指定节目中指定的区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  DeleteScreenProgramArea: function(nScreenNo, nProgramOrd, nAreaOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    DeleteScreenProgramAreaBmpTextFile
  删除指定显示屏指定节目指定图文区域的指定文件，删除文件成功后会将该文件信息删除。
  该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目指定区域中的指定文件信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
    nFileOrd        :文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  DeleteScreenProgramAreaBmpTextFile: function(nScreenNo, nProgramOrd, nAreaOrd, nFileOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    SendScreenInfo
  通过指定的通讯模式，发送相应信息、命令到显示屏。该函数与显示屏进行通讯
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      2:网络模式;
      4:WiFi模式
    nSendCmd        :通讯命令值
      SEND_CMD_PARAMETER =41471;  加载屏参数。
      SEND_CMD_SENDALLPROGRAM = 41456;  发送所有节目信息。
      SEND_CMD_POWERON =41727; 强制开机
      SEND_CMD_POWEROFF = 41726; 强制关机
      SEND_CMD_TIMERPOWERONOFF = 41725; 定时开关机
      SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; 取消定时开关机
      SEND_CMD_RESIVETIME = 41723; 校正时间。
      SEND_CMD_ADJUSTLIGHT = 41722; 亮度调整。
    nOtherParam1    :保留参数；0
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  SendScreenInfo    : function(nScreenNo, nSendCmd, nOtherParam1: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    SetScreenTimerPowerONOFF
  设定显示屏的定时开关机参数，可以设置3组开关机时间。该函数不与显示屏通讯，
  只用于动态库中对指定显示屏的定时开关机信息配置。如需将设定的定时开关值发送到显示屏上，
  只需使用SendScreenInfo函数发送定时开关命令即可。
  参数:
    nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nOnHour1		:第一组定时开关的开机时间的小时
    nOnMinute1	:第一组定时开关的开机时间的分钟
    nOffHour1		:第一组定时开关的关机时间的小时
    nOffMinute1	:第一组定时开关的关机时间的分钟
    nOnHour2		:第二组定时开关的开机时间的小时
    nOnMinute2	:第二组定时开关的开机时间的分钟
    nOffHour2		:第二组定时开关的关机时间的小时
    nOffMinute2	:第二组定时开关的关机时间的分钟
    nOnHour3		:第三组定时开关的开机时间的小时
    nOnMinute3	:第三组定时开关的开机时间的分钟
    nOffHour3		:第三组定时开关的关机时间的小时
    nOffMinute3	:第三组定时开关的关机时间的分钟
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  SetScreenTimerPowerONOFF: function(nScreenNo: Integer;
    nOnHour1, nOnMinute1, nOffHour1, nOffMinute1,
    nOnHour2, nOnMinute2, nOffHour2, nOffMinute2,
    nOnHour3, nOnMinute3, nOffHour3, nOffMinute3: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    SetScreenAdjustLight
  设定显示屏的亮度调整参数，该函数可设置手工调亮和定时调亮两种模式。该函数不与显示屏通讯，
  只用于动态库中对指定显示屏的亮度调整信息配置。如需将设定的亮度调整值发送到显示屏上，
  只需使用SendScreenInfo函数发送亮度调整命令即可。
  参数:
    nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nAdjustType	:亮度调整类型；0：手工调亮；1：定时调亮
    nHandleLight:手工调亮的亮度值，只有nAdjustType=0时该参数有效。
    nHour1			:第一组定时调亮时间的小时
    nMinute1		:第一组定时调亮时间的分钟
    nLight1			:第一组定时调亮的亮度值
    nHour2			:第二组定时调亮时间的小时
    nMinute2		:第二组定时调亮时间的分钟
    nLight2			:第二组定时调亮的亮度值
    nHour3			:第三组定时调亮时间的小时
    nMinute3		:第三组定时调亮时间的分钟
    nLight3			:第三组定时调亮的亮度值
    nHour4			:第四组定时调亮时间的小时
    nMinute4		:第四组定时调亮时间的分钟
    nLight4			:第四组定时调亮的亮度值
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  SetScreenAdjustLight: function(nScreenNo: Integer; nAdjustType, nHandleLight: Integer;
    nHour1, nMinute1, nLight1,
    nHour2, nMinute2, nLight2,
    nHour3, nMinute3, nLight3,
    nHour4, nMinute4, nLight4: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    SaveUSBScreenInfo
  保存显示屏数据信息到USB设备。方便用户用USB方式更新显示屏信息。该函数与LedshowTW软件配套的USB下载功能一致。
  使用该功能时，注意当前控制器是否支持USB下载功能。
  参数
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    bCorrectTime    :是否校正时间
      0：不校正时间；
      1：校正时间；
    nAdvanceHour    :校正时间比当前计算机时间提前的小时值。范围0~23；只有当bCorrectTime=1时有效。
    nAdvanceMinute  :校正时间比当前计算机时间提前的分钟值。范围0~59；只有当bCorrectTime=1时有效。
    pUSBDisk        :USB设备的路径名称；格式为"盘符:\"的格式；例如："F:\"
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  SaveUSBScreenInfo : function(nScreenNo: Integer;
    bCorrectTime, nAdvanceHour, nAdvanceMinute: Integer; pUSBDisk: PChar): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    GetScreenStatus
  查询当前显示屏状态，将查询状态参数保存到AddScreen函数中的pScreenStatusFile的INI类型文件中。
  该函数与显示屏进行通讯
  参数:      nScreenNo, nSendMode: Integer
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      2:网络模式;
      4:WiFi模式
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  GetScreenStatus   : function(nScreenNo, nSendMode: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    GetScreenParameter
  查询当前显示屏参数，将查询状态参数保存到szFileName的INI类型文件中。
  该函数与显示屏进行通讯
  参数:      nScreenNo, nSendMode: Integer ; szFileName : PChar
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      2:网络模式;
      4:WiFi模式
    szFileName      :保存的Ini文件路径；
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  GetScreenParameter   : function(nScreenNo, nSendMode: Integer; szFileName : PChar): Integer; stdcall;

  {-------------------------------------------------------------------------------
  过程名:    QuerryServerDeviceList
  查询中转服务器设备的列表信息。
  该函数与显示屏进行通讯
  参数:
    pTransitDeviceType :中转设备类型 BX-3GPRS，BX-3G
    pServerIP       :中转服务器IP地址
    nServerPort     :中转服务器网络端口
    pServerAccessUser:中转服务器访问用户名
    pServerAccessPassword:中转服务器访问密码
    pDeviceList       : 保存查询的设备列表信息
      将设备的信息用组成字符串, 比如：
      设备1：名称 条形码 状态 类型 网络ID
      设备2：名称 条形码 状态 类型 网络ID
      组成字符串为：'设备1名称,设备1条形码,设备1状态,设备1类型,设备1网络ID;设备2名称,设备2条形码,设备2状态,设备2类型,设备2网络ID'
      设备状态(Byte):  $10:设备未知
                       $11:设备在线
                       $12:设备不在线

      设备类型(Byte): $16:设备为2G
                      $17:设备为3G

  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  QuerryServerDeviceList : function(pTransitDeviceType: PChar;pServerIP: PChar; nServerPort: Integer;
  pServerAccessUser: PChar; pServerAccessPassword: PChar;pDeviceList:PChar): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    StartServer
  启动服务器,用于网络模式下的服务器模式和GPRS通讯模式。
  参数:
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      1:GPRS模式
      2:网络模式
      4:WiFi模式
      5:ONBON服务器-GPRS
      6:ONBON服务器-3G
    pServerIP       :中转服务器IP地址
    nServerPort     :中转服务器网络端口
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  StartServer : function(nSendMode:Integer;pServerIP: PChar; nServerPort: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    StopServer
  关闭服务器,用于网络模式下的服务器模式和GPRS通讯模式。
  参数:
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      1:GPRS模式
      2:网络模式
      4:WiFi模式
      5:ONBON服务器-GPRS
      6:ONBON服务器-3G
  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  StopServer : function(nSendMode:Integer): Integer; stdcall;

implementation

{$R *.dfm}

function SplitString(const Source, Ch: string): TStringList;
var
  Temp              : string;
  I                 : Cardinal;
begin
  Result := tstringlist.Create;
  Temp := Source;
  i := pos(Ch, Source);
  while I <> 0 do
  begin
    Result.Add(copy(Temp, 0, I - 1));
    Delete(Temp, 1, i);
    i := Pos(Ch, Temp);
  end;
  Result.Add(Temp);
end;

procedure CallBack(szMessagge:string;nProcess:integer); stdcall;
var
  afile:   TFileStream;
  StrToWrite :string;
begin
  Application.ProcessMessages;
  Frm_Main.rzpbSendProgress.Visible:=True;
  Frm_Main.rzpbSendProgress.Percent:=nProcess;
  Frm_Main.lblMessage.Caption := szMessagge; 
  {StrToWrite:=DateTimeToStr(now)+':   '+szMessagge + '---' + inttostr(nProcess)+#13#10;
  Frm_Main.FileStream.Seek(0,   soEnd);
  Frm_Main.FileStream.WriteBuffer(PChar(StrToWrite)^,Length(StrToWrite)); }
  {if   not   FileExists( 'e:/a.txt ')   then
  begin
      try
          afile   :=   TFileStream.Create( 'e:/a.txt ',   fmCreate);
          afile.WriteBuffer(PChar(StrToWrite)^,Length(StrToWrite));
      finally
          afile.Free;
      end;
  end
  else   begin
      try
          afile   :=   TFileStream.Create( 'e:/a.txt ',   fmOpenWrite);
          afile.Seek(0,   soEnd);
          afile.WriteBuffer(PChar(StrToWrite)^,Length(StrToWrite));
      finally
          afile.Free;
      end;
  end; }
end;

function TFrm_Main.GetScreenControlTypeValue(nControlTypeIndex: Cardinal): Cardinal;
begin
  case nControlTypeIndex of
    Controller_AX_UL_Index: Result := Controller_AX_UL;
    Controller_AX_UT_Index: Result := Controller_AX_UT;
    Controller_AX_U0_Index: Result := Controller_AX_U0;
    Controller_AX_U1_Index: Result := Controller_AX_U1;
    Controller_AX_U2_Index: Result := Controller_AX_U2;
    Controller_AX_MT_Index: Result := Controller_AX_MT;
    Controller_AX_M1_Index: Result := Controller_AX_M1;
    Controller_AX_M2_Index: Result := Controller_AX_M2;
    Controller_AX_M3_Index: Result := Controller_AX_M3;
    Controller_AX_M4_Index: Result := Controller_AX_M4;
    Controller_AX_AT_Index: Result := Controller_AX_AT;
    Controller_AX_A0_Index: Result := Controller_AX_A0;

    Controller_BX_5UL_Index: Result := Controller_BX_5UL;
    Controller_BX_5UT_Index: Result := Controller_BX_5UT;
    Controller_BX_5U0_Index: Result := Controller_BX_5U0;
    Controller_BX_5U1_Index: Result := Controller_BX_5U1;
    Controller_BX_5U2_Index: Result := Controller_BX_5U2;
    Controller_BX_5U3_Index: Result := Controller_BX_5U3;
    Controller_BX_5U4_Index: Result := Controller_BX_5U4;
    Controller_BX_5U5_Index: Result := Controller_BX_5U5;
    Controller_BX_5U_Index: Result := Controller_BX_5U;

    Controller_BX_5MT_Index: Result := Controller_BX_5MT;
    Controller_BX_5M1_Index: Result := Controller_BX_5M1;
    Controller_BX_5M1X_Index: Result := Controller_BX_5M1X;
    Controller_BX_5M2_Index: Result := Controller_BX_5M2;
    Controller_BX_5M3_Index: Result := Controller_BX_5M3;
    Controller_BX_5M4_Index: Result := Controller_BX_5M4;

    Controller_BX_5E1_Index: Result := Controller_BX_5E1;
    Controller_BX_5E2_Index: Result := Controller_BX_5E2;
    Controller_BX_5E3_Index: Result := Controller_BX_5E3;

    Controller_BX_5AL_Index: Result := Controller_BX_5AL;
    Controller_BX_5AT_Index: Result := Controller_BX_5AT;
    Controller_BX_5AT_WIFI_Index: Result := Controller_BX_5AT_WIFI;
    Controller_BX_5A0_Index: Result := Controller_BX_5A0;
    Controller_BX_5A0_WIFI_Index: Result := Controller_BX_5A0_WIFI;
    Controller_BX_5A1_Index: Result := Controller_BX_5A1;
    Controller_BX_5A1_WIFI_Index: Result := Controller_BX_5A1_WIFI;
    Controller_BX_5A_Index: Result := Controller_BX_5A;
    Controller_BX_5A2_Index: Result := Controller_BX_5A2;
    Controller_BX_5A2_RF_Index: Result := Controller_BX_5A2_RF;
    Controller_BX_5A2_WIFI_Index: Result := Controller_BX_5A2_WIFI;
    Controller_BX_5A3_Index: Result := Controller_BX_5A3;
    Controller_BX_5A4_Index: Result := Controller_BX_5A4;
    Controller_BX_5A4_RF_Index: Result := Controller_BX_5A4_RF;
    Controller_BX_5A4_WIFI_Index: Result := Controller_BX_5A4_WIFI;

    Controller_BX_5Q0_Index: Result := Controller_BX_5Q0;
    Controller_BX_5Q1_Index: Result := Controller_BX_5Q1;
    Controller_BX_5Q2_Index: Result := Controller_BX_5Q2;
    Controller_BX_5Q0P_Index: Result := Controller_BX_5Q0P;
    Controller_BX_5Q1P_Index: Result := Controller_BX_5Q1P;
    Controller_BX_5Q2P_Index: Result := Controller_BX_5Q2P;
    Controller_BX_5QL_Index: Result := Controller_BX_5QL;

    Controller_BX_5QS1_Index: Result := Controller_BX_5QS1;
    Controller_BX_5QS2_Index: Result := Controller_BX_5QS2;
    Controller_BX_5QS_Index: Result := Controller_BX_5QS;
    Controller_BX_5QS1P_Index: Result := Controller_BX_5QS1P;
    Controller_BX_5QS2P_Index: Result := Controller_BX_5QS2P;
    Controller_BX_5QSP_Index: Result := Controller_BX_5QSP;

  else
    Result := $FE; //广播模式，不指定设备类型，任何设备都应对其进行处理
  end;
end;

procedure TFrm_Main.FormCreate(Sender: TObject);
var
  reg               : TRegistry;
  ts                : TStrings;
  i                 : integer;
begin
  m_bSendBusy := False;
  reg := TRegistry.Create;
  reg.RootKey := HKEY_LOCAL_MACHINE;
  reg.OpenKey('hardware\DEVICEMAP\SERIALCOMM',
    false);
  ts := TStringList.Create;
  reg.GetValueNames(ts);
  comb_COMM.Clear;
  for i := 0 to ts.Count - 1 do begin
    comb_COMM.Items.Add(reg.ReadString(ts.Strings[i]));
  end;
  ts.Free;
  reg.CloseKey;
  reg.free;
  comb_COMM.ItemIndex := 0;
  hDll := LoadLibrary('BX_IV.dll');
  if hDll < 32 then exit; //如果Dll无法加载则跳出
  Initialize := GetProcAddress(hDll, 'Initialize');
  Uninitialize := GetProcAddress(hDll, 'Uninitialize');
  
  AddScreen := GetProcAddress(hDll, 'AddScreen');
  SendScreenInfo := GetProcAddress(hDll, 'SendScreenInfo');
  AddScreenProgram := GetProcAddress(hDll, 'AddScreenProgram');
  AddScreenProgramBmpTextArea := GetProcAddress(hDll, 'AddScreenProgramBmpTextArea');
  AddScreenProgramAreaBmpTextText := GetProcAddress(hDll, 'AddScreenProgramAreaBmpTextText');
  AddScreenProgramAreaBmpTextFile := GetProcAddress(hDll, 'AddScreenProgramAreaBmpTextFile');

  AddScreenProgramTimeArea := GetProcAddress(hDll, 'AddScreenProgramTimeArea');
  AddScreenProgramTimeAreaFile := GetProcAddress(hDll, 'AddScreenProgramTimeAreaFile');
  AddScreenProgramLunarArea := GetProcAddress(hDll, 'AddScreenProgramLunarArea');
  AddScreenProgramLunarAreaFile := GetProcAddress(hDll, 'AddScreenProgramLunarAreaFile');
  AddScreenProgramClockArea := GetProcAddress(hDll, 'AddScreenProgramClockArea');
  AddScreenProgramClockAreaFile := GetProcAddress(hDll, 'AddScreenProgramClockAreaFile');
  AddScreenProgramChroArea := GetProcAddress(hDll, 'AddScreenProgramChroArea');
  AddScreenProgramChroAreaFile := GetProcAddress(hDll, 'AddScreenProgramChroAreaFile');

  AddScreenProgramTemperatureArea := GetProcAddress(hDll, 'AddScreenProgramTemperatureArea');
  AddScreenProgramHumidityArea := GetProcAddress(hDll, 'AddScreenProgramHumidityArea');
  AddScreenProgramNoiseArea := GetProcAddress(hDll, 'AddScreenProgramNoiseArea');

  DeleteScreen := GetProcAddress(hDll, 'DeleteScreen');
  DeleteScreenProgram := GetProcAddress(hDll, 'DeleteScreenProgram');
  DeleteScreenProgramArea := GetProcAddress(hDll, 'DeleteScreenProgramArea');
  DeleteScreenProgramAreaBmpTextFile := GetProcAddress(hDll, 'DeleteScreenProgramAreaBmpTextFile');
  SetScreenTimerPowerONOFF := GetProcAddress(hDll, 'SetScreenTimerPowerONOFF');
  SetScreenAdjustLight := GetProcAddress(hDll, 'SetScreenAdjustLight');
  SaveUSBScreenInfo := GetProcAddress(hDll, 'SaveUSBScreenInfo');
  GetScreenStatus := GetProcAddress(hDll, 'GetScreenStatus');
  GetScreenParameter := GetProcAddress(hDll, 'GetScreenParameter');
  QuerryServerDeviceList := GetProcAddress(hDll, 'QuerryServerDeviceList');
  StartServer := GetProcAddress(hDll, 'StartServer');
  StopServer := GetProcAddress(hDll, 'StopServer');
  comb_ControlType.Items.Clear;
  for I := 1 to Length(Screen_Control) do
  begin
    comb_ControlType.Items.Add(Screen_Control[I - 1]);
  end;
  comb_ControlType.ItemIndex := CONTROLLER_BX_5E3_INDEX;
  comb_SendModeChange(self);
  InitializeCriticalSection(CS); 
end;

procedure TFrm_Main.Button1Click(Sender: TObject);
var
  nResult           : Integer;
  nServerMode: Integer;
  Barcode,NetworkID:string;
begin
  if (g_nSendMode = SEND_MODE_NET) then begin
    if rdbServerMode.Checked then begin
      nServerMode:=1;
    end
    else begin
      nServerMode:=0;
    end;
  end
  else if (g_nSendMode = SEND_MODE_WIFI) then begin
    if rdbWifiServerMode.Checked then begin
      nServerMode:=1;
    end
    else begin
      nServerMode:=0;
    end;
  end;

  if (g_nSendMode=SEND_MODE_Server_2G) or (g_nSendMode=SEND_MODE_Server_3G) then begin
    Barcode:=edtTransitBarcode.Text;
    NetworkID:=edtTransitNetworkId.Text;
  end
  else if (g_nSendMode=SEND_MODE_NET) then begin
    Barcode:='';
    NetworkID:=edtNetworkID.Text;
  end
  else if (g_nSendMode = SEND_MODE_WIFI) then begin
    Barcode:='';
    NetworkID:=edtWifiNetworkID.Text;
  end
  else begin
    Barcode:='';
    NetworkID:='';
  end;
  nResult := AddScreen(GetScreenControlTypeValue(comb_ControlType.ItemIndex), spnedt_ScreenNo.Value,
    g_nSendMode, spnedt_Width.Value, spnedt_Height.Value, comb_ScreenType.ItemIndex + 1, 2, 0, 0, 0, 0, 0,
    PChar(comb_COMM.Items[comb_COMM.ItemIndex]), StrToInt(comb_Baud.Items[comb_Baud.ItemIndex]),
    PChar(edt_IP.Text), spnedt_Port.Value, 0, nServerMode, PChar(Barcode), PChar(NetworkID), PChar(edtServerIP.Text),
    edtServerPort.value,PChar(edtUserName.Text), PChar(edtPassword.Text),PChar(edtWifiIP.Text), spnedtWifiPort.Value,
    PChar(edt_GprsIP.text),edt_GprsPort.Value,PChar(edt_GprsID.Text),
    pChar(ExtractFilePath(Application.ExeName) + 'ScreenStatus.ini'), CallBack);
  mmo1.Lines.Add('AddScreen' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn1Click(Sender: TObject);
var
  nResult           : Integer;
begin
  nResult := AddScreenProgram(spnedt_ScreenNo.Value, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59);
  mmo1.Lines.Add('AddScreenProgram' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn2Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramBmpTextArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value, 0, 0, spnedt_Width.Value, spnedt_Height.Value);
  mmo1.Lines.Add('AddScreenProgramBmpTextArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn3Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if (edt_FileName.Text <> '') then
  begin
    if (FileExists(edt_FileName.Text)) then
    begin
      nResult := AddScreenProgramAreaBmpTextFile(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
        spnedt_curAreaOrd.Value, PChar(edt_FileName.Text), 0, 0, PChar('宋体'), 14, 0, clYellow, 2, 0, 10);
      mmo1.Lines.Add('AddScreenProgramAreaBmpTextFile' + '---' + GetErrorMessage(nResult));
    end
    else
      ShowMessage('没有查找到有效的文件！');
  end
  else
    ShowMessage('请先添加有效的文件！');
end;

procedure TFrm_Main.btn5Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_PARAMETER, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.btn6Click(Sender: TObject);
begin
  dlgOpen1.Filter := '文件类型(*.bmp;*.jpg;*.jpeg;*.rtf;*.txt;*.txtf;*.txts)|*.bmp;*.jpg;*.jpeg;*.rtf;*.txt;*.txts';
  if dlgOpen1.Execute then
  begin
    edt_FileName.Text := dlgOpen1.FileName;
  end;
end;

procedure TFrm_Main.btn4Click(Sender: TObject);
begin
  tmr_SendProgram.Enabled := True;
end;

procedure TFrm_Main.Button5Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_POWERON, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.Button6Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_POWEROFF, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.Button7Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_RESIVETIME, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

function TFrm_Main.GetErrorMessage(nResult: Cardinal): string;
begin
  Result := FormatDateTime('YYYY-MM-DD HH:nn:ss', Now) + '--';
  case nResult of
    RETURN_ERROR_AERETYPE:
      Result := Result + '区域类型错误，在添加、删除图文区域文件时区域类型出错返回此类型错误。';
    RETURN_ERROR_RA_SCREENNO:
      Result := Result + '已经有该显示屏信息。如要重新设定请先DeleteScreen删除该显示屏再添加';
    RETURN_ERROR_NOFIND_AREAFILE:
      Result := Result + '没有找到有效的区域文件(图文区域)';
    RETURN_ERROR_NOFIND_AREA:
      Result := Result + '没有找到有效的显示区域可以使用AddScreenProgramBmpTextArea添加区域信息。';
    RETURN_ERROR_NOFIND_PROGRAM:
      Result := Result + '没有找到有效的显示屏节目可以使用AddScreenProgram函数添加指定节目';
    RETURN_ERROR_NOFIND_SCREENNO:
      Result := Result + '系统内没有查找到该显示屏可以使用AddScreen函数添加显示屏';
    RETURN_ERROR_NOW_SENDING:
      Result := Result + '系统内正在向该显示屏通讯，请稍后再通讯';
    RETURN_ERROR_OTHER:
      Result := Result + '其它错误';
    RETURN_ERROR_NOSUPPORT_USB:
      Result := Result + '该控制卡不支持保存到USB设备';
    RETURN_ERROR_NO_USB_DISK:
      Result := Result + '找不到对应的USB设备';
    RETURN_NOERROR:
      Result := Result + '函数执行/通讯成功';
    $01..$18, $FE:
      Result := Result + '通讯错误';
  else
    Result := Result + '其它错误';
  end;
end;

procedure TFrm_Main.mmo1DblClick(Sender: TObject);
begin
  mmo1.Lines.Clear;
end;

procedure TFrm_Main.Button8Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreen(spnedt_ScreenNo.Value);
  mmo1.Lines.Add('DeleteScreen' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn7Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreenProgram(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value);
  mmo1.Lines.Add('DeleteScreenProgram' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button3Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreenProgramArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value, spnedt_curAreaOrd.Value);
  mmo1.Lines.Add('DeleteScreenProgramArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button4Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreenProgramAreaBmpTextFile(spnedt_ScreenNo.Value,
    spnedt_curProgramOrd.Value, spnedt_curAreaOrd.Value, spnedt_curlFileOrd.Value);
  mmo1.Lines.Add('DeleteScreenProgramAreaBmpTextFile' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn8Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SetScreenTimerPowerONOFF(spnedt_ScreenNo.Value, 7, 0, 8, 0
    , 255, 255, 255, 255
    , 255, 255, 255, 255);
  mmo1.Lines.Add('SetScreenTimerPowerONOFF' + '---' + GetErrorMessage(nResult));
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_TIMERPOWERONOFF, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.Button2Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SetScreenAdjustLight(spnedt_ScreenNo.Value, 0, TrackBar1.Position,
    7, 0, 1,
    11, 0, 5,
    12, 0, 8,
    14, 0, 14);
  mmo1.Lines.Add('SetScreenAdjustLight' + '---' + GetErrorMessage(nResult));
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_ADJUSTLIGHT, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.btn9Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if m_bSendBusy = False then
  begin
    m_bSendBusy := True;
    nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_CANCEL_TIMERPOWERONOFF, 0);
    mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
    m_bSendBusy := False;
  end;
end;

procedure TFrm_Main.comb_SendModeChange(Sender: TObject);
begin
  if comb_SendMode.ItemIndex = 1 then
    g_nSendMode := SEND_MODE_GPRS //GPRS
  else
  if comb_SendMode.ItemIndex = 2 then
    g_nSendMode := SEND_MODE_NET //网络传输
  else
  if comb_SendMode.ItemIndex = 3 then
    g_nSendMode := SEND_MODE_WIFI //WIFi通讯
  else
  if comb_SendMode.ItemIndex = 4 then
    g_nSendMode := SEND_MODE_Server_2G //ONBON服务器-GPRS
  else
  if comb_SendMode.ItemIndex = 5 then
    g_nSendMode := SEND_MODE_Server_3G //ONBON服务器-3G
  else
  if comb_SendMode.ItemIndex = 6 then
    g_nSendMode := SEND_MODE_RF //RF通讯
  else
    g_nSendMode := SEND_MODE_COMM; //串口传输

  grpNet.Visible:=g_nSendMode=SEND_MODE_NET;
  grpWifi.Visible:=g_nSendMode=SEND_MODE_WIFI;
  grpGPRS.Visible:=g_nSendMode=SEND_MODE_GPRS;
  grpComm.Visible:=(g_nSendMode=SEND_MODE_COMM)or(g_nSendMode=SEND_MODE_RF);
  grpServer.Visible:=(g_nSendMode=SEND_MODE_Server_2G)or(g_nSendMode=SEND_MODE_Server_3G);
  btnBindWirelessDevice.Visible:=(g_nSendMode=SEND_MODE_Server_2G)or(g_nSendMode=SEND_MODE_Server_3G);
  lblTransitBarcode.Visible:=(g_nSendMode=SEND_MODE_Server_2G)or(g_nSendMode=SEND_MODE_Server_3G);
  edtTransitBarcode.Visible:=(g_nSendMode=SEND_MODE_Server_2G)or(g_nSendMode=SEND_MODE_Server_3G);
  lblTransitNetworkId.Visible:=(g_nSendMode=SEND_MODE_Server_3G);
  edtTransitNetworkId.Visible:=(g_nSendMode=SEND_MODE_Server_3G);
end;

procedure TFrm_Main.comb_ControlTypeChange(Sender: TObject);
begin
  comb_Baud.ItemIndex := 1;
  comb_ScreenType.ItemIndex := 0;
end;

procedure TFrm_Main.btn_USBClick(Sender: TObject);
var
  nResult           : Integer;
begin
  nResult := SaveUSBScreenInfo(spnedt_ScreenNo.Value, 1, 0, 1, PChar('H:\'));
  mmo1.Lines.Add('SaveUSBScreenInfo' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button9Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramTimeArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value
    , 0, 0, spnedt_Width.Value, spnedt_Height.Value);
  mmo1.Lines.Add('AddScreenProgramTimeArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button11Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramLunarArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value, 0, 0, spnedt_Width.Value, spnedt_Height.Value);
  mmo1.Lines.Add('AddScreenProgramLunarArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button13Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramClockArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value, 0, 0, spnedt_Width.Value, spnedt_Height.Value);
  mmo1.Lines.Add('AddScreenProgramClockArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button10Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramTimeAreaFile
    (spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
    spnedt_curAreaOrd.Value,
    PChar(''), PChar('宋体'),
    1, 1, 10, 0, 0, 0,
    0, 255,
    0, 0, 255,
    0, 0, 255,
    1, 1, 255,
    0);
  mmo1.Lines.Add('AddScreenProgramTimeAreaFile' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button12Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramLunarAreaFile
    (spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
    spnedt_curAreaOrd.Value,
    PChar(''), PChar('宋体'),
    1, 1, 10, 0, 0, 0,
    0, 255,
    1, 255,
    1, 255,
    0, 255,
    0);
  mmo1.Lines.Add('AddScreenProgramLunarAreaFile' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button14Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramClockAreaFile
    (spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
    spnedt_curAreaOrd.Value,
    0, 0, 0,
    0, 0,
    10, 255, 0, 0, 0, 0, 0,
    10, 255, 0, 0, 0, 0, 0,
    10, 255, 0, 0, 0, 0, 0,
    10, 255, 0, 0, 0,
    2, 255,
    1, 1, 255,
    1, 1, 255,
    1, 0, 255,
    2, 255,
    2, 255,
    1, 255,
    1,
    pchar(''), pchar('宋体'), pchar('宋体'), pchar('宋体'), pchar('宋体'));
  mmo1.Lines.Add('AddScreenProgramClockAreaFile' + '---' + GetErrorMessage(nResult));

end;

procedure TFrm_Main.btn10Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  Sleep(0);
  nResult := GetScreenStatus(spnedt_ScreenNo.Value, g_nSendMode);
  mmo1.Lines.Add('GetScreenStatus' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button15Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramChroArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value, 0, 0, spnedt_Width.Value, spnedt_Height.Value);
  mmo1.Lines.Add('AddScreenProgramChroArea' + '---' + GetErrorMessage(nResult));
end;


procedure TFrm_Main.Button16Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramChroAreaFile
    (spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
    spnedt_curAreaOrd.Value,
    pchar(''), pchar('天'), pchar('小时'), pchar('分钟'), pchar('秒'), pchar('宋体'),
    1, 1, 10, 0, 0, 0,
    255, 255,
    1, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 0,
    2015, 12, 31, 12, 59, 59,
    0);
  mmo1.Lines.Add('AddScreenProgramChroAreaFile' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn_StopClick(Sender: TObject);
begin
  tmr_SendProgram.Enabled := False;
end;

procedure TFrm_Main.tmr_SendProgramTimer(Sender: TObject);
var
  tmpSendThread ,tmpSendThread1,tmpSendThread2    : TSendThread;
  nResult           : Cardinal;
begin
 // while (SendThread = nil) do
  begin
    tmpSendThread := TSendThread.Create(spnedt_ScreenNo.Value, g_nSendMode, edt_FileName.Text);
    tmpSendThread.CallBack:=CallBack;

    {tmpSendThread1 := TSendThread.Create(1, SEND_MODE_NET, edt_FileName.Text);
    tmpSendThread1.CallBack:=CallBack;
    tmpSendThread2 := TSendThread.Create(2, SEND_MODE_NET, edt_FileName.Text);
    tmpSendThread2.CallBack:=CallBack;}
  end;
end;

procedure TFrm_Main.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  //FreeLibrary(hDll);
  DeleteCriticalSection(CS);    
end;

procedure TFrm_Main.btn_1Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendScreenInfo(spnedt_ScreenNo.Value, SEND_CMD_SENDALLPROGRAM, 0);
  mmo1.Lines.Add('SendScreenInfo' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.GetShowResultMsg(var Message: TMessage);
var
  ptmptagSendStatus : PtagSendStatus;
  messagestr        : string;
begin
  ptmptagSendStatus := PtagSendStatus(Message.LParam);
  messagestr := ptmptagSendStatus^.szMessagestr;
  mmo1.Lines.Add(messagestr);
end;

procedure TFrm_Main.btn_TemperatureClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramTemperatureArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value
    , 0, 0, spnedt_Width.Value, spnedt_Height.Value,
    0,
    0,
    0,
    100,
    5,
    0,
    0,
    0,
    0,
    clRed,
    clRed,
    '温度:',
    '宋体',
    12,
    clRed,
    0);
  mmo1.Lines.Add('AddScreenProgramTemperatureArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn_HumidityClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramHumidityArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value
    , 0, 0, spnedt_Width.Value, spnedt_Height.Value,
    0,
    0,
    0,
    100,
    5,
    0,
    0,
    0,
    0,
    clRed,
    clRed,
    '湿度:',
    '宋体',
    12,
    clRed,
    0);
  mmo1.Lines.Add('AddScreenProgramHumidityArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btn_NoiseClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := AddScreenProgramNoiseArea(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value
    , 0, 0, spnedt_Width.Value, spnedt_Height.Value,
    0,
    0,
    0,
    70,
    4,
    0,
    0,
    0,
    0,
    clRed,
    clRed,
    '噪音:',
    '宋体',
    12,
    clRed,
    0);
  mmo1.Lines.Add('AddScreenProgramNoiseArea' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btnBindWirelessDeviceClick(Sender: TObject);
var
  nResult: Cardinal;
  nScreenOrd: Cardinal;
  szmessage, szPrompt: WideString;
  Form:Ttntfm_Check_Transit_DevList;
  TransitBarcode,TransitNetworkId:string;
  Device:string;
  Devicelist:PChar;
  DeviceCount:Integer;
  StringList:TStringList;
  List:TList;
  DeviceInfo:PDeviceInfo;
  I:Integer;
  PosTmp:Integer;
  str:string;
  TransitDeviceType:string;
begin
  if (Trim(edtUserName.Text) = '') or (Trim(edtPassword.Text) = '') then
  begin
    szmessage :='User name and password can not be empty, please set the attributes in the <ONBON server login > and then to perform the operation.';
    szPrompt :='Prompt';
    MessageBoxw(Handle, PWideChar(szmessage), PWideChar(szPrompt), MB_ICONINFORMATION + MB_OK);
    Exit;
  end;

  Devicelist:=stralloc(8192);
  List:=TList.Create();
  try
    if comb_SendMode.ItemIndex = 4 then
      TransitDeviceType := 'BX-3GPRS' //ONBON服务器-GPRS
    else
    if comb_SendMode.ItemIndex = 5 then
      TransitDeviceType := 'BX-3G'; //ONBON服务器-3G

    nResult:=QuerryServerDeviceList(PChar(TransitDeviceType),PChar(edtServerIP.Text), edtServerPort.value,
    PChar(edtUserName.Text), PChar(edtPassword.Text),Devicelist);
    if nResult=0 then begin   //没有错误
      StringList:=SplitString(Devicelist,';');
      for I:=0 to StringList.count-1 do begin
        New(DeviceInfo);

        Device:=StringList.strings[I];
        PosTmp:=Pos(',',Device);
        DeviceInfo.Name:=Copy(Device,1,PosTmp-1);
        Device:=Copy(Device,PosTmp+1,Length(Device)-PosTmp);

        PosTmp:=Pos(',',Device);
        DeviceInfo.BarCode:=Copy(Device,1,PosTmp-1);
        Device:=Copy(Device,PosTmp+1,Length(Device)-PosTmp);

        PosTmp:=Pos(',',Device);
        DeviceInfo.Status:=Copy(Device,1,PosTmp-1);
        Device:=Copy(Device,PosTmp+1,Length(Device)-PosTmp);

        PosTmp:=Pos(',',Device);
        DeviceInfo.TransitType:=Copy(Device,1,PosTmp-1);
        DeviceInfo.NetworkID:=Copy(Device,PosTmp+1,Length(Device)-PosTmp);
        List.Add(DeviceInfo);
      end;
      if not Show_Transit_List(self,List,TransitBarcode,TransitNetworkId) then begin
        Exit;
      end;
      edtTransitBarcode.Text:=TransitBarcode;
      edtTransitNetworkId.Text:=TransitNetworkId;
    end;
  finally
    List.Free;
    strdispose(Devicelist);
  end;
end;

procedure TFrm_Main.rdbFixIPModeClick(Sender: TObject);
begin
  lblNetworkID.Visible:=rdbServerMode.Checked;
  edtNetworkID.Visible:=rdbServerMode.Checked;
  btnStartServer.Visible:=rdbServerMode.Checked;
  btnStopServer.Visible:=rdbServerMode.Checked;
end;

procedure TFrm_Main.Button17Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  if (mmo_Text.Text <> '') then
  begin
    nResult := AddScreenProgramAreaBmpTextText(spnedt_ScreenNo.Value, spnedt_curProgramOrd.Value,
      spnedt_curAreaOrd.Value, PChar(mmo_Text.Text), 0, 0, PChar('宋体'), 14, 0, clYellow, 2, 48, 10);
    mmo1.Lines.Add('AddScreenProgramAreaText' + '---' + GetErrorMessage(nResult));
  end
  else
    ShowMessage('请先添加文本！');
end;

procedure TFrm_Main.btnInitializeClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := Initialize();
  mmo1.Lines.Add('Initialize' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btnUninitializeClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := Uninitialize();
  mmo1.Lines.Add('Uninitialize' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btnStartServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StartServer(g_nSendMode,PChar(edt_IP.Text),spnedt_Port.Value);
  mmo1.Lines.Add('StartServer' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btnStopServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StopServer(g_nSendMode);
  mmo1.Lines.Add('StopServer' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.rdbWifiFixIPModeClick(Sender: TObject);
begin
  lblWifiNetworkID.Visible:=rdbWifiServerMode.Checked;
  edtWifiNetworkID.Visible:=rdbWifiServerMode.Checked;
  btnStartWifiServer.Visible:=rdbWifiServerMode.Checked;
  btnStopWifiServer.Visible:=rdbWifiServerMode.Checked;
end;

procedure TFrm_Main.btnStartWifiServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StartServer(g_nSendMode,PChar(edtWifiIP.Text),spnedtWifiPort.Value);
  mmo1.Lines.Add('StartServer' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.btnStopWifiServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StopServer(g_nSendMode);
  mmo1.Lines.Add('StopServer' + '---' + GetErrorMessage(nResult));
end;

procedure TFrm_Main.Button18Click(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := GetScreenParameter(spnedt_ScreenNo.Value, g_nSendMode, pChar(ExtractFilePath(Application.ExeName) + 'ScreenParameter.ini'));
  mmo1.Lines.Add('GetScreenParameter' + '---' + GetErrorMessage(nResult));
end;

end.

