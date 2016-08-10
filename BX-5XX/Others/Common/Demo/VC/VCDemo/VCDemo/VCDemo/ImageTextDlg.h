#pragma once
#include "afxwin.h"
#include "afxcmn.h"

/*-------------------------------------------------------------------------------
          ������:    AddScreenProgramBmpTextArea:
          ��̬����ָ����ʾ����ָ����Ŀ���ͼ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ͼ��������Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
            nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
            nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
            nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramBmpTextArea)(int nScreenNo, int nProgramOrd, int nX, int nY,
            int nWidth, int nHeight);//��ָ����ʾ��ָ����Ŀ���ͼ������

/*-------------------------------------------------------------------------------
          ������:    AddScreenProgramAreaBmpTextFile
          ��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ļ���
              �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
            pFileName       :�ļ�����  ֧��.bmp,jpg,jpeg,rtf,txt���ļ����͡�
            nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nStunt          :��ʾ�ؼ���
              0x00:�����ʾ
              0x01:��̬
              0x02:���ٴ��
              0x03:�����ƶ�
              0x04:��������
              0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
              0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
              0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
              0x08:Ʈѩ
              0x09:ð��
              0x0A:�м��Ƴ�
              0x0B:��������
              0x0C:���ҽ�������
              0x0D:���½�������
              0x0E:����պ�
              0x0F:�����
              0x10:��������
              0x11:��������
              0x12:��������
              0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
              0x14:��������
              0x15:��������
              0x16:��������
              0x17:��������
              0x18:���ҽ�����Ļ
              0x19:���½�����Ļ
              0x1A:��ɢ����
              0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
              0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
              0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
              0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
              0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
              0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
              0x25:��������
              0x26:��������
              0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
              0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
            nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
            nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

          ����ֵ:           :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
        char* pFileName, int nShowSingle, int nAlignment, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime); //��ָ����ʾ��ָ����Ŀָ����������ļ�

/*-------------------------------------------------------------------------------
          ������:    AddScreenProgramAreaBmpTextFile
          ��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ļ���
              �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
            pFileName       :�ļ�����  ֧��.bmp,jpg,jpeg,rtf,txt���ļ����͡�
            nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
            nStunt          :��ʾ�ؼ���
              0x00:�����ʾ
              0x01:��̬
              0x02:���ٴ��
              0x03:�����ƶ�
              0x04:��������
              0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
              0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
              0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
              0x08:Ʈѩ
              0x09:ð��
              0x0A:�м��Ƴ�
              0x0B:��������
              0x0C:���ҽ�������
              0x0D:���½�������
              0x0E:����պ�
              0x0F:�����
              0x10:��������
              0x11:��������
              0x12:��������
              0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
              0x14:��������
              0x15:��������
              0x16:��������
              0x17:��������
              0x18:���ҽ�����Ļ
              0x19:���½�����Ļ
              0x1A:��ɢ����
              0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
              0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
              0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
              0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
              0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
              0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
              0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
              0x25:��������
              0x26:��������
              0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
              0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
            nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
            nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

          ����ֵ:           :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgramAreaBmpTextText)(int nScreenNo, int nProgramOrd, int nAreaOrd,
        char* pText, int nShowSingle, int nAlignment, char* pFontName, int nFontSize, int nBold, int nFontColor,
            int nStunt, int nRunSpeed, int nShowTime); //��ָ����ʾ��ָ����Ŀָ����������ļ�

/*-------------------------------------------------------------------------------
          ������:    DeleteScreenProgramAreaBmpTextFile
          ɾ��ָ����ʾ��ָ����Ŀָ��ͼ�������ָ���ļ���ɾ���ļ��ɹ���Ὣ���ļ���Ϣɾ����
          �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀָ�������е�ָ���ļ���Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
            nFileOrd        :�ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pDeleteScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd, int nFileOrd); //ɾ��ָ����ʾ��ָ����Ŀָ��ͼ�������ָ���ļ���ɾ���ļ��ɹ���Ὣ���ļ���Ϣɾ��

// CImageTextDlg �Ի���

class CImageTextDlg : public CDialog
{
	DECLARE_DYNAMIC(CImageTextDlg)

public:
	CImageTextDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CImageTextDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//�˱��������ݸ����зǳ���Ҫ������ر�����
	pAddScreenProgramBmpTextArea AddScreenProgramBmpTextArea;
	pAddScreenProgramAreaBmpTextFile AddScreenProgramAreaBmpTextFile;
	pAddScreenProgramAreaBmpTextText AddScreenProgramAreaBmpTextText;
	pDeleteScreenProgramAreaBmpTextFile DeleteScreenProgramAreaBmpTextFile;

// �Ի�������
	enum { IDD = IDD_ImageText_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
