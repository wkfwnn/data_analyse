// NoiseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCDemo.h"
#include "NoiseDlg.h"
#include "afxdialogex.h"


// CNoiseDlg �Ի���

IMPLEMENT_DYNAMIC(CNoiseDlg, CDialog)

CNoiseDlg::CNoiseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoiseDlg::IDD, pParent)
{
	hInst = NULL;
	hInst = LoadLibrary(L"BX_IV.dll");
	AddScreenProgramNoiseArea = (pAddScreenProgramNoiseArea)GetProcAddress(hInst,"AddScreenProgramNoiseArea");
}

CNoiseDlg::~CNoiseDlg()
{
}

void CNoiseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNoiseDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CNoiseDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNoiseDlg ��Ϣ�������

void CNoiseDlg::GetErrorMessage(char* szfunctionName, int nResult)
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

void CNoiseDlg::OnBnClickedButton1()	//�����������
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
            nResult = AddScreenProgramNoiseArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd)
                 , 0, 0, _ttoi(strWidth), _ttoi(strHeight),
                 0,
                 0,
                 0,
                 70,
                 4,
                 0,
                 0,
                 0,
                 0,
                 65535,
                 65535,
                 "����",
                 "����",
                 12,
                 65535,
                 0);
	GetErrorMessage("AddScreenProgramNoiseArea",nResult);
}
