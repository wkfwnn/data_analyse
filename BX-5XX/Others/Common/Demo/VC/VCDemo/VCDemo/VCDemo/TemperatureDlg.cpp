// TemperatureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VCDemo.h"
#include "TemperatureDlg.h"
#include "afxdialogex.h"


// CTemperatureDlg 对话框

IMPLEMENT_DYNAMIC(CTemperatureDlg, CDialog)

CTemperatureDlg::CTemperatureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTemperatureDlg::IDD, pParent)
{
	hInst = NULL;
	hInst = LoadLibrary(L"BX_IV.dll");
	AddScreenProgramTemperatureArea = (pAddScreenProgramTemperatureArea)GetProcAddress(hInst,"AddScreenProgramTemperatureArea");
}

CTemperatureDlg::~CTemperatureDlg()
{
}

void CTemperatureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTemperatureDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTemperatureDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTemperatureDlg 消息处理程序

void CTemperatureDlg::GetErrorMessage(char* szfunctionName, int nResult)
{
	CString szResult;
	CTime time = CTime::GetCurrentTime(); ///构造CTime对象
	CString m_strTime = time.Format("%Y-%m-%d %H:%M:%S");
	CString functionName(szfunctionName);
	CString tmp1("---执行函数：");
	CString tmp2("---返回结果：");
	CString tmp3 = m_strTime + tmp1 + functionName + tmp2;

	CString returnResult;
	switch (nResult)
            {
                case 0xF7:
                    returnResult = "区域类型错误，在添加、删除图文区域文件时区域类型出错返回此类型错误。\r\n";
                    break;
                case 0xF8:
                    returnResult = "已经有该显示屏信息。如要重新设定请先DeleteScreen删除该显示屏再添加\r\n";
                    break;
                case 0xF9:
                    returnResult = "没有找到有效的区域文件(图文区域)\r\n";
                    break;
                case 0xFA:
                    returnResult = "没有找到有效的显示区域可以使用AddScreenProgramBmpTextArea添加区域信息。\r\n";
                    break;
                case 0xFB:
                    returnResult = "没有找到有效的显示屏节目可以使用AddScreenProgram函数添加指定节目\r\n";
                    break;
                case 0xFC:
                    returnResult = "系统内没有查找到该显示屏可以使用AddScreen函数添加显示屏\r\n";
                    break;
                case 0xFD:
                    returnResult = "系统内正在向该显示屏通讯，请稍后再通讯\r\n";
                    break;
                case 0xFF:
                    returnResult = "其它错误\r\n";
                    break;
                case 0:
                    returnResult = "函数执行/通讯成功\r\n";
                    break;
                case 0x01:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x02:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x03:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x04:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x05:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x06:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x07:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x08:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x09:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0A:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0B:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0C:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0D:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0E:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x0F:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x10:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x11:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x12:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x13:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x14:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x15:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x16:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x17:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0x18:
                    returnResult = "通讯错误\r\n";
                    break;
                case 0xFE:
                    returnResult = "通讯错误\r\n";
                    break;
            }
	CString tmp4 = tmp3 + returnResult;
	GetParent()->GetParent()->GetDlgItem(IDC_RICHEDIT21)->SetWindowText(tmp4);
}

void CTemperatureDlg::OnBnClickedButton1()	//添加温度区域
{
	// TODO: 在此添加控件通知处理程序代码
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strWidth;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT2)->GetWindowText(strWidth);
	CString strHeight;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT3)->GetWindowText(strHeight);

	int nResult;
                nResult = AddScreenProgramTemperatureArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd)
                    , 32, 0, _ttoi(strWidth), _ttoi(strHeight),
                    0,
                    0,
                    0,
                    100,
                    5,
                    0,
                    0,
                    0,
                    0,
                    65535,
                    65535,
                    "温度",
                    "宋体",
                    12,
                    65535,
                    0);
	GetErrorMessage("AddScreenProgramTemperatureArea",nResult);
}
