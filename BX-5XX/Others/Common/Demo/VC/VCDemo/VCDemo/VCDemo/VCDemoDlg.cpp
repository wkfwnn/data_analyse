
// VCDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCDemo.h"
#include "VCDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------------------------
        // ����������
      #define BX_5AT  0x0051
      #define BX_5A0  0x0151
      #define BX_5A1  0x0251
      #define BX_5A2  0x0351
      #define BX_5A3  0x0451
      #define BX_5A4  0x0551
      #define BX_5A1_WIFI  0x0651
      #define BX_5A2_WIFI  0x0751
      #define BX_5A4_WIFI  0x0851
      #define BX_5A   0x0951
      #define BX_5A2_RF  0x1351
      #define BX_5A4_RF  0x1551
      #define BX_5AT_WIFI  0x1651
      #define BX_5AL  0x1851

      #define AX_AT   0x2051
      #define AX_A0   0x2151

      #define BX_5MT  0x0552
      #define BX_5M1  0x0052
      #define BX_5M1X  0x0152
      #define BX_5M2  0x0252
      #define BX_5M3  0x0352
      #define BX_5M4  0x0452

      #define BX_5E1  0x0154
      #define BX_5E2  0x0254
      #define BX_5E3  0x0354

      #define BX_5UT  0x0055
      #define BX_5U0  0x0155
      #define BX_5U1  0x0255
      #define BX_5U2  0x0355
      #define BX_5U3  0x0455
      #define BX_5U4  0x0555
      #define BX_5U5  0x0655
      #define BX_5U   0x0755
      #define BX_5UL  0x0855

      #define AX_UL   0x2055
      #define AX_UT   0x2155
      #define AX_U0   0x2255
      #define AX_U1   0x2355
      #define AX_U2   0x2455

      #define BX_5Q0  0x0056
      #define BX_5Q1  0x0156
      #define BX_5Q2  0x0256
      #define BX_5Q0P  0x1056
      #define BX_5Q1P  0x1156
      #define BX_5Q2P  0x1256
      #define BX_5QL  0x1356

      #define BX_5QS1  0x0157
      #define BX_5QS2  0x0257
      #define BX_5QS  0x0357
      #define BX_5QS1P  0x1157
      #define BX_5QS2P  0x1257
      #define BX_5QSP  0x1357

	  int controlType[52]  =  { BX_5AT, BX_5A0, BX_5A1, BX_5A2, BX_5A3, BX_5A4, BX_5A1_WIFI, BX_5A2_WIFI,
                                        BX_5A4_WIFI,BX_5A,BX_5A2_RF,BX_5A4_RF,BX_5AT_WIFI,BX_5AL,AX_AT,AX_A0,BX_5MT,BX_5M1,
                                        BX_5M1X,BX_5M2,BX_5M3,BX_5M4,BX_5E1,BX_5E2,BX_5E3,BX_5UT,BX_5U0,BX_5U1,BX_5U2,
                                        BX_5U3,BX_5U4,BX_5U5,BX_5U,BX_5UL,AX_UL,AX_UT,AX_U0,AX_U1,AX_U2,BX_5Q0,BX_5Q1,
                                        BX_5Q2,BX_5Q0P,BX_5Q1P,BX_5Q2P,BX_5QL,BX_5QS1,BX_5QS2,BX_5QS,BX_5QS1P,BX_5QS2P,BX_5QSP};

        //------------------------------------------------------------------------------
//                                                                              
// ������ͨѶģʽ
        #define SEND_MODE_COMM   0
	    #define SEND_MODE_GPRS   1
        #define SEND_MODE_NET   2
	    #define SEND_MODE_WIFI   4
        #define SEND_MODE_SERVER_2G 5
	    #define SEND_MODE_SERVER_3G 6
//                                                                              

//                                                                              
// �û�������Ϣ�����
        #define SEND_CMD_PARAMETER   0xA1FF //������������
        #define SEND_CMD_SCREENSCAN   0xA1FE //����ɨ�跽ʽ��
        #define SEND_CMD_SENDALLPROGRAM   0xA1F0 //�������н�Ŀ��Ϣ��
        #define SEND_CMD_POWERON   0xA2FF //ǿ�ƿ���
        #define SEND_CMD_POWEROFF   0xA2FE //ǿ�ƹػ�
        #define SEND_CMD_TIMERPOWERONOFF   0xA2FD //��ʱ���ػ�
        #define  SEND_CMD_CANCEL_TIMERPOWERONOFF   0xA2FC //ȡ����ʱ���ػ�
        #define SEND_CMD_RESIVETIME   0xA2FB //У��ʱ�䡣
        #define SEND_CMD_ADJUSTLIGHT   0xA2FA //���ȵ�����

//���ؽ��
	    #define RETURN_ERROR_AERETYPE  0xF7;//�������ʹ�������ӡ�ɾ��ͼ�������ļ�ʱ�������ͳ����ش����ʹ��� 
        #define RETURN_ERROR_RA_SCREENNO  0xF8;  //�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ������ӣ� 
        #define RETURN_ERROR_NOFIND_AREAFILE  0xF9; //û���ҵ���Ч�������ļ�(ͼ������)�� 
        #define RETURN_ERROR_NOFIND_AREA  0xFA;  //û���ҵ���Ч����ʾ���򣻿���ʹ��AddScreenProgramBmpTextArea���������Ϣ�� 
        #define RETURN_ERROR_NOFIND_PROGRAM  0xFB;  //û���ҵ���Ч����ʾ����Ŀ������ʹ��AddScreenProgram�������ָ����Ŀ 
        #define RETURN_ERROR_NOFIND_SCREENNO  0xFC;  //ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen���������ʾ�� 
        #define RETURN_ERROR_NOW_SENDING  0xFD; //ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��
        #define RETURN_ERROR_OTHER  0xFF; //�������� 
        #define RETURN_NOERROR  0; //û�д���

//                                                                              

        #define SCREEN_NO   1
        #define SCREEN_WIDTH   64
        #define SCREEN_HEIGHT   32
        #define SCREEN_TYPE   2
        #define SCREEN_DATADA   0
        #define SCREEN_DATAOE   0
        #define SCREEN_COMM   "COM4"
        #define SCREEN_BAUD   57600
        #define SCREEN_ROWORDER   0
        #define SCREEN_FREQPAR   0
	    #define SCREEN_DATAFLOW   0
        #define SCREEN_SOCKETIP   "192.168.1.2"
        #define SCREEN_SOCKETPORT   5005
        #define SCREEN_WiFiIP   "192.168.100.1"
        #define SCREEN_WiFiPORT   5005
/////////////////////////////////////////////////////////////////////////////

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVCDemoDlg �Ի���


void WINAPI CallBackMethod(char* szMessagge,int nProgress)
{
	
}

CVCDemoDlg::CVCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVCDemoDlg::IDD, pParent)
	, m_screenNo(0)
	, m_Radio1(0)
	, m_Radio2(0)
	, m_SocketIP(_T(""))
	, m_width(0)
	, m_height(0)
	, m_curProgramOrd(0)
	, m_curAreaOrd(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hInst = NULL;
	hInst = LoadLibrary(L"BX_IV.dll");
	Initialize = (pInitialize)GetProcAddress(hInst,"Initialize");
	Uninitialize = (pUninitialize)GetProcAddress(hInst,"Uninitialize");
	AddScreen = (pAddScreen)GetProcAddress(hInst,"AddScreen");
	DeleteScreen = (pDeleteScreen)GetProcAddress(hInst,"DeleteScreen");
	SendScreenInfo = (pSendScreenInfo)GetProcAddress(hInst,"SendScreenInfo");
	AddScreenProgram = (pAddScreenProgram)GetProcAddress(hInst,"AddScreenProgram");
	DeleteScreenProgram = (pDeleteScreenProgram)GetProcAddress(hInst,"DeleteScreenProgram");
	DeleteScreenProgramArea = (pDeleteScreenProgramArea)GetProcAddress(hInst,"DeleteScreenProgramArea");
	
	
	
	QuerryServerDeviceList = (pQuerryServerDeviceList)GetProcAddress(hInst,"QuerryServerDeviceList");
	BindServerDevice = (pBindServerDevice)GetProcAddress(hInst,"BindServerDevice");
	SetScreenAdjustLight = (pSetScreenAdjustLight)GetProcAddress(hInst,"SetScreenAdjustLight");
	SetScreenTimerPowerONOFF = (pSetScreenTimerPowerONOFF)GetProcAddress(hInst,"SetScreenTimerPowerONOFF");
	
	
	
	
	GetScreenStatus = (pGetScreenStatus)GetProcAddress(hInst,"GetScreenStatus");
	SaveUSBScreenInfo = (pSaveUSBScreenInfo)GetProcAddress(hInst,"SaveUSBScreenInfo");

	callBack = CallBackMethod;

}

void CVCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_EDIT1, m_screenNo);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Control(pDX, IDC_COMBO1, m_cbCtrlType);
	DDX_Control(pDX, IDC_COMBO2, m_SendMode);
	DDX_Control(pDX, IDC_SpGroup, m_spGroupBox);
	DDX_Control(pDX, IDC_COMBO4, m_Baud);
	DDX_Control(pDX, IDC_BaudText, m_baudText);
	DDX_Control(pDX, IDC_SpText, m_spText);
	DDX_Control(pDX, IDC_COMBO3, m_Sp);
	DDX_Control(pDX, IDC_NetGroupBox, m_netGroupBox);
	DDX_Radio(pDX, IDC_RADIO1, m_Radio1);
	DDX_Text(pDX, IDC_EDIT6, m_SocketIP);
	DDX_Control(pDX, IDC_SPIN6, m_spin6);
	DDX_Control(pDX, IDC_SPIN7, m_spin7);
	DDX_Control(pDX, IDC_BarcodeText, m_BarcodeText);
	DDX_Control(pDX, IDC_NetIDText2, m_NetIDText2);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_SPIN3, m_spin3);
	DDX_Control(pDX, IDC_COMBO5, m_ScreenType);
	DDX_Text(pDX, IDC_EDIT2, m_width);
	DDX_Text(pDX, IDC_EDIT3, m_height);
	DDX_Control(pDX, IDC_RICHEDIT21, m_RichEdit);
	DDX_Control(pDX, IDC_SPIN4, m_spin4);
	DDX_Control(pDX, IDC_SPIN5, m_spin5);
	DDX_Text(pDX, IDC_EDIT4, m_curProgramOrd);
	DDX_Text(pDX, IDC_EDIT5, m_curAreaOrd);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_EDIT13, m_Edit13);
	DDX_Control(pDX, IDC_EDIT14, m_Edit14);
	DDX_Control(pDX, IDC_COMBO6, m_Combo6);
}

BEGIN_MESSAGE_MAP(CVCDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CVCDemoDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, &CVCDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVCDemoDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CVCDemoDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO2, &CVCDemoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CVCDemoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON3, &CVCDemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CVCDemoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CVCDemoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CVCDemoDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CVCDemoDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON13, &CVCDemoDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CVCDemoDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CVCDemoDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CVCDemoDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON18, &CVCDemoDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON17, &CVCDemoDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON12, &CVCDemoDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CVCDemoDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CVCDemoDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CVCDemoDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CVCDemoDlg::OnBnClickedButton8)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON19, &CVCDemoDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CVCDemoDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CVCDemoDlg ��Ϣ�������

BOOL CVCDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_bSendBusy = false;

	//��ʼ�����ſؼ�
	m_spin1.SetRange(1,100);
	m_spin1.SetPos(1);
	m_screenNo=m_spin1.GetPos();

	//��ʼ�����ƿ��ͺ�combobox
	m_cbCtrlType.InsertString(0,L"BX_5AT");
	m_cbCtrlType.InsertString(1,L"BX_5A0");
	m_cbCtrlType.InsertString(2,L"BX_5A1");
	m_cbCtrlType.InsertString(3,L"BX_5A2");
	m_cbCtrlType.InsertString(4,L"BX_5A3");
	m_cbCtrlType.InsertString(5,L"BX_5A4");
	m_cbCtrlType.InsertString(6,L"BX_5A1_WIFI");
	m_cbCtrlType.InsertString(7,L"BX_5A2_WIFI");
	m_cbCtrlType.InsertString(8,L"BX_5A4_WIFI");
	m_cbCtrlType.InsertString(9,L"BX_5A");
	m_cbCtrlType.InsertString(10,L"BX_5A2_RF");
	m_cbCtrlType.InsertString(11,L"BX_5A4_RF");
	m_cbCtrlType.InsertString(12,L"BX_5AT_WIFI");
	m_cbCtrlType.InsertString(13,L"BX_5AL");
	m_cbCtrlType.InsertString(14,L"AX_AT");
	m_cbCtrlType.InsertString(15,L"AX_A0");
	m_cbCtrlType.InsertString(16,L"BX_5MT");
	m_cbCtrlType.InsertString(17,L"BX_5M1");
	m_cbCtrlType.InsertString(18,L"BX_5M1X");
	m_cbCtrlType.InsertString(19,L"BX_5M2");
	m_cbCtrlType.InsertString(20,L"BX_5M3");
	m_cbCtrlType.InsertString(21,L"BX_5M4");
	m_cbCtrlType.InsertString(22,L"BX_5E1");
	m_cbCtrlType.InsertString(23,L"BX_5E2");
	m_cbCtrlType.InsertString(24,L"BX_5E3");
	m_cbCtrlType.InsertString(25,L"BX_5UT");
	m_cbCtrlType.InsertString(26,L"BX_5U0");
	m_cbCtrlType.InsertString(27,L"BX_5U1");
	m_cbCtrlType.InsertString(28,L"BX_5U2");
	m_cbCtrlType.InsertString(29,L"BX_5U3");
	m_cbCtrlType.InsertString(30,L"BX_5U4");
	m_cbCtrlType.InsertString(31,L"BX_5U5");
	m_cbCtrlType.InsertString(32,L"BX_5U");
	m_cbCtrlType.InsertString(33,L"BX_5UL");
	m_cbCtrlType.InsertString(34,L"AX_UL");
	m_cbCtrlType.InsertString(35,L"AX_UT");
	m_cbCtrlType.InsertString(36,L"AX_U0");
	m_cbCtrlType.InsertString(37,L"AX_U1");
	m_cbCtrlType.InsertString(38,L"AX_U2");
	m_cbCtrlType.InsertString(39,L"BX_5Q0");
	m_cbCtrlType.InsertString(40,L"BX_5Q1");
	m_cbCtrlType.InsertString(41,L"BX_5Q2");
	m_cbCtrlType.InsertString(42,L"BX_5Q0P");
	m_cbCtrlType.InsertString(43,L"BX_5Q1P");
	m_cbCtrlType.InsertString(44,L"BX_5Q2P");
	m_cbCtrlType.InsertString(45,L"BX_5QL");
	m_cbCtrlType.InsertString(46,L"BX_5QS1");
	m_cbCtrlType.InsertString(47,L"BX_5QS2");
	m_cbCtrlType.InsertString(48,L"BX_5QS");
	m_cbCtrlType.InsertString(49,L"BX_5QS1P");
	m_cbCtrlType.InsertString(50,L"BX_5QS2P");
	m_cbCtrlType.InsertString(51,L"BX_5QSP");
	m_cbCtrlType.SetCurSel(0);//���ó�ʼ����

	//��ʼ��ͨѶģʽcombobox
	m_SendMode.InsertString(0,L"����ͨѶ");
	m_SendMode.InsertString(1,L"GPRS����ͨѶ");
	m_SendMode.InsertString(2,L"����ͨѶ");
	m_SendMode.InsertString(3,L"ONBON������-GPRS");
	m_SendMode.InsertString(4,L"ONBON������-3G");
	m_SendMode.InsertString(5,L"RFͨѶ");
	m_SendMode.SetCurSel(0);
	g_nSendMode = 0;

	//��ʼ������combobox
	m_Sp.InsertString(0,L"COM1");
	m_Sp.InsertString(1,L"COM2");
	m_Sp.InsertString(2,L"COM3");
	m_Sp.InsertString(3,L"COM4");
	m_Sp.InsertString(4,L"COM5");
	m_Sp.InsertString(5,L"COM6");
	m_Sp.SetCurSel(0);

	//��ʼ��������combobox
	m_Baud.InsertString(0,L"9600");
	m_Baud.InsertString(1,L"57600");
	m_Baud.SetCurSel(1);

	//��ʼ�������������ؼ�
	m_Radio1 = 0;
	GetDlgItem(IDC_EDIT6)->SetWindowText(L"192.168.1.2");
	m_spin6.SetRange(0,10000);
	m_spin6.SetPos(5005);
	GetDlgItem(IDC_EDIT8)->SetWindowText(L"BX-NET000001");

	//��ʼ��ONBON���������ؼ�
	GetDlgItem(IDC_EDIT9)->SetWindowText(L"112.65.245.174");
	m_spin7.SetRange(0,10000);
	m_spin7.SetPos(6055);
	GetDlgItem(IDC_EDIT11)->SetWindowText(L"chenm");
	GetDlgItem(IDC_EDIT12)->SetWindowText(L"chenmin");

	//����ͨѶģʽ���������ʾ������
	GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
	m_BarcodeText.ShowWindow(FALSE);
	m_Edit13.ShowWindow(FALSE);
	m_NetIDText2.ShowWindow(FALSE);
	m_Edit14.ShowWindow(FALSE);

	GetDlgItem(IDC_NetGroupBox)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO1)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
	GetDlgItem(IDC_IPText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
	GetDlgItem(IDC_PortText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
	GetDlgItem(IDC_SPIN6)->ShowWindow(FALSE);
	GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

	GetDlgItem(IDC_ServerGroupBox)->ShowWindow(FALSE);
	GetDlgItem(IDC_ServerIPText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
	GetDlgItem(IDC_ServerPortText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
	GetDlgItem(IDC_SPIN7)->ShowWindow(FALSE);
	GetDlgItem(IDC_UserText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
	GetDlgItem(IDC_PwdText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);

	//��ʼ������spin
	m_spin2.SetRange(64,4096);
	m_spin2.SetPos(64);
	m_spin2.SetBuddy(this->GetDlgItem(IDC_EDIT2));
	m_width = 64;

	//��ʼ������spin
	m_spin3.SetRange(16,512);
	m_spin3.SetPos(32);
	m_spin3.SetBuddy(this->GetDlgItem(IDC_EDIT3)); 
	m_height = 32;

	//��ʼ����Ŀ���spin
	m_spin4.SetRange(0,100);
	m_spin4.SetPos(0);

	//��ʼ���������spin
	m_spin5.SetRange(0,100);
	m_spin5.SetPos(0);

	//��ʼ������combobox
	m_ScreenType.InsertString(0,L"����ɫ");
	m_ScreenType.InsertString(1,L"˫��ɫ");
	m_ScreenType.InsertString(2,L"����ɫ");
	m_ScreenType.InsertString(3,L"ȫ��ɫ");
	m_ScreenType.InsertString(4,L"˫��ɫ�Ҷ�");
	m_ScreenType.SetCurSel(0);

	//��ʼ���̶�IPͨѶģʽ
	m_Combo6.InsertString(0,L"TCPģʽ");
	m_Combo6.InsertString(1,L"UDPģʽ");
	m_Combo6.SetCurSel(0);

	//��ʼ��slider�ؼ�
	m_slider.SetRange(0,15);
	m_slider.SetPos(8);

	//��ʼ��TabControl�ؼ�
	CRect tabRect;
	m_tab.InsertItem(0,_T("ͼ��������༭"));
	m_tab.InsertItem(1,_T("ʱ��������༭"));
	m_tab.InsertItem(2,_T("�¶�����"));
	m_tab.InsertItem(3,_T("ʪ������"));
	m_tab.InsertItem(4,_T("��������"));

	m_imageTextDlg.Create(IDD_ImageText_DIALOG,&m_tab);
	m_timeDlg.Create(IDD_Time_DIALOG,&m_tab);
	m_temperatureDlg.Create(IDD_Temperature_DIALOG,&m_tab);
	m_humidityDlg.Create(IDD_Humidity_DIALOG,&m_tab);
	m_noiseDlg.Create(IDD_Noise_DIALOG,&m_tab);

	m_tab.GetClientRect(&tabRect);    // ��ȡ��ǩ�ؼ��ͻ���Rect   
	// ����tabRect��ʹ�串�Ƿ�Χ�ʺϷ��ñ�ǩҳ   
    tabRect.left += 10;                  
    tabRect.right -= 1;   
    tabRect.top += 20;   
    tabRect.bottom -= 1; 

	m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
	m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVCDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVCDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVCDemoDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CRect tabRect;    // ��ǩ�ؼ��ͻ�����Rect   
  
    // ��ȡ��ǩ�ؼ��ͻ���Rect����������������ʺϷ��ñ�ǩҳ   
    m_tab.GetClientRect(&tabRect);   
    tabRect.left += 1;   
    tabRect.right -= 1;   
    tabRect.top += 25;   
    tabRect.bottom -= 1;   

	switch (m_tab.GetCurSel())   
	{
		case 0:   
			m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
			m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			break;
		case 1:
			m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
			m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			break;
		case 2:
			m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
			m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			break;
		case 3:
			m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
			m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			break;
		case 4:
			m_imageTextDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_timeDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_temperatureDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_humidityDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_noiseDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
			break;
		default:
			break;

	}
}


void CVCDemoDlg::OnBnClickedButton1()	//�����Ļ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strSocketIP;
	GetDlgItem(IDC_EDIT6)->GetWindowText(strSocketIP);
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *SocketIP = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,SocketIP,dwNum,0,NULL);
	

	int nServerMode;
    if (m_Radio1 == 0)
    {
		nServerMode = 0;
    }
    else 
	{
		nServerMode = 1; 
    }

	CString strBarcode;
	CString	strNetworkID;
			if (g_nSendMode == SEND_MODE_SERVER_2G || g_nSendMode == SEND_MODE_SERVER_3G)
            { 
				m_Edit13.GetWindowText(strBarcode);
				m_Edit14.GetWindowText(strNetworkID);
            }
            else if (g_nSendMode == SEND_MODE_NET)
            {
                strBarcode = "";
				GetDlgItem(IDC_EDIT8)->GetWindowText(strNetworkID);
            }
            else
            {
                strBarcode = "";
                strNetworkID = "";
            }
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strBarcode,-1,NULL,NULL,0,NULL);
	char *Barcode = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strBarcode,-1,Barcode,dwNum,0,NULL);

	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strNetworkID,-1,NULL,NULL,0,NULL);
	char *NetworkID = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strNetworkID,-1,NetworkID,dwNum,0,NULL);
	
	CString strCom;
	m_Sp.GetWindowText(strCom);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strCom,-1,NULL,NULL,0,NULL);
	char *Com = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strCom,-1,Com,dwNum,0,NULL);

	int tmp1 = controlType[m_cbCtrlType.GetCurSel()];
	int tmp2 = m_ScreenType.GetCurSel()+1;
	m_screenNo = m_spin1.GetPos();
	m_width = m_spin2.GetPos();
	m_height = m_spin3.GetPos();
	int SocketPort = m_spin6.GetPos();
	int result = AddScreen(tmp1, m_screenNo,g_nSendMode, m_width, m_height,
		tmp2, 2, SCREEN_DATADA, SCREEN_DATAOE, SCREEN_ROWORDER, SCREEN_DATAFLOW,SCREEN_FREQPAR, Com, SCREEN_BAUD, SocketIP, SocketPort,
                                m_Combo6.GetCurSel(),nServerMode, Barcode, NetworkID, "", 5005, "", "", SCREEN_WiFiIP,
                                SCREEN_WiFiPORT, "", 5005, "", "D:\\ScreenStatus.ini",callBack);

	GetErrorMessage("AddScreen", result);
}


void CVCDemoDlg::OnBnClickedButton2()	//ɾ����Ļ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screenNo = m_spin1.GetPos();
	int result = DeleteScreen(m_screenNo);
    GetErrorMessage("DeleteScreen", result);
}


void CVCDemoDlg::OnCbnSelchangeCombo2()	//ͨѶģʽcombobox��Ϣ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
			if(m_SendMode.GetCurSel() == 1)
			{
				g_nSendMode = SEND_MODE_GPRS; //���ڴ���
				
				GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
				m_BarcodeText.ShowWindow(FALSE);
				m_Edit13.ShowWindow(FALSE);
				m_NetIDText2.ShowWindow(FALSE);
				m_Edit14.ShowWindow(FALSE);

				m_spGroupBox.ShowWindow(TRUE);
				m_Baud.ShowWindow(TRUE);
				m_baudText.ShowWindow(TRUE);
				m_spText.ShowWindow(TRUE);
				m_Sp.ShowWindow(TRUE);

				GetDlgItem(IDC_NetGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
				GetDlgItem(IDC_IPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
				GetDlgItem(IDC_PortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN6)->ShowWindow(FALSE);
				GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

				GetDlgItem(IDC_ServerGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerIPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerPortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN7)->ShowWindow(FALSE);
				GetDlgItem(IDC_UserText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
				GetDlgItem(IDC_PwdText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);
			}
	        else if(m_SendMode.GetCurSel() == 2)
            {
                g_nSendMode = SEND_MODE_NET; //���紫��

				GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
				m_BarcodeText.ShowWindow(FALSE);
				m_Edit13.ShowWindow(FALSE);
				m_NetIDText2.ShowWindow(FALSE);
				m_Edit14.ShowWindow(FALSE);

				m_spGroupBox.ShowWindow(FALSE);
				m_Baud.ShowWindow(FALSE);
				m_baudText.ShowWindow(FALSE);
				m_spText.ShowWindow(FALSE);
				m_Sp.ShowWindow(FALSE);

				GetDlgItem(IDC_NetGroupBox)->ShowWindow(TRUE);
				GetDlgItem(IDC_RADIO1)->ShowWindow(TRUE);
				GetDlgItem(IDC_RADIO2)->ShowWindow(TRUE);
				GetDlgItem(IDC_IPText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
				GetDlgItem(IDC_PortText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
				GetDlgItem(IDC_SPIN6)->ShowWindow(TRUE);
				GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

				GetDlgItem(IDC_ServerGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerIPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerPortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN7)->ShowWindow(FALSE);
				GetDlgItem(IDC_UserText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
				GetDlgItem(IDC_PwdText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);
            }
            else if(m_SendMode.GetCurSel() == 3)
            {
                g_nSendMode = SEND_MODE_SERVER_2G;//ONBON������-GPRS

				GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
				m_BarcodeText.ShowWindow(TRUE);
				m_Edit13.ShowWindow(TRUE);
				m_NetIDText2.ShowWindow(FALSE);
				m_Edit14.ShowWindow(FALSE);

				m_spGroupBox.ShowWindow(FALSE);
				m_Baud.ShowWindow(FALSE);
				m_baudText.ShowWindow(FALSE);
				m_spText.ShowWindow(FALSE);
				m_Sp.ShowWindow(FALSE);

				GetDlgItem(IDC_NetGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
				GetDlgItem(IDC_IPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
				GetDlgItem(IDC_PortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN6)->ShowWindow(FALSE);
				GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

				GetDlgItem(IDC_ServerGroupBox)->ShowWindow(TRUE);
				GetDlgItem(IDC_ServerIPText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT9)->ShowWindow(TRUE);
				GetDlgItem(IDC_ServerPortText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT10)->ShowWindow(TRUE);
				GetDlgItem(IDC_SPIN7)->ShowWindow(TRUE);
				GetDlgItem(IDC_UserText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT11)->ShowWindow(TRUE);
				GetDlgItem(IDC_PwdText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT12)->ShowWindow(TRUE);
            }
            else if(m_SendMode.GetCurSel() == 4)
            {
                g_nSendMode = SEND_MODE_SERVER_3G;//ONBON������-3G  

				GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
				m_BarcodeText.ShowWindow(TRUE);
				m_Edit13.ShowWindow(TRUE);
				m_NetIDText2.ShowWindow(TRUE);
				m_Edit14.ShowWindow(TRUE);

				m_spGroupBox.ShowWindow(FALSE);
				m_Baud.ShowWindow(FALSE);
				m_baudText.ShowWindow(FALSE);
				m_spText.ShowWindow(FALSE);
				m_Sp.ShowWindow(FALSE);

				GetDlgItem(IDC_NetGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
				GetDlgItem(IDC_IPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
				GetDlgItem(IDC_PortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN6)->ShowWindow(FALSE);
				GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

				GetDlgItem(IDC_ServerGroupBox)->ShowWindow(TRUE);
				GetDlgItem(IDC_ServerIPText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT9)->ShowWindow(TRUE);
				GetDlgItem(IDC_ServerPortText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT10)->ShowWindow(TRUE);
				GetDlgItem(IDC_SPIN7)->ShowWindow(TRUE);
				GetDlgItem(IDC_UserText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT11)->ShowWindow(TRUE);
				GetDlgItem(IDC_PwdText)->ShowWindow(TRUE);
				GetDlgItem(IDC_EDIT12)->ShowWindow(TRUE);
            }
            else
            {
                g_nSendMode = SEND_MODE_COMM; //���ڴ���
				
				GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
				m_BarcodeText.ShowWindow(FALSE);
				m_NetIDText2.ShowWindow(FALSE);

				m_spGroupBox.ShowWindow(TRUE);
				m_Baud.ShowWindow(TRUE);
				m_baudText.ShowWindow(TRUE);
				m_spText.ShowWindow(TRUE);
				m_Sp.ShowWindow(TRUE);

				GetDlgItem(IDC_NetGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->ShowWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
				GetDlgItem(IDC_IPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
				GetDlgItem(IDC_PortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN6)->ShowWindow(FALSE);
				GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);

				GetDlgItem(IDC_ServerGroupBox)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerIPText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
				GetDlgItem(IDC_ServerPortText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
				GetDlgItem(IDC_SPIN7)->ShowWindow(FALSE);
				GetDlgItem(IDC_UserText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
				GetDlgItem(IDC_PwdText)->ShowWindow(FALSE);
				GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);
            }
}


void CVCDemoDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_NetIDText)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(TRUE);
}


void CVCDemoDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_NetIDText)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
}

void CVCDemoDlg::GetErrorMessage(char* szfunctionName, int nResult)
{
	CString szResult;
	CTime time = CTime::GetCurrentTime(); ///����CTime����
	CString m_strTime = time.Format("%Y-%m-%d %H:%M:%S");
	m_RichEdit.ReplaceSel(m_strTime);
	m_RichEdit.ReplaceSel(L"---ִ�к�����");
	CString functionName(szfunctionName);
	m_RichEdit.ReplaceSel(functionName);
	m_RichEdit.ReplaceSel(L"---���ؽ����");

	CString returnResult;
	switch (nResult)
            {
                case 0xF7:
                    returnResult = "�������ʹ�������ӡ�ɾ��ͼ�������ļ�ʱ�������ͳ����ش����ʹ���\r\n";
                    break;
                case 0xF8:
                    returnResult = "�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ�������\r\n";
                    break;
                case 0xF9:
                    returnResult = "û���ҵ���Ч�������ļ�(ͼ������)\r\n";
                    break;
                case 0xFA:
                    returnResult = "û���ҵ���Ч����ʾ�������ʹ��AddScreenProgramBmpTextArea���������Ϣ��\r\n";
                    break;
                case 0xFB:
                    returnResult = "û���ҵ���Ч����ʾ����Ŀ����ʹ��AddScreenProgram�������ָ����Ŀ\r\n";
                    break;
                case 0xFC:
                    returnResult = "ϵͳ��û�в��ҵ�����ʾ������ʹ��AddScreen���������ʾ��\r\n";
                    break;
                case 0xFD:
                    returnResult = "ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ\r\n";
                    break;
                case 0xFF:
                    returnResult = "��������\r\n";
                    break;
                case 0:
                    returnResult = "����ִ��/ͨѶ�ɹ�\r\n";
                    break;
                case 0x01:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x02:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x03:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x04:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x05:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x06:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x07:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x08:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x09:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0A:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0B:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0C:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0D:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0E:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x0F:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x10:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x11:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x12:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x13:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x14:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x15:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x16:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x17:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0x18:
                    returnResult = "ͨѶ����\r\n";
                    break;
                case 0xFE:
                    returnResult = "ͨѶ����\r\n";
                    break;
            }
	m_RichEdit.ReplaceSel(returnResult);
}

//void WINAPI CVCDemoDlg::CallBackMethod(char* szMessagge,int nProgress)
//{
//	char* tmpResult = szMessagge;
//	m_RichEdit.SetWindowTextW(L"Wait");
//}

void CVCDemoDlg::OnBnClickedButton3()	//������Ļ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bSendBusy == false)
    {
     m_bSendBusy = true;
     int nResult;

     //nResult = SendScreenInfo(m_screenNo, g_nSendMode, SEND_CMD_PARAMETER, 0,callBack);

     nResult = SendScreenInfo(m_screenNo,SEND_CMD_PARAMETER, 0);
     GetErrorMessage("SendScreenInfo", nResult);
     m_bSendBusy = false;
	}
}


void CVCDemoDlg::OnBnClickedButton4()	//�������豸
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screenNo = m_spin1.GetPos();
	int nResult;
    nResult = BindServerDevice(m_screenNo, "", "");
    GetErrorMessage("BindServerDevice", nResult);
}


void CVCDemoDlg::OnBnClickedButton5()	//��ӽ�Ŀ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screenNo = m_spin1.GetPos();
	int rusult = AddScreenProgram(m_screenNo, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59);
    GetErrorMessage("AddScreenProgram", rusult);
}


void CVCDemoDlg::OnBnClickedButton6()	//ɾ��ϵͳ��ǰ��Ŀ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screenNo = m_spin1.GetPos();
	m_curProgramOrd = m_spin4.GetPos();
	int result = DeleteScreenProgram(m_screenNo, m_curProgramOrd);
    GetErrorMessage("DeleteScreenProgram", result);
}


void CVCDemoDlg::OnBnClickedButton7()	//ɾ��ϵͳ��ǰ��Ŀ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_screenNo = m_spin1.GetPos();
	m_curProgramOrd = m_spin4.GetPos();
	m_curAreaOrd = m_spin5.GetPos();
	int nResult;
    nResult = DeleteScreenProgramArea(m_screenNo, m_curProgramOrd, m_curAreaOrd);
    GetErrorMessage("DeleteScreenProgramArea", nResult);
}


void CVCDemoDlg::OnBnClickedButton13()	//ǿ�ƹػ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bSendBusy == false)
    {
		m_bSendBusy = true;
		//��������
		int nResult;

		nResult = SendScreenInfo(m_screenNo, SEND_CMD_POWEROFF, 0);
		GetErrorMessage("SendScreenInfo", nResult);
		m_bSendBusy = false;
    }
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton14()	//ǿ�ƿ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bSendBusy == false)
    {
		m_bSendBusy = true;
		//��������
		int nResult;

		nResult = SendScreenInfo(m_screenNo, SEND_CMD_POWERON, 0);
		GetErrorMessage("SendScreenInfo", nResult);
		m_bSendBusy = false;
    }
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton15()	//��ʱ���ػ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    nResult = SetScreenTimerPowerONOFF(m_screenNo, 7, 0, 8, 0
    , 255, 255, 255, 255
    , 255, 255, 255, 255);
    GetErrorMessage("SetScreenTimerPowerONOFF", nResult);

    if (m_bSendBusy == false)
	{
       m_bSendBusy = true;
       nResult = SendScreenInfo(m_screenNo, SEND_CMD_TIMERPOWERONOFF, 0);
       GetErrorMessage("SendScreenInfo", nResult);
       m_bSendBusy = false;
	}
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton16()	//ȡ����ʱ���ػ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    if (m_bSendBusy == false)
	{
		m_bSendBusy = true;
		nResult = SendScreenInfo(m_screenNo, SEND_CMD_CANCEL_TIMERPOWERONOFF, 0);
		GetErrorMessage("SendScreenInfo", nResult);
		m_bSendBusy = false;
	}
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton18()	//��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
	nResult = SetScreenAdjustLight(m_screenNo, 0, m_slider.GetPos(),
                 7, 0, 1,
                 11, 0, 5,
                 12, 0, 8,
                 14, 0, 14);

	if (m_bSendBusy == false)
	{
		m_bSendBusy = true;
		nResult = SendScreenInfo(m_screenNo, SEND_CMD_ADJUSTLIGHT, 0);
		GetErrorMessage("SendScreenInfo", nResult);
		m_bSendBusy = false;
	}
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton17()	//У��ʱ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
	if (m_bSendBusy == false)
	{
		m_bSendBusy = true;
		nResult = SendScreenInfo(m_screenNo, SEND_CMD_RESIVETIME, 0);
		GetErrorMessage("SendScreenInfo", nResult);
		m_bSendBusy = false;
	}
	else
	{
		MessageBox(L"XXX");
	}
}


void CVCDemoDlg::OnBnClickedButton12()	//��ѯ��ǰ��ʾ��״̬
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    nResult = GetScreenStatus(m_screenNo, g_nSendMode);
    GetErrorMessage("GetScreenStatus",nResult);
}


void CVCDemoDlg::OnBnClickedButton11()	//���浽USB
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = SaveUSBScreenInfo(m_screenNo, 1, 0, 1, "E:\\");
    GetErrorMessage("SaveUSBScreenInfo", nResult);
}


void CVCDemoDlg::OnBnClickedButton10()	//������ʾ����Ŀ��Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bSendBusy == false)
    {
     m_bSendBusy = true;
     int nResult;

     nResult = SendScreenInfo(m_screenNo, SEND_CMD_SENDALLPROGRAM, 0);

     //nResult = SendScreenInfo(1, 2, 41471, 0);
     GetErrorMessage("SendScreenInfo", nResult);
     m_bSendBusy = false;
	}
}


void CVCDemoDlg::OnBnClickedButton9()	//��ʼ���½�Ŀ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1,200,NULL);
}


void CVCDemoDlg::OnBnClickedButton8()	//ֹͣ���½�Ŀ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}


void CVCDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);
	OnBnClickedButton10();
}


void CVCDemoDlg::OnBnClickedButton19()	//��ʼ����̬��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = Initialize();
	GetErrorMessage("Initialize", nResult);
}


void CVCDemoDlg::OnBnClickedButton20()	//�ͷŶ�̬��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = Uninitialize();
	GetErrorMessage("Uninitialize", nResult);
}
