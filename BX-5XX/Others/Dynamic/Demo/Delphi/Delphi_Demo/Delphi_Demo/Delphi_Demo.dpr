program Delphi_Demo;

uses
  Forms,
  uMain in 'uMain.pas' {frm_Main};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(Tfrm_Main, frm_Main);
  Application.Run;
end.
