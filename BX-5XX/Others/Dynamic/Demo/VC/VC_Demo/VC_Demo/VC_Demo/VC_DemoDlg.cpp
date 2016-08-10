
// VC_DemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VC_Demo.h"
#include "VC_DemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//------------------------------------------------------------------------------
			//����������
		#define BX_5E1  0x0154
        #define BX_5E2  0x0254
        #define BX_5E3  0x0354
        #define BX_5Q0P  0x1056
        #define BX_5Q1P  0x1156
        #define BX_5Q2P  0x1256

		int controlType[6]  =  {BX_5E1,BX_5E2,BX_5E3,BX_5Q0P,BX_5Q1P,BX_5Q2P};

		//----------------------------------------------------------------------

		#define FRAME_SINGLE_COLOR_COUNT  23 //��ɫ�߿�ͼƬ����
        #define FRAME_MULI_COLOR_COUNT  47 //��ɫ�߿�ͼƬ����

//------------------------------------------------------------------------------
        // ͨѶģʽ
        #define SEND_MODE_SERIALPORT  0
        #define SEND_MODE_NETWORK  2
        #define SEND_MODE_Server_2G  5
        #define SEND_MODE_Server_3G  6
        #define SEND_MODE_SAVEFILE  7
        //------------------------------------------------------------------------------
        //------------------------------------------------------------------------------
        // ��̬��������ģʽ
        #define RUN_MODE_CYCLE_SHOW  0 //��̬������ѭ����ʾ��
        #define RUN_MODE_SHOW_LAST_PAGE  1 //��̬��������ʾ��ɺ�ֹ��ʾ���һҳ���ݣ�
        #define RUN_MODE_SHOW_CYCLE_WAITOUT_NOSHOW  2 //��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ������ʾ��
        #define RUN_MODE_SHOW_ORDERPLAYED_NOSHOW  4 //��̬������˳����ʾ����ʾ�����һҳ��Ͳ�����ʾ
        //------------------------------------------------------------------------------
        //==============================================================================
        // ����״̬���붨��
        #define RETURN_ERROR_NOFIND_DYNAMIC_AREA  0xE1 //û���ҵ���Ч�Ķ�̬����
        #define RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD  0xE2 //��ָ���Ķ�̬����û���ҵ�ָ�����ļ���š�
        #define RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD  0xE3 //��ָ���Ķ�̬����û���ҵ�ָ����ҳ��š�
        #define RETURN_ERROR_NOSUPPORT_FILETYPE  0xE4 //��֧�ָ��ļ����͡�
        #define RETURN_ERROR_RA_SCREENNO  0xF8 //�Ѿ��и���ʾ����Ϣ����Ҫ�����趨����DeleteScreenɾ������ʾ������ӣ�
        #define RETURN_ERROR_NOFIND_AREA  0xFA //û���ҵ���Ч����ʾ���򣻿���ʹ��AddScreenProgramBmpTextArea���������Ϣ��
        #define RETURN_ERROR_NOFIND_SCREENNO  0xFC //ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen���������ʾ��
        #define RETURN_ERROR_NOW_SENDING  0xFD //ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��
        #define RETURN_ERROR_OTHER  0xFF //��������
        #define RETURN_NOERROR  0 //û�д���
        //==============================================================================

		#define SCREEN_NO  1
        #define SCREEN_WIDTH  192
        #define SCREEN_HEIGHT  96
        #define SCREEN_TYPE  2
        #define SCREEN_DATADA  0
        #define SCREEN_DATAOE  0
        #define SCREEN_COMM  "COM1"
        #define SCREEN_BAUD  57600
        #define SCREEN_ROWORDER  0
        #define SCREEN_FREQPAR  0
        #define SCREEN_SOCKETIP  "192.168.2.199"
        #define SCREEN_SOCKETPORT  5005
        //#define m_bSendBusy  false	�˱��������ݸ����зǳ���Ҫ������ر�����
        #define FAddDynamicArea  "�ڶ���-----��Ӷ�̬����"
        #define FAddDYAreaFile  "������-----��̬�����ļ�����"


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


// CVC_DemoDlg �Ի���




CVC_DemoDlg::CVC_DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVC_DemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hInst = NULL;
	hInst = LoadLibrary(L"LedDynamicArea.dll");
	Initialize = (pInitialize)GetProcAddress(hInst,"Initialize");
	Uninitialize = (pUninitialize)GetProcAddress(hInst,"Uninitialize");
	AddScreen_Dynamic = (pAddScreen_Dynamic)GetProcAddress(hInst,"AddScreen_Dynamic");
	QuerryServerDeviceList = (pQuerryServerDeviceList)GetProcAddress(hInst,"QuerryServerDeviceList");
	BindServerDevice = (pBindServerDevice)GetProcAddress(hInst,"BindServerDevice");
	AddScreenDynamicArea = (pAddScreenDynamicArea)GetProcAddress(hInst,"AddScreenDynamicArea");
	AddScreenDynamicAreaFile = (pAddScreenDynamicAreaFile)GetProcAddress(hInst,"AddScreenDynamicAreaFile");
	AddScreenDynamicAreaText = (pAddScreenDynamicAreaText)GetProcAddress(hInst,"AddScreenDynamicAreaText");
	DeleteScreen_Dynamic = (pDeleteScreen_Dynamic)GetProcAddress(hInst,"DeleteScreen_Dynamic");
	DeleteScreenDynamicAreaFile = (pDeleteScreenDynamicAreaFile)GetProcAddress(hInst,"DeleteScreenDynamicAreaFile");
	SendDynamicAreaInfoCommand = (pSendDynamicAreaInfoCommand)GetProcAddress(hInst,"SendDynamicAreaInfoCommand");
	SendDeleteDynamicAreasCommand = (pSendDeleteDynamicAreasCommand)GetProcAddress(hInst,"SendDeleteDynamicAreasCommand");
}

void CVC_DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_ctrlRadio1);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_SPIN4, m_Spin4);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_COMBO5, m_Combo5);
	DDX_Control(pDX, IDC_COMBO6, m_Combo6);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_EDIT8, m_Edit8);
	DDX_Control(pDX, IDC_SPIN5, m_Spin5);
	DDX_Control(pDX, IDC_EDIT9, m_Edit9);
	DDX_Control(pDX, IDC_EDIT10, m_Edit10);
	DDX_Control(pDX, IDC_EDIT11, m_Edit11);
	DDX_Control(pDX, IDC_SPIN1, m_Spin1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_SPIN2, m_Spin2);
	DDX_Control(pDX, IDC_SPIN3, m_Spin3);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_COMBO4, m_Combo4);
	DDX_Control(pDX, IDC_COMBO11, m_Combo11);
	DDX_Control(pDX, IDC_RICHEDIT21, m_RichEdit);
	DDX_Control(pDX, IDC_SPIN6, m_Spin6);
	DDX_Control(pDX, IDC_SPIN7, m_Spin7);
	DDX_Control(pDX, IDC_SPIN8, m_Spin8);
	DDX_Control(pDX, IDC_SPIN9, m_Spin9);
	DDX_Control(pDX, IDC_SPIN10, m_Spin10);
	DDX_Control(pDX, IDC_COMBO7, m_Combo7);
	DDX_Control(pDX, IDC_SPIN11, m_Spin11);
	DDX_Control(pDX, IDC_COMBO8, m_Combo8);
	DDX_Control(pDX, IDC_RADIO3, m_Radio3);
	DDX_Control(pDX, IDC_RADIO4, m_Radio4);
	DDX_Control(pDX, IDC_SPIN12, m_Spin12);
	DDX_Control(pDX, IDC_SPIN13, m_Spin13);
	DDX_Control(pDX, IDC_SPIN14, m_Spin14);
	DDX_Control(pDX, IDC_COMBO9, m_Combo9);
	DDX_Control(pDX, IDC_SPIN15, m_Spin15);
	DDX_Control(pDX, IDC_SPIN16, m_Spin16);
	DDX_Control(pDX, IDC_RADIO6, m_Radio6);
	DDX_Control(pDX, IDC_RADIO5, m_Radio5);
	DDX_Control(pDX, IDC_EDIT23, m_Edit23);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_COMBO10, m_Combo10);
	DDX_Control(pDX, IDC_SPIN17, m_Spin17);
	DDX_Control(pDX, IDC_SPIN18, m_Spin18);
	DDX_Control(pDX, IDC_CHECK3, m_Check3);
	DDX_Control(pDX, IDC_LIST1, m_ListBox1);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT12, m_Edit12);
}

BEGIN_MESSAGE_MAP(CVC_DemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CVC_DemoDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO1, &CVC_DemoDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CVC_DemoDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON4, &CVC_DemoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CVC_DemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CVC_DemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CVC_DemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO3, &CVC_DemoDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CVC_DemoDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON5, &CVC_DemoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CVC_DemoDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CVC_DemoDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON10, &CVC_DemoDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CVC_DemoDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CVC_DemoDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CVC_DemoDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CVC_DemoDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CVC_DemoDlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CVC_DemoDlg ��Ϣ�������

BOOL CVC_DemoDlg::OnInitDialog()
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

	//��ʼ����ʾ����ʼ��GroupBox
	m_Spin1.SetRange(1,255);
	m_Spin1.SetPos(1);
	m_Combo1.InsertString(0,L"BX-5E1");
	m_Combo1.InsertString(1,L"BX-5E2");
	m_Combo1.InsertString(2,L"BX-5E3");
	m_Combo1.InsertString(3,L"BX-5Q1+");
	m_Combo1.InsertString(4,L"BX-5Q2+");
	m_Combo1.InsertString(5,L"BX-5Q3+");
	m_Combo1.SetCurSel(0);
	m_Combo2.InsertString(0,L"����ͨѶ");
	m_Combo2.InsertString(1,L"����ͨѶ");
	m_Combo2.InsertString(2,L"ONBON������-GPRS");
	m_Combo2.InsertString(3,L"ONBON������-3G");
	m_Combo2.InsertString(4,L"���浽�ļ�");
	m_Combo2.SetCurSel(1);
	m_Spin2.SetRange(0,4096);
	m_Spin2.SetPos(80);
	m_Spin3.SetRange(0,512);
	m_Spin3.SetPos(16);
	m_Combo3.InsertString(0,L"����ɫ");
	m_Combo3.InsertString(1,L"˫��ɫ");
	m_Combo3.InsertString(2,L"ȫ��ɫ");
	m_Combo3.SetCurSel(0);
	m_Combo4.InsertString(0,L"I  (R+G)");
	m_Combo4.InsertString(1,L"II (G+R)");
	m_Combo4.SetCurSel(0);
	m_Combo11.InsertString(0,L"TCPģʽ");
	m_Combo11.InsertString(1,L"UDPģʽ");
	m_Combo11.SetCurSel(0);

	//����ͨѶģʽ���������ʾ������
	GetDlgItem(IDC_GrpNet)->ShowWindow(TRUE);
	m_ctrlRadio1.ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->ShowWindow(TRUE);
	GetDlgItem(IDC_textNetIP)->ShowWindow(TRUE);
	m_Edit4.ShowWindow(TRUE);
	GetDlgItem(IDC_textNetPort)->ShowWindow(TRUE);
	m_Edit5.ShowWindow(TRUE);
	m_Spin4.ShowWindow(TRUE);
	GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
	m_Edit6.ShowWindow(FALSE);

	GetDlgItem(IDC_GrpSp)->ShowWindow(FALSE);
	GetDlgItem(IDC_textSp)->ShowWindow(FALSE);
	m_Combo5.ShowWindow(FALSE);
	GetDlgItem(IDC_textBaud)->ShowWindow(FALSE);
	m_Combo6.ShowWindow(FALSE);

	GetDlgItem(IDC_GrpServer)->ShowWindow(FALSE);
	GetDlgItem(IDC_textServerIP)->ShowWindow(FALSE);
	m_Edit7.ShowWindow(FALSE);
	GetDlgItem(IDC_textServerPort)->ShowWindow(FALSE);
	m_Edit8.ShowWindow(FALSE);
	m_Spin5.ShowWindow(FALSE);
	GetDlgItem(IDC_textServerUser)->ShowWindow(FALSE);
	m_Edit9.ShowWindow(FALSE);
	GetDlgItem(IDC_textServerPwd)->ShowWindow(FALSE);
	m_Edit10.ShowWindow(FALSE);

	GetDlgItem(IDC_GrpSave)->ShowWindow(FALSE);
	GetDlgItem(IDC_textSave)->ShowWindow(FALSE);
	m_Edit11.ShowWindow(FALSE);

	GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);

	//ͨѶģʽ����GroupBox��ؿؼ���ʼ��
	m_Combo5.InsertString(0,L"COM1");
	m_Combo5.InsertString(1,L"COM2");
	m_Combo5.InsertString(2,L"COM3");
	m_Combo5.InsertString(3,L"COM4");
	m_Combo5.InsertString(4,L"COM5");
	m_Combo5.InsertString(5,L"COM6");
	m_Combo5.InsertString(6,L"COM7");
	m_Combo5.InsertString(7,L"COM8");
	m_Combo5.InsertString(8,L"COM9");
	m_Combo5.InsertString(9,L"COM10");
	m_Combo5.SetCurSel(0);
	m_Combo6.InsertString(0,L"9600");
	m_Combo6.InsertString(1,L"57600");
	m_Combo6.SetCurSel(1);
	m_ctrlRadio1.SetCheck(TRUE);
	m_Edit4.SetWindowText(L"192.168.0.15");
	m_Spin4.SetRange(1000,9999);
	m_Spin4.SetPos(5005);
	m_Spin5.SetRange(1000,9999);
	m_Spin5.SetPos(5005);
	m_Edit11.SetWindowText(L"curCommandData.dat");

	//�ڶ�����Ӷ�̬������ؿؼ���ʼ��
	m_Spin6.SetRange(0,3);
	m_Spin6.SetPos(0);
	m_Spin7.SetRange(0,8192);
	m_Spin7.SetPos(0);
	m_Spin8.SetRange(0,512);
	m_Spin8.SetPos(0);
	m_Spin9.SetRange(8,8192);
	m_Spin9.SetPos(8);
	m_Spin10.SetRange(8,512);
	m_Spin10.SetPos(8);
	m_Combo7.InsertString(0,L"��̬������ѭ����ʾ");
	m_Combo7.InsertString(1,L"��ʾ��ɺ�ֹ��ʾ���һҳ");
	m_Combo7.InsertString(2,L"��ʱ��δ����ɾ����̬��");
	m_Combo7.InsertString(3,L"˳����ʾ������ҳ��Ͳ�����ʾ ");
	m_Combo7.SetCurSel(0);
	m_Spin11.SetRange32(1,65535);
	m_Spin11.SetPos(1);
	m_Combo8.InsertString(0,L"���Ŀһ�𲥷�(��̬�������첽��Ŀ����Ч)");
	m_Combo8.InsertString(1,L"��Ŀֹͣ���ţ������Ÿö�̬����");
	m_Combo8.SetCurSel(0);
	m_Radio3.SetCheck(TRUE);
	m_Spin12.SetRange(0,23);
	m_Spin12.SetPos(0);
	m_Spin13.SetRange32(0,65535);
	m_Spin13.SetPos(255);
	m_Spin14.SetRange(0,46);
	m_Spin14.SetPos(0);
	m_Combo9.InsertString(0,L"0-��˸ ");
	m_Combo9.InsertString(1,L"1 �C˳ʱ��ת�� ");
	m_Combo9.InsertString(2,L"2 �C��ʱ��ת�� ");
	m_Combo9.InsertString(3,L"3 �C��˸��˳ʱ��ת��");
	m_Combo9.InsertString(4,L"4 �C��˸����ʱ��ת��");
	m_Combo9.InsertString(5,L"5 �C���̽�����˸");
	m_Combo9.InsertString(6,L"6 �C���̽���ת��");
	m_Combo9.InsertString(7,L"7 �C��ֹ���");
	m_Combo9.SetCurSel(1);
	m_Spin15.SetRange32(0,65535);
	m_Spin15.SetPos(0);
	m_Spin16.SetRange(1,32);
	m_Spin16.SetPos(1);
	m_Radio6.SetCheck(TRUE);
	GetCurGrpCaption();

	//��������̬�����ļ�������ؿؼ���ʼ��
	m_Combo10.InsertString(0,L"0 �C�����ʾ");
	m_Combo10.InsertString(1,L"1 �C��ֹ��ʾ");
	m_Combo10.InsertString(2,L"2 �C���ٴ��");
	m_Combo10.InsertString(3,L"3 �C�����ƶ�");
	m_Combo10.InsertString(4,L"4 �C��������");
	m_Combo10.InsertString(5,L"5 �C�����ƶ�");
	m_Combo10.InsertString(6,L"6 �C��������");
	m_Combo10.InsertString(7,L"7 �C��˸");
	m_Combo10.InsertString(8,L"8 �CƮѩ");
	m_Combo10.InsertString(9,L"9 �Cð��");
	m_Combo10.InsertString(10,L"10 �C�м��Ƴ�");
	m_Combo10.InsertString(11,L"11 �C��������");
	m_Combo10.InsertString(12,L"12 �C���ҽ�������");
	m_Combo10.InsertString(13,L"13 �C���½�������");
	m_Combo10.InsertString(14,L"14 �C����պ�");
	m_Combo10.InsertString(15,L"15 �C�����");
	m_Combo10.InsertString(16,L"16 �C��������");
	m_Combo10.InsertString(17,L"17 �C��������");
	m_Combo10.InsertString(18,L"18 �C��������");
	m_Combo10.InsertString(19,L"19 �C��������");
	m_Combo10.InsertString(20,L"20 �C��������");
	m_Combo10.InsertString(21,L"21 �C��������");
	m_Combo10.InsertString(22,L"22 �C��������");
	m_Combo10.InsertString(23,L"23 �C��������");
	m_Combo10.InsertString(24,L"24 �C���ҽ�����Ļ");
	m_Combo10.InsertString(25,L"25 �C���½�����Ļ");
	m_Combo10.InsertString(26,L"26 �C��ɢ����");
	m_Combo10.InsertString(27,L"27 �Cˮƽ��ҳ");
	m_Combo10.InsertString(28,L"28 �C��ֱ��ҳ");
	m_Combo10.InsertString(29,L"29 �C������Ļ");
	m_Combo10.InsertString(30,L"30 �C������Ļ");
	m_Combo10.InsertString(31,L"31 �C������Ļ");
	m_Combo10.InsertString(32,L"32 �C������Ļ");
	m_Combo10.InsertString(33,L"33 �C���ұպ�");
	m_Combo10.InsertString(34,L"34 �C���ҶԿ�");
	m_Combo10.InsertString(35,L"35 �C���±պ�");
	m_Combo10.InsertString(36,L"36 �C���¶Կ�");
	m_Combo10.InsertString(37,L"37 �C�����ƶ�");
	m_Combo10.InsertString(38,L"38 �C��������");
	m_Combo10.InsertString(39,L"39 �C�����ƶ�");
	m_Combo10.InsertString(40,L"40 �C��������");
	m_Combo10.SetCurSel(2);
	m_Spin17.SetRange(0,63);
	m_Spin17.SetPos(8);
	m_Spin18.SetRange32(0,65535);
	m_Spin18.SetPos(5);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVC_DemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVC_DemoDlg::OnPaint()
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
HCURSOR CVC_DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVC_DemoDlg::OnCbnSelchangeCombo2()	//ͨѶģʽcombobox��Ϣ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_Combo2.GetCurSel() == 1)
	{
		g_nSendMode = SEND_MODE_NETWORK;	//����ͨѶ

		GetDlgItem(IDC_GrpNet)->ShowWindow(TRUE);
		m_ctrlRadio1.ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(TRUE);
		GetDlgItem(IDC_textNetIP)->ShowWindow(TRUE);
		m_Edit4.ShowWindow(TRUE);
		GetDlgItem(IDC_textNetPort)->ShowWindow(TRUE);
		m_Edit5.ShowWindow(TRUE);
		m_Spin4.ShowWindow(TRUE);
		GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
		m_Edit6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSp)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSp)->ShowWindow(FALSE);
		m_Combo5.ShowWindow(FALSE);
		GetDlgItem(IDC_textBaud)->ShowWindow(FALSE);
		m_Combo6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpServer)->ShowWindow(FALSE);
		GetDlgItem(IDC_textServerIP)->ShowWindow(FALSE);
		m_Edit7.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPort)->ShowWindow(FALSE);
		m_Edit8.ShowWindow(FALSE);
		m_Spin5.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerUser)->ShowWindow(FALSE);
		m_Edit9.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPwd)->ShowWindow(FALSE);
		m_Edit10.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSave)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSave)->ShowWindow(FALSE);
		m_Edit11.ShowWindow(FALSE);

		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	}
	else if(m_Combo2.GetCurSel() == 2)
	{
		g_nSendMode = SEND_MODE_Server_2G;	//ONBON������-GPRS

		GetDlgItem(IDC_GrpNet)->ShowWindow(FALSE);
		m_ctrlRadio1.ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
		GetDlgItem(IDC_textNetIP)->ShowWindow(FALSE);
		m_Edit4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetPort)->ShowWindow(FALSE);
		m_Edit5.ShowWindow(FALSE);
		m_Spin4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
		m_Edit6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSp)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSp)->ShowWindow(FALSE);
		m_Combo5.ShowWindow(FALSE);
		GetDlgItem(IDC_textBaud)->ShowWindow(FALSE);
		m_Combo6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpServer)->ShowWindow(TRUE);
		GetDlgItem(IDC_textServerIP)->ShowWindow(TRUE);
		m_Edit7.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerPort)->ShowWindow(TRUE);
		m_Edit8.ShowWindow(TRUE);
		m_Spin5.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerUser)->ShowWindow(TRUE);
		m_Edit9.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerPwd)->ShowWindow(TRUE);
		m_Edit10.ShowWindow(TRUE);

		GetDlgItem(IDC_GrpSave)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSave)->ShowWindow(FALSE);
		m_Edit11.ShowWindow(FALSE);

		GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	}
	else if(m_Combo2.GetCurSel() == 3)
	{
		g_nSendMode = SEND_MODE_Server_3G;	//ONBON������-3G

		GetDlgItem(IDC_GrpNet)->ShowWindow(FALSE);
		m_ctrlRadio1.ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
		GetDlgItem(IDC_textNetIP)->ShowWindow(FALSE);
		m_Edit4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetPort)->ShowWindow(FALSE);
		m_Edit5.ShowWindow(FALSE);
		m_Spin4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
		m_Edit6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSp)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSp)->ShowWindow(FALSE);
		m_Combo5.ShowWindow(FALSE);
		GetDlgItem(IDC_textBaud)->ShowWindow(FALSE);
		m_Combo6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpServer)->ShowWindow(TRUE);
		GetDlgItem(IDC_textServerIP)->ShowWindow(TRUE);
		m_Edit7.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerPort)->ShowWindow(TRUE);
		m_Edit8.ShowWindow(TRUE);
		m_Spin5.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerUser)->ShowWindow(TRUE);
		m_Edit9.ShowWindow(TRUE);
		GetDlgItem(IDC_textServerPwd)->ShowWindow(TRUE);
		m_Edit10.ShowWindow(TRUE);

		GetDlgItem(IDC_GrpSave)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSave)->ShowWindow(FALSE);
		m_Edit11.ShowWindow(FALSE);

		GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	}
	else if(m_Combo2.GetCurSel() == 4)
	{
		g_nSendMode = SEND_MODE_SAVEFILE;	//���浽�ļ�

		GetDlgItem(IDC_GrpNet)->ShowWindow(FALSE);
		m_ctrlRadio1.ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
		GetDlgItem(IDC_textNetIP)->ShowWindow(FALSE);
		m_Edit4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetPort)->ShowWindow(FALSE);
		m_Edit5.ShowWindow(FALSE);
		m_Spin4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
		m_Edit6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSp)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSp)->ShowWindow(FALSE);
		m_Combo5.ShowWindow(FALSE);
		GetDlgItem(IDC_textBaud)->ShowWindow(FALSE);
		m_Combo6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpServer)->ShowWindow(FALSE);
		GetDlgItem(IDC_textServerIP)->ShowWindow(FALSE);
		m_Edit7.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPort)->ShowWindow(FALSE);
		m_Edit8.ShowWindow(FALSE);
		m_Spin5.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerUser)->ShowWindow(FALSE);
		m_Edit9.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPwd)->ShowWindow(FALSE);
		m_Edit10.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSave)->ShowWindow(TRUE);
		GetDlgItem(IDC_textSave)->ShowWindow(TRUE);
		m_Edit11.ShowWindow(TRUE);

		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	}
	else
	{
		g_nSendMode = SEND_MODE_SERIALPORT;	//����ͨѶ

		GetDlgItem(IDC_GrpNet)->ShowWindow(FALSE);
		m_ctrlRadio1.ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(FALSE);
		GetDlgItem(IDC_textNetIP)->ShowWindow(FALSE);
		m_Edit4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetPort)->ShowWindow(FALSE);
		m_Edit5.ShowWindow(FALSE);
		m_Spin4.ShowWindow(FALSE);
		GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
		m_Edit6.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSp)->ShowWindow(TRUE);
		GetDlgItem(IDC_textSp)->ShowWindow(TRUE);
		m_Combo5.ShowWindow(TRUE);
		GetDlgItem(IDC_textBaud)->ShowWindow(TRUE);
		m_Combo6.ShowWindow(TRUE);

		GetDlgItem(IDC_GrpServer)->ShowWindow(FALSE);
		GetDlgItem(IDC_textServerIP)->ShowWindow(FALSE);
		m_Edit7.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPort)->ShowWindow(FALSE);
		m_Edit8.ShowWindow(FALSE);
		m_Spin5.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerUser)->ShowWindow(FALSE);
		m_Edit9.ShowWindow(FALSE);
		GetDlgItem(IDC_textServerPwd)->ShowWindow(FALSE);
		m_Edit10.ShowWindow(FALSE);

		GetDlgItem(IDC_GrpSave)->ShowWindow(FALSE);
		GetDlgItem(IDC_textSave)->ShowWindow(FALSE);
		m_Edit11.ShowWindow(FALSE);

		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	}
}


void CVC_DemoDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_textNetID)->ShowWindow(FALSE);
	m_Edit6.ShowWindow(FALSE);
}


void CVC_DemoDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_textNetID)->ShowWindow(TRUE);
	m_Edit6.ShowWindow(TRUE);
}

void CVC_DemoDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio4.SetCheck(FALSE);
}


void CVC_DemoDlg::OnBnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio3.SetCheck(FALSE);
}

void CVC_DemoDlg::GetCurGrpCaption()
{
	CString tmp1(FAddDynamicArea);
	CString tmp2(_T("(���ţ�"));
	CString tmp3;
	m_Edit1.GetWindowText(tmp3);
	CString tmp4(_T("��"));
	SetDlgItemText(grp_AddDynamicArea,tmp1+tmp2+tmp3+tmp4);

	CString Tmp1(FAddDYAreaFile);
	CString Tmp2(_T("����̬�����ţ�"));
	CString Tmp3;
	m_Edit12.GetWindowText(Tmp3);
	SetDlgItemText(grp_AddDYAreaFile,Tmp1+tmp2+tmp3+Tmp2+Tmp3+tmp4);
}

void CVC_DemoDlg::GetErrorMessage(char* szfunctionName, int nResult)	//����ִ�н������
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
                case RETURN_ERROR_NOFIND_DYNAMIC_AREA:
                    returnResult = "û���ҵ���Ч�Ķ�̬����\r\n";
                    break;
                case RETURN_ERROR_NOFIND_DYNAMIC_AREA_FILE_ORD:
                    returnResult = "��ָ���Ķ�̬����û���ҵ�ָ�����ļ���š�\r\n";
                    break;
                case RETURN_ERROR_NOFIND_DYNAMIC_AREA_PAGE_ORD:
                    returnResult = "��ָ���Ķ�̬����û���ҵ�ָ����ҳ��š�\r\n";
                    break;
                case RETURN_ERROR_NOSUPPORT_FILETYPE:
                    returnResult = "��̬�ⲻ֧�ָ��ļ����͡�\r\n";
                    break;
                case RETURN_ERROR_RA_SCREENNO:
                    returnResult = "ϵͳ���Ѿ��и���ʾ����Ϣ����Ҫ�����趨����ִ��DeleteScreen����ɾ������ʾ��������ӡ�\r\n";
                    break;
                case RETURN_ERROR_NOFIND_AREA:
                    returnResult = "ϵͳ��û���ҵ���Ч�Ķ�̬���򣻿�����ִ��AddScreenDynamicArea������Ӷ�̬������Ϣ������ӡ�\r\n";
                    break;
                case RETURN_ERROR_NOFIND_SCREENNO:
                    returnResult = "ϵͳ��û�в��ҵ�����ʾ��������ʹ��AddScreen������Ӹ���ʾ����\r\n";
                    break;
                case RETURN_ERROR_NOW_SENDING:
                    returnResult = "ϵͳ�����������ʾ��ͨѶ�����Ժ���ͨѶ��\r\n";
                    break;
                case RETURN_ERROR_OTHER:
                    returnResult = "��������\r\n";
                    break;
                case RETURN_NOERROR:
                    returnResult = "����ִ�гɹ���\r\n";
                    break;
            }
	m_RichEdit.ReplaceSel(returnResult);
}


void CVC_DemoDlg::OnBnClickedButton4()	//�����ʾ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSendMode;
	int nScreenType;
	CString strCom;
	CString strBaud;
	CString strSocketIP;
	CString strNetWorkID;
	CString strServerIP;
	CString strUserName;
	CString strUserPassword;
	CString strSaveFile;
	int nServerMode;
	int nResult;

	switch(m_Combo2.GetCurSel())
	{
		case 0:
			nSendMode = SEND_MODE_SERIALPORT;
			break;
		case 1:
			nSendMode = SEND_MODE_NETWORK;
			break;
		case 2:
			nSendMode = SEND_MODE_Server_2G;
			break;
		case 3:
			nSendMode = SEND_MODE_Server_3G;
			break;
		case 4:
			nSendMode = SEND_MODE_SAVEFILE;
			break;
		default:
			nSendMode = SEND_MODE_NETWORK;
			break;
	}

	switch(m_Combo3.GetCurSel())
	{
		case 0:
			nScreenType = 1;
            break;
        case 1:
            nScreenType = 2;
            break;
        case 2:
            nScreenType = 4;
            break;
        default:
            nScreenType = 2;
            break;
	}

	m_Combo5.GetWindowText(strCom);
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strCom,-1,NULL,NULL,0,NULL);
	char *Com = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strCom,-1,Com,dwNum,0,NULL);

	m_Combo6.GetWindowText(strBaud);

	m_Edit4.GetWindowText(strSocketIP);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *SocketIP = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,SocketIP,dwNum,0,NULL);

	char *Barcode = "";

	m_Edit6.GetWindowText(strNetWorkID);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *NetWorkID = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strNetWorkID,-1,NetWorkID,dwNum,0,NULL);

	m_Edit7.GetWindowText(strServerIP);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *ServerIP = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strServerIP,-1,ServerIP,dwNum,0,NULL);

	m_Edit9.GetWindowText(strUserName);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *UserName = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strUserName,-1,UserName,dwNum,0,NULL);

	m_Edit10.GetWindowText(strUserPassword);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *UserPassword = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strUserPassword,-1,UserPassword,dwNum,0,NULL);

	m_Edit10.GetWindowText(strSaveFile);
	dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strSocketIP,-1,NULL,NULL,0,NULL);
	char *SaveFile = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strSaveFile,-1,SaveFile,dwNum,0,NULL);

	if(m_ctrlRadio1.GetCheck() == 1)
	{
		nServerMode = 0;
	}
	else
	{
		nServerMode = 1;
	}

	nResult = AddScreen_Dynamic(controlType[m_Combo1.GetCurSel()], m_Spin1.GetPos(), nSendMode, m_Spin2.GetPos()
                , m_Spin3.GetPos(), nScreenType, m_Combo4.GetCurSel() + 1
                , Com, _ttoi(strBaud)
                , SocketIP, m_Spin4.GetPos(),m_Combo11.GetCurSel(), nServerMode, Barcode, NetWorkID
                , ServerIP, m_Spin5.GetPos(), UserName, UserPassword
                , SaveFile);

	GetErrorMessage("ִ��AddScreen_Dynamic����,", nResult);
	GetCurGrpCaption();
}


void CVC_DemoDlg::OnBnClickedButton3()	//ɾ����ʾ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = DeleteScreen_Dynamic(m_Spin1.GetPos());
    GetErrorMessage("ִ��DeleteScreen����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton2()	//��ѯ�豸�б�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    int DeviceCount = 0;
    byte DeviceList[100];
    nResult = QuerryServerDeviceList(m_Spin1.GetPos(), DeviceList, DeviceCount);
	GetErrorMessage("ִ��QuerryServerDeviceList����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton1()	//���豸
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    char* sBarcode = "";
    char* sNetworkID = "BX-NET000001";
    nResult = BindServerDevice(m_Spin1.GetPos(), sBarcode, sNetworkID);
	GetErrorMessage("ִ��BindServerDevice����, ", nResult);
}

void CVC_DemoDlg::OnBnClickedButton5()	//�����Ļ��̬����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nRunMode;
	CString strTmp;
	char* szProRelateList = "";
    int nAllProRelate = 1;
	int nPlayPriority;
	int nAreaFMode;
	int nAreaFLine;
	int nResult;

	switch(m_Combo7.GetCurSel())
	{
		case 1:
			nRunMode = RUN_MODE_SHOW_LAST_PAGE;
			break;
		case 2:
			nRunMode = RUN_MODE_SHOW_CYCLE_WAITOUT_NOSHOW;
			break;
		case 3:
			nRunMode = RUN_MODE_SHOW_ORDERPLAYED_NOSHOW;
			break;
		default:
			nRunMode = RUN_MODE_CYCLE_SHOW;
			break;
	}

	if (m_Radio6.GetCheck() == 1)
    {
		nAllProRelate = 1;
		szProRelateList = "";
    }
	else
	{
		nAllProRelate = 0;
		if(m_Radio5.GetCheck() == 1)
		{
			szProRelateList = "";
		}
		else
		{
			m_Edit23.GetWindowTextW(strTmp);
			DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strTmp,-1,NULL,NULL,0,NULL);
			//char *Com = new char[dwNum];
			WideCharToMultiByte(CP_OEMCP,NULL,strTmp,-1,szProRelateList,dwNum,0,NULL);
		}
	}

	nPlayPriority = m_Combo8.GetCurSel();

	if(m_Check2.GetCheck() == 1)
	{
		if(m_Radio3.GetCheck() == 1)
		{
			nAreaFMode = 0;
			nAreaFLine = m_Spin12.GetPos();
		}
		else
		{
			nAreaFMode = 1;
			nAreaFLine = m_Spin14.GetPos();
		}
	}
	else
	{
		nAreaFMode = 255;
        nAreaFLine = 0;
	}

	nResult = AddScreenDynamicArea(m_Spin1.GetPos(), m_Spin6.GetPos(), nRunMode
            , m_Spin11.GetPos(), nAllProRelate, szProRelateList, nPlayPriority
            , m_Spin7.GetPos(), m_Spin8.GetPos(), m_Spin9.GetPos(), m_Spin10.GetPos()
            , nAreaFMode, nAreaFLine, m_Spin13.GetPos()
			, m_Combo9.GetCurSel(), m_Spin15.GetPos(), m_Spin16.GetPos());
    GetErrorMessage("ִ��AddScreenDynamicArea����,", nResult);
	GetCurGrpCaption();
}


void CVC_DemoDlg::OnBnClickedButton6()	//����ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSingleLine;
    int nResult;

	if(m_Check3.GetCheck() == 1)
	{
		nSingleLine = 1;
	}
	else
	{
		nSingleLine = 0;
	}

	CString strFilename;//����·��		
	CFileDialog opendlg (TRUE,_T("*"),_T(""),OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"),NULL);   	
	if (opendlg.DoModal()==IDOK)	
	{		
		strFilename=opendlg.GetPathName();
		m_ListBox1.AddString(strFilename);
		DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strFilename,-1,NULL,NULL,0,NULL);
		char *filename = new char[dwNum];
		WideCharToMultiByte(CP_OEMCP,NULL,strFilename,-1,filename,dwNum,0,NULL);
		nResult = AddScreenDynamicAreaFile(m_Spin1.GetPos(), m_Spin6.GetPos()
                , filename, nSingleLine, "����", 12, 0, 255
				, m_Combo10.GetCurSel(), m_Spin17.GetPos(), m_Spin18.GetPos());
		GetErrorMessage("ִ��AddScreenDynamicAreaFile����, ", nResult);
	} 
}


void CVC_DemoDlg::OnBnClickedButton7()	//ɾ���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nFileOrd;
    int nIndex;
    int nResult;

	if(m_ListBox1.GetCount() >= 0)
	{
		nFileOrd = m_ListBox1.GetCurSel();
		nIndex = nFileOrd;
		nResult = DeleteScreenDynamicAreaFile(m_Spin1.GetPos(), m_Spin6.GetPos()
                , nFileOrd);
		nIndex = nIndex - 1;
		m_ListBox1.DeleteString(nFileOrd);
		GetErrorMessage("ִ��DeleteScreenDynamicAreaFile����, ", nResult);
	}
}


void CVC_DemoDlg::OnBnClickedButton10()	//���¶�̬������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
	nResult = SendDynamicAreaInfoCommand(m_Spin1.GetPos(), m_Spin6.GetPos());
    GetErrorMessage("ִ��SendDynamicAreaInfoCommand����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton9()	//ɾ����ǰ��̬����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    int nResult;
	CString strDYAreaIDList;
	GetDlgItem(IDC_EDIT12)->GetWindowText(strDYAreaIDList);
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strDYAreaIDList,-1,NULL,NULL,0,NULL);
	char *szDYAreaIDList = new char[dwNum];	
	WideCharToMultiByte(CP_OEMCP,NULL,strDYAreaIDList,-1,szDYAreaIDList,dwNum,0,NULL);
    nResult = SendDeleteDynamicAreasCommand(m_Spin1.GetPos(), 0
            , szDYAreaIDList);
    GetErrorMessage("ִ��SendDeleteDynamicAreasCommand����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton8()	//ɾ�����ж�̬����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult;
    nResult = SendDeleteDynamicAreasCommand(m_Spin1.GetPos(), 1, "");
    GetErrorMessage("ִ��SendDeleteDynamicAreasCommand����, ", nResult);
}



void CVC_DemoDlg::OnBnClickedButton11()	//��ʼ����̬��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = Initialize();
    GetErrorMessage("ִ��Initialize����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton12()	//�ͷŶ�̬��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nResult = Uninitialize();
    GetErrorMessage("ִ��Uninitialize����, ", nResult);
}


void CVC_DemoDlg::OnBnClickedButton13()	//����ı�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSingleLine;
    int nResult;

	if(m_Check3.GetCheck() == 1)
	{
		nSingleLine = 1;
	}
	else
	{
		nSingleLine = 0;
	}

	nResult = AddScreenDynamicAreaText(m_Spin1.GetPos(), m_Spin6.GetPos()
                , "����", nSingleLine, "����", 12, 0, 255
				, m_Combo10.GetCurSel(), m_Spin17.GetPos(), m_Spin18.GetPos());
	GetErrorMessage("ִ��AddScreenDynamicAreaText����, ", nResult);
}
