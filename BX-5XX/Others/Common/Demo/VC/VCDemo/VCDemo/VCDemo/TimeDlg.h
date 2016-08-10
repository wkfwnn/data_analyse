#pragma once

/*
        过程名:    AddScreenProgramTimeArea
        向动态库中指定显示屏的指定节目添加时间区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的时间区域信息配置。
        参数:
             nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
             nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
             nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
             nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
             nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
             nHeight         :区域的高度；最大值不大于显示屏高度-nY
            返回值            :详见返回状态代码定义。
  -----------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramTimeArea)(int nScreenNo,
            int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

        /*--------------------------------------------------------------------------
               过程名:    AddScreenProgramTimeAreaFile
        向动态库中指定显示屏的指定节目的指定时间区域属性；该函数不与显示屏通讯，
        只用于动态库中的指定显示屏指定节目中指定时间区域属性信息配置。
        参数:
          nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
          nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
          nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
          pInputtxt   :固定文字
          pFontName   :文字的字体
          nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
          nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
          nFontSize   :文字的大小
          nBold       :是否加粗，0为不1为是
          nItalic     :是否斜体，0为不1为是
          nUnderline  :是否下滑线，0为不1为是
          nUsetxt     :是否使用固定文字，0为不1为是
          nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
          nUseymd     :是否使用年月日，0为不1为是
          nYmdstyle   :年月日格式，详见使用说明文档的附件1
          nYmdcolor   :年月日颜色，传递颜色的10进制
          nUseweek    :是否使用星期，0为不1为是
          nWeekstyle  :星期格式，详见使用说明文档的附件1
          nWeekcolor  :星期颜色，传递颜色的10进制
          nUsehns     :是否使用时分秒，0为不1是
          nHnsstyle   :时分秒格式，详见使用说明文档的附件1
          nHnscolor   :时分秒颜色，传递颜色的10进制
          nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
        返回值            :详见返回状态代码定义。
      -------------------------------------------------------------------------------}
      ---------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramTimeAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
            char* pInputtxt, char* pFontName,
            int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
            int nUsetxt, int nTxtcolor,
            int nUseymd, int nYmdstyle, int nYmdcolor,
            int nUseweek, int nWeekstyle, int nWeekcolor,
            int nUsehns, int nHnsstyle, int nHnscolor, int nAutoset);

        /*-----------------------------------------------------------------------
        过程名:    AddScreenProgramLunarArea
        向动态库中指定显示屏的指定节目添加农历区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的农历区域信息配置。
        参数:
            nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
            nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
            nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
            nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
            nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
            nHeight         :区域的高度；最大值不大于显示屏高度-nY
           返回值            :详见返回状态代码定义。
        ---------------------------------------------------------------------------}
         ------------------------------------------------------------------------- * */
        typedef int (__stdcall *pAddScreenProgramLunarArea)(int nScreenNo, int nProgramOrd,
            int nX, int nY, int nWidth, int nHeight);

        /*-------------------------------------------------------------------------------
          过程名:    AddScreenProgramLunarAreaFile
          向动态库中指定显示屏的指定节目的指定农历区域属性；该函数不与显示屏通讯，
          只用于动态库中的指定显示屏指定节目中指定农历区域属性信息配置。
          参数:
              nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
              nProgramOrd	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
              nAreaOrd		:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
              pInputtxt		:固定文字
              pFontName		:文字的字体
              nSingal			:单行多行，0为单行 1为多行，单行模式下nAlign不起作用
              nAlign			:文字对齐模式，对多行有效，0为左1为中2为右
              nFontSize		:文字的大小
              nBold				:是否加粗，0为不1为是
              nItalic			:是否斜体，0为不1为是
              nUnderline	:是否下滑线，0为不1为是
              nUsetxt			:是否使用固定文字，0为不1为是
              nTxtcolor		:固定文字颜色，传递颜色的10进制
              nUseyear		:是否使用天干，0为不1为是  （辛卯兔年）
              nYearcolor	:天干颜色，传递颜色的10进制
              nUsemonth		:是否使用农历，0为不1为是  （九月三十）
              nMonthcolor	:农历颜色，传递颜色的10进制
              nUsesolar		:是否使用节气，0为不1是
              nSolarcolor	:节气颜色，传递颜色的10进制
              nAutoset		:是否自动设置大小对应宽度，0为不1为是（默认不使用）
          返回值            :详见返回状态代码定义。
                -----------------------------------------------------------------------}
                -----------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramLunarAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
            char* pInputtxt, char* pFontName,
            int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
            int nUsetxt, int nTxtcolor, int nUseyear, int nYearcolor, int nUsemonth, int nMonthcolor,
            int nUsesolar, int nSolarcolor, int nAutoset);
        /*----------------------------------------------------------------------------
         过程名:    AddScreenProgramClockArea
  向动态库中指定显示屏的指定节目添加表盘区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的表盘区域信息配置。
  参数:
    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
    nHeight         :区域的高度；最大值不大于显示屏高度-nY
  返回值            :详见返回状态代码定义。
      -------------------------------------------------------------------------------}
      -------------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramClockArea)(int nScreenNo, int nProgramOrd,
          int nX, int nY, int nWidth, int nHeight);

        /*------------------------------------------------------------------------- 
          {-------------------------------------------------------------------------------
          过程名:    AddScreenProgramClockAreaFile
          向动态库中指定显示屏的指定节目的指定表盘区域属性；该函数不与显示屏通讯，
          只用于动态库中的指定显示屏指定节目中指定表盘区域属性信息配置。
          参数:
              nScreenNo			:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
              nProgramOrd 	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
              nAreaOrd			:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
              nusetxt				:是否使用固定文字 0为不1为是
              nusetime			:是否使用年月日时间 0为不1为是
              nuseweek			:是否使用星期 0为不1为是
              ntimeStyle		:年月日时间格式，参考时间区的表格说明
              nWeekStyle		:星期时间格式，参考时间区的表格说明
              ntxtfontsize	:固定文字的字大小
              ntxtfontcolor	:固定文字的颜色；传递颜色的10进制;红255绿65280黄65535
              ntxtbold			:固定文字是否加粗 0为不1为是
              ntxtitalic		:固定文字是否斜体 0为不1为是
              ntxtunderline	:固定文字是否下划线 0为不1为是
              txtleft				:固定文字在表盘区域中的X坐标
              txttop				:固定文字在表盘区域中的Y坐标
              ntimefontsize	:年月日文字的字大小
              ntimefontcolor:年月日文字的颜色； 传递颜色的10进制
              ntimebold			:年月日文字是否加粗 0为不1为是
              ntimeitalic		:年月日文字是否斜体 0为不1为是
              ntimeunderline:年月日文字是否下划线 0为不1为是
              timeleft			:年月日文字在表盘区域中的X坐标
              timetop				:年月日文字在表盘区域中的X坐标
              nweekfontsize	:星期文字的字大小
              nweekfontcolor:星期文字的颜色；传递颜色的10进制
              nweekbold			:星期文字是否加粗 0为不1为是
              nweekitalic		:星期文字是否斜体 0为不1为是
              nweekunderline:星期文字是否下划线 0为不1为是
              weekleft			:星期文字在表盘区域中的X坐标
              weektop				:星期文字在表盘区域中的X坐标
              nclockfontsize:表盘文字的字大小
              nclockfontcolor:表盘文字的颜色；传递颜色的10进制
              nclockbold		:表盘文字是否加粗 0为不1为是
              nclockitalic	:表盘文字是否斜体 0为不1为是
              nclockunderline:表盘文字是否下划线 0为不1为是
              clockcentercolor:表盘中心颜色；传递颜色的10进制
              mhrdotstyle		:3/6/9时点类型 0线形1圆形2方形3数字4罗马
              mhrdotsize		:3/6/9时点尺寸 0-8
              mhrdotcolor		:3/6/9时点颜色；传递颜色的10进制
              hrdotstyle		:3/6/9外的时点类型  0线形1圆形2方形3数字4罗马
              hrdotsize			:3/6/9外的时点尺寸 0-8
              hrdotcolor		:3/6/9外的时点颜色；传递颜色的10进制
              mindotstyle		:分钟点类型  0线形1圆形2方形
              mindotsize		:分钟点尺寸 0-1
              mindotcolor		:分钟点颜色；传递颜色的10进制
              hrhandsize		:时针尺寸 0-8
              hrhandcolor		:时针颜色；传递颜色的10进制
              minhandsize		:分针尺寸 0-8
              minhandcolor	:分针颜色；传递颜色的10进制
              sechandsize		:秒针尺寸 0-8
              sechandcolor	:秒针颜色；传递颜色的10进制
              nAutoset			:自适应位置设置，0为不1为是 如果为1，那txtleft/txttop/ weekleft/weektop/timeleft/timetop需要自己设坐标值
              btxtcontent		:固定文字信息
              btxtfontname	:固定文字字体
              btimefontname	:时间文字字体
              bweekfontname	:星期文字字体
              bclockfontname:表盘文字字体
         返回值            :详见返回状态代码定义。
         -------------------------------------------------------------------------------}
         -------------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramClockAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
        int nusetxt, int nusetime, int nuseweek, int ntimeStyle, int nWeekStyle,
        int ntxtfontsize, int ntxtfontcolor, int ntxtbold, int ntxtitalic, int ntxtunderline, int txtleft, int txttop,
        int ntimefontsize, int ntimefontcolor, int ntimebold, int ntimeitalic, int ntimeunderline, int timeleft, int timetop,
        int nweekfontsize, int nweekfontcolor, int nweekbold, int nweekitalic, int nweekunderline, int weekleft, int weektop,
        int nclockfontsize, int nclockfontcolor, int nclockbold, int nclockitalic, int nclockunderline,
        int clockcentersize, int clockcentercolor, int mhrdotstyle, int mhrdotsize, int mhrdotcolor,
        int hrdotstyle, int hrdotsize, int hrdotcolor, int mindotstyle, int mindotsize, int mindotcolor,
        int hrhandsize, int hrhandcolor, int minhandsize, int minhandcolor, int sechandsize, int sechandcolor, int nAutoset,
        char* btxtcontent, char* btxtfontname, char* btimefontname, char* bweekfontname, char* bclockfontname);

        typedef int (__stdcall *pAddScreenProgramChroArea)(int nScreenNo, int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

        /**---------------------------------------------------------------------------------------------
         过程名:    AddScreenProgramChroAreaFile
         向动态库中指定显示屏的指定节目的指定计时区域属性；该函数不与显示屏通讯，
         只用于动态库中的指定显示屏指定节目中指定计时区域属性信息配置。
         参数:
             nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
             nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
             nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
             pInputtxt   :固定文字
             pDaystr    :天单位
             pHourstr   :小时单位
             pMinstr    :分钟单位
             pSecstr    :秒单位
             pFontName   :文字的字体
             nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
             nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
             nFontSize   :文字的大小
             nBold       :是否加粗，0为不1为是
             nItalic     :是否斜体，0为不1为是
             nUnderline  :是否下滑线，0为不1为是
             nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
             nFontcolor  :计时显示颜色，传递颜色的10进制 红255 绿65280 黄65535
             nShowstr     :是否显示单位，对应于所有的天，时，分，秒单位
             nShowAdd     :是否计时累加显示 默认是累加的
             nUsetxt     :是否使用固定文字，0为不1为是
             nUseDay     :是否使用天，0为不1为是
             nUseHour    :是否使用小时，0为不1为是
             nUseMin     :是否使用分钟，0为不1为是
             nUseSec     :是否使用秒，0为不1为是
             nDayLength     :天显示位数    默认为0 自动
             nHourLength    :小时显示位数  默认为0 自动
             nMinLength     :分显示位数    默认为0 自动
             nSecLength     :秒显示位数    默认为0 自动

             EndYear     :目标年值
             EndMonth   :目标月值
             EndDay     :目标日值
             EndHour    :目标时值
             EndMin     :目标分值
             EndSec     :目标秒值


             nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
         返回值            :详见返回状态代码定义。
         ----------------------------------------------------------------------}
         ----------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramChroAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
             char* pInputtxt, char* pDaystr, char* pHourstr, char* pMinstr, char* pSecstr, char* pFontName,
             int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
             int nTxtcolor, int nFontcolor,
             int nShowstr, int nShowAdd, int nUseTxt, int nUseDay, int nUseHour, int nUseMin, int nUseSec,
             int nDayLength, int nHourLength, int nMinLength, int nSecLength,
             int EndYear, int EndMonth, int EndDay, int EndHour, int EndMin, int EndSec,
             int nAutoset);

// CTimeDlg 对话框

class CTimeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeDlg)

public:
	CTimeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTimeDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//此变量在数据更新中非常重要，请务必保留。
	pAddScreenProgramTimeArea AddScreenProgramTimeArea;
	pAddScreenProgramTimeAreaFile AddScreenProgramTimeAreaFile;
	pAddScreenProgramLunarArea AddScreenProgramLunarArea;
	pAddScreenProgramLunarAreaFile AddScreenProgramLunarAreaFile;
	pAddScreenProgramClockArea AddScreenProgramClockArea;
	pAddScreenProgramClockAreaFile AddScreenProgramClockAreaFile;
	pAddScreenProgramChroArea AddScreenProgramChroArea;
	pAddScreenProgramChroAreaFile AddScreenProgramChroAreaFile;

// 对话框数据
	enum { IDD = IDD_Time_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	void GetErrorMessage(char* szfunctionName, int nResult);
};
