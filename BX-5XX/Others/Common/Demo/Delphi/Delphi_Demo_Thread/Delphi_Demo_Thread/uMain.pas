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
// �û�������Ϣ�����
  SEND_CMD_PARAMETER = $A1FF; //������������
  SEND_CMD_SCREENSCAN = $A1FE; //����ɨ�跽ʽ��
  SEND_CMD_SENDALLPROGRAM = $A1F0; //�������н�Ŀ��Ϣ��
  SEND_CMD_POWERON  = $A2FF; //ǿ�ƿ���
  SEND_CMD_POWEROFF = $A2FE; //ǿ�ƹػ�
  SEND_CMD_TIMERPOWERONOFF = $A2FD; //��ʱ���ػ�
  SEND_CMD_CANCEL_TIMERPOWERONOFF = $A2FC; //ȡ����ʱ���ػ�
  SEND_CMD_RESIVETIME = $A2FB; //У��ʱ�䡣
  SEND_CMD_ADJUSTLIGHT = $A2FA; //���ȵ�����


//==============================================================================
//==============================================================================
// ������ͨѶģʽ
  SEND_MODE_COMM    = 0;
  SEND_MODE_GPRS    = 1;
  SEND_MODE_NET     = 2;
  SEND_MODE_WIFI    = 4;
  SEND_MODE_Server_2G = 5;
  SEND_MODE_Server_3G = 6;
  SEND_MODE_RF      = 7;
//==============================================================================
//==============================================================================
// ͨѶ���󷵻ش���ֵ
  RETURN_ERROR_NOSUPPORT_USB = $F6; //��֧��USBģʽ��
  RETURN_ERROR_NO_USB_DISK = $F5; //�Ҳ���usb�豸·����
  RETURN_ERROR_AERETYPE = $F7; //�������ʹ��������ͼ�������ļ�ʱ�������ͳ����ش����ʹ���
  RETURN_ERROR_RA_SCREENNO = $F8; //�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ������ӣ�
  RETURN_ERROR_NOFIND_AREAFILE = $F9; //û���ҵ���Ч�������ļ�(ͼ������)��
  RETURN_ERROR_NOFIND_AREA = $FA; //û���ҵ���Ч����ʾ���򣻿���ʹ��AddScreenProgramBmpTextArea���������Ϣ��
  RETURN_ERROR_NOFIND_PROGRAM = $FB; //û���ҵ���Ч����ʾ����Ŀ������ʹ��AddScreenProgram�������ָ����Ŀ
  RETURN_ERROR_NOFIND_SCREENNO = $FC; //ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen���������ʾ��
  RETURN_ERROR_NOW_SENDING = $FD; //ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��
  RETURN_ERROR_OTHER = $FF; //��������
  RETURN_NOERROR    = 0; //û�д���

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
// �����������б����
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
// ����������
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
  tagSendStatus = packed record //���ͽ�Ŀ
    szMessagestr: string; //����״̬��ʾ�ַ���
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
    function GetScreenControlTypeValue(nControlTypeIndex: Cardinal): Cardinal; //���ݿ������б���ŵõ�����������ֵ��
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
  m_bSendBusy       : Boolean; //�˱��������ݸ����зǳ���Ҫ������ر�����
  CS                : TRTLCriticalSection;

{-------------------------------------------------------------------------------
  ������:    Initialize
  ��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
  ����:
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  Initialize         :function(): integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    Uninitialize
  �ͷŶ�̬�⣻�ú���������ʾ��ͨѶ��
  ����:
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  Uninitialize         :function(): integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreen
  ��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
  ����:
    nControlType    :��ʾ���Ŀ������ͺţ�����궨�塰�������ͺŶ��塱
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

    nScreenNo       :��ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      1:GPRSģʽ
      2:����ģʽ
      4:WiFiģʽ
      5:ONBON������-GPRS
      6:ONBON������-3G
    nWidth          :��ʾ����� 16������������С64��BX-5Eϵ����СΪ80
    nHeight         :��ʾ���߶� 16������������С16��
    nScreenType     :��ʾ�����ͣ�1������ɫ��2��˫��ɫ��
      3��˫��ɫ��ע�⣺����ʾ������ֻ��BX-4MC֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
      4��ȫ��ɫ��ע�⣺����ʾ������ֻ��BX-5Qϵ��֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
      5��˫��ɫ�Ҷȣ�ע�⣺����ʾ������ֻ��BX-5QS֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
    nPixelMode      :�������ͣ�1��R+G��2��G+R���ò���ֻ��˫��ɫ����Ч ��Ĭ��Ϊ2��
    nDataDA         :���ݼ��ԣ���0x00�����ݵ���Ч��0x01�����ݸ���Ч��Ĭ��Ϊ0��
    nDataOE         :OE���ԣ�  0x00��OE ����Ч��0x01��OE ����Ч��Ĭ��Ϊ0��
    nRowOrder       :����ģʽ��0��������1����1�У�2����1�У�Ĭ��Ϊ0��
    nDataFlow       :��������0��������1������2������U�ͣ�3������u�ͣ�Ĭ��Ϊ0��
    nFreqPar        :ɨ���Ƶ��0~6��Ĭ��Ϊ0��
    pCom            :�������ƣ�����ͨѶģʽʱ��Ч����:COM1
    nBaud           :���ڲ����ʣ�Ŀǰ֧��9600��57600��Ĭ��Ϊ57600��
    pSocketIP       :���ƿ�IP��ַ������ͨѶģʽʱ��Ч����:192.168.0.199��
      ����̬������ͨѶģʽʱֻ֧�̶ֹ�IPģʽ������ֱ�������������ģʽ��֧�֡�
    nSocketPort     :���ƿ�����˿ڣ�����ͨѶģʽʱ��Ч������5005
    nStaticIPMode   :�̶�IPͨѶģʽ��0��TCPģʽ 1��UDPģʽ
    nServerMode     :0:������ģʽδ������1��������ģʽ������
    pBarcode        :�豸������
    pNetworkID      :����ID���
    pServerIP       :��ת������IP��ַ
    nServerPort     :��ת����������˿�
    pServerAccessUser:��ת�����������û���
    pServerAccessPassword:��ת��������������
    pWiFiIP         :������WiFiģʽ��IP��ַ��Ϣ��WiFiͨѶģʽʱ��Ч����:192.168.100.1
    nWiFiPort       :���ƿ�WiFi�˿ڣ�WiFiͨѶģʽʱ��Ч������5005
    pGprsIP         :GPRS������IP��ַ
    nGprsPort       :GPRS�������˿�
    pGprsID         :GPRS���
    pScreenStatusFile:���ڱ����ѯ������ʾ��״̬���������INI�ļ�����
      ֻ��ִ�в�ѯ��ʾ��״̬GetScreenStatusʱ���ò�������Ч
    pCallBack :���ط��͵���Ϣ�ͽ���
                       ����Ϊ TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreen         : function(nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode: Integer;
    nDataDA, nDataOE: Integer; nRowOrder, nDataFlow, nFreqPar: Integer; pCom: PChar; nBaud: Integer; pSocketIP: PChar;
    nSocketPort: Integer; nStaticIPMode:Integer; nServerMode: Integer; pBarcode: PChar; pNetworkID: PChar; pServerIP: PChar; nServerPort: Integer;
    pServerAccessUser: PChar; pServerAccessPassword: PChar; pWiFiIP: PChar; nWiFiPort: Integer;
    pGprsIP: PChar; nGprsPort: Integer; pGprsID: PChar; pFileName: PChar; pCallBack: TCallBackFunc): integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgram
  ��̬����ָ����ʾ����ӽ�Ŀ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ��Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramType    :��Ŀ���ͣ�0������Ŀ��
    nPlayLength     :0:��ʾ�Զ�˳�򲥷ţ������ʾ��Ŀ���ŵĳ��ȣ���Χ1~65535����λ��
    nStartYear      :��Ŀ���������ڣ���ʼ����ʱ����ݡ����Ϊ�����Ʋ��ŵĻ��ò���ֵΪ65535����2010
    nStartMonth     :��Ŀ���������ڣ���ʼ����ʱ���·ݡ���11
    nStartDay       :��Ŀ���������ڣ���ʼ����ʱ�����ڡ���26
    nEndYear        :��Ŀ���������ڣ���������ʱ����ݡ���2011
    nEndMonth       :��Ŀ���������ڣ���������ʱ���·ݡ���11
    nEndDay         :��Ŀ���������ڣ���������ʱ�����ڡ���26
    nMonPlay        :��Ŀ����������������һ�Ƿ񲥷�;0��������;1������.
    nTuesPlay       :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    nWedPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    nThursPlay      :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    bFriPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    nSatPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    nSunPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
    nStartHour      :��Ŀ�ڵ��쿪ʼ����ʱ��Сʱ����8
    nStartMinute    :��Ŀ�ڵ��쿪ʼ����ʱ����ӡ���0
    nEndHour        :��Ŀ�ڵ����������ʱ��Сʱ����18
    nEndMinute      :��Ŀ�ڵ����������ʱ����ӡ���0
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgram  : function(nScreenNo, nProgramType: Integer; nPlayLength: Integer;
    nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay: Integer;
    nMonPlay, nTuesPlay, nWedPlay, nThursPlay, bFriPlay, nSatPlay, nSunPlay: integer;
    nStartHour, nStartMinute, nEndHour, nEndMinute: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgramBmpTextArea:
  ��̬����ָ����ʾ����ָ����Ŀ���ͼ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ͼ��������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramBmpTextArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenProgramAreaBmpTextText
  ��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ı���
      �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    pText           :�ı�
    nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nAlignment      :������ʾ��0 ���� 1���� 2 ���ң�
    pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nStunt          :��ʾ�ؼ���
      0x00:�����ʾ
      0x01:��̬
      0x02:���ٴ��
      0x03:�����ƶ�
      0x04:��������
      0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
      0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
      0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
      0x08:Ʈѩ
      0x09:ð��
      0x0A:�м��Ƴ�
      0x0B:��������
      0x0C:���ҽ�������
      0x0D:���½�������
      0x0E:����պ�
      0x0F:�����
      0x10:��������
      0x11:��������
      0x12:��������
      0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
      0x14:��������
      0x15:��������
      0x16:��������
      0x17:��������
      0x18:���ҽ�����Ļ
      0x19:���½�����Ļ
      0x1A:��ɢ����
      0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
      0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
      0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
      0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
      0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
      0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
      0x25:��������
      0x26:��������
      0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
      0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
    nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
    nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

  ����ֵ:           :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramAreaBmpTextText: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pText: PChar; nShowSingle: Integer; nAlignment: integer; pFontName: PChar;
    nFontSize, nBold, nFontColor: Integer; nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgramAreaBmpTextFile
  ��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ļ���
      �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    pFileName       :�ļ�����  ֧��.bmp,jpg,jpeg,rtf,txt���ļ����͡�
    nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nAlignment      :������ʾ��0 ���� 1���� 2 ���ң�
    pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
    nStunt          :��ʾ�ؼ���
      0x00:�����ʾ
      0x01:��̬
      0x02:���ٴ��
      0x03:�����ƶ�
      0x04:��������
      0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
      0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
      0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
      0x08:Ʈѩ
      0x09:ð��
      0x0A:�м��Ƴ�
      0x0B:��������
      0x0C:���ҽ�������
      0x0D:���½�������
      0x0E:����պ�
      0x0F:�����
      0x10:��������
      0x11:��������
      0x12:��������
      0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
      0x14:��������
      0x15:��������
      0x16:��������
      0x17:��������
      0x18:���ҽ�����Ļ
      0x19:���½�����Ļ
      0x1A:��ɢ����
      0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
      0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
      0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
      0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
      0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
      0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
      0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
      0x25:��������
      0x26:��������
      0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
      0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
    nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
    nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

  ����ֵ:           :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramAreaBmpTextFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pFileName: PChar; nShowSingle: Integer; nAlignment: integer; pFontName: PChar;
    nFontSize, nBold, nFontColor: Integer; nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgramTimeArea
  ��̬����ָ����ʾ����ָ����Ŀ���ʱ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ʱ��������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramTimeArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenProgramTimeAreaFile
  ��̬����ָ����ʾ����ָ����Ŀ��ָ��ʱ���������ԣ��ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ʱ������������Ϣ���á�
  ����:
    nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    pInputtxt   :�̶�����
    pFontName   :���ֵ�����
    nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
    nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
    nFontSize   :���ֵĴ�С
    nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
    nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
    nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
    nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
    nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
    nUseymd     :�Ƿ�ʹ�������գ�0Ϊ��1Ϊ��
    nYmdstyle   :�����ո�ʽ�����ʹ��˵���ĵ��ĸ���1
    nYmdcolor   :��������ɫ��������ɫ��10����
    nUseweek    :�Ƿ�ʹ�����ڣ�0Ϊ��1Ϊ��
    nWeekstyle  :���ڸ�ʽ�����ʹ��˵���ĵ��ĸ���1
    nWeekcolor  :������ɫ��������ɫ��10����
    nUsehns     :�Ƿ�ʹ��ʱ���룬0Ϊ��1��
    nHnsstyle   :ʱ�����ʽ�����ʹ��˵���ĵ��ĸ���1
    nHnscolor   :ʱ������ɫ��������ɫ��10����
    nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramTimeAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pInputtxt, pFontName: PChar;
    nSingal, nAlign, nFontSize, nBold, nItalic, nUnderline: Integer;
    nUsetxt, nTxtcolor,
    nUseymd, nYmdstyle, nYmdcolor,
    nUseweek, nWeekstyle, nWeekcolor,
    nUsehns, nHnsstyle, nHnscolor, nAutoset: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgramLunarArea
  ��̬����ָ����ʾ����ָ����Ŀ���ũ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ũ��������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramLunarArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenProgramLunarAreaFile
  ��̬����ָ����ʾ����ָ����Ŀ��ָ��ũ���������ԣ��ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ũ������������Ϣ���á�
  ����:
    nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd		:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    pInputtxt		:�̶�����
    pFontName		:���ֵ�����
    nSingal			:���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
    nAlign			:���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
    nFontSize		:���ֵĴ�С
    nBold				:�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
    nItalic			:�Ƿ�б�壬0Ϊ��1Ϊ��
    nUnderline	:�Ƿ��»��ߣ�0Ϊ��1Ϊ��
    nUsetxt			:�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
    nTxtcolor		:�̶�������ɫ��������ɫ��10����
    nUseyear		:�Ƿ�ʹ����ɣ�0Ϊ��1Ϊ��  ����î���꣩
    nYearcolor	:�����ɫ��������ɫ��10����
    nUsemonth		:�Ƿ�ʹ��ũ����0Ϊ��1Ϊ��  ��������ʮ��
    nMonthcolor	:ũ����ɫ��������ɫ��10����
    nUsesolar		:�Ƿ�ʹ�ý�����0Ϊ��1��
    nSolarcolor	:������ɫ��������ɫ��10����
    nAutoset		:�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramLunarAreaFile: function(nScreenNo, nProgramOrd, nAreaOrd: Integer;
    pInputtxt, pFontName: PChar;
    nSingal, nAlign, nFontSize, nBold, nItalic, nUnderline: Integer;
    nUsetxt, nTxtcolor, nUseyear, nYearcolor, nUsemonth, nMonthcolor,
    nUsesolar, nSolarcolor, nAutoset: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenProgramClockArea
  ��̬����ָ����ʾ����ָ����Ŀ��ӱ������򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�еı���������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenProgramClockArea: function(nScreenNo, nProgramOrd: Integer;
    nX, nY, nWidth, nHeight: integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenProgramClockAreaFile
  ��̬����ָ����ʾ����ָ����Ŀ��ָ�������������ԣ��ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����������������Ϣ���á�
  ����:
    nScreenNo			:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd 	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd			:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    nusetxt				:�Ƿ�ʹ�ù̶����� 0Ϊ��1Ϊ��
    nusetime			:�Ƿ�ʹ��������ʱ�� 0Ϊ��1Ϊ��
    nuseweek			:�Ƿ�ʹ������ 0Ϊ��1Ϊ��
    ntimeStyle		:������ʱ���ʽ���ο�ʱ�����ı��˵��
    nWeekStyle		:����ʱ���ʽ���ο�ʱ�����ı��˵��
    ntxtfontsize	:�̶����ֵ��ִ�С
    ntxtfontcolor	:�̶����ֵ���ɫ��������ɫ��10����;��255��65280��65535
    ntxtbold			:�̶������Ƿ�Ӵ� 0Ϊ��1Ϊ��
    ntxtitalic		:�̶������Ƿ�б�� 0Ϊ��1Ϊ��
    ntxtunderline	:�̶������Ƿ��»��� 0Ϊ��1Ϊ��
    txtleft				:�̶������ڱ��������е�X����
    txttop				:�̶������ڱ��������е�Y����
    ntimefontsize	:���������ֵ��ִ�С
    ntimefontcolor:���������ֵ���ɫ�� ������ɫ��10����
    ntimebold			:�����������Ƿ�Ӵ� 0Ϊ��1Ϊ��
    ntimeitalic		:�����������Ƿ�б�� 0Ϊ��1Ϊ��
    ntimeunderline:�����������Ƿ��»��� 0Ϊ��1Ϊ��
    timeleft			:�����������ڱ��������е�X����
    timetop				:�����������ڱ��������е�X����
    nweekfontsize	:�������ֵ��ִ�С
    nweekfontcolor:�������ֵ���ɫ��������ɫ��10����
    nweekbold			:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
    nweekitalic		:���������Ƿ�б�� 0Ϊ��1Ϊ��
    nweekunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
    weekleft			:���������ڱ��������е�X����
    weektop				:���������ڱ��������е�X����
    nclockfontsize:�������ֵ��ִ�С
    nclockfontcolor:�������ֵ���ɫ��������ɫ��10����
    nclockbold		:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
    nclockitalic	:���������Ƿ�б�� 0Ϊ��1Ϊ��
    nclockunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
    clockcentercolor:����������ɫ��������ɫ��10����
    mhrdotstyle		:3/6/9ʱ������ 0����1Բ��2����3����4����
    mhrdotsize		:3/6/9ʱ��ߴ� 0-8
    mhrdotcolor		:3/6/9ʱ����ɫ��������ɫ��10����
    hrdotstyle		:3/6/9���ʱ������  0����1Բ��2����3����4����
    hrdotsize			:3/6/9���ʱ��ߴ� 0-8
    hrdotcolor		:3/6/9���ʱ����ɫ��������ɫ��10����
    mindotstyle		:���ӵ�����  0����1Բ��2����
    mindotsize		:���ӵ�ߴ� 0-1
    mindotcolor		:���ӵ���ɫ��������ɫ��10����
    hrhandsize		:ʱ��ߴ� 0-8
    hrhandcolor		:ʱ����ɫ��������ɫ��10����
    minhandsize		:����ߴ� 0-8
    minhandcolor	:������ɫ��������ɫ��10����
    sechandsize		:����ߴ� 0-8
    sechandcolor	:������ɫ��������ɫ��10����
    nAutoset			:����Ӧλ�����ã�0Ϊ��1Ϊ�� ���Ϊ1����txtleft/txttop/ weekleft/weektop/timeleft/timetop��Ҫ�Լ�������ֵ
    btxtcontent		:�̶�������Ϣ
    btxtfontname	:�̶���������
    btimefontname	:ʱ����������
    bweekfontname	:������������
    bclockfontname:������������
  ����ֵ            :�������״̬���붨�塣
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
  ������:    AddScreenProgramChroAreaFile
  ��̬����ָ����ʾ����ָ����Ŀ��ָ����ʱ�������ԣ��ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����ʱ����������Ϣ���á�
  ����:
    nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣

    pInputtxt   :�̶�����
    pDaystr    :�쵥λ
    pHourstr   :Сʱ��λ
    pMinstr    :���ӵ�λ
    pSecstr    :�뵥λ
    pFontName   :���ֵ�����
    nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
    nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
    nFontSize   :���ֵĴ�С
    nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
    nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
    nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
    nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
    nFontcolor  :��ʱ��ʾ��ɫ��������ɫ��10���� ��255 ��65280 ��65535

    nShowstr     :�Ƿ���ʾ��λ����Ӧ�����е��죬ʱ���֣��뵥λ
    nShowAdd     :�Ƿ��ʱ�ۼ���ʾ Ĭ�����ۼӵ�
    nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
    nUseDay     :�Ƿ�ʹ���죬0Ϊ��1Ϊ��
    nUseHour    :�Ƿ�ʹ��Сʱ��0Ϊ��1Ϊ��
    nUseMin     :�Ƿ�ʹ�÷��ӣ�0Ϊ��1Ϊ��
    nUseSec     :�Ƿ�ʹ���룬0Ϊ��1Ϊ��

    nDayLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
    nHourLength    :Сʱ��ʾλ��  Ĭ��Ϊ0 �Զ�
    nMinLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
    nSecLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�

    EndYear     :Ŀ����ֵ
    EndMonth   :Ŀ����ֵ
    EndDay     :Ŀ����ֵ
    EndHour    :Ŀ��ʱֵ
    EndMin     :Ŀ���ֵ
    EndSec     :Ŀ����ֵ


    nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
  ����ֵ            :�������״̬���붨�塣
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
  ������:    AddScreenProgramTemperatureArea
  ��̬����ָ����ʾ����ָ����Ŀ����¶����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е��¶�������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
    nSensorType     :�¶ȴ��������ͣ�
      0:"Temp sensor S-T1";
      1:"Temp and hum sensor S-RHT 1";
      2:"Temp and hum sensor S-RHT 2"
    nTemperatureUnit:�¶���ʾ��λ��0:���϶�(��);1:���϶�(�H);2:���϶�(��)
    nTemperatureMode:�¶���ʾģʽ��0:�����ͣ�1:С���͡�
    nTemperatureUnitScale:�¶ȵ�λ��ʾ������50~100;Ĭ��Ϊ100.
    nTemperatureValueWidth:�¶���ֵ�ַ���ʾ��ȣ�
    nTemperatureCorrectionPol:�¶�ֵ�������ֵ���ԣ�0������1����
    nTemperatureCondition:�¶�ֵ�������ֵ��
    nTemperatureThreshPol:�¶���ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
    nTemperatureThresh:�¶���ֵ
    nTemperatureColor:�����¶���ɫ
    nTemperatureErrColor:�¶ȳ�����ֵʱ��ʾ����ɫ
    pStaticText     :�¶�����ǰ׺�̶��ı�;�ò�����Ϊ��
    pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
    nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
    nStaticColor    :������ɫ��
    nStaticBold     :������壻֧��1�����壻0��������
  ����ֵ            :�������״̬���붨�塣
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
  ������:    AddScreenProgramHumidityArea
  ��̬����ָ����ʾ����ָ����Ŀ���ʪ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е�ʪ��������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
    nSensorType     :ʪ�ȴ��������ͣ�
      0:"Temp and hum sensor S-RHT 1";
      1:"Temp and hum sensor S-RHT 2"
    nHumidityUnit   :ʪ����ʾ��λ��0:���ʪ��(%RH);1:���ʪ��(��)
    nHumidityMode   :ʪ����ʾģʽ��0:�����ͣ�1:С���͡�
    nHumidityUnitScale:ʪ�ȵ�λ��ʾ������50~100;Ĭ��Ϊ100.
    nHumidityValueWidth:ʪ����ֵ�ַ���ʾ��ȣ�
    nHumidityConditionPol:ʪ��ֵ�������ֵ���ԣ�0������1����
    nHumidityCondition:ʪ��ֵ�������ֵ��
    nHumidityThreshPol:ʪ����ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
    nHumidityThresh :ʪ����ֵ
    nHumidityColor  :����ʪ����ɫ
    nHumidityErrColor:ʪ�ȳ�����ֵʱ��ʾ����ɫ
    pStaticText     :ʪ������ǰ׺�̶��ı�;�ò�����Ϊ��
    pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
    nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
    nStaticColor    :������ɫ��
    nStaticBold     :������壻֧��1�����壻0��������
  ����ֵ            :�������״̬���붨�塣
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
  ������:    AddScreenProgramNoiseArea
  ��̬����ָ����ʾ����ָ����Ŀ����������򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е�����������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
    nSensorType     :�������������ͣ�
      0:"I-������";
      1:"II-������"
    nNoiseUnit      :������ʾ��λ��0:���ʪ��(%RH);1:���ʪ��(��)
    nNoiseMode      :������ʾģʽ��0:�����ͣ�1:С���͡�
    nNoiseUnitScale :������λ��ʾ������50~100;Ĭ��Ϊ100.
    nNoiseValueWidth:������ֵ�ַ���ʾ��ȣ�
    nNoiseConditionPol:����ֵ�������ֵ���ԣ�0������1����
    nNoiseCondition :����ֵ�������ֵ��
    nNoiseThreshPol :������ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
    nNoiseThresh    :������ֵ
    nNoiseColor     :����������ɫ
    nNoiseErrColor  :����������ֵʱ��ʾ����ɫ
    pStaticText     :��������ǰ׺�̶��ı�;�ò�����Ϊ��
    pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
    nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
    nStaticColor    :������ɫ��
    nStaticBold     :������壻֧��1�����壻0��������
  ����ֵ            :�������״̬���붨�塣
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
  ������:    DeleteScreen
  ɾ��ָ����ʾ����Ϣ��ɾ����ʾ���ɹ���Ὣ����ʾ�������н�Ŀ��Ϣ�Ӷ�̬����ɾ����
  �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  DeleteScreen      : function(nScreenNo: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    DeleteScreenProgram
  ɾ��ָ����ʾ��ָ����Ŀ��ɾ����Ŀ�ɹ���Ὣ�ý�Ŀ������������Ϣɾ����
  �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  DeleteScreenProgram: function(nScreenNo, nProgramOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    DeleteScreenProgramArea
  ɾ��ָ����ʾ��ָ����Ŀ��ָ������ɾ������ɹ���Ὣ��������������Ϣɾ����
  �ú���������ʾ��ͨѶ��ֻ���ڶ�̬����ָ����ʾ��ָ����Ŀ��ָ����������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  DeleteScreenProgramArea: function(nScreenNo, nProgramOrd, nAreaOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    DeleteScreenProgramAreaBmpTextFile
  ɾ��ָ����ʾ��ָ����Ŀָ��ͼ�������ָ���ļ���ɾ���ļ��ɹ���Ὣ���ļ���Ϣɾ����
  �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀָ�������е�ָ���ļ���Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
    nFileOrd        :�ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  DeleteScreenProgramAreaBmpTextFile: function(nScreenNo, nProgramOrd, nAreaOrd, nFileOrd: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    SendScreenInfo
  ͨ��ָ����ͨѶģʽ��������Ӧ��Ϣ�������ʾ�����ú�������ʾ������ͨѶ
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      2:����ģʽ;
      4:WiFiģʽ
    nSendCmd        :ͨѶ����ֵ
      SEND_CMD_PARAMETER =41471;  ������������
      SEND_CMD_SENDALLPROGRAM = 41456;  �������н�Ŀ��Ϣ��
      SEND_CMD_POWERON =41727; ǿ�ƿ���
      SEND_CMD_POWEROFF = 41726; ǿ�ƹػ�
      SEND_CMD_TIMERPOWERONOFF = 41725; ��ʱ���ػ�
      SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; ȡ����ʱ���ػ�
      SEND_CMD_RESIVETIME = 41723; У��ʱ�䡣
      SEND_CMD_ADJUSTLIGHT = 41722; ���ȵ�����
    nOtherParam1    :����������0
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  SendScreenInfo    : function(nScreenNo, nSendCmd, nOtherParam1: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    SetScreenTimerPowerONOFF
  �趨��ʾ���Ķ�ʱ���ػ���������������3�鿪�ػ�ʱ�䡣�ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���ж�ָ����ʾ���Ķ�ʱ���ػ���Ϣ���á����轫�趨�Ķ�ʱ����ֵ���͵���ʾ���ϣ�
  ֻ��ʹ��SendScreenInfo�������Ͷ�ʱ��������ɡ�
  ����:
    nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nOnHour1		:��һ�鶨ʱ���صĿ���ʱ���Сʱ
    nOnMinute1	:��һ�鶨ʱ���صĿ���ʱ��ķ���
    nOffHour1		:��һ�鶨ʱ���صĹػ�ʱ���Сʱ
    nOffMinute1	:��һ�鶨ʱ���صĹػ�ʱ��ķ���
    nOnHour2		:�ڶ��鶨ʱ���صĿ���ʱ���Сʱ
    nOnMinute2	:�ڶ��鶨ʱ���صĿ���ʱ��ķ���
    nOffHour2		:�ڶ��鶨ʱ���صĹػ�ʱ���Сʱ
    nOffMinute2	:�ڶ��鶨ʱ���صĹػ�ʱ��ķ���
    nOnHour3		:�����鶨ʱ���صĿ���ʱ���Сʱ
    nOnMinute3	:�����鶨ʱ���صĿ���ʱ��ķ���
    nOffHour3		:�����鶨ʱ���صĹػ�ʱ���Сʱ
    nOffMinute3	:�����鶨ʱ���صĹػ�ʱ��ķ���
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  SetScreenTimerPowerONOFF: function(nScreenNo: Integer;
    nOnHour1, nOnMinute1, nOffHour1, nOffMinute1,
    nOnHour2, nOnMinute2, nOffHour2, nOffMinute2,
    nOnHour3, nOnMinute3, nOffHour3, nOffMinute3: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    SetScreenAdjustLight
  �趨��ʾ�������ȵ����������ú����������ֹ������Ͷ�ʱ��������ģʽ���ú���������ʾ��ͨѶ��
  ֻ���ڶ�̬���ж�ָ����ʾ�������ȵ�����Ϣ���á����轫�趨�����ȵ���ֵ���͵���ʾ���ϣ�
  ֻ��ʹ��SendScreenInfo�����������ȵ�������ɡ�
  ����:
    nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nAdjustType	:���ȵ������ͣ�0���ֹ�������1����ʱ����
    nHandleLight:�ֹ�����������ֵ��ֻ��nAdjustType=0ʱ�ò�����Ч��
    nHour1			:��һ�鶨ʱ����ʱ���Сʱ
    nMinute1		:��һ�鶨ʱ����ʱ��ķ���
    nLight1			:��һ�鶨ʱ����������ֵ
    nHour2			:�ڶ��鶨ʱ����ʱ���Сʱ
    nMinute2		:�ڶ��鶨ʱ����ʱ��ķ���
    nLight2			:�ڶ��鶨ʱ����������ֵ
    nHour3			:�����鶨ʱ����ʱ���Сʱ
    nMinute3		:�����鶨ʱ����ʱ��ķ���
    nLight3			:�����鶨ʱ����������ֵ
    nHour4			:�����鶨ʱ����ʱ���Сʱ
    nMinute4		:�����鶨ʱ����ʱ��ķ���
    nLight4			:�����鶨ʱ����������ֵ
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  SetScreenAdjustLight: function(nScreenNo: Integer; nAdjustType, nHandleLight: Integer;
    nHour1, nMinute1, nLight1,
    nHour2, nMinute2, nLight2,
    nHour3, nMinute3, nLight3,
    nHour4, nMinute4, nLight4: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    SaveUSBScreenInfo
  ������ʾ��������Ϣ��USB�豸�������û���USB��ʽ������ʾ����Ϣ���ú�����LedshowTW������׵�USB���ع���һ�¡�
  ʹ�øù���ʱ��ע�⵱ǰ�������Ƿ�֧��USB���ع��ܡ�
  ����
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    bCorrectTime    :�Ƿ�У��ʱ��
      0����У��ʱ�䣻
      1��У��ʱ�䣻
    nAdvanceHour    :У��ʱ��ȵ�ǰ�����ʱ����ǰ��Сʱֵ����Χ0~23��ֻ�е�bCorrectTime=1ʱ��Ч��
    nAdvanceMinute  :У��ʱ��ȵ�ǰ�����ʱ����ǰ�ķ���ֵ����Χ0~59��ֻ�е�bCorrectTime=1ʱ��Ч��
    pUSBDisk        :USB�豸��·�����ƣ���ʽΪ"�̷�:\"�ĸ�ʽ�����磺"F:\"
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  SaveUSBScreenInfo : function(nScreenNo: Integer;
    bCorrectTime, nAdvanceHour, nAdvanceMinute: Integer; pUSBDisk: PChar): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    GetScreenStatus
  ��ѯ��ǰ��ʾ��״̬������ѯ״̬�������浽AddScreen�����е�pScreenStatusFile��INI�����ļ��С�
  �ú�������ʾ������ͨѶ
  ����:      nScreenNo, nSendMode: Integer
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      2:����ģʽ;
      4:WiFiģʽ
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  GetScreenStatus   : function(nScreenNo, nSendMode: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    GetScreenParameter
  ��ѯ��ǰ��ʾ������������ѯ״̬�������浽szFileName��INI�����ļ��С�
  �ú�������ʾ������ͨѶ
  ����:      nScreenNo, nSendMode: Integer ; szFileName : PChar
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      2:����ģʽ;
      4:WiFiģʽ
    szFileName      :�����Ini�ļ�·����
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  GetScreenParameter   : function(nScreenNo, nSendMode: Integer; szFileName : PChar): Integer; stdcall;

  {-------------------------------------------------------------------------------
  ������:    QuerryServerDeviceList
  ��ѯ��ת�������豸���б���Ϣ��
  �ú�������ʾ������ͨѶ
  ����:
    pTransitDeviceType :��ת�豸���� BX-3GPRS��BX-3G
    pServerIP       :��ת������IP��ַ
    nServerPort     :��ת����������˿�
    pServerAccessUser:��ת�����������û���
    pServerAccessPassword:��ת��������������
    pDeviceList       : �����ѯ���豸�б���Ϣ
      ���豸����Ϣ������ַ���, ���磺
      �豸1������ ������ ״̬ ���� ����ID
      �豸2������ ������ ״̬ ���� ����ID
      ����ַ���Ϊ��'�豸1����,�豸1������,�豸1״̬,�豸1����,�豸1����ID;�豸2����,�豸2������,�豸2״̬,�豸2����,�豸2����ID'
      �豸״̬(Byte):  $10:�豸δ֪
                       $11:�豸����
                       $12:�豸������

      �豸����(Byte): $16:�豸Ϊ2G
                      $17:�豸Ϊ3G

  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  QuerryServerDeviceList : function(pTransitDeviceType: PChar;pServerIP: PChar; nServerPort: Integer;
  pServerAccessUser: PChar; pServerAccessPassword: PChar;pDeviceList:PChar): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    StartServer
  ����������,��������ģʽ�µķ�����ģʽ��GPRSͨѶģʽ��
  ����:
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      1:GPRSģʽ
      2:����ģʽ
      4:WiFiģʽ
      5:ONBON������-GPRS
      6:ONBON������-3G
    pServerIP       :��ת������IP��ַ
    nServerPort     :��ת����������˿�
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  StartServer : function(nSendMode:Integer;pServerIP: PChar; nServerPort: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    StopServer
  �رշ�����,��������ģʽ�µķ�����ģʽ��GPRSͨѶģʽ��
  ����:
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      1:GPRSģʽ
      2:����ģʽ
      4:WiFiģʽ
      5:ONBON������-GPRS
      6:ONBON������-3G
  ����ֵ            :�������״̬���붨�塣
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
    Result := $FE; //�㲥ģʽ����ָ���豸���ͣ��κ��豸��Ӧ������д���
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
  if hDll < 32 then exit; //���Dll�޷�����������
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
        spnedt_curAreaOrd.Value, PChar(edt_FileName.Text), 0, 0, PChar('����'), 14, 0, clYellow, 2, 0, 10);
      mmo1.Lines.Add('AddScreenProgramAreaBmpTextFile' + '---' + GetErrorMessage(nResult));
    end
    else
      ShowMessage('û�в��ҵ���Ч���ļ���');
  end
  else
    ShowMessage('���������Ч���ļ���');
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
  dlgOpen1.Filter := '�ļ�����(*.bmp;*.jpg;*.jpeg;*.rtf;*.txt;*.txtf;*.txts)|*.bmp;*.jpg;*.jpeg;*.rtf;*.txt;*.txts';
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
      Result := Result + '�������ʹ�������ӡ�ɾ��ͼ�������ļ�ʱ�������ͳ����ش����ʹ���';
    RETURN_ERROR_RA_SCREENNO:
      Result := Result + '�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ�������';
    RETURN_ERROR_NOFIND_AREAFILE:
      Result := Result + 'û���ҵ���Ч�������ļ�(ͼ������)';
    RETURN_ERROR_NOFIND_AREA:
      Result := Result + 'û���ҵ���Ч����ʾ�������ʹ��AddScreenProgramBmpTextArea���������Ϣ��';
    RETURN_ERROR_NOFIND_PROGRAM:
      Result := Result + 'û���ҵ���Ч����ʾ����Ŀ����ʹ��AddScreenProgram�������ָ����Ŀ';
    RETURN_ERROR_NOFIND_SCREENNO:
      Result := Result + 'ϵͳ��û�в��ҵ�����ʾ������ʹ��AddScreen���������ʾ��';
    RETURN_ERROR_NOW_SENDING:
      Result := Result + 'ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ';
    RETURN_ERROR_OTHER:
      Result := Result + '��������';
    RETURN_ERROR_NOSUPPORT_USB:
      Result := Result + '�ÿ��ƿ���֧�ֱ��浽USB�豸';
    RETURN_ERROR_NO_USB_DISK:
      Result := Result + '�Ҳ�����Ӧ��USB�豸';
    RETURN_NOERROR:
      Result := Result + '����ִ��/ͨѶ�ɹ�';
    $01..$18, $FE:
      Result := Result + 'ͨѶ����';
  else
    Result := Result + '��������';
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
    g_nSendMode := SEND_MODE_NET //���紫��
  else
  if comb_SendMode.ItemIndex = 3 then
    g_nSendMode := SEND_MODE_WIFI //WIFiͨѶ
  else
  if comb_SendMode.ItemIndex = 4 then
    g_nSendMode := SEND_MODE_Server_2G //ONBON������-GPRS
  else
  if comb_SendMode.ItemIndex = 5 then
    g_nSendMode := SEND_MODE_Server_3G //ONBON������-3G
  else
  if comb_SendMode.ItemIndex = 6 then
    g_nSendMode := SEND_MODE_RF //RFͨѶ
  else
    g_nSendMode := SEND_MODE_COMM; //���ڴ���

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
    PChar(''), PChar('����'),
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
    PChar(''), PChar('����'),
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
    pchar(''), pchar('����'), pchar('����'), pchar('����'), pchar('����'));
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
    pchar(''), pchar('��'), pchar('Сʱ'), pchar('����'), pchar('��'), pchar('����'),
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
    '�¶�:',
    '����',
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
    'ʪ��:',
    '����',
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
    '����:',
    '����',
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
      TransitDeviceType := 'BX-3GPRS' //ONBON������-GPRS
    else
    if comb_SendMode.ItemIndex = 5 then
      TransitDeviceType := 'BX-3G'; //ONBON������-3G

    nResult:=QuerryServerDeviceList(PChar(TransitDeviceType),PChar(edtServerIP.Text), edtServerPort.value,
    PChar(edtUserName.Text), PChar(edtPassword.Text),Devicelist);
    if nResult=0 then begin   //û�д���
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
      spnedt_curAreaOrd.Value, PChar(mmo_Text.Text), 0, 0, PChar('����'), 14, 0, clYellow, 2, 48, 10);
    mmo1.Lines.Add('AddScreenProgramAreaText' + '---' + GetErrorMessage(nResult));
  end
  else
    ShowMessage('��������ı���');
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

