
// VC_DemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

		/*-------------------------------------------------------------------------------
        ������:    Initialize
        ��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
        ����:
        ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
		typedef int(__stdcall *pInitialize)();	//��ʼ����̬��

		/*-------------------------------------------------------------------------------
        ������:    Uninitialize
        ��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
        ����:
        ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
		typedef int(__stdcall *pUninitialize)();	//�ͷŶ�̬��

			/*-------------------------------------------------------------------------------
            ������:    AddScreen
            ��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��
            ����:
            nControlType:��ʾ���Ŀ������ͺţ�Ŀǰ�ö�̬����̬��ֻ֧��BX-5E1��BX-5E2��BX-5E3��BX-5Eϵ�п�������
            nScreenNo����ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
            nSendMode��ͨѶģʽ��Ŀǰ��̬����֧��0:����ͨѶ��2������ͨѶ(ֻ֧�̶ֹ�IPģʽ)��5�����浽�ļ�������ͨѶģʽ��
            nWidth����ʾ����ȣ���λ�����ء�
            nHeight����ʾ���߶ȣ���λ�����ء�
            nScreenType����ʾ�����ͣ�1������ɫ��2��˫��ɫ��
            nPixelMode���������ͣ�ֻ����ʾ������Ϊ˫��ɫʱ��Ч��1��R+G��2��G+R��
            pCom��ͨѶ���ڣ�ֻ���ڴ���ͨѶʱ�ò�����Ч������"COM1"
            nBaud��ͨѶ���ڲ����ʣ�ֻ���ڴ���ͨѶʱ�ò�����Ч��Ŀǰֻ֧��9600��57600���ֲ����ʡ�
            pSocketIP����������IP��ַ��ֻ��������ͨѶ(�̶�IPģʽ)ģʽ�¸ò�����Ч������"192.168.0.199"
            nSocketPort���������Ķ˿ڵ�ַ��ֻ��������ͨѶ(�̶�IPģʽ)ģʽ�¸ò�����Ч������5005
            nServerMode     :0:������ģʽδ������1��������ģʽ������
            pNetworkID      :������ģʽʱ������ID���
            pServerIP       :��ת������IP��ַ
            nServerPort     :��ת����������˿�
            pServerAccessUser:��ת�����������û���
            pServerAccessPassword:��ת��������������
            pCommandDataFile�����浽�ļ���ʽʱ������������ļ����ơ�ֻ���ڱ��浽�ļ�ģʽ�¸ò�����Ч������"curCommandData.dat"
            ����ֵ:    �������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pAddScreen_Dynamic)(int nControlType, int nScreenNo, int nSendMode, int nWidth, int nHeight,
              int nScreenType, int nPixelMode, char* pCom, int nBaud, char* pSocketIP, int nSocketPort, int nStaticIpMode, int nServerMode,
              char* pBarcode, char* pNetworkID, char* pServerIP, int nServerPort, char* pServerAccessUser, char* pServerAccessPassword,
              char* pCommandDataFile);

		/*-------------------------------------------------------------------------------
          ������:    QuerryServerDeviceList
          ��ѯ��ת�������豸���б���Ϣ��
          �ú�������ʾ������ͨѶ
          ����:      nScreenNo, nSendMode: Integer
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nSendMode       :����ʾ����ͨѶģʽ��
              0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
              2:����ģʽ;
              4:WiFiģʽ
              5:ONBON������-GPRS
              6:ONBON������-3G
            pDeviceList       : �����ѯ���豸�б���Ϣ
              ���豸����Ϣ������ַ���, ���磺
              �豸1������ ������ ״̬ ���� ����ID
              �豸2������ ������ ״̬ ���� ����ID
              ����ַ���Ϊ��'�豸1����,�豸1������,�豸1״̬,�豸1����,�豸1����ID;�豸2����,�豸2������,�豸2״̬,�豸2����,�豸2����ID'
              �豸״̬(Byte):  $10:�豸δ֪
                               $11:�豸����
                               $12:�豸������

              �豸����(Byte): $16:�豸Ϊ2G
                              $17:�豸Ϊ3G
            pDeviceCount      : ��ѯ���豸����

          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pQuerryServerDeviceList)(int nScreenNo, byte pDeviceList[], int &nDeviceCount);

		/*-------------------------------------------------------------------------------
          ������:    BindServerDevice
          ����ת�������豸��
          �ú���������ʾ������ͨѶ
          ����:      nScreenNo, nSendMode: Integer
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            pBarcode       :���豸�������룻
            pNetworkId     :���豸������ID��

          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pBindServerDevice)(int nScreenNo, char* pBarcode, char* pNetworkId);

		/*-------------------------------------------------------------------------------
          ������:    AddScreenDynamicArea
          ��̬����ָ����ʾ����Ӷ�̬���򣻸ú���������ʾ��ͨѶ��
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nDYAreaID����̬�����ţ�Ŀǰϵͳ�����5����̬���򣻸�ֵȡֵ��ΧΪ0~4;
            nRunMode����̬��������ģʽ��
                      0:��̬������ѭ����ʾ��
                      1:��̬��������ʾ��ɺ�ֹ��ʾ���һҳ���ݣ�
                      2:��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ������ʾ��
                      3:��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ��ʾLogo��Ϣ,Logo ��Ϣ��Ϊ��̬��������һҳ��Ϣ
                      4:��̬������˳����ʾ����ʾ�����һҳ��Ͳ�����ʾ
            nTimeOut����̬�����ݳ�ʱʱ�䣻��λ���� 
            nAllProRelate����Ŀ������־��
                      1�����н�Ŀ����ʾ�ö�̬����
                      0����ָ����Ŀ����ʾ�ö�̬���������̬����Ҫ�����ڽ�Ŀ��ʾ������һ������Ϊ�ա�
            pProRelateList����Ŀ�����б��ý�Ŀ��ű�ʾ����Ŀ��ż���","����,��Ŀ��Ŷ���ΪLedshowTW 2013�����"P***"�е�"***"
            nPlayImmediately����̬�����Ƿ���������0���ö�̬�������첽��Ŀһ�𲥷ţ�1���첽��Ŀֹͣ���ţ������Ÿö�̬����
            nAreaX����̬������ʼ�����ꣻ��λ������
            nAreaY����̬������ʼ�����ꣻ��λ������
            nAreaWidth����̬�����ȣ���λ������
            nAreaHeight����̬����߶ȣ���λ������
            nAreaFMode����̬����߿���ʾ��־��0����ɫ��1����ɫ��255���ޱ߿�
            nAreaFLine����̬����߿�����, ��ɫ���ȡֵΪFRAME_SINGLE_COLOR_COUNT����ɫ���ȡֵΪ��FRAME_MULI_COLOR_COUNT
            nAreaFColor���߿���ʾ��ɫ��ѡ��Ϊ��ɫ�߿�����ʱ�ò�����Ч��
            nAreaFStunt���߿������ؼ���
                      0����˸��1��˳ʱ��ת����2����ʱ��ת����3����˸��˳ʱ��ת����
                      4:��˸����ʱ��ת����5�����̽�����˸��6�����̽���ת����7����ֹ���
            nAreaFRunSpeed���߿������ٶȣ�
            nAreaFMoveStep���߿��ƶ���������ֵȡֵ��Χ��1~8��
          ����ֵ:    �������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pAddScreenDynamicArea)(int nScreenNo, int nDYAreaID, int nRunMode,
            int nTimeOut, int nAllProRelate, char* pProRelateList, int nPlayImmediately,
            int nAreaX, int nAreaY, int nAreaWidth, int nAreaHeight, int nAreaFMode, int nAreaFLine, int nAreaFColor,
            int nAreaFStunt, int nAreaFRunSpeed, int nAreaFMoveStep);

		/*-------------------------------------------------------------------------------
          ������:    AddScreenDynamicAreaFile
          ��̬����ָ����ʾ����ָ����̬���������Ϣ�ļ����ú���������ʾ��ͨѶ��
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
            pFileName����ӵ���Ϣ�ļ����ƣ�Ŀǰֻ֧��txt(֧��ANSI��UTF-8��Unicode�ȸ�ʽ����)��bmp���ļ���ʽ
            nShowSingle��������Ϣ�Ƿ�����ʾ��0��������ʾ��1��������ʾ����ʾ�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            pFontName��������Ϣ��ʾ���壻�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nFontSize��������Ϣ��ʾ������ֺţ��ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nBold��������Ϣ�Ƿ������ʾ��0��������1��������ʾ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nFontColor��������Ϣ��ʾ��ɫ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nStunt����̬������Ϣ�����ؼ���
                      00�������ʾ 
                      01����ֹ��ʾ
                      02�����ٴ�� 
                      03�������ƶ� 
                      04���������� 
                      05�������ƶ� 
                      06���������� 
                      07����˸ 
                      08��Ʈѩ 
                      09��ð�� 
                      10���м��Ƴ� 
                      11���������� 
                      12�����ҽ������� 
                      13�����½������� 
                      14������պ� 
                      15������� 
                      16���������� 
                      17���������� 
                      18���������� 
                      19���������� 
                      20���������� 
                      21���������� 
                      22���������� 
                      23���������� 
                      24�����ҽ�����Ļ 
                      25�����½�����Ļ 
                      26����ɢ���� 
                      27��ˮƽ��ҳ 
                      28����ֱ��ҳ 
                      29��������Ļ 
                      30��������Ļ 
                      31��������Ļ 
                      32��������Ļ 
                      33�����ұպ� 
                      34�����ҶԿ� 
                      35�����±պ� 
                      36�����¶Կ� 
                      37�������ƶ� 
                      38���������� 
                      39�������ƶ� 
                      40����������
            nRunSpeed����̬������Ϣ�����ٶ�
            nShowTime����̬������Ϣ��ʾʱ�䣻��λ��10ms
          ����ֵ:    �������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pAddScreenDynamicAreaFile)(int nScreenNo, int nDYAreaID,
            char* pFileName, int nShowSingle, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime);

		/*-------------------------------------------------------------------------------
          ������:    AddScreenDynamicAreaText
          ��̬����ָ����ʾ����ָ����̬���������Ϣ�ļ����ú���������ʾ��ͨѶ��
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
            pText����ӵ���Ϣ�ļ����ƣ�Ŀǰֻ֧��txt(֧��ANSI��UTF-8��Unicode�ȸ�ʽ����)��bmp���ļ���ʽ
            nShowSingle��������Ϣ�Ƿ�����ʾ��0��������ʾ��1��������ʾ����ʾ�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            pFontName��������Ϣ��ʾ���壻�ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nFontSize��������Ϣ��ʾ������ֺţ��ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nBold��������Ϣ�Ƿ������ʾ��0��������1��������ʾ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nFontColor��������Ϣ��ʾ��ɫ���ò���ֻ��szFileNameΪtxt��ʽ�ĵ�ʱ����Ч��
            nStunt����̬������Ϣ�����ؼ���
                      00�������ʾ 
                      01����ֹ��ʾ
                      02�����ٴ�� 
                      03�������ƶ� 
                      04���������� 
                      05�������ƶ� 
                      06���������� 
                      07����˸ 
                      08��Ʈѩ 
                      09��ð�� 
                      10���м��Ƴ� 
                      11���������� 
                      12�����ҽ������� 
                      13�����½������� 
                      14������պ� 
                      15������� 
                      16���������� 
                      17���������� 
                      18���������� 
                      19���������� 
                      20���������� 
                      21���������� 
                      22���������� 
                      23���������� 
                      24�����ҽ�����Ļ 
                      25�����½�����Ļ 
                      26����ɢ���� 
                      27��ˮƽ��ҳ 
                      28����ֱ��ҳ 
                      29��������Ļ 
                      30��������Ļ 
                      31��������Ļ 
                      32��������Ļ 
                      33�����ұպ� 
                      34�����ҶԿ� 
                      35�����±պ� 
                      36�����¶Կ� 
                      37�������ƶ� 
                      38���������� 
                      39�������ƶ� 
                      40����������
            nRunSpeed����̬������Ϣ�����ٶ�
            nShowTime����̬������Ϣ��ʾʱ�䣻��λ��10ms
          ����ֵ:    �������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pAddScreenDynamicAreaText)(int nScreenNo, int nDYAreaID,
            char* pText, int nShowSingle, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime);

		/*-------------------------------------------------------------------------------
          ������:    DeleteScreen
          ɾ����̬����ָ����ʾ����������Ϣ���ú���������ʾ��ͨѶ��
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
          ����ֵ:    �������״̬���붨��
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pDeleteScreen_Dynamic)(int nScreenNo);

        /*-------------------------------------------------------------------------------
          ������:    DeleteScreenDynamicAreaFile
          ɾ����̬����ָ����ʾ��ָ���Ķ�̬����ָ���ļ���Ϣ���ú���������ʾ��ͨѶ��
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
            nFileOrd����̬�����ָ���ļ����ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
          ����ֵ:    �������״̬���붨��
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pDeleteScreenDynamicAreaFile)(int nScreenNo, int nDYAreaID, int nFileOrd);

		/*-------------------------------------------------------------------------------
         ������:    SendDynamicAreaInfoCommand
         ���Ͷ�̬����ָ����ʾ��ָ���Ķ�̬������Ϣ����ʾ�����ú�������ʾ��ͨѶ��
         ����:
           nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
           nDYAreaID����̬�����ţ��ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ
         ����ֵ:    �������״̬���붨��
       -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pSendDynamicAreaInfoCommand)(int nScreenNo, int nDYAreaID);

		/*-------------------------------------------------------------------------------
          ������:    SendDeleteDynamicAreasCommand
          ɾ����̬����ָ����ʾ��ָ���Ķ�̬������Ϣ��ͬʱ����ʾ��ͨѶɾ��ָ���Ķ�̬������Ϣ���ú�������ʾ��ͨѶ
          ����:
            nScreenNo����ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nDelAllDYArea	��̬�������б�1��ͬʱɾ�������̬����0��ɾ��������̬����
			pDYAreaIDList	��̬�����ţ���nDelAllDYAreaΪ1ʱ����ֵΪ�� ������nDelAllDYAreaΪ0ʱ���ò�����AddScreenDynamicArea�����е�nDYAreaID������Ӧ��ɾ����Ӧ��̬����
          ����ֵ:    �������״̬���붨��
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pSendDeleteDynamicAreasCommand)(int nScreenNo, int nDelAllDYArea, char* pDYAreaIDList);


// CVC_DemoDlg �Ի���
class CVC_DemoDlg : public CDialogEx
{
// ����
public:
	CVC_DemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VC_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	int g_nSendMode;//ͨѶģʽֵ����
	pInitialize Initialize;
	pUninitialize Uninitialize;
	pAddScreen_Dynamic AddScreen_Dynamic;
	pQuerryServerDeviceList QuerryServerDeviceList;
	pBindServerDevice BindServerDevice;
	pAddScreenDynamicArea AddScreenDynamicArea;
	pAddScreenDynamicAreaFile AddScreenDynamicAreaFile;
	pAddScreenDynamicAreaText AddScreenDynamicAreaText;
	pDeleteScreen_Dynamic DeleteScreen_Dynamic;
	pDeleteScreenDynamicAreaFile DeleteScreenDynamicAreaFile;
	pSendDynamicAreaInfoCommand SendDynamicAreaInfoCommand;
	pSendDeleteDynamicAreasCommand SendDeleteDynamicAreasCommand;
	void GetErrorMessage(char* szfunctionName, int nResult);
	void GetCurGrpCaption();
	CButton m_ctrlRadio1;
	CEdit m_Edit4;
	CEdit m_Edit5;
	CSpinButtonCtrl m_Spin4;
	CEdit m_Edit6;
	CComboBox m_Combo5;
	CComboBox m_Combo6;
	CEdit m_Edit7;
	CEdit m_Edit8;
	CSpinButtonCtrl m_Spin5;
	CEdit m_Edit9;
	CEdit m_Edit10;
	CEdit m_Edit11;
	CSpinButtonCtrl m_Spin1;
	CComboBox m_Combo1;
	CComboBox m_Combo2;
	CSpinButtonCtrl m_Spin2;
	CSpinButtonCtrl m_Spin3;
	CComboBox m_Combo3;
	CComboBox m_Combo4;
	CComboBox m_Combo11;
	CRichEditCtrl m_RichEdit;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CSpinButtonCtrl m_Spin6;
	CSpinButtonCtrl m_Spin7;
	CSpinButtonCtrl m_Spin8;
	CSpinButtonCtrl m_Spin9;
	CSpinButtonCtrl m_Spin10;
	CComboBox m_Combo7;
	CSpinButtonCtrl m_Spin11;
	CComboBox m_Combo8;
	CButton m_Radio3;
	CButton m_Radio4;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	CSpinButtonCtrl m_Spin12;
	CSpinButtonCtrl m_Spin13;
	CSpinButtonCtrl m_Spin14;
	CComboBox m_Combo9;
	CSpinButtonCtrl m_Spin15;
	CSpinButtonCtrl m_Spin16;
	CButton m_Radio6;
	afx_msg void OnBnClickedButton5();
	CButton m_Radio5;
	CEdit m_Edit23;
	CButton m_Check2;
	CComboBox m_Combo10;
	CSpinButtonCtrl m_Spin17;
	CSpinButtonCtrl m_Spin18;
	afx_msg void OnBnClickedButton6();
	CButton m_Check3;
	CListBox m_ListBox1;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	CEdit m_Edit1;
	CEdit m_Edit12;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
};
