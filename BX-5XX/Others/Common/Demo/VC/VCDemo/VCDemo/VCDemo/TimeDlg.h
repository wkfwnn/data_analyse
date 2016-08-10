#pragma once

/*
        ������:    AddScreenProgramTimeArea
        ��̬����ָ����ʾ����ָ����Ŀ���ʱ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ʱ��������Ϣ���á�
        ����:
             nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
             nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
             nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
             nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
             nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
             nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
            ����ֵ            :�������״̬���붨�塣
  -----------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramTimeArea)(int nScreenNo,
            int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

        /*--------------------------------------------------------------------------
               ������:    AddScreenProgramTimeAreaFile
        ��̬����ָ����ʾ����ָ����Ŀ��ָ��ʱ���������ԣ��ú���������ʾ��ͨѶ��
        ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ʱ������������Ϣ���á�
        ����:
          nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
          nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
          nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
          pInputtxt   :�̶�����
          pFontName   :���ֵ�����
          nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
          nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
          nFontSize   :���ֵĴ�С
          nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
          nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
          nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
          nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
          nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
          nUseymd     :�Ƿ�ʹ�������գ�0Ϊ��1Ϊ��
          nYmdstyle   :�����ո�ʽ�����ʹ��˵���ĵ��ĸ���1
          nYmdcolor   :��������ɫ��������ɫ��10����
          nUseweek    :�Ƿ�ʹ�����ڣ�0Ϊ��1Ϊ��
          nWeekstyle  :���ڸ�ʽ�����ʹ��˵���ĵ��ĸ���1
          nWeekcolor  :������ɫ��������ɫ��10����
          nUsehns     :�Ƿ�ʹ��ʱ���룬0Ϊ��1��
          nHnsstyle   :ʱ�����ʽ�����ʹ��˵���ĵ��ĸ���1
          nHnscolor   :ʱ������ɫ��������ɫ��10����
          nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
        ����ֵ            :�������״̬���붨�塣
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
        ������:    AddScreenProgramLunarArea
        ��̬����ָ����ʾ����ָ����Ŀ���ũ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ũ��������Ϣ���á�
        ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
            nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
            nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
            nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
           ����ֵ            :�������״̬���붨�塣
        ---------------------------------------------------------------------------}
         ------------------------------------------------------------------------- * */
        typedef int (__stdcall *pAddScreenProgramLunarArea)(int nScreenNo, int nProgramOrd,
            int nX, int nY, int nWidth, int nHeight);

        /*-------------------------------------------------------------------------------
          ������:    AddScreenProgramLunarAreaFile
          ��̬����ָ����ʾ����ָ����Ŀ��ָ��ũ���������ԣ��ú���������ʾ��ͨѶ��
          ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ũ������������Ϣ���á�
          ����:
              nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
              nProgramOrd	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
              nAreaOrd		:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
              pInputtxt		:�̶�����
              pFontName		:���ֵ�����
              nSingal			:���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
              nAlign			:���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
              nFontSize		:���ֵĴ�С
              nBold				:�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
              nItalic			:�Ƿ�б�壬0Ϊ��1Ϊ��
              nUnderline	:�Ƿ��»��ߣ�0Ϊ��1Ϊ��
              nUsetxt			:�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
              nTxtcolor		:�̶�������ɫ��������ɫ��10����
              nUseyear		:�Ƿ�ʹ����ɣ�0Ϊ��1Ϊ��  ����î���꣩
              nYearcolor	:�����ɫ��������ɫ��10����
              nUsemonth		:�Ƿ�ʹ��ũ����0Ϊ��1Ϊ��  ��������ʮ��
              nMonthcolor	:ũ����ɫ��������ɫ��10����
              nUsesolar		:�Ƿ�ʹ�ý�����0Ϊ��1��
              nSolarcolor	:������ɫ��������ɫ��10����
              nAutoset		:�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
          ����ֵ            :�������״̬���붨�塣
                -----------------------------------------------------------------------}
                -----------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramLunarAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
            char* pInputtxt, char* pFontName,
            int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
            int nUsetxt, int nTxtcolor, int nUseyear, int nYearcolor, int nUsemonth, int nMonthcolor,
            int nUsesolar, int nSolarcolor, int nAutoset);
        /*----------------------------------------------------------------------------
         ������:    AddScreenProgramClockArea
  ��̬����ָ����ʾ����ָ����Ŀ��ӱ������򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�еı���������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
  ����ֵ            :�������״̬���붨�塣
      -------------------------------------------------------------------------------}
      -------------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramClockArea)(int nScreenNo, int nProgramOrd,
          int nX, int nY, int nWidth, int nHeight);

        /*------------------------------------------------------------------------- 
          {-------------------------------------------------------------------------------
          ������:    AddScreenProgramClockAreaFile
          ��̬����ָ����ʾ����ָ����Ŀ��ָ�������������ԣ��ú���������ʾ��ͨѶ��
          ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����������������Ϣ���á�
          ����:
              nScreenNo			:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
              nProgramOrd 	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
              nAreaOrd			:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
              nusetxt				:�Ƿ�ʹ�ù̶����� 0Ϊ��1Ϊ��
              nusetime			:�Ƿ�ʹ��������ʱ�� 0Ϊ��1Ϊ��
              nuseweek			:�Ƿ�ʹ������ 0Ϊ��1Ϊ��
              ntimeStyle		:������ʱ���ʽ���ο�ʱ�����ı��˵��
              nWeekStyle		:����ʱ���ʽ���ο�ʱ�����ı��˵��
              ntxtfontsize	:�̶����ֵ��ִ�С
              ntxtfontcolor	:�̶����ֵ���ɫ��������ɫ��10����;��255��65280��65535
              ntxtbold			:�̶������Ƿ�Ӵ� 0Ϊ��1Ϊ��
              ntxtitalic		:�̶������Ƿ�б�� 0Ϊ��1Ϊ��
              ntxtunderline	:�̶������Ƿ��»��� 0Ϊ��1Ϊ��
              txtleft				:�̶������ڱ��������е�X����
              txttop				:�̶������ڱ��������е�Y����
              ntimefontsize	:���������ֵ��ִ�С
              ntimefontcolor:���������ֵ���ɫ�� ������ɫ��10����
              ntimebold			:�����������Ƿ�Ӵ� 0Ϊ��1Ϊ��
              ntimeitalic		:�����������Ƿ�б�� 0Ϊ��1Ϊ��
              ntimeunderline:�����������Ƿ��»��� 0Ϊ��1Ϊ��
              timeleft			:�����������ڱ��������е�X����
              timetop				:�����������ڱ��������е�X����
              nweekfontsize	:�������ֵ��ִ�С
              nweekfontcolor:�������ֵ���ɫ��������ɫ��10����
              nweekbold			:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
              nweekitalic		:���������Ƿ�б�� 0Ϊ��1Ϊ��
              nweekunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
              weekleft			:���������ڱ��������е�X����
              weektop				:���������ڱ��������е�X����
              nclockfontsize:�������ֵ��ִ�С
              nclockfontcolor:�������ֵ���ɫ��������ɫ��10����
              nclockbold		:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
              nclockitalic	:���������Ƿ�б�� 0Ϊ��1Ϊ��
              nclockunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
              clockcentercolor:����������ɫ��������ɫ��10����
              mhrdotstyle		:3/6/9ʱ������ 0����1Բ��2����3����4����
              mhrdotsize		:3/6/9ʱ��ߴ� 0-8
              mhrdotcolor		:3/6/9ʱ����ɫ��������ɫ��10����
              hrdotstyle		:3/6/9���ʱ������  0����1Բ��2����3����4����
              hrdotsize			:3/6/9���ʱ��ߴ� 0-8
              hrdotcolor		:3/6/9���ʱ����ɫ��������ɫ��10����
              mindotstyle		:���ӵ�����  0����1Բ��2����
              mindotsize		:���ӵ�ߴ� 0-1
              mindotcolor		:���ӵ���ɫ��������ɫ��10����
              hrhandsize		:ʱ��ߴ� 0-8
              hrhandcolor		:ʱ����ɫ��������ɫ��10����
              minhandsize		:����ߴ� 0-8
              minhandcolor	:������ɫ��������ɫ��10����
              sechandsize		:����ߴ� 0-8
              sechandcolor	:������ɫ��������ɫ��10����
              nAutoset			:����Ӧλ�����ã�0Ϊ��1Ϊ�� ���Ϊ1����txtleft/txttop/ weekleft/weektop/timeleft/timetop��Ҫ�Լ�������ֵ
              btxtcontent		:�̶�������Ϣ
              btxtfontname	:�̶���������
              btimefontname	:ʱ����������
              bweekfontname	:������������
              bclockfontname:������������
         ����ֵ            :�������״̬���붨�塣
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
         ������:    AddScreenProgramChroAreaFile
         ��̬����ָ����ʾ����ָ����Ŀ��ָ����ʱ�������ԣ��ú���������ʾ��ͨѶ��
         ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����ʱ����������Ϣ���á�
         ����:
             nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
             nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
             nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
             pInputtxt   :�̶�����
             pDaystr    :�쵥λ
             pHourstr   :Сʱ��λ
             pMinstr    :���ӵ�λ
             pSecstr    :�뵥λ
             pFontName   :���ֵ�����
             nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
             nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
             nFontSize   :���ֵĴ�С
             nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
             nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
             nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
             nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
             nFontcolor  :��ʱ��ʾ��ɫ��������ɫ��10���� ��255 ��65280 ��65535
             nShowstr     :�Ƿ���ʾ��λ����Ӧ�����е��죬ʱ���֣��뵥λ
             nShowAdd     :�Ƿ��ʱ�ۼ���ʾ Ĭ�����ۼӵ�
             nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
             nUseDay     :�Ƿ�ʹ���죬0Ϊ��1Ϊ��
             nUseHour    :�Ƿ�ʹ��Сʱ��0Ϊ��1Ϊ��
             nUseMin     :�Ƿ�ʹ�÷��ӣ�0Ϊ��1Ϊ��
             nUseSec     :�Ƿ�ʹ���룬0Ϊ��1Ϊ��
             nDayLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
             nHourLength    :Сʱ��ʾλ��  Ĭ��Ϊ0 �Զ�
             nMinLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
             nSecLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�

             EndYear     :Ŀ����ֵ
             EndMonth   :Ŀ����ֵ
             EndDay     :Ŀ����ֵ
             EndHour    :Ŀ��ʱֵ
             EndMin     :Ŀ���ֵ
             EndSec     :Ŀ����ֵ


             nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
         ����ֵ            :�������״̬���붨�塣
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

// CTimeDlg �Ի���

class CTimeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeDlg)

public:
	CTimeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTimeDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	pAddScreenProgramTimeArea AddScreenProgramTimeArea;
	pAddScreenProgramTimeAreaFile AddScreenProgramTimeAreaFile;
	pAddScreenProgramLunarArea AddScreenProgramLunarArea;
	pAddScreenProgramLunarAreaFile AddScreenProgramLunarAreaFile;
	pAddScreenProgramClockArea AddScreenProgramClockArea;
	pAddScreenProgramClockAreaFile AddScreenProgramClockAreaFile;
	pAddScreenProgramChroArea AddScreenProgramChroArea;
	pAddScreenProgramChroAreaFile AddScreenProgramChroAreaFile;

// �Ի�������
	enum { IDD = IDD_Time_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
