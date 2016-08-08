object Frm_Main: TFrm_Main
  Left = 251
  Top = 0
  Width = 763
  Height = 712
  BorderIcons = [biSystemMenu]
  Caption = 'Bx-IV Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pnl1: TPanel
    Left = 0
    Top = 0
    Width = 747
    Height = 553
    Align = alTop
    TabOrder = 0
    object grpScreen: TGroupBox
      Left = 8
      Top = 56
      Width = 737
      Height = 169
      Caption = #31532#20108#27493'-----'#21021#22987#21270#26174#31034#23631#21442#25968
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label8: TLabel
        Left = 250
        Top = 18
        Width = 48
        Height = 13
        Caption = #36890#35759#27169#24335
      end
      object Label13: TLabel
        Left = 10
        Top = 20
        Width = 24
        Height = 13
        Caption = #23631#21495
      end
      object Label5: TLabel
        Left = 368
        Top = 17
        Width = 34
        Height = 13
        AutoSize = False
        Caption = #23485#24230
      end
      object Label6: TLabel
        Left = 488
        Top = 17
        Width = 34
        Height = 13
        AutoSize = False
        Caption = #39640#24230
      end
      object Label7: TLabel
        Left = 608
        Top = 17
        Width = 34
        Height = 13
        AutoSize = False
        Caption = #23631#22411
      end
      object Label15: TLabel
        Left = 130
        Top = 18
        Width = 60
        Height = 13
        Caption = #25511#21046#21345#22411#21495
      end
      object lbl3: TLabel
        Left = 8
        Top = 134
        Width = 391
        Height = 26
        Caption = #27880#24847#65306'M'#12289'E'#31995#21015#25165#25903#25345#32593#32476#26041#24335#36890#35759';BX-4MC'#21482#25903#25345#19977#22522#33394#65307#20854#20313#31867#22411#25511#21046#21345#37117#19981#25903#25345#19977#22522#33394#65307'BX-3T'#21482#25903#25345'9600'#27874#29305#29575
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
      object grpGPRS: TGroupBox
        Left = 10
        Top = 60
        Width = 719
        Height = 69
        Caption = 'GPRS'#35774#32622
        TabOrder = 12
        object Label21: TLabel
          Left = 12
          Top = 20
          Width = 34
          Height = 13
          AutoSize = False
          Caption = 'IP'#22320#22336
        end
        object Label22: TLabel
          Left = 128
          Top = 20
          Width = 29
          Height = 13
          AutoSize = False
          Caption = #31471#21475
        end
        object TntLabel44: TTntLabel
          Left = 240
          Top = 20
          Width = 57
          Height = 13
          AutoSize = False
          Caption = 'GPRS'#32534#21495
          Color = clBtnFace
          ParentColor = False
        end
        object edt_GprsIP: TEdit
          Left = 12
          Top = 35
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '192.168.0.152'
        end
        object edt_GprsPort: TSpinEdit
          Left = 128
          Top = 35
          Width = 98
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 1
          Value = 8120
        end
        object edt_GprsID: TEdit
          Left = 240
          Top = 35
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = 'BX-GP000001'
        end
        object btnStartGprs: TButton
          Left = 348
          Top = 29
          Width = 100
          Height = 25
          Caption = #21551#21160#26381#21153#22120
          TabOrder = 3
          OnClick = btnStartServerClick
        end
        object btnCloseGprs: TButton
          Left = 452
          Top = 29
          Width = 100
          Height = 25
          Caption = #20851#38381#26381#21153#22120
          TabOrder = 4
          OnClick = btnStopServerClick
        end
      end
      object grpComm: TGroupBox
        Left = 10
        Top = 60
        Width = 719
        Height = 69
        Caption = #20018#21475#35774#32622
        TabOrder = 3
        object Label3: TLabel
          Left = 12
          Top = 21
          Width = 32
          Height = 13
          AutoSize = False
          Caption = #20018#21475
        end
        object Label4: TLabel
          Left = 130
          Top = 21
          Width = 34
          Height = 13
          AutoSize = False
          Caption = #27874#29305#29575
        end
        object comb_COMM: TComboBox
          Left = 12
          Top = 37
          Width = 98
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 0
        end
        object comb_Baud: TComboBox
          Left = 130
          Top = 36
          Width = 98
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 1
          Text = '57600'
          Items.Strings = (
            '9600'
            '57600')
        end
      end
      object grpServer: TGroupBox
        Left = 10
        Top = 60
        Width = 719
        Height = 69
        Caption = 'ONBON'#26381#21153#22120
        TabOrder = 5
        object Label17: TLabel
          Left = 12
          Top = 19
          Width = 34
          Height = 13
          AutoSize = False
          Caption = 'IP'#22320#22336
        end
        object Label18: TLabel
          Left = 106
          Top = 19
          Width = 24
          Height = 13
          AutoSize = False
          Caption = #31471#21475
        end
        object Label19: TLabel
          Left = 200
          Top = 19
          Width = 45
          Height = 13
          AutoSize = False
          Caption = #29992#25143#21517
        end
        object Label20: TLabel
          Left = 292
          Top = 19
          Width = 34
          Height = 13
          AutoSize = False
          Caption = #23494#30721
        end
        object lblTransitBarcode: TLabel
          Left = 384
          Top = 19
          Width = 49
          Height = 13
          AutoSize = False
          Caption = #26465#24418#30721
        end
        object lblTransitNetworkId: TLabel
          Left = 504
          Top = 19
          Width = 49
          Height = 13
          AutoSize = False
          Caption = #32593#32476'ID'
          Visible = False
        end
        object edtServerIP: TEdit
          Left = 12
          Top = 35
          Width = 85
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '112.65.245.174'
        end
        object edtServerPort: TSpinEdit
          Left = 106
          Top = 34
          Width = 85
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 1
          Value = 6055
        end
        object edtUserName: TEdit
          Left = 200
          Top = 35
          Width = 85
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 2
        end
        object edtPassword: TEdit
          Left = 292
          Top = 35
          Width = 85
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          PasswordChar = '*'
          TabOrder = 3
        end
        object btnBindWirelessDevice: TButton
          Left = 624
          Top = 32
          Width = 87
          Height = 25
          Caption = #32465#23450#26080#32447#35774#22791
          TabOrder = 4
          OnClick = btnBindWirelessDeviceClick
        end
        object edtTransitBarcode: TEdit
          Left = 384
          Top = 35
          Width = 113
          Height = 21
          Hint = #35831#28857#20987#32465#23450#26080#32447#35774#22791
          Color = clMenu
          Enabled = False
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 5
        end
        object edtTransitNetworkId: TEdit
          Left = 504
          Top = 35
          Width = 113
          Height = 21
          Color = clMenu
          Enabled = False
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 6
        end
      end
      object grpNet: TGroupBox
        Left = 10
        Top = 60
        Width = 719
        Height = 70
        Caption = #32593#21475#35774#32622
        TabOrder = 4
        object Label9: TLabel
          Left = 12
          Top = 28
          Width = 34
          Height = 13
          AutoSize = False
          Caption = 'IP'#22320#22336
        end
        object Label10: TLabel
          Left = 130
          Top = 28
          Width = 29
          Height = 13
          AutoSize = False
          Caption = #31471#21475
        end
        object lblNetworkID: TLabel
          Left = 248
          Top = 28
          Width = 45
          Height = 13
          AutoSize = False
          Caption = ' '#32593#32476'ID'
          Visible = False
        end
        object rdbFixIPMode: TRadioButton
          Left = 72
          Top = 3
          Width = 113
          Height = 17
          Caption = #22266#23450'IP'#27169#24335
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = rdbFixIPModeClick
        end
        object rdbServerMode: TRadioButton
          Left = 176
          Top = 3
          Width = 113
          Height = 17
          Caption = #26381#21153#22120#27169#24335
          TabOrder = 1
          OnClick = rdbFixIPModeClick
        end
        object edt_IP: TEdit
          Left = 12
          Top = 43
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '192.168.3.110'
        end
        object spnedt_Port: TSpinEdit
          Left = 130
          Top = 43
          Width = 98
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 3
          Value = 5005
        end
        object edtNetworkID: TEdit
          Left = 248
          Top = 43
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 4
          Text = 'BX-NET000001'
          Visible = False
        end
        object btnStartServer: TButton
          Left = 356
          Top = 37
          Width = 100
          Height = 25
          Caption = #21551#21160#26381#21153#22120
          TabOrder = 5
          Visible = False
          OnClick = btnStartServerClick
        end
        object btnStopServer: TButton
          Left = 460
          Top = 37
          Width = 100
          Height = 25
          Caption = #20851#38381#26381#21153#22120
          TabOrder = 6
          Visible = False
          OnClick = btnStopServerClick
        end
      end
      object comb_SendMode: TComboBox
        Left = 250
        Top = 35
        Width = 111
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 2
        TabOrder = 2
        Text = #32593#21475#36890#35759
        OnChange = comb_SendModeChange
        Items.Strings = (
          #20018#21475#36890#35759
          'GPRS'#26080#32447#36890#35759
          #32593#21475#36890#35759
          'WIFI'#36890#35759
          'ONBON'#26381#21153#22120'-GPRS'
          'ONBON'#26381#21153#22120'-3G'
          'RF'#36890#35759)
      end
      object spnedt_ScreenNo: TSpinEdit
        Left = 10
        Top = 35
        Width = 111
        Height = 22
        MaxValue = 65535
        MinValue = 1
        TabOrder = 0
        Value = 1
      end
      object spnedt_Width: TSpinEdit
        Left = 368
        Top = 34
        Width = 111
        Height = 22
        Increment = 8
        MaxValue = 2048
        MinValue = 8
        TabOrder = 6
        Value = 80
      end
      object spnedt_Height: TSpinEdit
        Left = 488
        Top = 34
        Width = 111
        Height = 22
        Increment = 8
        MaxLength = 512
        MaxValue = 512
        MinValue = 8
        TabOrder = 7
        Value = 32
      end
      object comb_ScreenType: TComboBox
        Left = 608
        Top = 34
        Width = 111
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 1
        TabOrder = 8
        Text = #21452#22522#33394
        Items.Strings = (
          #21333#22522#33394
          #21452#22522#33394
          #19977#22522#33394
          #20840#24425#33394
          #21452#22522#33394#28784#24230)
      end
      object Button1: TButton
        Left = 412
        Top = 131
        Width = 100
        Height = 25
        Caption = #28155#21152#23631#24149
        TabOrder = 9
        OnClick = Button1Click
      end
      object Button8: TButton
        Left = 520
        Top = 131
        Width = 100
        Height = 25
        Caption = #21024#38500#31995#32479#24403#21069#23631#24149
        TabOrder = 10
        OnClick = Button8Click
      end
      object btn5: TButton
        Left = 628
        Top = 131
        Width = 100
        Height = 25
        Caption = #35774#32622#23631#24149#21442#25968
        TabOrder = 11
        OnClick = btn5Click
      end
      object comb_ControlType: TComboBox
        Left = 130
        Top = 35
        Width = 111
        Height = 21
        Style = csDropDownList
        DropDownCount = 64
        ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 1
        OnChange = comb_ControlTypeChange
      end
      object grpWifi: TGroupBox
        Left = 10
        Top = 60
        Width = 719
        Height = 70
        Caption = 'WIFI'#35774#32622
        TabOrder = 13
        object Label12: TLabel
          Left = 12
          Top = 28
          Width = 34
          Height = 13
          AutoSize = False
          Caption = 'IP'#22320#22336
        end
        object Label23: TLabel
          Left = 130
          Top = 28
          Width = 29
          Height = 13
          AutoSize = False
          Caption = #31471#21475
        end
        object lblWifiNetworkID: TLabel
          Left = 248
          Top = 28
          Width = 45
          Height = 13
          AutoSize = False
          Caption = ' '#32593#32476'ID'
          Visible = False
        end
        object rdbWifiFixIPMode: TRadioButton
          Left = 72
          Top = 3
          Width = 113
          Height = 17
          Caption = #22266#23450'IP'#27169#24335
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = rdbWifiFixIPModeClick
        end
        object rdbWifiServerMode: TRadioButton
          Left = 176
          Top = 3
          Width = 113
          Height = 17
          Caption = #26381#21153#22120#27169#24335
          TabOrder = 1
          OnClick = rdbWifiFixIPModeClick
        end
        object edtWifiIP: TEdit
          Left = 12
          Top = 43
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '192.168.3.110'
        end
        object spnedtWifiPort: TSpinEdit
          Left = 130
          Top = 43
          Width = 98
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 3
          Value = 5005
        end
        object edtWifiNetworkID: TEdit
          Left = 248
          Top = 43
          Width = 98
          Height = 21
          ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
          TabOrder = 4
          Text = 'BX-NET000001'
          Visible = False
        end
        object btnStartWifiServer: TButton
          Left = 356
          Top = 37
          Width = 100
          Height = 25
          Caption = #21551#21160#26381#21153#22120
          TabOrder = 5
          Visible = False
          OnClick = btnStartWifiServerClick
        end
        object btnStopWifiServer: TButton
          Left = 460
          Top = 37
          Width = 100
          Height = 25
          Caption = #20851#38381#26381#21153#22120
          TabOrder = 6
          Visible = False
          OnClick = btnStopWifiServerClick
        end
      end
    end
    object grpProgram: TGroupBox
      Left = 8
      Top = 224
      Width = 737
      Height = 265
      Caption = #31532#19977#27493'-----'#33410#30446'/'#21629#20196#20449#24687
      TabOrder = 2
      object PageControl3: TPageControl
        Left = 8
        Top = 16
        Width = 721
        Height = 241
        ActivePage = TabSheet5
        TabOrder = 0
        object TabSheet5: TTabSheet
          Caption = #33410#30446#20449#24687
          object PageControl1: TPageControl
            Left = 8
            Top = 37
            Width = 705
            Height = 148
            ActivePage = TabSheet1
            TabOrder = 6
            object TabSheet1: TTabSheet
              Caption = #22270#25991#31867#21306#22495#32534#36753
              object btn2: TButton
                Left = 4
                Top = 3
                Width = 100
                Height = 25
                Caption = #28155#21152#22270#25991#21306#22495
                TabOrder = 0
                OnClick = btn2Click
              end
              object PageControl2: TPageControl
                Left = 0
                Top = 32
                Width = 697
                Height = 89
                ActivePage = TabSheet3
                TabOrder = 1
                object TabSheet3: TTabSheet
                  Caption = #28155#21152#25991#20214
                  object Label16: TLabel
                    Left = 8
                    Top = 14
                    Width = 48
                    Height = 13
                    Caption = #25991#20214#21517#31216
                  end
                  object btn6: TSpeedButton
                    Left = 506
                    Top = 12
                    Width = 23
                    Height = 22
                    Glyph.Data = {
                      36040000424D3604000000000000360000002800000010000000100000000100
                      2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
                      0000000000000000000000000000000000000000000000000000000000000000
                      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
                      0000008484000084840000848400008484000084840000848400008484000084
                      84000084840000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000FF
                      FF00000000000084840000848400008484000084840000848400008484000084
                      8400008484000084840000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF
                      FF0000FFFF000000000000848400008484000084840000848400008484000084
                      840000848400008484000084840000000000FFFFFF00FFFFFF000000000000FF
                      FF00FFFFFF0000FFFF0000000000008484000084840000848400008484000084
                      84000084840000848400008484000084840000000000FFFFFF0000000000FFFF
                      FF0000FFFF00FFFFFF0000FFFF00000000000000000000000000000000000000
                      00000000000000000000000000000000000000000000000000000000000000FF
                      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
                      FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
                      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
                      FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000FF
                      FF00FFFFFF0000FFFF0000000000000000000000000000000000000000000000
                      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
                      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
                      FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
                      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
                      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
                    OnClick = btn6Click
                  end
                  object edt_FileName: TEdit
                    Left = 62
                    Top = 12
                    Width = 443
                    Height = 21
                    ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
                    TabOrder = 0
                  end
                  object btn3: TButton
                    Left = 535
                    Top = 10
                    Width = 148
                    Height = 25
                    Caption = #28155#21152#25991#20214#21040#24403#21069#22270#25991#21306#22495
                    TabOrder = 1
                    OnClick = btn3Click
                  end
                end
                object TabSheet4: TTabSheet
                  Caption = #28155#21152#25991#26412
                  ImageIndex = 1
                  object mmo_Text: TMemo
                    Left = 0
                    Top = 0
                    Width = 537
                    Height = 57
                    TabOrder = 0
                  end
                  object Button17: TButton
                    Left = 544
                    Top = 27
                    Width = 137
                    Height = 25
                    Caption = #28155#21152#25991#26412#21040#24403#21069#22270#25991#21306#22495
                    TabOrder = 1
                    OnClick = Button17Click
                  end
                end
              end
              object GroupBox3: TGroupBox
                Left = 384
                Top = 22
                Width = 313
                Height = 33
                TabOrder = 2
                object Label14: TLabel
                  Left = 1
                  Top = 11
                  Width = 100
                  Height = 13
                  Caption = #24403#21069#25991#20214'/'#25991#26412#24207#21495
                end
                object spnedt_curlFileOrd: TSpinEdit
                  Left = 115
                  Top = 7
                  Width = 60
                  Height = 22
                  MaxLength = 128
                  MaxValue = 126
                  MinValue = 0
                  TabOrder = 0
                  Value = 0
                end
                object Button4: TButton
                  Left = 176
                  Top = 6
                  Width = 132
                  Height = 25
                  Caption = #21024#38500#31995#32479#24403#21069#25991#20214
                  TabOrder = 1
                  OnClick = Button4Click
                end
              end
            end
            object TabSheet2: TTabSheet
              Caption = #26102#38388#31867#21306#22495#32534#36753
              ImageIndex = 1
              object GroupBox8: TGroupBox
                Left = 0
                Top = 0
                Width = 289
                Height = 41
                TabOrder = 0
                object Button20: TButton
                  Left = 5
                  Top = 8
                  Width = 100
                  Height = 25
                  Caption = #28155#21152#26102#38388#21306#22495
                  TabOrder = 0
                  OnClick = Button9Click
                end
                object Button21: TButton
                  Left = 134
                  Top = 8
                  Width = 147
                  Height = 25
                  Caption = #28155#21152'/'#20462#25913#26102#38388#21306#22495#25991#20214
                  TabOrder = 1
                  OnClick = Button10Click
                end
              end
              object GroupBox9: TGroupBox
                Left = 0
                Top = 40
                Width = 289
                Height = 41
                TabOrder = 1
                object Button13: TButton
                  Left = 5
                  Top = 8
                  Width = 100
                  Height = 25
                  Caption = #28155#21152#34920#30424#21306#22495
                  TabOrder = 0
                  OnClick = Button13Click
                end
                object Button14: TButton
                  Left = 134
                  Top = 8
                  Width = 147
                  Height = 25
                  Caption = #28155#21152'/'#20462#25913#34920#30424#21306#22495#25991#20214
                  TabOrder = 1
                  OnClick = Button14Click
                end
              end
              object GroupBox10: TGroupBox
                Left = 304
                Top = 40
                Width = 289
                Height = 41
                TabOrder = 2
                object Button11: TButton
                  Left = 5
                  Top = 8
                  Width = 100
                  Height = 25
                  Caption = #28155#21152#20892#21382#21306#22495
                  TabOrder = 0
                  OnClick = Button11Click
                end
                object Button12: TButton
                  Left = 134
                  Top = 8
                  Width = 147
                  Height = 25
                  Caption = #28155#21152'/'#20462#25913#20892#21382#21306#22495#25991#20214
                  TabOrder = 1
                  OnClick = Button12Click
                end
              end
              object GroupBox11: TGroupBox
                Left = 304
                Top = 0
                Width = 289
                Height = 41
                TabOrder = 3
                object Button9: TButton
                  Left = 5
                  Top = 8
                  Width = 100
                  Height = 25
                  Caption = #28155#21152#26102#38388#21306#22495
                  TabOrder = 0
                  OnClick = Button9Click
                end
                object Button10: TButton
                  Left = 134
                  Top = 8
                  Width = 147
                  Height = 25
                  Caption = #28155#21152'/'#20462#25913#26102#38388#21306#22495#25991#20214
                  TabOrder = 1
                  OnClick = Button10Click
                end
              end
              object GroupBox12: TGroupBox
                Left = 0
                Top = 82
                Width = 289
                Height = 41
                TabOrder = 4
                object Button15: TButton
                  Left = 5
                  Top = 8
                  Width = 100
                  Height = 25
                  Caption = #28155#21152#35745#26102#21306#22495
                  TabOrder = 0
                  OnClick = Button15Click
                end
                object Button16: TButton
                  Left = 134
                  Top = 8
                  Width = 147
                  Height = 25
                  Caption = #28155#21152'/'#20462#25913#35745#26102#21306#22495#25991#20214
                  TabOrder = 1
                  OnClick = Button16Click
                end
              end
            end
            object tabsht_Temperature: TTabSheet
              Caption = #28201#24230#21306#22495
              ImageIndex = 2
              object btn_Temperature: TButton
                Left = 4
                Top = 3
                Width = 100
                Height = 25
                Caption = #28155#21152#28201#24230#21306#22495
                TabOrder = 0
                OnClick = btn_TemperatureClick
              end
            end
            object tabsht_Humidity: TTabSheet
              Caption = #28287#24230#21306#22495
              ImageIndex = 3
              object btn_Humidity: TButton
                Left = 4
                Top = 3
                Width = 100
                Height = 25
                Caption = #28155#21152#28287#24230#21306#22495
                TabOrder = 0
                OnClick = btn_HumidityClick
              end
            end
            object tabsht_Noise: TTabSheet
              Caption = #22122#38899#21306#22495
              ImageIndex = 4
              object btn_Noise: TButton
                Left = 4
                Top = 3
                Width = 100
                Height = 25
                Caption = #28155#21152#22122#38899#21306#22495
                TabOrder = 0
                OnClick = btn_NoiseClick
              end
            end
          end
          object btn4: TButton
            Left = 505
            Top = 187
            Width = 123
            Height = 25
            Caption = #24320#22987#26356#26032#33410#30446
            TabOrder = 0
            OnClick = btn4Click
          end
          object btn10: TButton
            Left = 46
            Top = 187
            Width = 124
            Height = 25
            Caption = #26597#35810#24403#21069#26174#31034#23631#29366#24577
            TabOrder = 1
            OnClick = btn10Click
          end
          object btn_USB: TButton
            Left = 302
            Top = 187
            Width = 75
            Height = 25
            Caption = #20445#23384#21040'USB'
            TabOrder = 2
            OnClick = btn_USBClick
          end
          object btn_Stop: TButton
            Left = 632
            Top = 187
            Width = 75
            Height = 25
            Caption = #20572#27490#26356#26032#33410#30446
            TabOrder = 3
            OnClick = btn_StopClick
          end
          object btn_1: TButton
            Left = 381
            Top = 187
            Width = 121
            Height = 25
            Caption = #21457#36865#26174#31034#23631#33410#30446#20449#24687
            TabOrder = 4
            OnClick = btn_1Click
          end
          object btn1: TButton
            Left = 12
            Top = 7
            Width = 95
            Height = 25
            Caption = #28155#21152#33410#30446
            TabOrder = 5
            OnClick = btn1Click
          end
          object GroupBox2: TGroupBox
            Left = 408
            Top = 24
            Width = 305
            Height = 33
            TabOrder = 7
            object Label11: TLabel
              Left = 1
              Top = 12
              Width = 72
              Height = 13
              Caption = #24403#21069#21306#22495#24207#21495
            end
            object spnedt_curAreaOrd: TSpinEdit
              Left = 106
              Top = 9
              Width = 55
              Height = 22
              MaxLength = 128
              MaxValue = 128
              MinValue = 0
              TabOrder = 0
              Value = 0
            end
            object Button3: TButton
              Left = 177
              Top = 6
              Width = 124
              Height = 25
              Caption = #21024#38500#31995#32479#24403#21069#33410#30446#21306#22495
              TabOrder = 1
              OnClick = Button3Click
            end
          end
          object GroupBox7: TGroupBox
            Left = 112
            Top = 0
            Width = 281
            Height = 33
            TabOrder = 8
            object lbl1: TLabel
              Left = 13
              Top = 12
              Width = 72
              Height = 13
              Caption = #24403#21069#33410#30446#24207#21495
            end
            object spnedt_curProgramOrd: TSpinEdit
              Left = 106
              Top = 8
              Width = 60
              Height = 22
              MaxValue = 255
              MinValue = 0
              TabOrder = 0
              Value = 0
            end
            object btn7: TButton
              Left = 177
              Top = 6
              Width = 100
              Height = 25
              Caption = #21024#38500#31995#32479#24403#21069#33410#30446
              TabOrder = 1
              OnClick = btn7Click
            end
          end
          object Button18: TButton
            Left = 174
            Top = 188
            Width = 124
            Height = 25
            Caption = #26597#35810#24403#21069#26174#31034#23631#21442#25968
            TabOrder = 9
            OnClick = Button18Click
          end
        end
        object TabSheet6: TTabSheet
          Caption = #21629#20196#20449#24687
          ImageIndex = 1
          object GroupBox4: TGroupBox
            Left = 8
            Top = 7
            Width = 313
            Height = 53
            Caption = #24378#21046#24320#12289#20851#26426
            TabOrder = 0
            object Button5: TButton
              Left = 137
              Top = 19
              Width = 120
              Height = 25
              Caption = #24378#21046#24320#26426
              TabOrder = 0
              OnClick = Button5Click
            end
            object Button6: TButton
              Left = 9
              Top = 19
              Width = 120
              Height = 25
              Caption = #24378#21046#20851#26426
              TabOrder = 1
              OnClick = Button6Click
            end
          end
          object grp3: TGroupBox
            Left = 336
            Top = 8
            Width = 313
            Height = 53
            Caption = #23450#26102#24320#20851#26426
            TabOrder = 1
            object btn8: TButton
              Left = 9
              Top = 19
              Width = 120
              Height = 25
              Caption = #23450#26102#24320#20851#26426
              TabOrder = 0
              OnClick = btn8Click
            end
            object btn9: TButton
              Left = 137
              Top = 19
              Width = 120
              Height = 25
              Caption = #21462#28040#23450#26102#24320#20851#26426
              TabOrder = 1
              OnClick = btn9Click
            end
          end
          object grp4: TGroupBox
            Left = 8
            Top = 64
            Width = 313
            Height = 81
            Caption = #35843#25972#26174#31034#23631#20142#24230
            TabOrder = 2
            object Label1: TLabel
              Left = 12
              Top = 16
              Width = 10
              Height = 13
              AutoSize = False
              Caption = '0'
            end
            object Label2: TLabel
              Left = 292
              Top = 16
              Width = 16
              Height = 13
              AutoSize = False
              Caption = '15'
            end
            object Button2: TButton
              Left = 184
              Top = 52
              Width = 120
              Height = 25
              Caption = #35843#25972#20142#24230
              TabOrder = 1
              OnClick = Button2Click
            end
            object TrackBar1: TTrackBar
              Left = 4
              Top = 28
              Width = 305
              Height = 29
              Max = 16
              TabOrder = 0
              ThumbLength = 10
              TickMarks = tmTopLeft
            end
          end
          object grp5: TGroupBox
            Left = 336
            Top = 64
            Width = 313
            Height = 53
            Caption = #20854#23427#21629#20196
            TabOrder = 3
            object Button7: TButton
              Left = 9
              Top = 19
              Width = 120
              Height = 25
              Caption = #26657#27491#26102#38388
              TabOrder = 0
              OnClick = Button7Click
            end
          end
        end
      end
    end
    object grpInitialize: TGroupBox
      Left = 8
      Top = 0
      Width = 737
      Height = 57
      Caption = #31532#19968#27493'-----'#21021#22987#21270#21160#24577#24211
      TabOrder = 0
      object btnInitialize: TButton
        Left = 8
        Top = 24
        Width = 129
        Height = 25
        Caption = #21021#22987#21270#21160#24577#24211
        TabOrder = 0
        OnClick = btnInitializeClick
      end
    end
    object grpUninitialize: TGroupBox
      Left = 7
      Top = 489
      Width = 737
      Height = 57
      Caption = #31532#22235#27493'-----'#37322#25918#21160#24577#24211
      TabOrder = 3
      object btnUninitialize: TButton
        Left = 8
        Top = 24
        Width = 129
        Height = 25
        Caption = #37322#25918#21160#24577#24211
        TabOrder = 0
        OnClick = btnUninitializeClick
      end
    end
  end
  object pnl2: TPanel
    Left = 0
    Top = 553
    Width = 747
    Height = 121
    Align = alClient
    TabOrder = 1
    object mmo1: TMemo
      Left = 1
      Top = 1
      Width = 745
      Height = 98
      Hint = #21452#20987#21487#28165#31354#20449#24687
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
      ParentFont = False
      ParentShowHint = False
      ScrollBars = ssBoth
      ShowHint = True
      TabOrder = 0
      OnDblClick = mmo1DblClick
    end
    object pnl3: TPanel
      Left = 1
      Top = 99
      Width = 745
      Height = 21
      Align = alBottom
      TabOrder = 1
      object lblMessage: TLabel
        Left = 266
        Top = 1
        Width = 478
        Height = 19
        Align = alClient
      end
      object tntpnl_Progross: TTntPanel
        Left = 1
        Top = 1
        Width = 265
        Height = 19
        Align = alLeft
        Alignment = taLeftJustify
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object rzpbSendProgress: TRzProgressBar
          Left = 1
          Top = 1
          Width = 263
          Height = 17
          Align = alClient
          BorderWidth = 0
          InteriorOffset = 0
          PartsComplete = 0
          Percent = 0
          TotalParts = 0
          Visible = False
        end
      end
    end
  end
  object dlgOpen1: TOpenDialog
    Left = 532
    Top = 232
  end
  object tmr_SendProgram: TTimer
    Enabled = False
    Interval = 10
    OnTimer = tmr_SendProgramTimer
    Left = 641
    Top = 511
  end
end
