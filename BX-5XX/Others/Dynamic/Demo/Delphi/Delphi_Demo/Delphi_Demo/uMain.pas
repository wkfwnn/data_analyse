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

  FRAME_SINGLE_COLOR_COUNT = 23; //��ɫ�߿�ͼƬ����
  FRAME_MULI_COLOR_COUNT = 47; //��ɫ�߿�ͼƬ����

//------------------------------------------------------------------------------
// ͨѶģʽ
  SEND_MODE_SERIALPORT = 0;
  SEND_MODE_NETWORK = 2;
  SEND_MODE_Server_2G = 5;
  SEND_MODE_Server_3G = 6;
  SEND_MODE_SAVEFILE = 7;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ��̬��������ģʽ
  RUN_MODE_CYCLE_SHOW = 0; //��̬������ѭ����ʾ��
  RUN_MODE_SHOW_LAST_PAGE = 1; //��̬��������ʾ��ɺ�ֹ��ʾ���һҳ���ݣ�
  RUN_MODE_SHOW_CYCLE_WAITOUT_NOSHOW = 2; //��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ������ʾ��
  RUN_MODE_SHOW_ORDERPLAYED_NOSHOW = 4; //��̬������˳����ʾ����ʾ�����һҳ��Ͳ�����ʾ
//------------------------------------------------------------------------------
//==============================================================================
// ����״̬���붨��
  RETURN_ERROR_NOFIND_DYNAMIC_AREA = $E1; //û���ҵ���Ч�Ķ�̬����
  RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD = $E2; //��ָ���Ķ�̬����û���ҵ�ָ�����ļ���š�
  RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD = $E3; //��ָ���Ķ�̬����û���ҵ�ָ����ҳ��š�
  RETURN_ERROR_NOSUPPORT_FILETYPE = $E4; //��֧�ָ��ļ����͡�
  RETURN_ERROR_RA_SCREENNO = $F8; //�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ������ӣ�
  RETURN_ERROR_NOFIND_AREA = $FA; //û���ҵ���Ч����ʾ���򣻿���ʹ��AddScreenProgramBmpTextArea���������Ϣ��
  RETURN_ERROR_NOFIND_SCREENNO = $FC; //ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen���������ʾ��
  RETURN_ERROR_NOW_SENDING = $FD; //ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��
  RETURN_ERROR_OTHER = $FF; //��������
  RETURN_NOERROR    = 0; //û�д���
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
  ������:    AddScreen_Dynamic
  ��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��
  ����:
    nControlType:��ʾ���Ŀ������ͺţ�Ŀǰ�ö�̬����̬��ֻ֧��BX-5E1��BX-5E2��BX-5E3��BX-5Eϵ�к�5Q+ϵ�п�������
    nScreenNo����ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
    nSendMode��ͨѶģʽ��Ŀǰ��̬����֧��0:����ͨѶ��2������ͨѶ(ֻ֧�̶ֹ�IPģʽ)��5��ONBON������-GPRS 6��ONBON������-3G 7�����浽�ļ�������ͨѶģʽ��
    nWidth����ʾ����ȣ���λ�����ء�
    nHeight����ʾ���߶ȣ���λ�����ء�
    nScreenType����ʾ�����ͣ�1������ɫ��2��˫��ɫ; 3:˫��ɫ 4:ȫ��ɫ 5:˫��ɫ�Ҷȡ�
    nPixelMode���������ͣ�ֻ����ʾ������Ϊ˫��ɫʱ��Ч��1��R+G��2��G+R��
    pCom��ͨѶ���ڣ�ֻ���ڴ���ͨѶʱ�ò�����Ч������"COM1"
    nBaud��ͨѶ���ڲ����ʣ�ֻ���ڴ���ͨѶʱ�ò�����Ч��Ŀǰֻ֧��9600��57600���ֲ����ʡ�
    pSocketIP����������IP��ַ��ֻ��������ͨѶ(�̶�IPģʽ)ģʽ�¸ò�����Ч������"192.168.0.199"
    nSocketPort���������Ķ˿ڵ�ַ��ֻ��������ͨѶ(�̶�IPģʽ)ģʽ�¸ò�����Ч������5005
    nStaticIPMode   :�̶�IPͨѶģʽ��0��TCPģʽ 1��UDPģʽ
    nServerMode     :0:������ģʽδ������1��������ģʽ������
    pBarcode        :�豸�����룬���ڷ�����ģʽ����ת������
    pNetworkID      :����ID��ţ����ڷ�����ģʽ����ת������
    pServerIP       :��ת������IP��ַ
    nServerPort     :��ת����������˿�
    pServerAccessUser:��ת�����������û���
    pServerAccessPassword:��ת��������������
    pCommandDataFile�����浽�ļ���ʽʱ������������ļ����ơ�ֻ���ڱ��浽�ļ�ģʽ�¸ò�����Ч������"curCommandData.dat"
  ����ֵ:    �������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreen_Dynamic         :function(nControlType, nScreenNo, nSendMode, nWidth, nHeight, nScreenType, nPixelMode: Integer;
    pCom: PChar; nBaud: Integer; pSocketIP: PChar; nSocketPort: Integer; nStaticIPMode:Integer; nServerMode: Integer; pBarcode: PChar;
    pNetworkID:PChar; pServerIP: PChar; nServerPort: Integer; pServerAccessUser: PChar; pServerAccessPassword: PChar;
    pCommandDataFile: pChar): integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    AddScreenDynamicArea
  ��̬����ָ����ʾ����Ӷ�̬���򣻸ú���������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ�Ŀǰϵͳ�����5����̬���򣻸�ֵȡֵ��ΧΪ0~4;
    nRunMode����̬��������ģʽ��
              0:��̬������ѭ����ʾ��
              1:��̬��������ʾ��ɺ�ֹ��ʾ���һҳ���ݣ�
              2:��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ������ʾ��
              4:��̬������˳����ʾ����ʾ�����һҳ��Ͳ�����ʾ
    nTimeOut����̬�����ݳ�ʱʱ�䣻��λ����
    nAllProRelate����Ŀ������־��
              1�����н�Ŀ����ʾ�ö�̬����
              0����ָ����Ŀ����ʾ�ö�̬���������̬����Ҫ�����ڽ�Ŀ��ʾ������һ������Ϊ�ա�
    pProRelateList����Ŀ�����б��ý�Ŀ��ű�ʾ����Ŀ��ż���","����,��Ŀ��Ŷ���ΪLedshowTW 2013�����"P***"�е�"***"
    nPlayPriority����̬���򲥷����ȼ���
              0���ö�̬�������첽��Ŀһ�𲥷�(��̬�����й����첽��Ŀ����Ч)��
              1���첽��Ŀֹͣ���ţ������Ÿö�̬����
    nAreaX����̬������ʼ�����ꣻ��λ������
    nAreaY����̬������ʼ�����ꣻ��λ������
    nAreaWidth����̬�����ȣ���λ������
    nAreaHeight����̬����߶ȣ���λ������
    nAreaFMode����̬����߿���ʾ��־��0����ɫ��1����ɫ��255���ޱ߿�
    nAreaFLine����̬����߿�����, ��ɫ���ȡֵΪFRAME_SINGLE_COLOR_COUNT����ɫ���ȡֵΪ��FRAME_MULI_COLOR_COUNT
    nAreaFColor���߿���ʾ��ɫ��ѡ��Ϊ��ɫ�߿�����ʱ�ò�����Ч��
    nAreaFStunt���߿������ؼ���
              0����˸��1��˳ʱ��ת����2����ʱ��ת����3����˸��˳ʱ��ת����
              4:��˸����ʱ��ת����5�����̽�����˸��6�����̽���ת����7����ֹ���
    nAreaFRunSpeed���߿������ٶȣ�
    nAreaFMoveStep���߿��ƶ���������ֵȡֵ��Χ��1~8��
  ����ֵ:    �������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenDynamicArea:
    function(nScreenNo, nDYAreaID: Integer; nRunMode: Integer;
    nTimeOut, nAllProRelate: Integer; pProRelateList: PChar; nPlayPriority: Integer;
    nAreaX, nAreaY, nAreaWidth, nAreaHeight: Integer; nAreaFMode, nAreaFLine, nAreaFColor,
    nAreaFStunt, nAreaFRunSpeed, nAreaFMoveStep: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenDynamicAreaText
  ��̬����ָ����ʾ����ָ����̬���������Ϣ�ļ����ú���������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    pText����ӵ���Ϣ�ı�
    nShowSingle��������Ϣ�Ƿ�����ʾ��0��������ʾ��1��������ʾ����ʾ�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    pFontName��������Ϣ��ʾ���壻�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nFontSize��������Ϣ��ʾ������ֺţ��ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nBold��������Ϣ�Ƿ������ʾ��0��������1��������ʾ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nFontColor��������Ϣ��ʾ��ɫ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nStunt����̬������Ϣ�����ؼ���
              00�������ʾ
              01����ֹ��ʾ
              02�����ٴ��
              03�������ƶ�
              04����������
              05�������ƶ�
              06����������
              07����˸
              08��Ʈѩ
              09��ð��
              10���м��Ƴ�
              11����������
              12�����ҽ�������
              13�����½�������
              14������պ�
              15�������
              16����������
              17����������
              18����������
              19����������
              20����������
              21����������
              22����������
              23����������
              24�����ҽ�����Ļ
              25�����½�����Ļ
              26����ɢ����
              27��ˮƽ��ҳ
              28����ֱ��ҳ
              29��������Ļ
              30��������Ļ
              31��������Ļ
              32��������Ļ
              33�����ұպ�
              34�����ҶԿ�
              35�����±պ�
              36�����¶Կ�
              37�������ƶ�
              38����������
              39�������ƶ�
              40����������
    nRunSpeed����̬������Ϣ�����ٶ�
    nShowTime����̬������Ϣ��ʾʱ�䣻��λ��10ms
  ����ֵ:    �������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenDynamicAreaText:
    function(nScreenNo, nDYAreaID: Integer;
    pText: PChar; nShowSingle: integer; pFontName: PChar; nFontSize, nBold, nFontColor: Integer;
    nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;
{-------------------------------------------------------------------------------
  ������:    AddScreenDynamicAreaFile
  ��̬����ָ����ʾ����ָ����̬���������Ϣ�ļ����ú���������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    pFileName����ӵ���Ϣ�ļ����ƣ�Ŀǰֻ֧��txt(֧��ANSI��UTF-8��Unicode�ȸ�ʽ����)��bmp���ļ���ʽ
    nShowSingle��������Ϣ�Ƿ�����ʾ��0��������ʾ��1��������ʾ����ʾ�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    pFontName��������Ϣ��ʾ���壻�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nFontSize��������Ϣ��ʾ������ֺţ��ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nBold��������Ϣ�Ƿ������ʾ��0��������1��������ʾ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nFontColor��������Ϣ��ʾ��ɫ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
    nStunt����̬������Ϣ�����ؼ���
              00�������ʾ
              01����ֹ��ʾ
              02�����ٴ��
              03�������ƶ�
              04����������
              05�������ƶ�
              06����������
              07����˸
              08��Ʈѩ
              09��ð��
              10���м��Ƴ�
              11����������
              12�����ҽ�������
              13�����½�������
              14������պ�
              15�������
              16����������
              17����������
              18����������
              19����������
              20����������
              21����������
              22����������
              23����������
              24�����ҽ�����Ļ
              25�����½�����Ļ
              26����ɢ����
              27��ˮƽ��ҳ
              28����ֱ��ҳ
              29��������Ļ
              30��������Ļ
              31��������Ļ
              32��������Ļ
              33�����ұպ�
              34�����ҶԿ�
              35�����±պ�
              36�����¶Կ�
              37�������ƶ�
              38����������
              39�������ƶ�
              40����������
    nRunSpeed����̬������Ϣ�����ٶ�
    nShowTime����̬������Ϣ��ʾʱ�䣻��λ��10ms
  ����ֵ:    �������״̬���붨�塣
-------------------------------------------------------------------------------}
  AddScreenDynamicAreaFile:
    function(nScreenNo, nDYAreaID: Integer;
    pFileName: PChar; nShowSingle: integer; pFontName: PChar; nFontSize, nBold, nFontColor: Integer;
    nStunt, nRunSpeed, nShowTime: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    DeleteScreen_Dynamic
  ɾ����̬����ָ����ʾ����������Ϣ���ú���������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  DeleteScreen_Dynamic      :
    function(nScreenNo: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    DeleteScreenDynamicAreaFile
  ɾ����̬����ָ����ʾ��ָ���Ķ�̬����ָ���ļ���Ϣ���ú���������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    nFileOrd����̬�����ָ���ļ����ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  DeleteScreenDynamicAreaFile:
    function(nScreenNo, nDYAreaID, nFileOrd: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    SendDynamicAreaInfoCommand
  ���Ͷ�̬����ָ����ʾ��ָ���Ķ�̬������Ϣ����ʾ�����ú�������ʾ��ͨѶ��
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  SendDynamicAreaInfoCommand:
    function(nScreenNo, nDYAreaID: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    SendDeleteDynamicAreasCommand
  ɾ����̬����ָ����ʾ��ָ���Ķ�̬������Ϣ��ͬʱ����ʾ��ͨѶɾ��ָ���Ķ�̬������Ϣ���ú�������ʾ��ͨѶ
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    pDYAreaIDList����̬�������б����ͬʱɾ�������̬���򣬶�̬�����ż���","��������"0,1"
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  SendDeleteDynamicAreasCommand:
    function(nScreenNo, nDelAllDYArea: Integer; pDYAreaIDList: PChar): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    SendUpdateDynamicAreaPageInfoCommand
  ��̬����ָ����ʾ��ָ���Ķ�̬���򵥶�����ָ��������ҳ��Ϣ���ú�������ʾ��ͨѶ
  �ú���ʹ��ʱ����������ȷ�õ�ǰԤ������Ϣ����ʾ���е���ʾҳ�룬������ܸ��³���
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    nFileOrd����̬�����ָ���ļ����ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
    nPageOrd��Ԥ��������ҳ��ҳ��š���0��ʼ˳�������
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  SendUpdateDynamicAreaPageInfoCommand:
    function(nScreenNo, nDYAreaID, nFileOrd, nPageOrd: Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    SendDeleteDynamicAreaPageCommand
  ɾ����̬����ָ����ʾ����ָ����̬����ָ��������ҳ��Ϣ���ú�������ʾ��ͨѶ
  �ú���ʹ��ʱ����������ȷ�õ�ǰԤɾ������ҳ��Ϣ����ʾ���е���ʾҳ�룬�������ɾ������
  ����:
    nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
    pDYAreaPageOrdList��Ԥɾ����̬��������ҳ����б����ͬʱɾ���������ҳ��Ϣ������ҳ��ż���","��������"0,1"��
              ɾ������ҳ��Ϣִ�гɹ��󣬺��������ҳ��Ϣ������ҳ����Զ���ǰ���롣
  ����ֵ:    �������״̬���붨��
-------------------------------------------------------------------------------}
  SendDeleteDynamicAreaPageCommand:
    function(nScreenNo, nDYAreaID: Integer; pDYAreaPageOrdList: PChar): Integer; stdcall;

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
    pDeviceCount      : ��ѯ���豸����

  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
  QuerryServerDeviceList : function(pTransitDeviceType: PChar;pServerIP: PChar; nServerPort: Integer;
  pServerAccessUser: PChar; pServerAccessPassword: PChar;pDeviceList:PChar;var nDeviceCount:Integer): Integer; stdcall;

{-------------------------------------------------------------------------------
  ������:    StartServer
  ����������,��������ģʽ�µķ�����ģʽ��GPRSͨѶģʽ��
  ����:
    nSendMode       :����ʾ����ͨѶģʽ��
      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
      2:����ģʽ
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
      2:����ģʽ
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

procedure Tfrm_Main.FormCreate(Sender: TObject);
begin
  hDll := LoadLibrary('LedDynamicArea.dll');
  if hDll < 32 then
    Exit; //���Dll�޷�����������

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
  mmo_FunResultInfo.Lines.Add('ִ��AddScreen����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteScreenClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := DeleteScreen_Dynamic(spnedt_PNo.Value);
  mmo_FunResultInfo.Lines.Add('ִ��DeleteScreen����, ' + GetFun_Result_Info(nResult));
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
  mmo_FunResultInfo.Lines.Add('ִ��AddScreenDynamicArea����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_UpDateDYAreaClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendDynamicAreaInfoCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value);
  mmo_FunResultInfo.Lines.Add('ִ��SendDynamicAreaInfoCommand����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteScreenDynamicAreasClick(Sender: TObject);
var
  szDYAreaIDList    : string;
  nResult           : Cardinal;
begin
  szDYAreaIDList := IntToStr(spnedt_DYAreaID.Value); //���ɾ�������̬���򣬶�̬�����ż���","������
  nResult := SendDeleteDynamicAreasCommand(spnedt_PNo.Value, 0
    , pChar(szDYAreaIDList));
  mmo_FunResultInfo.Lines.Add('ִ��SendDeleteDynamicAreasCommand����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DeleteAllDYAreaClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendDeleteDynamicAreasCommand(spnedt_PNo.Value, 1, '');
  mmo_FunResultInfo.Lines.Add('ִ��SendDeleteDynamicAreasCommand����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_UpdateDYAreaPageClick(Sender: TObject);
var
  nResult           : Cardinal;
begin
  nResult := SendUpdateDynamicAreaPageInfoCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value, spnedt_curlFileOrd.Value, spnedt_DYAreaPageOrd.Value);
  mmo_FunResultInfo.Lines.Add('ִ��SendUpdateDynamicAreaPageInfoCommand����, ' + GetFun_Result_Info(nResult));
end;

procedure Tfrm_Main.btn_DelDYAreaPageClick(Sender: TObject);
var
  szDYAreaPageOrdList: string;
  nResult           : Cardinal;
begin
//���ɾ����ǰ��̬�����ҳ���ݣ�ҳ��ż���","������
  szDYAreaPageOrdList := IntToStr(spnedt_DYAreaPageOrd.Value);
  nResult := SendDeleteDynamicAreaPageCommand(spnedt_PNo.Value, spnedt_DYAreaID.Value, pChar(szDYAreaPageOrdList));
  mmo_FunResultInfo.Lines.Add('ִ��SendDeleteDynamicAreaPageCommand����, ' + GetFun_Result_Info(nResult));
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
    RETURN_ERROR_NOFIND_DYNAMIC_AREA: result := 'û���ҵ���Ч�Ķ�̬����';
    RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD: result := '��ָ���Ķ�̬����û���ҵ�ָ�����ļ���š�';
    RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD: result := '��ָ���Ķ�̬����û���ҵ�ָ����ҳ��š�';
    RETURN_ERROR_NOSUPPORT_FILETYPE: result := '(��̬�ⲻ֧�ָ��ļ����͡�';
    RETURN_ERROR_RA_SCREENNO: result := 'ϵͳ���Ѿ��и���ʾ����Ϣ����Ҫ�����趨����ִ��DeleteScreen����ɾ������ʾ��������ӡ�';
    RETURN_ERROR_NOFIND_AREA: result := 'ϵͳ��û���ҵ���Ч�Ķ�̬���򣻿�����ִ��AddScreenDynamicArea������Ӷ�̬������Ϣ������ӡ�';
    RETURN_ERROR_NOFIND_SCREENNO: result := 'ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen������Ӹ���ʾ����';
    RETURN_ERROR_NOW_SENDING: result := 'ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��';
    RETURN_ERROR_OTHER: result := '��������';
    RETURN_NOERROR: result := '����ִ�гɹ���';
    $01..$18, $FE:
      Result := Result + 'ͨѶ����';
  else //ERRR_OTHER  Other Error;
    Result := Result + '��������';
  end;
end;

procedure Tfrm_Main.FormShow(Sender: TObject);
begin
  GetcurGrpCaption;
end;

procedure Tfrm_Main.GetcurGrpCaption;
begin
  grp_AddDynamicArea.Caption := grp_AddDynamicArea.Caption + '(���ţ�' + IntToStr(spnedt_PNo.Value) + ')';
  grp_AddDYAreaFile.Caption := grp_AddDYAreaFile.Caption + '(���ţ�' + IntToStr(spnedt_PNo.Value)
    + '����̬�����ţ�' + IntToStr(spnedt_DYAreaID.Value) + ')';
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
      TransitDeviceType := 'BX-3GPRS' //ONBON������-GPRS
    else
    if cbb_SendMode.ItemIndex = 3 then
      TransitDeviceType := 'BX-3G'; //ONBON������-3G

    nResult:=QuerryServerDeviceList(PChar(TransitDeviceType),PChar(edtServerIP.Text), edtServerPort.value,
    PChar(edtUserName.Text), PChar(edtPassword.Text),Devicelist,DeviceCount);
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
      , PChar(edt_FileName.Text), nSingleLine, PChar('����'), 12, 0, clRed
      , cbb_DYAreaStunt.ItemIndex, spnedt_DYAreaRunSpeed.Value, spnedt_DYAreaShowTime.Value);
      mmo_FunResultInfo.Lines.Add('ִ��AddScreenDynamicAreaFile����, ' + GetFun_Result_Info(nResult));
    end
    else
      ShowMessage('û�в��ҵ���Ч���ļ���');
  end
  else
    ShowMessage('���������Ч���ļ���');
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
      , PChar(mmo_Text.Text), nSingleLine, PChar('����'), 12, 0, clRed
      , cbb_DYAreaStunt.ItemIndex, spnedt_DYAreaRunSpeed.Value, spnedt_DYAreaShowTime.Value);
    mmo_FunResultInfo.Lines.Add('ִ��AddScreenDynamicAreaText����, ' + GetFun_Result_Info(nResult));
  end
  else
    ShowMessage('��������ı���');
end;

procedure Tfrm_Main.btn_DelFileClick(Sender: TObject);
var
  nFileOrd          : Cardinal;
  nResult           : Cardinal;
begin
  nFileOrd := spnedt_curlFileOrd.Value;
  nResult := DeleteScreenDynamicAreaFile(spnedt_PNo.Value, spnedt_DYAreaID.Value
    , nFileOrd);
  mmo_FunResultInfo.Lines.Add('ִ��DeleteScreenDynamicAreaFile����, ' + GetFun_Result_Info(nResult));
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

