program Bx_IV_Demo;

uses
  Forms,
  uMain in 'uMain.pas' {Frm_Main},
  uSendThread in 'uSendThread.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFrm_Main, Frm_Main);
  Application.Run;
end.
