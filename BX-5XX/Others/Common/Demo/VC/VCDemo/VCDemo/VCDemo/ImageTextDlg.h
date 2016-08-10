#pragma once
#include "afxwin.h"
#include "afxcmn.h"

/*-------------------------------------------------------------------------------
          过程名:    AddScreenProgramBmpTextArea:
          向动态库中指定显示屏的指定节目添加图文区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的图文区域信息配置。
          参数:
            nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
            nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
            nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
            nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
            nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
            nHeight         :区域的高度；最大值不大于显示屏高度-nY
          返回值            :详见返回状态代码定义。
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramBmpTextArea)(int nScreenNo, int nProgramOrd, int nX, int nY,
            int nWidth, int nHeight);//向指定显示屏指定节目添加图文区；

/*-------------------------------------------------------------------------------
          过程名:    AddScreenProgramAreaBmpTextFile
          向动态库中指定显示屏的指定节目的指定图文区域添加文件；
              该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
          参数:
            nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
            nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
            nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
            pFileName       :文件名称  支持.bmp,jpg,jpeg,rtf,txt等文件类型。
            nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
            pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
            nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
            nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
            nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
            nStunt          :显示特技。
              0x00:随机显示
              0x01:静态
              0x02:快速打出
              0x03:向左移动
              0x04:向左连移
              0x05:向上移动            3T类型控制卡无此特技
              0x06:向上连移            3T类型控制卡无此特技
              0x07:闪烁                3T类型控制卡无此特技
              0x08:飘雪
              0x09:冒泡
              0x0A:中间移出
              0x0B:左右移入
              0x0C:左右交叉移入
              0x0D:上下交叉移入
              0x0E:画卷闭合
              0x0F:画卷打开
              0x10:向左拉伸
              0x11:向右拉伸
              0x12:向上拉伸
              0x13:向下拉伸            3T类型控制卡无此特技
              0x14:向左镭射
              0x15:向右镭射
              0x16:向上镭射
              0x17:向下镭射
              0x18:左右交叉拉幕
              0x19:上下交叉拉幕
              0x1A:分散左拉
              0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
              0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
              0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
              0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
              0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
              0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
              0x21:左右闭合            3T类型控制卡无此特技
              0x22:左右对开            3T类型控制卡无此特技
              0x23:上下闭合            3T类型控制卡无此特技
              0x24:上下对开            3T类型控制卡无此特技
              0x25:向右连移
              0x26:向右连移
              0x27:向下移动            3T类型控制卡无此特技
              0x28:向下连移            3T类型控制卡无此特技
            nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
            nShowTime       :停留时间；0~65525；单位0.5秒

          返回值:           :详见返回状态代码定义。
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
        char* pFileName, int nShowSingle, int nAlignment, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime); //向指定显示屏指定节目指定区域添加文件

/*-------------------------------------------------------------------------------
          过程名:    AddScreenProgramAreaBmpTextFile
          向动态库中指定显示屏的指定节目的指定图文区域添加文件；
              该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
          参数:
            nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
            nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
            nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
            pFileName       :文件名称  支持.bmp,jpg,jpeg,rtf,txt等文件类型。
            nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
            pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
            nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
            nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
            nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
            nStunt          :显示特技。
              0x00:随机显示
              0x01:静态
              0x02:快速打出
              0x03:向左移动
              0x04:向左连移
              0x05:向上移动            3T类型控制卡无此特技
              0x06:向上连移            3T类型控制卡无此特技
              0x07:闪烁                3T类型控制卡无此特技
              0x08:飘雪
              0x09:冒泡
              0x0A:中间移出
              0x0B:左右移入
              0x0C:左右交叉移入
              0x0D:上下交叉移入
              0x0E:画卷闭合
              0x0F:画卷打开
              0x10:向左拉伸
              0x11:向右拉伸
              0x12:向上拉伸
              0x13:向下拉伸            3T类型控制卡无此特技
              0x14:向左镭射
              0x15:向右镭射
              0x16:向上镭射
              0x17:向下镭射
              0x18:左右交叉拉幕
              0x19:上下交叉拉幕
              0x1A:分散左拉
              0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
              0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
              0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
              0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
              0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
              0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
              0x21:左右闭合            3T类型控制卡无此特技
              0x22:左右对开            3T类型控制卡无此特技
              0x23:上下闭合            3T类型控制卡无此特技
              0x24:上下对开            3T类型控制卡无此特技
              0x25:向右连移
              0x26:向右连移
              0x27:向下移动            3T类型控制卡无此特技
              0x28:向下连移            3T类型控制卡无此特技
            nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
            nShowTime       :停留时间；0~65525；单位0.5秒

          返回值:           :详见返回状态代码定义。
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramAreaBmpTextText)(int nScreenNo, int nProgramOrd, int nAreaOrd,
        char* pText, int nShowSingle, int nAlignment, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime); //向指定显示屏指定节目指定区域添加文件

/*-------------------------------------------------------------------------------
          过程名:    DeleteScreenProgramAreaBmpTextFile
          删除指定显示屏指定节目指定图文区域的指定文件，删除文件成功后会将该文件信息删除。
          该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目指定区域中的指定文件信息配置。
          参数:
            nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
            nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
            nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
            nFileOrd        :文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
          返回值            :详见返回状态代码定义。
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pDeleteScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd, int nFileOrd); //删除指定显示屏指定节目指定图文区域的指定文件，删除文件成功后会将该文件信息删除

// CImageTextDlg 对话框

class CImageTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CImageTextDlg)

public:
	CImageTextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CImageTextDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//此变量在数据更新中非常重要，请务必保留。
	pAddScreenProgramBmpTextArea AddScreenProgramBmpTextArea;
	pAddScreenProgramAreaBmpTextFile AddScreenProgramAreaBmpTextFile;
	pAddScreenProgramAreaBmpTextText AddScreenProgramAreaBmpTextText;
	pDeleteScreenProgramAreaBmpTextFile DeleteScreenProgramAreaBmpTextFile;

// 对话框数据
	enum { IDD = IDD_ImageText_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	CEdit m_fileName;
	void GetErrorMessage(char* szfunctionName, int nResult);
	CRichEditCtrl m_RichEdit;
	afx_msg void OnBnClickedButton5();
	virtual BOOL OnInitDialog();
	CComboBox m_Alignment;
	int g_nAlignment;
	afx_msg void OnCbnSelchangeCombo1();
};
