Attribute VB_Name = "Module1"
Public Declare Function Initialize Lib "LedDynamicArea.dll" () As Long  '��ʼ����̬��

Public Declare Function Uninitialize Lib "LedDynamicArea.dll" () As Long  '�ͷŶ�̬��

Public Declare Function AddScreen_Dynamic Lib "LedDynamicArea.dll" _
        (ByVal nControlType As Long, ByVal nScreenNo As Long, ByVal nSendMode As Long, ByVal nWidth As Long, ByVal nHeight As Long, _
         ByVal nScreenType As Long, ByVal nPixelMode As Long, ByVal pCom As String, ByVal nBaud As Long, ByVal pSocketIP As String, _
         ByVal pSocketPort As Long, ByVal nStaticIpMode As Long, ByVal nServerMode As Long, ByVal pBarcode As String, ByVal pNetworkID As String, ByVal pServerIP As String, _
         ByVal nServerPort As Long, ByVal pServerAccessUser As String, ByVal pServerAccessPassword As String, ByVal pCommandDataFile As String) As Long '�����Ļ
         
Public Declare Function QuerryServerDeviceList Lib "LedDynamicArea.dll" _
        (ByVal pTransitDeviceType As String, ByVal pServerIP As String, ByVal nServerPort As Long, _
         ByVal pServerAccessUser As String, ByVal pServerAccessPassword As String, _
         ByRef pDeviceList() As Byte, ByRef nDeviceCount As Long) As Long   '��ѯ��ת�������豸���б���Ϣ
         
Public Declare Function AddScreenDynamicArea Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDYAreaID As Long, ByVal nRunMode As Long, ByVal nTimeOut As Long, ByVal nAllProRelate As Long, _
         ByVal pProRelateList As String, ByVal nPlayImmediately As Long, ByVal nAreaX As Long, ByVal nAreaY As Long, ByVal nAreaWidth As Long, _
         ByVal nAreaHeight As Long, ByVal nAreaFMode As Long, ByVal nAreaFLine As Long, ByVal nAreaFColor As Long, ByVal nAreaFStunt As Long, ByVal nAreaFRunSpeed As Long, _
         ByVal nAreaFMoveStep As Long) As Long  '��̬����ָ����ʾ����Ӷ�̬����
         
Public Declare Function AddScreenDynamicAreaFile Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDYAreaID As Long, ByVal pFileName As String, ByVal nShowSingle As Long, ByVal pFontName As String, _
         ByVal nFontSize As Long, ByVal nBold As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long) As Long    '��̬����ָ����ʾ����ָ����̬���������Ϣ�ļ�
         
Public Declare Function AddScreenDynamicAreaText Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDYAreaID As Long, ByVal pText As String, ByVal nShowSingle As Long, ByVal pFontName As String, _
         ByVal nFontSize As Long, ByVal nBold As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long) As Long    '��̬����ָ����ʾ����ָ����̬���������Ϣ�ı�
         
Public Declare Function DeleteScreen_Dynamic Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long) As Long   'ɾ����̬����ָ����ʾ����������Ϣ
        
Public Declare Function DeleteScreenDynamicAreaFile Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDYAreaID As Long, ByVal nFileOrd As Long) As Long  'ɾ����̬����ָ����ʾ��ָ���Ķ�̬����ָ���ļ���Ϣ
        
Public Declare Function SendDynamicAreaInfoCommand Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDYAreaID As Long) As Long  '���Ͷ�̬����ָ����ʾ��ָ���Ķ�̬������Ϣ����ʾ��
        
Public Declare Function SendDeleteDynamicAreasCommand Lib "LedDynamicArea.dll" _
        (ByVal nScreenNo As Long, ByVal nDelAllDYArea As Long, ByVal pDYAreaIDList As String) As Long   'ɾ����̬����ָ����ʾ��ָ���Ķ�̬������Ϣ��ͬʱ����ʾ��ͨѶɾ��ָ���Ķ�̬������Ϣ

Public Declare Function StartServer Lib "LedDynamicArea.dll" _
        (ByVal nSendMode As Long, ByVal pServerIP As String, ByVal nServerPort As Long) As Long     '����������,��������ģʽ�µķ�����ģʽ��GPRSͨѶģʽ��
        
Public Declare Function StopServer Lib "LedDynamicArea.dll" _
        (ByVal nSendMode As Long) As Long   '�رշ�����,��������ģʽ�µķ�����ģʽ��GPRSͨѶģʽ��
