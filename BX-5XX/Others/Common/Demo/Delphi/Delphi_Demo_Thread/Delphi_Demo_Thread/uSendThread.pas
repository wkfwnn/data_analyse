unit uSendThread;

interface

uses
  Classes, Windows, SysUtils, Messages;
const
  WM_SHOW_RESULT_MSG = WM_USER + 1;

type
  TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;

  TSendThread = class(TThread)
  private
    { Private declarations }
    thrd_nScreenNo, thrd_nSendMode: Cardinal;
    thrd_szFileName: string;
    FCallBack:TCallBackFunc;
  protected
    procedure Execute; override;
  public
    constructor Create(nScreenNo, nSendMode: Cardinal; szFileName: string);

    property CallBack:TCallBackFunc read FCallBack write FCallBack;
  end;

implementation
uses uMain;
{ Important: Methods and properties of objects in visual components can only be
  used in a method called using Synchronize, for example,

      Synchronize(UpdateCaption);

  and UpdateCaption could look like,

    procedure TSendThread.UpdateCaption;
    begin
      Form1.Caption := 'Updated in a thread';
    end; }

{ TSendThread }

constructor TSendThread.Create(nScreenNo, nSendMode: Cardinal; szFileName: string);
begin
  thrd_nScreenNo := nScreenNo;
  thrd_nSendMode := nSendMode;
  thrd_szFileName := szFileName;
  FreeOnTerminate := True;
  inherited Create(False);
end;

procedure TSendThread.Execute;
var
  nResult           : Cardinal;
  nFileHdl          : Integer;
  errfp             : TextFile;
  tmptagSendStatus  : tagSendStatus;
begin
{  try
    EnterCriticalSection(CS);
    try
      nFileHdl := FileCreate(thrd_szFileName);
    finally
      FileClose(nFileHdl);
    end;
 // if wideFileExists(szLogoFile) then
    begin
      try
        AssignFile(errfp, thrd_szFileName);
        Rewrite(errfp);
        Writeln(errfp, 'BX-5E系列控制器正在测试中...      ' + DateTimeToStr(Now));
      finally
        CloseFile(errfp);
      end;
    end;
  finally
    LeaveCriticalSection(CS);
  end;}
  try
    nResult := SendScreenInfo(thrd_nScreenNo, SEND_CMD_SENDALLPROGRAM, 0);
    //tmptagSendStatus.szMessagestr := 'SendScreenInfo' + '---' + Frm_Main.GetErrorMessage(nResult);
    //SendMessage(Frm_Main.Handle, WM_SHOW_RESULT_MSG, WPARAM(0), Longint(@tmptagSendStatus));
  finally
    Terminate;
  end;
 // SendThread := nil;
end;

end.

