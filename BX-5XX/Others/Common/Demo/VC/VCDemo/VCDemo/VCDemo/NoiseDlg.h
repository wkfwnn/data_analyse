#pragma once

/**
               {-------------------------------------------------------------------------------
  ������:    AddScreenProgramNoiseArea
  ��̬����ָ����ʾ����ָ����Ŀ����������򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ�е�����������Ϣ���á�
  ����:
    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
    nSensorType     :�������������ͣ�
      0:"I-������";
      1:"II-������"
    nNoiseUnit      :������ʾ��λ��0:���ʪ��(%RH);1:���ʪ��(��)
    nNoiseMode      :������ʾģʽ��0:�����ͣ�1:С���͡�
    nNoiseUnitScale :������λ��ʾ������50~100;Ĭ��Ϊ100.
    nNoiseValueWidth:������ֵ�ַ���ʾ��ȣ�
    nNoiseConditionPol:����ֵ�������ֵ���ԣ�0������1����
    nNoiseCondition :����ֵ�������ֵ��
    nNoiseThreshPol :������ֵ������0:��ʾС�ڴ�ֵ��������;1:��ʾ���ڴ�ֵ��������
    nNoiseThresh    :������ֵ
    nNoiseColor     :����������ɫ
    nNoiseErrColor  :����������ֵʱ��ʾ����ɫ
    pStaticText     :��������ǰ׺�̶��ı�;�ò�����Ϊ��
    pStaticFont     :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻
    nStaticSize     :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ�
    nStaticColor    :������ɫ��
    nStaticBold     :������壻֧��1�����壻0��������
  ����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
        ------------------------------------------------------------------------ * */
        typedef int (__stdcall *pAddScreenProgramNoiseArea)(int nScreenNo, int nProgramOrd,
             int nX, int nY, int nWidth, int nHeight,
             int nSensorType,
             int nNoiseUnit,
             int nNoiseMode,
             int nNoiseUnitScale,
             int nNoiseValueWidth,
             int nNoiseConditionPol,
             int nNoiseCondition,
             int nNoiseThreshPol,
             int nNoiseThresh,
             int nNoiseColor,
             int nNoiseErrColor,
             char* pStaticText,
             char* pStaticFont,
             int nStaticSize,
             int nStaticColor,
             int nStaticBold);

// CNoiseDlg �Ի���

class CNoiseDlg : public CDialog
{
	DECLARE_DYNAMIC(CNoiseDlg)

public:
	CNoiseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNoiseDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	pAddScreenProgramNoiseArea AddScreenProgramNoiseArea;

// �Ի�������
	enum { IDD = IDD_Noise_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void CNoiseDlg::GetErrorMessage(char* szfunctionName, int nResult);
};
