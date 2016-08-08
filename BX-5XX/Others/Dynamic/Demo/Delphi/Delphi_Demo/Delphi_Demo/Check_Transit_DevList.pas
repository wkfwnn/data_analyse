unit Check_Transit_DevList;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, ComCtrls,
  StrUtils;

type
  PDeviceInfo = ^TDeviceInfo;
  TDeviceInfo = packed record //通过中转服务其的设备列表
    Name: string; //设备名称
    BarCode: string; //设备条形码
    NetworkID: string; //网络ID,只有3G类型时该属性才有效
    TransitType: string; //设备类型；2G ? 3G
    Status: string; //设备在线状态
  end;

  Tfm_Check_Transit_DevList = class(TForm)
    lstDevice: TListView;
    procedure lstDeviceDblClick(Sender: TObject);
  private
    { Private declarations }
    FBarCode:string;
    FNetWorkID:String;
  public
    { Public declarations }
    constructor Create(AOwner:TComponent;ADeviceList:TList);reintroduce;
    destructor Destroy();override;
  end;

function Show_Transit_List(AOwner:TComponent;ADeviceList:TList;var ABarCode:string;var ANetWorkID:String):Boolean;

implementation

{$R *.DFM}

{ Ttntfm_Check_Transit_DevList }

function Show_Transit_List(AOwner:TComponent;ADeviceList:TList;var ABarCode:string;var ANetWorkID:String):Boolean;
var
  Form:Tfm_Check_Transit_DevList;
begin
  Form:=Tfm_Check_Transit_DevList.Create(AOwner,ADeviceList);
  try
    Form.ShowModal;
    Result:=Form.ModalResult = mrOK;
    if Result then begin
      ABarCode:=Form.FBarCode;
      ANetWorkID:=Form.FNetWorkID;
    end;
  finally
    Form.Free;
  end;
end;

constructor Tfm_Check_Transit_DevList.Create(AOwner:TComponent;ADeviceList:TList);
var
  I: Integer;
  DeviceInfo: PDeviceInfo;
  Item:TListItem;
begin
  inherited Create(AOwner);
  lstDevice.Clear;
  for I := 1 to ADeviceList.Count do
  begin
    DeviceInfo := ADeviceList.Items[i - 1];
    Item:=lstDevice.Items.Add;
    Item.Caption:=DeviceInfo.name;
    Item.SubItems.Add(DeviceInfo^.TransitType);
    Item.SubItems.Add(DeviceInfo^.BarCode);
    Item.SubItems.Add(DeviceInfo^.NetworkID);
    Item.SubItems.Add(DeviceInfo^.Status);
  end;
end;

destructor Tfm_Check_Transit_DevList.Destroy();
begin
  inherited Destroy();
end;

procedure Tfm_Check_Transit_DevList.lstDeviceDblClick(Sender: TObject);
var
  Item:TListItem;
begin
  if lstDevice.SelCount<=0 then begin
    Exit;
  end;
  Item:=lstDevice.Selected;
  FBarCode:=Item.SubItems[1];
  FNetWorkID:=Item.SubItems[2];
  ModalResult:=mrOk;
end;

end.

