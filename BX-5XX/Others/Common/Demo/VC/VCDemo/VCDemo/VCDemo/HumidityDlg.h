#pragma once

/**-----------------------------------------------------------------------------------------------------
         ������:    AddScreenProgramHumidityArea
         ��̬����ָ����ʾ����ָ����Ŀ���ʪ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е�ʪ��������Ϣ���á�
         ����:
             nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
             nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
             nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
             nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
             nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
             nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
             nSensorType     :ʪ�ȴ��������ͣ�
             0:"Temp and hum sensor S-RHT 1";
             1:"Temp and hum sensor S-RHT 2"
             nHumidityUnit   :ʪ����ʾ��λ��0:���ʪ��(%RH);1:���ʪ��(��)
             nHumidityMode   :ʪ����ʾģʽ��0:�����ͣ�1:С���͡�
             nHumidityUnitScale:ʪ�ȵ�λ��ʾ������50~100;Ĭ��Ϊ100.
             nHumidityValueWidth:ʪ����ֵ�ַ���ʾ��ȣ�
             nHumidityConditionPol:ʪ��ֵ�������ֵ���ԣ�0������1����
             nHumidityCondition:ʪ��ֵ�������ֵ��
             nHumidityThreshPol:ʪ����ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
             nHumidityThresh :ʪ����ֵ
             nHumidityColor  :����ʪ����ɫ
             nHumidityErrColor:ʪ�ȳ�����ֵʱ��ʾ����ɫ
             pStaticText     :ʪ������ǰ׺�̶��ı�;�ò�����Ϊ��
             pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
             nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
             nStaticColor    :������ɫ��
             nStaticBold     :������壻֧��1�����壻0��������
         ����ֵ            :�������״̬���붨�塣
         ------------------------------------------------------------------------}
         ------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramHumidityArea)(int nScreenNo,int nProgramOrd,
             int nX, int nY, int nWidth, int nHeight,
             int nSensorType,
             int nHumidityUnit,
             int nHumidityMode,
             int nHumidityUnitScale,
             int nHumidityValueWidth,
             int nHumidityConditionPol,
             int nHumidityCondition,
             int nHumidityThreshPol,
             int nHumidityThresh,
             int nHumidityColor,
             int nHumidityErrColor,
             char* pStaticText,
             char* pStaticFont,
             int nStaticSize,
             int nStaticColor,
             int nStaticBold);

// CHumidityDlg �Ի���

class CHumidityDlg : public CDialog
{
	DECLARE_DYNAMIC(CHumidityDlg)

public:
	CHumidityDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHumidityDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	pAddScreenProgramHumidityArea AddScreenProgramHumidityArea;

// �Ի�������
	enum { IDD = IDD_Humidity_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void CHumidityDlg::GetErrorMessage(char* szfunctionName, int nResult);
};
