#pragma once

/*------------------------------------------------------------------------------------
         ������:    AddScreenProgramTemperatureArea
         ��̬����ָ����ʾ����ָ����Ŀ����¶����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е��¶�������Ϣ���á�
              ����:
                  nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
                  nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
                  nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
                  nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
                  nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
                  nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
                  nSensorType     :�¶ȴ��������ͣ�
                  0:"Temp sensor S-T1";
                  1:"Temp and hum sensor S-RHT 1";
                  2:"Temp and hum sensor S-RHT 2"
                  nTemperatureUnit:�¶���ʾ��λ��0:���϶�(��);1:���϶�(�H);2:���϶�(��)
                  nTemperatureMode:�¶���ʾģʽ��0:�����ͣ�1:С���͡�
                  nTemperatureUnitScale:�¶ȵ�λ��ʾ������50~100;Ĭ��Ϊ100.
                  nTemperatureValueWidth:�¶���ֵ�ַ���ʾ��ȣ�
                  nTemperatureCorrectionPol:�¶�ֵ�������ֵ���ԣ�0������1����
                  nTemperatureCondition:�¶�ֵ�������ֵ��
                  nTemperatureThreshPol:�¶���ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
                  nTemperatureThresh:�¶���ֵ
                  nTemperatureColor:�����¶���ɫ
                  nTemperatureErrColor:�¶ȳ�����ֵʱ��ʾ����ɫ
                  pStaticText     :�¶�����ǰ׺�̶��ı�;�ò�����Ϊ��
                  pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
                  nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
                  nStaticColor    :������ɫ��
                  nStaticBold     :������壻֧��1�����壻0��������
             ����ֵ            :�������״̬���붨�塣
        ---------------------------------------------------------------------------}
        ---------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramTemperatureArea)(int nScreenNo, int nProgramOrd,
            int nX, int nY, int nWidth, int nHeight,
            int nSensorType,
            int nTemperatureUnit,
            int nTemperatureMode,
            int nTemperatureUnitScale,
            int nTemperatureValueWidth,
            int nTemperatureCorrectionPol,
            int nTemperatureCondition,
            int nTemperatureThreshPol,
            int nTemperatureThresh,
            int  nTemperatureColor,
            int  nTemperatureErrColor,
            char* pStaticText,
            char* pStaticFont,
            int nStaticSize,
            int  intnStaticColor,
            int nStaticBold);

// CTemperatureDlg �Ի���

class CTemperatureDlg : public CDialog
{
	DECLARE_DYNAMIC(CTemperatureDlg)

public:
	CTemperatureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTemperatureDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	pAddScreenProgramTemperatureArea AddScreenProgramTemperatureArea;

// �Ի�������
	enum { IDD = IDD_Temperature_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void CTemperatureDlg::GetErrorMessage(char* szfunctionName, int nResult);
};
