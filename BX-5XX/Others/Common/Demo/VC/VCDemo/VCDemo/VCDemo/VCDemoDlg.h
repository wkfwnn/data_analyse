
// VCDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "ImageTextDlg.h"
#include "TimeDlg.h"
#include "TemperatureDlg.h"
#include "HumidityDlg.h"
#include "NoiseDlg.h"
#include "afxwin.h"

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

		typedef void (__stdcall *pCallBack)(char* szMessagge,int nProgress);//�ص�����ָ��

/*-------------------------------------------------------------------------------
          ������:    AddScreen
          ��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
          ����:
            nControlType    :��ʾ���Ŀ������ͺţ�����궨�塰�������ͺŶ��塱
                Controller_BX_5AT = 0x0051;
                Controller_BX_5A0 = 0x0151;
                Controller_BX_5A1 = 0x0251;
                Controller_BX_5A2 = 0x0351;
                Controller_BX_5A3 = 0x0451;
                Controller_BX_5A4 = 0x0551;
                Controller_BX_5A1_WIFI = 0x0651;
                Controller_BX_5A2_WIFI = 0x0751;
                Controller_BX_5A4_WIFI = 0x0851;
                Controller_BX_5A  = 0x0951;
                Controller_BX_5A2_RF = 0x1351;
                Controller_BX_5A4_RF = 0x1551;
                Controller_BX_5AT_WIFI = 0x1651;
                Controller_BX_5AL = 0x1851;

                Controller_AX_AT  = 0x2051;
                Controller_AX_A0  = 0x2151;

				Controller_BX_5MT = 0x0552;
                Controller_BX_5M1 = 0x0052;
                Controller_BX_5M1X = 0x0152;
                Controller_BX_5M2 = 0x0252;
                Controller_BX_5M3 = 0x0352;
                Controller_BX_5M4 = 0x0452;

                Controller_BX_5E1 = 0x0154;
                Controller_BX_5E2 = 0x0254;
                Controller_BX_5E3 = 0x0354;

                Controller_BX_5UT = 0x0055;
                Controller_BX_5U0 = 0x0155;
                Controller_BX_5U1 = 0x0255;
                Controller_BX_5U2 = 0x0355;
                Controller_BX_5U3 = 0x0455;
                Controller_BX_5U4 = 0x0555;
                Controller_BX_5U5 = 0x0655;
                Controller_BX_5U  = 0x0755;
                Controller_BX_5UL = 0x0855;

                Controller_AX_UL  = 0x2055;
                Controller_AX_UT  = 0x2155;
                Controller_AX_U0  = 0x2255;
                Controller_AX_U1  = 0x2355;
                Controller_AX_U2  = 0x2455;

                Controller_BX_5Q0 = 0x0056;
                Controller_BX_5Q1 = 0x0156;
                Controller_BX_5Q2 = 0x0256;
                Controller_BX_5Q0P = 0x1056;
                Controller_BX_5Q1P = 0x1156;
                Controller_BX_5Q2P = 0x1256;
                Controller_BX_5QL = 0x1356;

                Controller_BX_5QS1 = 0x0157;
                Controller_BX_5QS2 = 0x0257;
                Controller_BX_5QS = 0x0357;
                Controller_BX_5QS1P = 0x1157;
                Controller_BX_5QS2P = 0x1257;
                Controller_BX_5QSP = 0x1357;
            nScreenNo       :��ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
			nSendMode       :����ʾ����ͨѶģʽ��
                0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
                1:GPRSģʽ
                2:����ģʽ
                4:WiFiģʽ
                5:ONBON������-GPRS
                6:ONBON������-3G
            nWidth          :��ʾ����� 16������������С64��BX-5Eϵ����СΪ80
            nHeight         :��ʾ���߶� 16������������С16��
            nScreenType     :��ʾ�����ͣ�1������ɫ��2��˫��ɫ��
              3��˫��ɫ��ע�⣺����ʾ������ֻ��BX-4MC֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
              4��ȫ��ɫ��ע�⣺����ʾ������ֻ��BX-5Qϵ��֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
              5��˫��ɫ�Ҷȣ�ע�⣺����ʾ������ֻ��BX-5QS֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
            nPixelMode      :�������ͣ�1��R+G��2��G+R���ò���ֻ��˫��ɫ����Ч ��Ĭ��Ϊ2��
            nDataDA         :���ݼ��ԣ���0x00�����ݵ���Ч��0x01�����ݸ���Ч��Ĭ��Ϊ0��
            nDataOE         :OE���ԣ�  0x00��OE ����Ч��0x01��OE ����Ч��Ĭ��Ϊ0��
            nRowOrder       :����ģʽ��0��������1����1�У�2����1�У�Ĭ��Ϊ0��
            nFreqPar        :ɨ���Ƶ��0~6��Ĭ��Ϊ0��
            pCom            :�������ƣ�����ͨѶģʽʱ��Ч����:COM1
            nBaud           :���ڲ����ʣ�Ŀǰ֧��9600��57600��Ĭ��Ϊ57600��
            pSocketIP       :���ƿ�IP��ַ������ͨѶģʽʱ��Ч����:192.168.0.199��
              ����̬������ͨѶģʽʱֻ֧�̶ֹ�IPģʽ������ֱ�������������ģʽ��֧�֡�
            nSocketPort     :���ƿ�����˿ڣ�����ͨѶģʽʱ��Ч������5005
			nStaticIPMode	�̶�IPͨѶģʽ  0��TCPģʽ  ��1��UDPģʽ  
            nServerMode     :0:������ģʽδ������1��������ģʽ������
			pBarcode        :�豸������
            pNetworkID      :������ģʽʱ������ID���
            pServerIP       :��ת������IP��ַ
            nServerPort     :��ת����������˿�
            pServerAccessUser:��ת�����������û���
            pServerAccessPassword:��ת��������������
            pWiFiIP         :������WiFiģʽ��IP��ַ��Ϣ��WiFiͨѶģʽʱ��Ч����:192.168.100.1
            nWiFiPort       :���ƿ�WiFi�˿ڣ�WiFiͨѶģʽʱ��Ч������5005
			pGprsIP         :GPRS������IP��ַ
            nGprsPort       :GPRS�������˿�
            pGprsID         :GPRS���
            pScreenStatusFile:���ڱ����ѯ������ʾ��״̬���������INI�ļ�����
              ֻ��ִ�в�ѯ��ʾ��״̬GetScreenStatusʱ���ò�������Ч
            pCallBack :���ط��͵���Ϣ�ͽ���
                       ����Ϊ TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int(__stdcall *pAddScreen)(int nControlType, int nScreenNo,int nSendMode,
        int nWidth, int nHeight, int nScreenType, int nPixelMode, int nDataDA,
           int nDataOE, int nRowOrder, int nDataFlow, int nFreqPar,char* pCom, int nBaud,
           char* pSocketIP, int nSocketPort,int nStaticIPMode, int nServerMode, char* pBarcode, char* pNetworkID,
           char* pServerIP, int nServerPort, char* pServerAccessUser, char* pServerAccessPassword,
           char* pWiFiIP, int nWiFiPort, char* pGprsIP, int nGprsPort, char* pGprsID, char* pScreenStatusFile, pCallBack callBack); //�������

		/*-------------------------------------------------------------------------------
          ������:    DeleteScreen
          ɾ��ָ����ʾ����Ϣ��ɾ����ʾ���ɹ���Ὣ����ʾ�������н�Ŀ��Ϣ�Ӷ�̬����ɾ����
          �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------}*/
        typedef int(__stdcall *pDeleteScreen)(int nScreenNo);//ɾ������
        /*-------------------------------------------------------------------------------
          ������:    SendScreenInfo
          ͨ��ָ����ͨѶģʽ��������Ӧ��Ϣ�������ʾ�����ú�������ʾ������ͨѶ
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nSendCmd        :ͨѶ����ֵ
              SEND_CMD_PARAMETER =41471;  ������������
              SEND_CMD_SENDALLPROGRAM = 41456;  �������н�Ŀ��Ϣ��
              SEND_CMD_POWERON =41727; ǿ�ƿ���
              SEND_CMD_POWEROFF = 41726; ǿ�ƹػ�
              SEND_CMD_TIMERPOWERONOFF = 41725; ��ʱ���ػ�
              SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; ȡ����ʱ���ػ�
              SEND_CMD_RESIVETIME = 41723; У��ʱ�䡣
              SEND_CMD_ADJUSTLIGHT = 41722; ���ȵ�����
            nOtherParam1    :����������0
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pSendScreenInfo)(int nScreenNo, int nSendCmd, int nOtherParam1);//������Ӧ�����ʾ���� 

        /*-------------------------------------------------------------------------------
          ������:    AddScreenProgram
          ��̬����ָ����ʾ����ӽ�Ŀ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ��Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramType    :��Ŀ���ͣ�0������Ŀ��
            nPlayLength     :0:��ʾ�Զ�˳�򲥷ţ������ʾ��Ŀ���ŵĳ��ȣ���Χ1~65535����λ��
            nStartYear      :��Ŀ���������ڣ���ʼ����ʱ����ݡ����Ϊ�����Ʋ��ŵĻ��ò���ֵΪ65535����2010
            nStartMonth     :��Ŀ���������ڣ���ʼ����ʱ���·ݡ���11
            nStartDay       :��Ŀ���������ڣ���ʼ����ʱ�����ڡ���26
            nEndYear        :��Ŀ���������ڣ���������ʱ����ݡ���2011
            nEndMonth       :��Ŀ���������ڣ���������ʱ���·ݡ���11
            nEndDay         :��Ŀ���������ڣ���������ʱ�����ڡ���26
            nMonPlay        :��Ŀ����������������һ�Ƿ񲥷�;0��������;1������.
            nTuesPlay       :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            nWedPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            nThursPlay      :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            bFriPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            nSatPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            nSunPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
            nStartHour      :��Ŀ�ڵ��쿪ʼ����ʱ��Сʱ����8
            nStartMinute    :��Ŀ�ڵ��쿪ʼ����ʱ����ӡ���0
            nEndHour        :��Ŀ�ڵ����������ʱ��Сʱ����18
            nEndMinute      :��Ŀ�ڵ����������ʱ����ӡ���0
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pAddScreenProgram)(int nScreenNo, int nProgramType, int nPlayLength,
            int nStartYear, int nStartMonth, int nStartDay, int nEndYear, int nEndMonth, int nEndDay,
            int nMonPlay, int nTuesPlay, int nWedPlay, int nThursPlay, int bFriPlay, int nSatPlay, int nSunPlay,
            int nStartHour, int nStartMinute, int nEndHour, int nEndMinute); //��ָ����ʾ����ӽ�Ŀ�� 

        /*-------------------------------------------------------------------------------
          ������:    DeleteScreenProgram
          ɾ��ָ����ʾ��ָ����Ŀ��ɾ����Ŀ�ɹ���Ὣ�ý�Ŀ������������Ϣɾ����
          �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pDeleteScreenProgram)(int nScreenNo, int nProgramOrd); //ɾ����Ŀ

        /*-------------------------------------------------------------------------------
          ������:    DeleteScreenProgramArea
          ɾ��ָ����ʾ��ָ����Ŀ��ָ������ɾ������ɹ���Ὣ��������������Ϣɾ����
          �ú���������ʾ��ͨѶ��ֻ���ڶ�̬����ָ����ʾ��ָ����Ŀ��ָ����������Ϣ���á�
          ����:
            nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
            nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
          ����ֵ            :�������״̬���붨�塣
        -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pDeleteScreenProgramArea)(int nScreenNo, int nProgramOrd, int nAreaOrd);//ɾ������

        

        

        

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
        typedef int (__stdcall *pQuerryServerDeviceList)(int nScreenNo, int nSendMode, byte pDeviceList[], int &nDeviceCount);

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
        typedef int (__stdcall *pBindServerDevice)(int nScreenNo, char* pBarcode, char* pNetworkId);

        /*-------------------------------------------------------------------------------
         ������:    SetScreenAdjustLight
         �趨��ʾ�������ȵ����������ú����������ֹ������Ͷ�ʱ��������ģʽ���ú���������ʾ��ͨѶ��
         ֻ���ڶ�̬���ж�ָ����ʾ�������ȵ�����Ϣ���á����轫�趨�����ȵ���ֵ���͵���ʾ���ϣ�
         ֻ��ʹ��SendScreenInfo�����������ȵ�������ɡ�
         ����:
         nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
         nAdjustType	:���ȵ������ͣ�0���ֹ�������1����ʱ����
         nHandleLight:�ֹ�����������ֵ��ֻ��nAdjustType=0ʱ�ò�����Ч��
         nHour1			:��һ�鶨ʱ����ʱ���Сʱ
         nMinute1		:��һ�鶨ʱ����ʱ��ķ���
         nLight1			:��һ�鶨ʱ����������ֵ
         nHour2			:�ڶ��鶨ʱ����ʱ���Сʱ
         nMinute2		:�ڶ��鶨ʱ����ʱ��ķ���
         nLight2			:�ڶ��鶨ʱ����������ֵ
         nHour3			:�����鶨ʱ����ʱ���Сʱ
         nMinute3		:�����鶨ʱ����ʱ��ķ���
         nLight3			:�����鶨ʱ����������ֵ
         nHour4			:�����鶨ʱ����ʱ���Сʱ
         nMinute4		:�����鶨ʱ����ʱ��ķ���
         nLight4			:�����鶨ʱ����������ֵ
         ����ֵ            :�������״̬���붨�塣
       -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pSetScreenAdjustLight)(int nScreenNo, int nAdjustType, int nHandleLight,
            int nHour1, int nMinute1, int nLight1,
            int nHour2, int nMinute2, int nLight2,
            int nHour3, int nMinute3, int nLight3,
            int nHour4, int nMinute4, int nLight4);

        /*-------------------------------------------------------------------------------
            ������:    SetScreenTimerPowerONOFF
            �趨��ʾ���Ķ�ʱ���ػ���������������3�鿪�ػ�ʱ�䡣�ú���������ʾ��ͨѶ��
            ֻ���ڶ�̬���ж�ָ����ʾ���Ķ�ʱ���ػ���Ϣ���á����轫�趨�Ķ�ʱ����ֵ���͵���ʾ���ϣ�
            ֻ��ʹ��SendScreenInfo�������Ͷ�ʱ��������ɡ�
       ����:
            nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
            nOnHour1		:��һ�鶨ʱ���صĿ���ʱ���Сʱ
            nOnMinute1	:��һ�鶨ʱ���صĿ���ʱ��ķ���
            nOffHour1		:��һ�鶨ʱ���صĹػ�ʱ���Сʱ
            nOffMinute1	:��һ�鶨ʱ���صĹػ�ʱ��ķ���
            nOnHour2		:�ڶ��鶨ʱ���صĿ���ʱ���Сʱ
            nOnMinute2	:�ڶ��鶨ʱ���صĿ���ʱ��ķ���
            nOffHour2		:�ڶ��鶨ʱ���صĹػ�ʱ���Сʱ
            nOffMinute2	:�ڶ��鶨ʱ���صĹػ�ʱ��ķ���
            nOnHour3		:�����鶨ʱ���صĿ���ʱ���Сʱ
            nOnMinute3	:�����鶨ʱ���صĿ���ʱ��ķ���
            nOffHour3		:�����鶨ʱ���صĹػ�ʱ���Сʱ
            nOffMinute3	:�����鶨ʱ���صĹػ�ʱ��ķ���
       ����ֵ            :�������״̬���붨�塣
       -------------------------------------------------------------------------------*/
        typedef int (__stdcall *pSetScreenTimerPowerONOFF)(int nScreenNo,
           int nOnHour1, int nOnMinute1, int nOffHour1, int nOffMinute1,
           int nOnHour2, int nOnMinute2, int nOffHour2, int nOffMinute2,
           int nOnHour3, int nOnMinute3, int nOffHour3, int nOffMinute3);
        

        
        

        
         /*-------------------------------------------------------------------------------
          {-------------------------------------------------------------------------------
           ������:    GetScreenStatus
           ��ѯ��ǰ��ʾ��״̬������ѯ״̬�������浽AddScreen�����е�pScreenStatusFile��INI�����ļ��С�
           �ú�������ʾ������ͨѶ
           ����:      nScreenNo, nSendMode: Integer
                      nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
                      nSendMode       :����ʾ����ͨѶģʽ��
                      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
                      2:����ģʽ;
                      4:WiFiģʽ
          ����ֵ            :�������״̬���붨�塣
          ------------------------------------------------------------------------------}
          ------------------------------------------------------------------------------ * */
           typedef int (__stdcall *pGetScreenStatus)(int nScreenNo, int nSendMode);

            /*-------------------------------------------------------------------------------
              {-------------------------------------------------------------------------------
               ������:    SaveUSBScreenInfo
               ������ʾ��������Ϣ��USB�豸�������û���USB��ʽ������ʾ����Ϣ���ú�����LedshowTW������׵�USB���ع���һ�¡�
               ʹ�øù���ʱ��ע�⵱ǰ�������Ƿ�֧��USB���ع��ܡ�
               ����:      nScreenNo, bCorrectTime: nAdvanceHour,nAdvanceMinute,pUSBDisk
                          nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
                          bCorrectTime       :�Ƿ�У��ʱ��
                                                0����У��ʱ�䣻
                                                1��У��ʱ�䡣
                          nAdvanceHour  :У��ʱ��ȵ�ǰ�����ʱ����ǰ��Сʱֵ����Χ0~23��ֻ�е�bCorrectTime=1ʱ��Ч��
                          nAdvanceMinute    :У��ʱ��ȵ�ǰ�����ʱ����ǰ�ķ���ֵ����Χ0~59��ֻ�е�bCorrectTime=1ʱ��Ч��
                          pUSBDisk  :USB�豸��·�����ƣ���ʽΪ"�̷�:\"�ĸ�ʽ��
              ����ֵ            :�������״̬���붨�塣
              ------------------------------------------------------------------------------}
              ------------------------------------------------------------------------------ * */
            typedef int (__stdcall *pSaveUSBScreenInfo)(int nScreenNo, int bCorrectTime,int nAdvanceHour,int nAdvanceMinute,char* pUSBDisk);

// CVCDemoDlg �Ի���
class CVCDemoDlg : public CDialogEx
{
// ����
public:
	CVCDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VCDEMO_DIALOG };

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
	pInitialize Initialize;
	pUninitialize Uninitialize;
	pAddScreen AddScreen;
	pDeleteScreen DeleteScreen;
	pSendScreenInfo SendScreenInfo;
	pAddScreenProgram AddScreenProgram;
	pDeleteScreenProgram DeleteScreenProgram;
	pDeleteScreenProgramArea DeleteScreenProgramArea;
	
	
	
	pQuerryServerDeviceList QuerryServerDeviceList;
	pBindServerDevice BindServerDevice;
	pSetScreenAdjustLight SetScreenAdjustLight;
	pSetScreenTimerPowerONOFF SetScreenTimerPowerONOFF;
	
	
	
	
	pGetScreenStatus GetScreenStatus;
	pSaveUSBScreenInfo SaveUSBScreenInfo;
	pCallBack callBack;
	
    //void CallBackMethod(char* szMessagge,int nProgress);
	void GetErrorMessage(char* szfunctionName, int nResult);

	CTabCtrl m_tab;
	CImageTextDlg m_imageTextDlg;
	CTimeDlg m_timeDlg;
	CTemperatureDlg m_temperatureDlg;
	CHumidityDlg m_humidityDlg;
	CNoiseDlg m_noiseDlg;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	int m_screenNo;// ����
	CSpinButtonCtrl m_spin1;
	CComboBox m_cbCtrlType;
	CComboBox m_SendMode;// ͨѶģʽ���Ʊ���
	int g_nSendMode;//ͨѶģʽֵ����
	afx_msg void OnCbnSelchangeCombo2();
	CStatic m_spGroupBox;
	CComboBox m_Baud;
	CStatic m_baudText;
	CStatic m_spText;
	CComboBox m_Sp;
	CStatic m_netGroupBox;
	int m_Radio1;
	int m_Radio2;
	CString m_SocketIP;
	CSpinButtonCtrl m_spin6;
	CSpinButtonCtrl m_spin7;
	CStatic m_BarcodeText;
	CStatic m_NetIDText2;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
	CSpinButtonCtrl m_spin2;
	CSpinButtonCtrl m_spin3;
	CComboBox m_ScreenType;
	int m_width;
	int m_height;
	CRichEditCtrl m_RichEdit;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CSpinButtonCtrl m_spin4;
	CSpinButtonCtrl m_spin5;
	int m_curProgramOrd;
	int m_curAreaOrd;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	CSliderCtrl m_slider;
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	CButton m_radio1;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	CEdit m_Edit13;
	CEdit m_Edit14;
	CComboBox m_Combo6;
};
