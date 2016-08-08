unit uMain;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, ToolWin, Spin, ExtCtrls, Buttons, Check_Transit_DevList,
  IdStrings;
const
  CONTROLLER_BX_5E1 = $0154;
  CONTROLLER_BX_5E2 = $0254;
  CONTROLLER_BX_5E3 = $0354;
  Controller_BX_5Q0P = $1056;
  Controller_BX_5Q1P = $1156;
  Controller_BX_5Q2P = $1256;


  CONTROLLER_BX_5E1_INDEX = 0;
  CONTROLLER_BX_5E2_INDEX = 1;
  CONTROLLER_BX_5E3_INDEX = 2;
  CONTROLLER_BX_5Q0P_INDEX = 3;
  CONTROLLER_BX_5Q1P_INDEX = 4;
  CONTROLLER_BX_5Q2P_INDEX = 5;

  FRAME_SINGLE_COLOR_COUNT = 23; //纯色边框图片个数
  FRAME_MULI_COLOR_COUNT = 47; //花色边框图片个数

//------------------------------------------------------------------------------
// 通讯模式
  SEND_MODE_SERIALPORT = 0;
  SEND_MODE_NETWORK = 2;
  SEND_MODE_Server_2G = 5;
  SEND_MODE_Server_3G = 6;
  SEND_MODE_SAVEFILE = 7;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// 动态区域运行模式
  RUN_MODE_CYCLE_SHOW = 0; //动态区数据循环显示；
  RUN_MODE_SHOW_LAST_PAGE = 1; //动态区数据显示完成后静止显示最后一页数据；
  RUN_MODE_SHOW_CYCLE_WAITOUT_NOSHOW = 2; //动态区数据循环显示，超过设定时间后数据仍未更新时不再显示；
  RUN_MODE_SHOW_ORDERPLAYED_NOSHOW = 4; //动态区数据顺序显示，显示完最后一页后就不再显示
//------------------------------------------------------------------------------
//==============================================================================
// 返回状态代码定义
  RETURN_ERROR_NOFIND_DYNAMIC_AREA = $E1; //没有找到有效的动态区域。
  RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD = $E2; //在指定的动态区域没有找到指定的文件序号。
  RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD = $E3; //在指定的动态区域没有找到指定的页序号。
  RETURN_ERROR_NOSUPPORT_FILETYPE = $E4; //不支持该文件类型。
  RETURN_ERROR_RA_SCREENNO = $F8; //已经有该显示屏信息。如要重新设定请先DeleteScreen删除该显示屏再添加；
  RETURN_ERROR_NOFIND_AREA = $FA; //没有找到有效的显示区域；可以使用AddScreenProgramBmpTextArea添加区域信息。
  RETURN_ERROR_NOFIND_SCREENNO = $FC; //系统内没有查找到该显示屏；可以使用AddScreen函数添加显示屏
  RETURN_ERROR_NOW_SENDING = $FD; //系统内正在向该显示屏通讯，请稍后再通讯；
  RETURN_ERROR_OTHER = $FF; //其它错误；
  RETURN_NOERROR    = 0; //没有错误
//==============================================================================

type
  Tfrm_Main = class(TForm)
    grp_DeviceInit: TGroupBox;
    lbl_Screen_Address: TLabel;
    cbb_SendMode: TComboBox;
    Label16: TLabel;
    cbb_ControllerType: TComboBox;
    Label23: TLabel;
    spnedt_Width: TSpinEdit;
    Label24: TLabel;
    spnedt_Height: TSpinEdit;
    lbl_ScreenColor: TLabel;
    cbb_Color: TComboBox;
    lbl_Device_Pixel: TLabel;
    cbb_Pixel: TComboBox;
    pagecontrol_Communction: TPageControl;
    tbsht_SerialPort: TTabSheet;
    tbsht_Network: TTabSheet;
    lbl_ControllerType: TLabel;
    grp_SerialPort: TGroupBox;
    Label18: TLabel;
    cbb_Comm: TComboBox;
    Label19: TLabel;
    cbb_Baud: TComboBox;
    grp_Network: TGroupBox;
    lbl_StaticIP_IP: TLabel;
    edt_StaticIP_IP: TEdit;
    lbl_StaticIP_Port: TLabel;
    spnedt_StaticIP_Port: TSpinEdit;
    spnedt_PNo: TSpinEdit;
    pnl_AddScreen: TPanel;
    btn_AddScreen: TBitBtn;
    btn_DeleteScreen: TButton;
    grp_AddDynamicArea: TGroupBox;
    pnl_AddDynamicArea: TPanel;
    btn_AddDynamicArea: TBitBtn;
    spnedt_DYAreaID: TSpinEdit;
    lbl_DYAreaID: TLabel;
    cbb_RunMode: TComboBox;
    lbl_RunMode: TLabel;
    lbl_TimeOut: TLabel;
    spnedt_TimeOut: TSpinEdit;
    grp_RelatePro: TGroupBox;
    radbtn_AllRelatePro: TRadioButton;
    radbtn_SelRelatePro: TRadioButton;
    edt_RelatePro: TEdit;
    radbtn_NoRelate: TRadioButton;
    lbl_DYAreaX: TLabel;
    spnedt_DYAreaX: TSpinEdit;
    spnedt_DYAreaY: TSpinEdit;
    lbl_DYAreaY: TLabel;
    spnedt_DYAreaW: TSpinEdit;
    lbl_DYAreaW: TLabel;
    lbl_DYAreaH: TLabel;
    spnedt_DYAreaH: TSpinEdit;
    grp_DYAreaF: TGroupBox;
    chk_DYAreaF: TCheckBox;
    radbtn_DYAreaFSingle: TRadioButton;
    lbl_DYAreaFSingle: TLabel;
    spnedt_DYAreaFSingle: TSpinEdit;
    lbl_DYAreaFSingleColor: TLabel;
    spnedt_DYAreaFSingleColor: TSpinEdit;
    radbtn_DYAreaFMuli: TRadioButton;
    lbl_DYAreaFMuli: TLabel;
    spnedt_DYAreaFMuli: TSpinEdit;
    lbl_DYAreaFStunt: TLabel;
    cbb_DYAreaFStunt: TComboBox;
    lbl_DYAreaFRunSpeed: TLabel;
    spnedt_DYAreaFRunSpeed: TSpinEdit;
    spnedt_DYAreaFMoveStep: TSpinEdit;
    lbl_DYAreaFMoveStep: TLabel;
    grp_AddDYAreaFile: TGroupBox;
    pnl_AddDYAreaFile: TPanel;
    btn_UpDateDYArea: TBitBtn;
    btn_DeleteScreenDynamicAreas: TButton;
    grp_DelDYAreaPage: TGroupBox;
    lbl_DYAreaPage: TLabel;
    spnedt_DYAreaPageOrd: TSpinEdit;
    btn_UpdateDYAreaPage: TButton;
    btn_DelDYAreaPage: TButton;
    tbsht_SaveFile: TTabSheet;
    grp_SaveFile: TGroupBox;
    edt_SaveFile: TEdit;
    lbl_SaveFile: TLabel;
    btn_DeleteAllDYArea: TButton;
    dlgOpen_File: TOpenDialog;
    mmo_FunResultInfo: TMemo;
    lbl_PlayPriority: TLabel;
    cbb_PlayPriority: TComboBox;
    tbsht_Server: TTabSheet;
    grpServer: TGroupBox;
    Label17: TLabel;
    Label1: TLabel;
    Label2: TLabel;
    Label20: TLabel;
    edtServerIP: TEdit;
    edtServerPort: TSpinEdit;
    edtUserName: TEdit;
    edtPassword: TEdit;
    rdbServerMode: TRadioButton;
    rdbFixIPMode: TRadioButton;
    lblNetworkID: TLabel;
    edtNetworkID: TEdit;
    Panel1: TPanel;
    PageControl2: TPageControl;
    TabSheet3: TTabSheet;
    Label3: TLabel;
    btn6: TSpeedButton;
    edt_FileName: TEdit;
    btn3: TButton;
    TabSheet4: TTabSheet;
    mmo_Text: TMemo;
    Button17: TButton;
    edtTransitBarcode: TEdit;
    lblTransitBarcode: TLabel;
    lblTransitNetworkId: TLabel;
    edtTransitNetworkId: TEdit;
    btnBindWirelessDevice: TButton;
    GroupBox1: TGroupBox;
    Label14: TLabel;
    spnedt_curlFileOrd: TSpinEdit;
    btn_DelFile: TButton;
    lbl_DYAreaStunt: TLabel;
    lbl_DYAreaRunSpeed: TLabel;
    lbl_ShowTime: TLabel;
    chk_SingleLine: TCheckBox;
    spnedt_DYAreaShowTime: TSpinEdit;
    spnedt_DYAreaRunSpeed: TSpinEdit;
    cbb_DYAreaStunt: TComboBox;
    grp_Initialize: TGroupBox;
    btn_Initialize: TButton;
    grp_Uninitialize: TGroupBox;
    btn_Uninitialize: TButton;
    btnStartServer: TButton;
    btnStopServer: TButton;
    procedure FormCreate(Sender: TObject);
    procedure btn_AddScreenClick(Sender: TObject);
    procedure btn_DeleteScreenClick(Sender: TObject);
    procedure btn_AddDynamicAreaClick(Sender: TObject);
    procedure btn_UpDateDYAreaClick(Sender: TObject);
    procedure btn_DeleteScreenDynamicAreasClick(Sender: TObject);
    procedure btn_UpdateDYAreaPageClick(Sender: TObject);
    procedure btn_DelDYAreaPageClick(Sender: TObject);
    procedure btn_DeleteAllDYAreaClick(Sender: TObject);
    procedure cbb_SendModeChange(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure spnedt_PNoChange(Sender: TObject);
    procedure spnedt_DYAreaIDChange(Sender: TObject);
    procedure btnBindWirelessDeviceClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure rdbFixIPModeClick(Sender: TObject);
    procedure btn6Click(Sender: TObject);
    procedure btn3Click(Sender: TObject);
    procedure Button17Click(Sender: TObject);
    procedure btn_DelFileClick(Sender: TObject);
    procedure btn_InitializeClick(Sender: TObject);
    procedure btn_UninitializeClick(Sender: TObject);
    procedure btnStartServerClick(Sender: TObject);
    procedure btnStopServerClick(Sender: TObject);
  private
    { Private declarations }
    function GetFun_Result_Info(nResult: Cardinal): string;
    procedure GetcurGrpCaption;
  public
    { Public declarations }
  end;

var
  frm_Main          : Tfrm_Main;
  hDll              : THandle;
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
  过程名:    AddScreen_Dynamic
  向动态库中添加显示屏信息；该函数不与显示屏通讯。
  参数:
    nControlType:显示屏的控制器型号，目前该动态区域动态库只支持BX-5E1、BX-5E2、BX-5E3等BX-5E系列和5Q+系列控制器。
    nScreenNo：显示屏屏号；该参数与LedshowTW 2013软件中"设置屏参"模块的"屏号"参数一致。
    nSendMode：通讯模式；目前动态库中支持0:串口通讯；2：网络通讯(只支持固定IP模式)；5：ONBON服务器-GPRS 6：ONBON服务器-3G 7：保存到文件等三种通讯模式。
    nWidth：显示屏宽度；单位：像素。
    nHeight：显示屏高度；单位：像素。
    nScreenType：显示屏类型；1：单基色；2：双基色; 3:双基色 4:全彩色 5:双基色灰度。
    nPixelMode：点阵类型，只有显示屏类型为双基色时有效；1：R+G；2：G+R。
    pCom：通讯串口，只有在串口通讯时该参数有效；例："COM1"
    nBaud：通讯串口波特率，只有在串口通讯时该参数有效；目前只支持9600、57600两种波特率。
    pSocketIP：控制器的IP地址；只有在网络通讯(固定IP模式)模式下该参数有效，例："192.168.0.199"
    nSocketPort：控制器的端口地址；只有在网络通讯(固定IP模式)模式下该参数有效，例：5005
    nStaticIPMode   :固定IP通讯模式：0：TCP模式 1：UDP模式
    nServerMode     :0:服务器模式未启动；1：服务器模式启动。
    pBarcode        :设备条形码，用于服务器模式和中转服务器
    pNetworkID      :网络ID编号，用于服务器模式和中转服务器
    pServerIP       :中转服务器IP地址
    nServerPort     :中转服务器网络端口
    pServerAccessUser:中转服务器访问用户名
    pServerAccessPassword:中转服务器访问密码
    pCommandDataFile：保存到文件方式时，命令保存命令文件名称。只有在保存到文件模式下该参数有效，例："curCommandData.dat"
  返回值:    详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreen_Dynamic         :function(nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode: Integer;
    pCom: PChar; nBaud: Integer; pSocketIP: PChar; nSocketPort: Integer; nStaticIPMode:Integer; nServerMode: Integer; pBarcode: PChar;
    pNetworkID:PChar; pServerIP: PChar; nServerPort: Integer; pServerAccessUser: PChar; pServerAccessPassword: PChar;
    pCommandDataFile: pChar): integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    AddScreenDynamicArea
  向动态库中指定显示屏添加动态区域；该函数不与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；目前系统中最多5个动态区域；该值取值范围为0~4;
    nRunMode：动态区域运行模式：
              0:动态区数据循环显示；
              1:动态区数据显示完成后静止显示最后一页数据；
              2:动态区数据循环显示，超过设定时间后数据仍未更新时不再显示；
              4:动态区数据顺序显示，显示完最后一页后就不再显示
    nTimeOut：动态区数据超时时间；单位：秒
    nAllProRelate：节目关联标志；
              1：所有节目都显示该动态区域；
              0：在指定节目中显示该动态区域，如果动态区域要独立于节目显示，则下一个参数为空。
    pProRelateList：节目关联列表，用节目编号表示；节目编号间用","隔开,节目编号定义为LedshowTW 2013软件中"P***"中的"***"
    nPlayPriority：动态区域播放优先级；
              0：该动态区域与异步节目一起播放(动态区域有关联异步节目才有效)；
              1：异步节目停止播放，仅播放该动态区域
    nAreaX：动态区域起始横坐标；单位：像素
    nAreaY：动态区域起始纵坐标；单位：像素
    nAreaWidth：动态区域宽度；单位：像素
    nAreaHeight：动态区域高度；单位：像素
    nAreaFMode：动态区域边框显示标志；0：纯色；1：花色；255：无边框
    nAreaFLine：动态区域边框类型, 纯色最大取值为FRAME_SINGLE_COLOR_COUNT；花色最大取值为：FRAME_MULI_COLOR_COUNT
    nAreaFColor：边框显示颜色；选择为纯色边框类型时该参数有效；
    nAreaFStunt：边框运行特技；
              0：闪烁；1：顺时针转动；2：逆时针转动；3：闪烁加顺时针转动；
              4:闪烁加逆时针转动；5：红绿交替闪烁；6：红绿交替转动；7：静止打出
    nAreaFRunSpeed：边框运行速度；
    nAreaFMoveStep：边框移动步长；该值取值范围：1~8；
  返回值:    详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenDynamicArea:
    function(nScreenNo, nDYAreaID: Integer; nRunMode: Integer;
    nTimeOut, nAllProRelate: Integer; pProRelateList: PChar; nPlayPriority: Integer;
    nAreaX, nAreaY, nAreaWidth, nAreaHeight: Integer; nAreaFMode, nAreaFLine, nAreaFColor,
    nAreaFStunt, nAreaFRunSpeed, nAreaFMoveStep: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenDynamicAreaText
  向动态库中指定显示屏的指定动态区域添加信息文件；该函数不与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    pText：添加的信息文本
    nShowSingle：文字信息是否单行显示；0：多行显示；1：单行显示；显示该参数只有szFileName为txt格式文档时才有效；
    pFontName：文字信息显示字体；该参数只有szFileName为txt格式文档时才有效；
    nFontSize：文字信息显示字体的字号；该参数只有szFileName为txt格式文档时才有效；
    nBold：文字信息是否粗体显示；0：正常；1：粗体显示；该参数只有szFileName为txt格式文档时才有效；
    nFontColor：文字信息显示颜色；该参数只有szFileName为txt格式文档时才有效；
    nStunt：动态区域信息运行特技；
              00：随机显示
              01：静止显示
              02：快速打出
              03：向左移动
              04：向左连移
              05：向上移动
              06：向上连移
              07：闪烁
              08：飘雪
              09：冒泡
              10：中间移出
              11：左右移入
              12：左右交叉移入
              13：上下交叉移入
              14：画卷闭合
              15：画卷打开
              16：向左拉伸
              17：向右拉伸
              18：向上拉伸
              19：向下拉伸
              20：向左镭射
              21：向右镭射
              22：向上镭射
              23：向下镭射
              24：左右交叉拉幕
              25：上下交叉拉幕
              26：分散左拉
              27：水平百页
              28：垂直百页
              29：向左拉幕
              30：向右拉幕
              31：向上拉幕
              32：向下拉幕
              33：左右闭合
              34：左右对开
              35：上下闭合
              36：上下对开
              37：向右移动
              38：向右连移
              39：向下移动
              40：向下连移
    nRunSpeed：动态区域信息运行速度
    nShowTime：动态区域信息显示时间；单位：10ms
  返回值:    详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenDynamicAreaText:
    function(nScreenNo, nDYAreaID: Integer;
    pText: PChar; nShowSingle: integer; pFontName: PChar; nFontSize, nBold, nFontColor: Integer;
    nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  过程名:    AddScreenDynamicAreaFile
  向动态库中指定显示屏的指定动态区域添加信息文件；该函数不与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    pFileName：添加的信息文件名称；目前只支持txt(支持ANSI、UTF-8、Unicode等格式编码)、bmp的文件格式
    nShowSingle：文字信息是否单行显示；0：多行显示；1：单行显示；显示该参数只有szFileName为txt格式文档时才有效；
    pFontName：文字信息显示字体；该参数只有szFileName为txt格式文档时才有效；
    nFontSize：文字信息显示字体的字号；该参数只有szFileName为txt格式文档时才有效；
    nBold：文字信息是否粗体显示；0：正常；1：粗体显示；该参数只有szFileName为txt格式文档时才有效；
    nFontColor：文字信息显示颜色；该参数只有szFileName为txt格式文档时才有效；
    nStunt：动态区域信息运行特技；
              00：随机显示
              01：静止显示
              02：快速打出
              03：向左移动
              04：向左连移
              05：向上移动
              06：向上连移
              07：闪烁
              08：飘雪
              09：冒泡
              10：中间移出
              11：左右移入
              12：左右交叉移入
              13：上下交叉移入
              14：画卷闭合
              15：画卷打开
              16：向左拉伸
              17：向右拉伸
              18：向上拉伸
              19：向下拉伸
              20：向左镭射
              21：向右镭射
              22：向上镭射
              23：向下镭射
              24：左右交叉拉幕
              25：上下交叉拉幕
              26：分散左拉
              27：水平百页
              28：垂直百页
              29：向左拉幕
              30：向右拉幕
              31：向上拉幕
              32：向下拉幕
              33：左右闭合
              34：左右对开
              35：上下闭合
              36：上下对开
              37：向右移动
              38：向右连移
              39：向下移动
              40：向下连移
    nRunSpeed：动态区域信息运行速度
    nShowTime：动态区域信息显示时间；单位：10ms
  返回值:    详见返回状态代码定义。
-------------------------------------------------------------------------------}
  AddScreenDynamicAreaFile:
    function(nScreenNo, nDYAreaID: Integer;
    pFileName: PChar; nShowSingle: integer; pFontName: PChar; nFontSize, nBold, nFontColor: Integer;
    nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    DeleteScreen_Dynamic
  删除动态库中指定显示屏的所有信息；该函数不与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  DeleteScreen_Dynamic      :
    function(nScreenNo: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    DeleteScreenDynamicAreaFile
  删除动态库中指定显示屏指定的动态区域指定文件信息；该函数不与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    nFileOrd：动态区域的指定文件的文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  DeleteScreenDynamicAreaFile:
    function(nScreenNo, nDYAreaID, nFileOrd: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    SendDynamicAreaInfoCommand
  发送动态库中指定显示屏指定的动态区域信息到显示屏；该函数与显示屏通讯。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  SendDynamicAreaInfoCommand:
    function(nScreenNo, nDYAreaID: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    SendDeleteDynamicAreasCommand
  删除动态库中指定显示屏指定的动态区域信息；同时向显示屏通讯删除指定的动态区域信息。该函数与显示屏通讯
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    pDYAreaIDList：动态区域编号列表；如果同时删除多个动态区域，动态区域编号间用","隔开。如"0,1"
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  SendDeleteDynamicAreasCommand:
    function(nScreenNo, nDelAllDYArea: Integer; pDYAreaIDList: PChar): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    SendUpdateDynamicAreaPageInfoCommand
  向动态库中指定显示屏指定的动态区域单独更新指定的数据页信息；该函数与显示屏通讯
  该函数使用时，必须能明确好当前预更新信息在显示屏中的显示页码，否则可能更新出错。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    nFileOrd：动态区域的指定文件的文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
    nPageOrd：预更新数据页的页序号。从0开始顺序递增。
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  SendUpdateDynamicAreaPageInfoCommand:
    function(nScreenNo, nDYAreaID, nFileOrd, nPageOrd: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    SendDeleteDynamicAreaPageCommand
  删除动态库中指定显示屏的指定动态区域指定的数据页信息；该函数与显示屏通讯
  该函数使用时，必须能明确好当前预删除数据页信息在显示屏中的显示页码，否则可能删除出错。
  参数:
    nScreenNo：显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nDYAreaID：动态区域编号；该参数与AddScreenDynamicArea函数中的nDYAreaID参数对应
    pDYAreaPageOrdList：预删除动态区域数据页序号列表；如果同时删除多个数据页信息，数据页序号间用","隔开。如"0,1"；
              删除数据页信息执行成功后，后面的数据页信息的数据页序号自动向前对齐。
  返回值:    详见返回状态代码定义
-------------------------------------------------------------------------------}
  SendDeleteDynamicAreaPageCommand:
    function(nScreenNo, nDYAreaID: Integer; pDYAreaPageOrdList: PChar): Integer; stdcall;

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
    pDeviceCount      : 查询的设备个数

  返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
  QuerryServerDeviceList : function(pTransitDeviceType: PChar;pServerIP: PChar; nServerPort: Integer;
  pServerAccessUser: PChar; pServerAccessPassword: PChar;pDeviceList:PChar;var nDeviceCount:Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  过程名:    StartServer
  启动服务器,用于网络模式下的服务器模式和GPRS通讯模式。
  参数:
    nSendMode       :与显示屏的通讯模式；
      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
      2:网络模式
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
      2:网络模式
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

procedure Tfrm_Main.FormCreate(Sender: TObject);
begin
  hDll := LoadLibrary('LedDynamicArea.dll');
  if hDll < 32 then
    Exit; //如果Dll无法加载则跳出

  Initialize := GetProcAddress(hDll, 'Initialize');
  Uninitialize := GetProcAddress(hDll, 'Uninitialize');

  AddScreen_Dynamic := GetProcAddress(hDll, 'AddScreen_Dynamic');
  AddScreenDynamicArea := GetProcAddress(hDll, 'AddScreenDynamicArea');
  AddScreenDynamicAreaText := GetProcAddress(hDll, 'AddScreenDynamicAreaText');
  AddScreenDynamicAreaFile := GetProcAddress(hDll, 'AddScreenDynamicAreaFile');

  DeleteScreen_Dynamic := GetProcAddress(hDll, 'DeleteScreen_Dynamic');
  DeleteScreenDynamicAreaFile := GetProcAddress(hDll, 'DeleteScreenDynamicAreaFile');
  SendDynamicAreaInfoCommand := GetProcAddress(hDll, 'SendDynamicAreaInfoCommand');
  SendDeleteDynamicAreasCommand := GetProcAddress(hDll, 'SendDeleteDynamicAreasCommand');
  SendUpdateDynamicAreaPageInfoCommand := GetProcAddress(hDll, 'SendUpdateDynamicAreaPageInfoCommand');
  SendDeleteDynamicAreaPageCommand := GetProcAddress(hDll, 'SendDeleteDynamicAreaPageCommand');

  QuerryServerDeviceList := GetProcAddress(hDll, 'QuerryServerDeviceList');
  StartServer := GetProcAddress(hDll, 'StartServer');
  StopServer := GetProcAddress(hDll, 'StopServer');

  spnedt_DYAreaFSingle.MaxValue := FRAME_SINGLE_COLOR_COUNT - 1;
  spnedt_DYAreaFMuli.MaxValue := FRAME_MULI_COLOR_COUNT - 1;
  edt_SaveFile.Text := ExtractFilePath(Application.ExeName) + edt_SaveFile.Text;
  InitializeCriticalSection(CS);
end;

procedure Tfrm_Main.btn_AddScreenClick(Sender: TObject);
var
  nControlType, nSendMode,nServerMode: Cardinal;
  nResult           : Cardinal;
  nScreenType : Cardinal;
  Barcode,NetworkID:string;
begin
  case cbb_ControllerType.ItemIndex of
    CONTROLLER_BX_5E1_INDEX: nControlType := CONTROLLER_BX_5E1;
    CONTROLLER_BX_5E2_INDEX: nControlType := CONTROLLER_BX_5E2;
    CONTROLLER_BX_5E3_INDEX: nControlType := CONTROLLER_BX_5E3;
    CONTROLLER_BX_5Q0P_INDEX: nControlType := Controller_BX_5Q0P;
    CONTROLLER_BX_5Q1P_INDEX: nControlType := Controller_BX_5Q1P;
    CONTROLLER_BX_5Q2P_INDEX: nControlType := Controller_BX_5Q2P;
  end;
  case cbb_SendMode.ItemIndex of
    0:
      begin
        nSendMode := SEND_MODE_SERIALPORT;
      end;
    1:
      begin
        nSendMode := SEND_MODE_NETWORK;
      end;
    2:
      begin
        nSendMode := SEND_MODE_Server_2G;
      end;
    3:
      begin
        nSendMode := SEND_MODE_Server_3G;
      end;
    4:
      begin
        nSendMode := SEND_MODE_SAVEFILE;
      end;
  end;
  case cbb_Color.ItemIndex of
    0:
      begin
        nScreenType := 1;
      end;
    1:
      begin
        nScreenType := 2;
      end;
    2:
      begin
        nScreenType := 4;
      end;
  end;
  if rdbServerMode.Checked then begin
    nServerMode:=1;
  end
  else begin
    nServerMode:=0;
  end;
  if (nSendMode=SEND_MODE_Server_2G) or (nSendMode=SEND_MODE_Server_3G) then begin
    Barcode:=edtTransitBarcode.Text;
    NetworkID:=edtTransitNetworkId.Text;
  end
  else if (nSendMode=SEND_MODE_NETWORK) then begin
    Barcode:='';
    NetworkID:=edtNetworkID.Text;
  end
  else begin
    Barcode:='';
    NetworkID:='';
  end;
  nResult := AddScreen_Dynamic(nControlType, spnedt_PNo.Value, nSendMode, spnedt_Width.Value, spnedt_Height.Value
    , nScreenType, cbb_Pixel.ItemIndex + 1, PChar(cbb_Comm.Items[cbb_Comm.ItemIndex]), StrToInt(cbb_Baud.Items[cbb_Baud.ItemIndex])
    , PChar(edt_StaticIP_IP.Text), spnedt_StaticIP_Port.Value, 0, nServerMode, PChar(Barcode), PChar(NetworkID), PChar(edtServerIP.Text)
    , edtServerPort.value, PChar(edtUserName.Text), PChar(edtPassword.Text), PChar(edt_SaveFile.Text));
  mmo_FunResultInfo.Lines.Add('执行AddScreen函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteScreenClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreen_Dynamic(spnedt_PNo.Value);
  mmo_FunResultInfo.Lines.Add('执行DeleteScreen函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_AddDynamicAreaClick(Sender: TObject);
var
  szProRelateList   : string;
  nAllProRelate     : Cardinal;
  nPlayPriority, nAreaFMode, nAreaFLine: Cardinal;
  nResult           : Cardinal;
  nRunMode          : Cardinal;
begin
  if radbtn_AllRelatePro.Checked = True then
  begin
    nAllProRelate := 1;
    szProRelateList := '';
  end
  else
  begin
    nAllProRelate := 0;
    if radbtn_NoRelate.Checked = True then
      szProRelateList := ''
    else
      szProRelateList := edt_RelatePro.Text;
  end;
  nPlayPriority := cbb_PlayPriority.ItemIndex;
  if chk_DYAreaF.Checked = True then
  begin
    if radbtn_DYAreaFSingle.Checked = True then
    begin
      nAreaFMode := 0;
      nAreaFLine := spnedt_DYAreaFSingle.Value;
    end
    else
    begin
      nAreaFMode := 1;
      nAreaFLine := spnedt_DYAreaFMuli.Value;
    end;
  end
  else
  begin
    nAreaFMode := 255;
    nAreaFLine := 0;
  end;
  case cbb_RunMode.ItemIndex of
    0: nRunMode := RUN_MODE_CYCLE_SHOW;
    1: nRunMode := RUN_MODE_SHOW_LAST_PAGE;
    2: nRunMode := RUN_MODE_SHOW_CYCLE_WAITOUT_NOSHOW;
    3: nRunMode := RUN_MODE_SHOW_ORDERPLAYED_NOSHOW;
  end;
  nResult := AddScreenDynamicArea(spnedt_PNo.Value, spnedt_DYAreaID.Value, nRunMode
    , spnedt_TimeOut.Value, nAllProRelate, PChar(szProRelateList), nPlayPriority
    , spnedt_DYAreaX.Value, spnedt_DYAreaY.Value, spnedt_DYAreaW.Value, spnedt_DYAreaH.Value
    , nAreaFMode, nAreaFLine, spnedt_DYAreaFSingleColor.Value
    , cbb_DYAreaFStunt.ItemIndex, spnedt_DYAreaFRunSpeed.Value, spnedt_DYAreaFMoveStep.Value);
  mmo_FunResultInfo.Lines.Add('执行AddScreenDynamicArea函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_UpDateDYAreaClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendDynamicAreaInfoCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value);
  mmo_FunResultInfo.Lines.Add('执行SendDynamicAreaInfoCommand函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteScreenDynamicAreasClick(Sender: TObject);
var
  szDYAreaIDList    : string;
  nResult           : Cardinal;
begin
  szDYAreaIDList := IntToStr(spnedt_DYAreaID.Value); //如果删除多个动态区域，动态区域编号间用","隔开。
  nResult := SendDeleteDynamicAreasCommand(spnedt_PNo.Value, 0
    , pChar(szDYAreaIDList));
  mmo_FunResultInfo.Lines.Add('执行SendDeleteDynamicAreasCommand函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteAllDYAreaClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendDeleteDynamicAreasCommand(spnedt_PNo.Value, 1, '');
  mmo_FunResultInfo.Lines.Add('执行SendDeleteDynamicAreasCommand函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_UpdateDYAreaPageClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendUpdateDynamicAreaPageInfoCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value, spnedt_curlFileOrd.Value, spnedt_DYAreaPageOrd.Value);
  mmo_FunResultInfo.Lines.Add('执行SendUpdateDynamicAreaPageInfoCommand函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DelDYAreaPageClick(Sender: TObject);
var
  szDYAreaPageOrdList: string;
  nResult           : Cardinal;
begin
//如果删除当前动态区域多页数据，页序号间用","隔开。
  szDYAreaPageOrdList := IntToStr(spnedt_DYAreaPageOrd.Value);
  nResult := SendDeleteDynamicAreaPageCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value, pChar(szDYAreaPageOrdList));
  mmo_FunResultInfo.Lines.Add('执行SendDeleteDynamicAreaPageCommand函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.cbb_SendModeChange(Sender: TObject);
begin
  case cbb_SendMode.ItemIndex of
    0:
      begin
        pagecontrol_Communction.ActivePage := tbsht_SerialPort;
      end;
    1:
      begin
        pagecontrol_Communction.ActivePage := tbsht_Network;
      end;
    2,3:
      begin
        pagecontrol_Communction.ActivePage := tbsht_Server;
      end;
    4:
      begin
        pagecontrol_Communction.ActivePage := tbsht_SaveFile;
      end;
  end;
  btnBindWirelessDevice.Visible:=(cbb_SendMode.ItemIndex=2)or(cbb_SendMode.ItemIndex=3);
  lblTransitBarcode.Visible:=(cbb_SendMode.ItemIndex=2)or(cbb_SendMode.ItemIndex=3);
  edtTransitBarcode.Visible:=(cbb_SendMode.ItemIndex=2)or(cbb_SendMode.ItemIndex=3);
  lblTransitNetworkId.Visible:=(cbb_SendMode.ItemIndex=3);
  edtTransitNetworkId.Visible:=(cbb_SendMode.ItemIndex=3);
end;

function Tfrm_Main.GetFun_Result_Info(nResult: Cardinal): string;
begin
  case nResult of
    RETURN_ERROR_NOFIND_DYNAMIC_AREA: result := '没有找到有效的动态区域。';
    RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD: result := '在指定的动态区域没有找到指定的文件序号。';
    RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD: result := '在指定的动态区域没有找到指定的页序号。';
    RETURN_ERROR_NOSUPPORT_FILETYPE: result := '(动态库不支持该文件类型。';
    RETURN_ERROR_RA_SCREENNO: result := '系统中已经有该显示屏信息。如要重新设定请先执行DeleteScreen函数删除该显示屏后再添加。';
    RETURN_ERROR_NOFIND_AREA: result := '系统中没有找到有效的动态区域；可以先执行AddScreenDynamicArea函数添加动态区域信息后再添加。';
    RETURN_ERROR_NOFIND_SCREENNO: result := '系统内没有查找到该显示屏；可以使用AddScreen函数添加该显示屏。';
    RETURN_ERROR_NOW_SENDING: result := '系统内正在向该显示屏通讯，请稍后再通讯。';
    RETURN_ERROR_OTHER: result := '其它错误。';
    RETURN_NOERROR: result := '函数执行成功。';
    $01..$18, $FE:
      Result := Result + '通讯错误';
  else //ERRR_OTHER  Other Error;
    Result := Result + '其它错误。';
  end;
end;

procedure Tfrm_Main.FormShow(Sender: TObject);
begin
  GetcurGrpCaption;
end;

procedure Tfrm_Main.GetcurGrpCaption;
begin
  grp_AddDynamicArea.Caption := grp_AddDynamicArea.Caption + '(屏号：' + IntToStr(spnedt_PNo.Value) + ')';
  grp_AddDYAreaFile.Caption := grp_AddDYAreaFile.Caption + '(屏号：' + IntToStr(spnedt_PNo.Value)
    + '；动态区域编号：' + IntToStr(spnedt_DYAreaID.Value) + ')';
end;

procedure Tfrm_Main.spnedt_PNoChange(Sender: TObject);
begin
  GetcurGrpCaption;
end;

procedure Tfrm_Main.spnedt_DYAreaIDChange(Sender: TObject);
begin
  GetcurGrpCaption;
end;

procedure Tfrm_Main.btnBindWirelessDeviceClick(Sender: TObject);
var
  nResult: Cardinal;
  nScreenOrd: Cardinal;
  szmessage, szPrompt: WideString;
  Form:Tfm_Check_Transit_DevList;
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
    if cbb_SendMode.ItemIndex = 2 then
      TransitDeviceType := 'BX-3GPRS' //ONBON服务器-GPRS
    else
    if cbb_SendMode.ItemIndex = 3 then
      TransitDeviceType := 'BX-3G'; //ONBON服务器-3G

    nResult:=QuerryServerDeviceList(PChar(TransitDeviceType),PChar(edtServerIP.Text), edtServerPort.value,
    PChar(edtUserName.Text), PChar(edtPassword.Text),Devicelist,DeviceCount);
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

procedure Tfrm_Main.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  //FreeLibrary(hDll);
  DeleteCriticalSection(CS);
end;

procedure Tfrm_Main.rdbFixIPModeClick(Sender: TObject);
begin
  lblNetworkID.Visible:=rdbServerMode.Checked;
  edtNetworkID.Visible:=rdbServerMode.Checked;
  btnStartServer.Visible:=rdbServerMode.Checked;
  btnStopServer.Visible:=rdbServerMode.Checked;
end;

procedure Tfrm_Main.btn6Click(Sender: TObject);
begin
  dlgOpen_File.Filter := 'All Support Formats(*.bmp;*.txt)|*.bmp;*.txt';
  if dlgOpen_File.Execute then
  begin
    edt_FileName.Text := dlgOpen_File.FileName;
  end;
end;

procedure Tfrm_Main.btn3Click(Sender: TObject);
var
  nSingleLine       : Cardinal;
  nResult           : Cardinal;
begin
  if chk_SingleLine.Checked = True then
    nSingleLine := 1
  else
    nSingleLine := 0;
  if (edt_FileName.Text <> '') then
  begin
    if (FileExists(edt_FileName.Text)) then
    begin
      nResult := AddScreenDynamicAreaFile(spnedt_PNo.Value, spnedt_DYAreaID.Value
      , PChar(edt_FileName.Text), nSingleLine, PChar('宋体'), 12, 0, clRed
      , cbb_DYAreaStunt.ItemIndex, spnedt_DYAreaRunSpeed.Value, spnedt_DYAreaShowTime.Value);
      mmo_FunResultInfo.Lines.Add('执行AddScreenDynamicAreaFile函数, ' + GetFun_Result_Info(nResult));
    end
    else
      ShowMessage('没有查找到有效的文件！');
  end
  else
    ShowMessage('请先添加有效的文件！');
end;

procedure Tfrm_Main.Button17Click(Sender: TObject);
var
  nSingleLine       : Cardinal;
  nResult           : Cardinal;
begin
  if chk_SingleLine.Checked = True then
    nSingleLine := 1
  else
    nSingleLine := 0;
  if (mmo_Text.Text <> '') then
  begin
    nResult := AddScreenDynamicAreaText(spnedt_PNo.Value, spnedt_DYAreaID.Value
      , PChar(mmo_Text.Text), nSingleLine, PChar('宋体'), 12, 0, clRed
      , cbb_DYAreaStunt.ItemIndex, spnedt_DYAreaRunSpeed.Value, spnedt_DYAreaShowTime.Value);
    mmo_FunResultInfo.Lines.Add('执行AddScreenDynamicAreaText函数, ' + GetFun_Result_Info(nResult));
  end
  else
    ShowMessage('请先添加文本！');
end;

procedure Tfrm_Main.btn_DelFileClick(Sender: TObject);
var
  nFileOrd          : Cardinal;
  nResult           : Cardinal;
begin
  nFileOrd := spnedt_curlFileOrd.Value;
  nResult := DeleteScreenDynamicAreaFile(spnedt_PNo.Value, spnedt_DYAreaID.Value
    , nFileOrd);
  mmo_FunResultInfo.Lines.Add('执行DeleteScreenDynamicAreaFile函数, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_InitializeClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := Initialize();
  mmo_FunResultInfo.Lines.Add('Initialize' + '---' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_UninitializeClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := Uninitialize();
  mmo_FunResultInfo.Lines.Add('Uninitialize' + '---' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btnStartServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StartServer(SEND_MODE_NETWORK,PChar(edt_StaticIP_IP.Text),spnedt_StaticIP_Port.Value);
  mmo_FunResultInfo.Lines.Add('StartServer' + '---' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btnStopServerClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult:=StopServer(SEND_MODE_NETWORK);
  mmo_FunResultInfo.Lines.Add('StopServer' + '---' + GetFun_Result_Info(nResult));
end;

end.

