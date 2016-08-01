#include "QHash"
#include "QWidget"
//#include "const char*"

//using   namespace  std;

typedef int(*FUN1)();
typedef int(*FUN2)(int nControlType,int nScreenNo,int nSendMode,int nWidth,int nHeight,int nScreenType,int nPixelMode,\
                  const char* pCom ,int nBaud,const char* pSocketIP,int nSocketPort,int nServerMode,const char* pBarcode,\
                   const char* pNetworkID ,const char* pServerIP,int nServerPort,const char* pServerAccessUser,const char* pServerAccessPassword,const char* pCommandDataFile);
typedef int(*FUN3)(int nScreenNo, int nDYAreaID,
                   int nRunMode, int nTimeOut, int nAllProRelate,
                   const char* pProRelateList, int nPlayImmediately, int nAreaX,
                   int nAreaY, int nAreaWidth, int nAreaHeight, int nAreaFMode,
                   int nAreaFLine, int nAreaFColor, int nAreaFStunt,
                   int nAreaFRunSpeed, int nAreaFMoveStep);
typedef int(*FUN4)(int nScreenNo, int nDYAreaID,
                   const char* pFileName, int nShowSingle,  const char* pFontName,
                   int nFontSize, int nBold, int nFontColor, int nStunt,
                   int nRunSpeed, int nShowTime);
typedef int(*FUN5)(int nScreenNo, int nDYAreaID);


typedef int (*FUN6)(int nScreenNo, int nDYAreaID,
                     const char* pText, int nShowSingle,const char* pFontName, int nFontSize,
                     int nBold, int nFontColor, int nStunt, int nRunSpeed,
                     int nShowTime);




class Dll
{

public:
  Dll();
  void loadLibrary(Dll *);
  int  initScreen();
};
