// ImageTextDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCDemo.h"
#include "ImageTextDlg.h"
#include "afxdialogex.h"

//�ı�λ��
#define SCREEN_ALIGN_LEFT 0;
#define SCREEN_ALIGN_CENTER 1;
#define SCREEN_ALIGN_RIGHT 2;
// CImageTextDlg �Ի���

IMPLEMENT_DYNAMIC(CImageTextDlg, CDialog)

CImageTextDlg::CImageTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageTextDlg::IDD, pParent)
{
	hInst = NULL;
	hInst = LoadLibrary(L"BX_IV.dll");
	AddScreenProgramBmpTextArea = (pAddScreenProgramBmpTextArea)GetProcAddress(hInst,"AddScreenProgramBmpTextArea");
	AddScreenProgramAreaBmpTextFile = (pAddScreenProgramAreaBmpTextFile)GetProcAddress(hInst,"AddScreenProgramAreaBmpTextFile");
	AddScreenProgramAreaBmpTextText = (pAddScreenProgramAreaBmpTextText)GetProcAddress(hInst,"AddScreenProgramAreaBmpTextText");
	DeleteScreenProgramAreaBmpTextFile = (pDeleteScreenProgramAreaBmpTextFile)GetProcAddress(hInst,"DeleteScreenProgramAreaBmpTextFile");
}

CImageTextDlg::~CImageTextDlg()
{
}

void CImageTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_fileName);
	DDX_Control(pDX, IDC_RICHEDIT21, m_RichEdit);
	DDX_Control(pDX, IDC_COMBO1, m_Alignment);
}


BEGIN_MESSAGE_MAP(CImageTextDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CImageTextDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CImageTextDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CImageTextDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CImageTextDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CImageTextDlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CImageTextDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CImageTextDlg ��Ϣ�������

void CImageTextDlg::GetErrorMessage(char* szfunctionName, int nResult)
{
	CString szResult;
	CTime time = CTime::GetCurrentTime(); ///����CTime����
	CString m_strTime = time.Format("%Y-%m-%d %H:%M:%S");
	CString functionName(szfunctionName);
	CString tmp1("---ִ�к�����");
	CString tmp2("---���ؽ����");
	CString tmp3 = m_strTime + tmp1 + functionName + tmp2;

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
	CString tmp4 = tmp3 + returnResult;
	GetParent()->GetParent()->GetDlgItem(IDC_RICHEDIT21)->SetWindowText(tmp4);
}

void CImageTextDlg::OnBnClickedButton1()	//���ͼ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//GetParent()->GetParent()->GetDlgItem(IDC_RICHEDIT21)->SetWindowText(L"qwertyuiop");
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int result = AddScreenProgramBmpTextArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramBmpTextArea",result);
}


void CImageTextDlg::OnBnClickedButton3()	//����ļ�����ǰͼ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);
	CString fileName;
	m_fileName.GetWindowText(fileName);
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,fileName,-1,NULL,NULL,0,NULL);
	char *chFileName = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,fileName,-1,chFileName,dwNum,0,NULL);


	int result = AddScreenProgramAreaBmpTextFile(_ttoi(strScreenNo), _ttoi(strCurProgramOrd),
                                                 _ttoi(strCurAreaOrd), chFileName, 0, g_nAlignment, "����", 10, 0, 65535, 2, 48, 10);
	GetErrorMessage("AddScreenProgramAreaBmpTextFile",result);
}


void CImageTextDlg::OnBnClickedButton4()	//ɾ��ϵͳ��ǰ�ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);
	CString strCurFileOrd;
	GetDlgItem(IDC_EDIT2)->GetWindowText(strCurFileOrd);

	int result = DeleteScreenProgramAreaBmpTextFile(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd), _ttoi(strCurFileOrd));
	GetErrorMessage("DeleteScreenProgramAreaBmpTextFile",result);

}


void CImageTextDlg::OnBnClickedButton2()	//ѡ���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;//����·��		
	CFileDialog opendlg (TRUE,_T("*"),_T(""),OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"),NULL);   	
	if (opendlg.DoModal()==IDOK)	
	{		
		filename=opendlg.GetPathName();
		m_fileName.SetWindowText(filename);
	} 
}


void CImageTextDlg::OnBnClickedButton5()	//����ı�����ǰͼ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);
	CString strTextContent;
	m_RichEdit.GetWindowText(strTextContent);
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,strTextContent,-1,NULL,NULL,0,NULL);
	char *TextContent = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP,NULL,strTextContent,-1,TextContent,dwNum,0,NULL);


	int result = AddScreenProgramAreaBmpTextText(_ttoi(strScreenNo), _ttoi(strCurProgramOrd),
                                                 _ttoi(strCurAreaOrd), TextContent, 0, g_nAlignment, "����", 10, 0, 65535, 2, 48, 10);
	GetErrorMessage("AddScreenProgramAreaBmpTextText",result);
}


BOOL CImageTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_Alignment.InsertString(0,L"����");
	m_Alignment.InsertString(1,L"����");
	m_Alignment.InsertString(2,L"����");
	m_Alignment.SetCurSel(0);
	g_nAlignment=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



void CImageTextDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_Alignment.GetCurSel() == 1)
	{
		g_nAlignment = SCREEN_ALIGN_CENTER;
	}
	else if(m_Alignment.GetCurSel() == 2)
	{
		g_nAlignment = SCREEN_ALIGN_RIGHT;
	}
	else
	{
		g_nAlignment = SCREEN_ALIGN_LEFT;
	}
}
