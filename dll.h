#include "QHash"
#include "QWidget"
#include "string"

using   namespace  std;

typedef int(*FUN1)();
typedef int(*FUN2)(int nControlType,int nScreenNo,int nSendMode,int nWidth,int nHeight,int nScreenType,int nPixelMode,\
                  string pCom ,int nBaud,const string pSocketIP,int nSocketPort,int nServerMode,string pBarcode,\
                   string pNetworkID ,string pServerIP,int nServerPort,string pServerAccessUser,string pServerAccessPassword,string pCommandDataFile);
typedef int(*FUN3)(int nScreenNo, int nDYAreaID,
                   int nRunMode, int nTimeOut, int nAllProRelate,
                   string pProRelateList, int nPlayImmediately, int nAreaX,
                   int nAreaY, int nAreaWidth, int nAreaHeight, int nAreaFMode,
                   int nAreaFLine, int nAreaFColor, int nAreaFStunt,
                   int nAreaFRunSpeed, int nAreaFMoveStep);
typedef int(*FUN4)(int nScreenNo, int nDYAreaID,
                   string pFileName, int nShowSingle, string pFontName,
                   int nFontSize, int nBold, int nFontColor, int nStunt,
                   int nRunSpeed, int nShowTime);
typedef int(*FUN5)(int nScreenNo, int nDYAreaID);


typedef int (*FUN6)(int nScreenNo, int nDYAreaID,
                     string pText, int nShowSingle,string pFontName, int nFontSize,
                     int nBold, int nFontColor, int nStunt, int nRunSpeed,
                     int nShowTime);




class Dll
{

public:
  Dll();
  void loadLibrary(Dll *);
  int  initScreen();
  FUN1 mInitialize;
  FUN1 mUninitialize;
  FUN2 mAddScreen_Dynamic;
  FUN3 mAddScreenDynamicArea;
  FUN4 mAddScreenDynamicAreaFile;
  FUN5 mSendDynamicAreaInfoCommand;
  FUN6 mAddScreenDynamicAreaText;

};
