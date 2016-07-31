
#include "QHash"

typedef int(*FUN1)();
typedef int(*FUN2)(int nControlType,int nScreenNo,int nSendMode,int nWidth,int nHeight,int nScreenType,int nPixelMode,\
                   char*pCom ,int nBaud,char*pSocketIP,int nSocketPort,int nServerMode,char*pBarcode,\
                   char*pNetworkID ,char* pServerIP,int nServerPort,char*pServerAccessUser,char*pServerAccessPassword,char*pCommandDataFile);
typedef int(*FUN3)(int nScreenNo, int nDYAreaID,
                   int nRunMode, int nTimeOut, int nAllProRelate,
                   char * pProRelateList, int nPlayImmediately, int nAreaX,
                   int nAreaY, int nAreaWidth, int nAreaHeight, int nAreaFMode,
                   int nAreaFLine, int nAreaFColor, int nAreaFStunt,
                   int nAreaFRunSpeed, int nAreaFMoveStep);
typedef int(*FUN4)(int nScreenNo, int nDYAreaID,
                   char * pFileName, int nShowSingle, char* pFontName,
                   int nFontSize, int nBold, int nFontColor, int nStunt,
                   int nRunSpeed, int nShowTime);
typedef int(*FUN5)(int nScreenNo, int nDYAreaID);




class Dll
{
public:
  void loadLibrary(Dll *);
  int initScreen(QHash<QString,QString>);
  FUN1 mInitialize;
  FUN1 mUninitialize;
  FUN2 mAddScreen_Dynamic;
  FUN3 mAddScreenDynamicArea;
  FUN4 mAddScreenDynamicAreaFile;
  FUN5 mSendDynamicAreaInfoCommand;

};
