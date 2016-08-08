object fm_Check_Transit_DevList: Tfm_Check_Transit_DevList
  Left = 361
  Top = 304
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Device list'
  ClientHeight = 230
  ClientWidth = 563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object lstDevice: TListView
    Left = 8
    Top = 8
    Width = 545
    Height = 209
    Columns = <
      item
        Caption = #35774#22791#21517#31216
        Width = 100
      end
      item
        Caption = #35774#22791#31867#22411
        Width = 120
      end
      item
        Caption = #26465#30721#32534#21495
        Width = 120
      end
      item
        Caption = #32593#32476'ID'
        Width = 120
      end
      item
        Caption = #22312#32447#29366#24577
        Width = 60
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = lstDeviceDblClick
  end
end
