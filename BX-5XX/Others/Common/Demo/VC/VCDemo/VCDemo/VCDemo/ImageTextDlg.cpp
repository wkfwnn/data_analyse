// ImageTextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VCDemo.h"
#include "ImageTextDlg.h"
#include "afxdialogex.h"

//文本位置
#define SCREEN_ALIGN_LEFT 0;
#define SCREEN_ALIGN_CENTER 1;
#define SCREEN_ALIGN_RIGHT 2;
// CImageTextDlg 对话框

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


// CImageTextDlg 消息处理程序

void CImageTextDlg::GetErrorMessage(char* szfunctionName, int nResult)
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

void CImageTextDlg::OnBnClickedButton1()	//添加图文区域
{
	// TODO: 在此添加控件通知处理程序代码
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


void CImageTextDlg::OnBnClickedButton3()	//添加文件到当前图文区域
{
	// TODO: 在此添加控件通知处理程序代码
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
                                                 _ttoi(strCurAreaOrd), chFileName, 0, g_nAlignment, "宋体", 10, 0, 65535, 2, 48, 10);
	GetErrorMessage("AddScreenProgramAreaBmpTextFile",result);
}


void CImageTextDlg::OnBnClickedButton4()	//删除系统当前文件
{
	// TODO: 在此添加控件通知处理程序代码
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


void CImageTextDlg::OnBnClickedButton2()	//选择文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;//保存路径		
	CFileDialog opendlg (TRUE,_T("*"),_T(""),OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"),NULL);   	
	if (opendlg.DoModal()==IDOK)	
	{		
		filename=opendlg.GetPathName();
		m_fileName.SetWindowText(filename);
	} 
}


void CImageTextDlg::OnBnClickedButton5()	//添加文本到当前图文区域
{
	// TODO: 在此添加控件通知处理程序代码
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
                                                 _ttoi(strCurAreaOrd), TextContent, 0, g_nAlignment, "宋体", 10, 0, 65535, 2, 48, 10);
	GetErrorMessage("AddScreenProgramAreaBmpTextText",result);
}


BOOL CImageTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Alignment.InsertString(0,L"居左");
	m_Alignment.InsertString(1,L"居中");
	m_Alignment.InsertString(2,L"居右");
	m_Alignment.SetCurSel(0);
	g_nAlignment=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void CImageTextDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
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
