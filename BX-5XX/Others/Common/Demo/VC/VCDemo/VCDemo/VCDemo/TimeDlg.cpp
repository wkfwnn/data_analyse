// TimeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCDemo.h"
#include "TimeDlg.h"
#include "afxdialogex.h"


// CTimeDlg �Ի���

IMPLEMENT_DYNAMIC(CTimeDlg, CDialog)

CTimeDlg::CTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeDlg::IDD, pParent)
{
	hInst = NULL;
	hInst = LoadLibrary(L"BX_IV.dll");
	AddScreenProgramTimeArea = (pAddScreenProgramTimeArea)GetProcAddress(hInst,"AddScreenProgramTimeArea");
	AddScreenProgramTimeAreaFile = (pAddScreenProgramTimeAreaFile)GetProcAddress(hInst,"AddScreenProgramTimeAreaFile");
	AddScreenProgramLunarArea = (pAddScreenProgramLunarArea)GetProcAddress(hInst,"AddScreenProgramLunarArea");
	AddScreenProgramLunarAreaFile = (pAddScreenProgramLunarAreaFile)GetProcAddress(hInst,"AddScreenProgramLunarAreaFile");
	AddScreenProgramClockArea = (pAddScreenProgramClockArea)GetProcAddress(hInst,"AddScreenProgramClockArea");
	AddScreenProgramClockAreaFile = (pAddScreenProgramClockAreaFile)GetProcAddress(hInst,"AddScreenProgramClockAreaFile");
	AddScreenProgramChroArea = (pAddScreenProgramChroArea)GetProcAddress(hInst,"AddScreenProgramChroArea");
	AddScreenProgramChroAreaFile = (pAddScreenProgramChroAreaFile)GetProcAddress(hInst,"AddScreenProgramChroAreaFile");
}

CTimeDlg::~CTimeDlg()
{
}

void CTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTimeDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTimeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTimeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTimeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTimeDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTimeDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTimeDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTimeDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTimeDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CTimeDlg ��Ϣ�������

void CTimeDlg::GetErrorMessage(char* szfunctionName, int nResult)
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

void CTimeDlg::OnBnClickedButton1()	//���ʱ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int nResult;
            nResult = AddScreenProgramTimeArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd),
                                                0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramTimeArea", nResult);
}


void CTimeDlg::OnBnClickedButton2()	//���/�޸�ʱ�������ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramTimeAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd),
                " ", "����",
                1, 1, 10, 0, 0, 0,
                0, 255,
                0, 0, 255,
                0, 0, 255,
                1, 1, 255,
                0);
	GetErrorMessage("AddScreenProgramTimeAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton3()	//���ũ������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int nResult;
            nResult = AddScreenProgramLunarArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramLunarArea", nResult);
}


void CTimeDlg::OnBnClickedButton4()	//���/�޸�ũ�������ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramLunarAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd),
                " ", "����",
                1, 1, 10, 0, 0, 0,
                0, 255,
                1, 255,
                1, 255,
                0, 255,
                0);
	GetErrorMessage("AddScreenProgramLunarAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton5()	//��ӱ�������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int nResult;
            nResult = AddScreenProgramClockArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramClockArea", nResult);
}


void CTimeDlg::OnBnClickedButton6()	//���/�޸ı��������ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramClockAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd),
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
                " ", "����", "����", "����", "����");
	GetErrorMessage("AddScreenProgramClockAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton7()	//��Ӽ�ʱ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int nResult;
            nResult = AddScreenProgramChroArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramChroArea", nResult);
}


void CTimeDlg::OnBnClickedButton8()	//���/�޸ļ�ʱ�����ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramChroAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurProgramOrd),
                "", "��", "Сʱ", "����", "��", "����",
                1, 1, 5, 0, 0, 0,
                255, 255,
                1, 1, 0, 1, 1, 1, 1,
                0, 0, 0, 0,
                2015, 12, 31, 12, 59, 59,
                0);
	GetErrorMessage("AddScreenProgramChroAreaFile", nResult);
}
