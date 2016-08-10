// TimeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VCDemo.h"
#include "TimeDlg.h"
#include "afxdialogex.h"


// CTimeDlg 对话框

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


// CTimeDlg 消息处理程序

void CTimeDlg::GetErrorMessage(char* szfunctionName, int nResult)
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

void CTimeDlg::OnBnClickedButton1()	//添加时间区域
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
            nResult = AddScreenProgramTimeArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd),
                                                0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramTimeArea", nResult);
}


void CTimeDlg::OnBnClickedButton2()	//添加/修改时间区域文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramTimeAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd),
                " ", "宋体",
                1, 1, 10, 0, 0, 0,
                0, 255,
                0, 0, 255,
                0, 0, 255,
                1, 1, 255,
                0);
	GetErrorMessage("AddScreenProgramTimeAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton3()	//添加农历区域
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
            nResult = AddScreenProgramLunarArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramLunarArea", nResult);
}


void CTimeDlg::OnBnClickedButton4()	//添加/修改农历区域文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramLunarAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurAreaOrd),
                " ", "宋体",
                1, 1, 10, 0, 0, 0,
                0, 255,
                1, 255,
                1, 255,
                0, 255,
                0);
	GetErrorMessage("AddScreenProgramLunarAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton5()	//添加表盘区域
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
            nResult = AddScreenProgramClockArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramClockArea", nResult);
}


void CTimeDlg::OnBnClickedButton6()	//添加/修改表盘区域文件
{
	// TODO: 在此添加控件通知处理程序代码
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
                " ", "宋体", "宋体", "宋体", "宋体");
	GetErrorMessage("AddScreenProgramClockAreaFile", nResult);
}


void CTimeDlg::OnBnClickedButton7()	//添加计时区域
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
            nResult = AddScreenProgramChroArea(_ttoi(strScreenNo), _ttoi(strCurProgramOrd), 0, 0, _ttoi(strWidth), _ttoi(strHeight));
	GetErrorMessage("AddScreenProgramChroArea", nResult);
}


void CTimeDlg::OnBnClickedButton8()	//添加/修改计时区域文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString strScreenNo;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT1)->GetWindowText(strScreenNo);
	CString strCurProgramOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT4)->GetWindowText(strCurProgramOrd);
	CString strCurAreaOrd;
	GetParent()->GetParent()->GetDlgItem(IDC_EDIT5)->GetWindowText(strCurAreaOrd);

	int nResult;
            nResult = AddScreenProgramChroAreaFile(_ttoi(strScreenNo),
                _ttoi(strCurProgramOrd), _ttoi(strCurProgramOrd),
                "", "天", "小时", "分钟", "秒", "宋体",
                1, 1, 5, 0, 0, 0,
                255, 255,
                1, 1, 0, 1, 1, 1, 1,
                0, 0, 0, 0,
                2015, 12, 31, 12, 59, 59,
                0);
	GetErrorMessage("AddScreenProgramChroAreaFile", nResult);
}
