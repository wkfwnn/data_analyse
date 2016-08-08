object frm_Main: Tfrm_Main
  Left = 266
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Delphi Demo'
  ClientHeight = 706
  ClientWidth = 769
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object grp_DeviceInit: TGroupBox
    Left = 0
    Top = 49
    Width = 769
    Height = 153
    Align = alTop
    Caption = #31532#20108#27493'-----'#26174#31034#23631#21021#22987#21270
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object lbl_Screen_Address: TLabel
      Left = 6
      Top = 18
      Width = 24
      Height = 13
      Caption = #23631#21495
      Color = clBtnFace
      ParentColor = False
    end
    object Label16: TLabel
      Left = 227
      Top = 18
      Width = 48
      Height = 13
      Caption = #36890#35759#27169#24335
    end
    object Label23: TLabel
      Left = 338
      Top = 18
      Width = 60
      Height = 13
      Caption = #26174#31034#23631#23485#24230
      Color = clBtnFace
      ParentColor = False
    end
    object Label24: TLabel
      Left = 449
      Top = 18
      Width = 24
      Height = 13
      Caption = #39640#24230
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_ScreenColor: TLabel
      Left = 559
      Top = 18
      Width = 24
      Height = 13
      Caption = #31867#22411
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object lbl_Device_Pixel: TLabel
      Left = 670
      Top = 18
      Width = 48
      Height = 13
      Caption = #28857#38453#31867#22411
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_ControllerType: TLabel
      Left = 117
      Top = 18
      Width = 60
      Height = 13
      Caption = #25511#21046#22120#22411#21495
      Color = clBtnFace
      ParentColor = False
    end
    object cbb_SendMode: TComboBox
      Left = 227
      Top = 34
      Width = 94
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 1
      TabOrder = 0
      Text = #32593#32476#36890#35759
      OnChange = cbb_SendModeChange
      Items.Strings = (
        #20018#21475#36890#35759
        #32593#32476#36890#35759
        'ONBON'#26381#21153#22120'-GPRS'
        'ONBON'#26381#21153#22120'-3G'
        #20445#23384#21040#25991#20214)
    end
    object cbb_ControllerType: TComboBox
      Left = 117
      Top = 35
      Width = 94
      Height = 21
      Style = csDropDownList
      DropDownCount = 24
      ItemHeight = 13
      ItemIndex = 2
      TabOrder = 1
      Text = 'BX-5E3'
      Items.Strings = (
        'BX-5E1'
        'BX-5E2'
        'BX-5E3'
        'BX_5Q0+'
        'BX_5Q1+'
        'BX_5Q2+')
    end
    object spnedt_Width: TSpinEdit
      Left = 338
      Top = 34
      Width = 94
      Height = 22
      Increment = 8
      MaxValue = 8192
      MinValue = 80
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Value = 256
    end
    object spnedt_Height: TSpinEdit
      Left = 449
      Top = 34
      Width = 94
      Height = 22
      Increment = 8
      MaxValue = 512
      MinValue = 16
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      Value = 128
    end
    object cbb_Color: TComboBox
      Left = 559
      Top = 34
      Width = 94
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 1
      TabOrder = 4
      Text = #21452#22522#33394
      Items.Strings = (
        #21333#22522#33394
        #21452#22522#33394
        #20840#24425#33394)
    end
    object cbb_Pixel: TComboBox
      Left = 670
      Top = 34
      Width = 94
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 5
      Text = 'I  (R+G)'
      Items.Strings = (
        'I  (R+G)'
        'II (G+R)')
    end
    object pagecontrol_Communction: TPageControl
      Left = 2
      Top = 54
      Width = 765
      Height = 69
      ActivePage = tbsht_Network
      Align = alBottom
      Style = tsFlatButtons
      TabOrder = 6
      object tbsht_SerialPort: TTabSheet
        TabVisible = False
        object grp_SerialPort: TGroupBox
          Left = 0
          Top = 0
          Width = 757
          Height = 59
          Align = alClient
          Caption = #20018#21475#37197#32622
          TabOrder = 0
          object Label18: TLabel
            Left = 12
            Top = 17
            Width = 100
            Height = 13
            AutoSize = False
            Caption = #20018#21475
            Color = clBtnFace
            ParentColor = False
          end
          object Label19: TLabel
            Left = 128
            Top = 17
            Width = 100
            Height = 13
            AutoSize = False
            Caption = #27874#29305#29575
            Color = clBtnFace
            ParentColor = False
          end
          object cbb_Comm: TComboBox
            Left = 12
            Top = 32
            Width = 91
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = 'COM1'
            Items.Strings = (
              'COM1'
              'COM2'
              'COM3'
              'COM4'
              'COM5'
              'COM6'
              'COM7'
              'COM8'
              'COM9'
              'COM10')
          end
          object cbb_Baud: TComboBox
            Left = 128
            Top = 32
            Width = 92
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            ItemIndex = 1
            TabOrder = 1
            Text = '57600'
            Items.Strings = (
              '9600'
              '57600')
          end
        end
      end
      object tbsht_Network: TTabSheet
        ImageIndex = 1
        TabVisible = False
        object grp_Network: TGroupBox
          Left = 0
          Top = 0
          Width = 757
          Height = 59
          Align = alClient
          Caption = #32593#32476#37197#32622
          TabOrder = 0
          object lbl_StaticIP_IP: TLabel
            Left = 7
            Top = 36
            Width = 34
            Height = 13
            Caption = 'IP'#22320#22336
          end
          object lbl_StaticIP_Port: TLabel
            Left = 191
            Top = 36
            Width = 24
            Height = 13
            Caption = #31471#21475
          end
          object lblNetworkID: TLabel
            Left = 356
            Top = 36
            Width = 45
            Height = 13
            AutoSize = False
            Caption = ' '#32593#32476'ID'
            Visible = False
          end
          object edt_StaticIP_IP: TEdit
            Left = 55
            Top = 31
            Width = 98
            Height = 21
            TabOrder = 2
            Text = '192.168.0.199'
          end
          object spnedt_StaticIP_Port: TSpinEdit
            Left = 229
            Top = 31
            Width = 98
            Height = 22
            MaxValue = 9999
            MinValue = 1024
            TabOrder = 3
            Value = 5005
          end
          object rdbServerMode: TRadioButton
            Left = 184
            Top = 3
            Width = 113
            Height = 17
            Caption = #26381#21153#22120#27169#24335
            TabOrder = 1
            OnClick = rdbFixIPModeClick
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
          object edtNetworkID: TEdit
            Left = 408
            Top = 30
            Width = 98
            Height = 21
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 4
            Text = 'BX-NET000001'
            Visible = False
          end
          object btnStartServer: TButton
            Left = 532
            Top = 26
            Width = 100
            Height = 25
            Caption = #21551#21160#26381#21153#22120
            TabOrder = 5
            Visible = False
            OnClick = btnStartServerClick
          end
          object btnStopServer: TButton
            Left = 636
            Top = 26
            Width = 100
            Height = 25
            Caption = #20851#38381#26381#21153#22120
            TabOrder = 6
            Visible = False
            OnClick = btnStopServerClick
          end
        end
      end
      object tbsht_SaveFile: TTabSheet
        Caption = 'tbsht_SaveFile'
        ImageIndex = 2
        TabVisible = False
        object grp_SaveFile: TGroupBox
          Left = 0
          Top = 0
          Width = 757
          Height = 59
          Align = alClient
          Caption = #21629#20196#20445#23384#25991#20214#21517#31216
          TabOrder = 0
          object lbl_SaveFile: TLabel
            Left = 13
            Top = 23
            Width = 96
            Height = 13
            Caption = #21629#20196#20445#23384#25991#20214#21517#31216
            Color = clBtnFace
            ParentColor = False
          end
          object edt_SaveFile: TEdit
            Left = 112
            Top = 19
            Width = 569
            Height = 21
            TabOrder = 0
            Text = 'curCommandData.dat'
          end
        end
      end
      object tbsht_Server: TTabSheet
        Caption = 'tbsht_Server'
        ImageIndex = 3
        TabVisible = False
        object grpServer: TGroupBox
          Left = 4
          Top = 2
          Width = 757
          Height = 57
          Caption = 'ONBON'#26381#21153#22120
          TabOrder = 0
          object Label17: TLabel
            Left = 12
            Top = 14
            Width = 34
            Height = 13
            AutoSize = False
            Caption = 'IP'#22320#22336
          end
          object Label1: TLabel
            Left = 124
            Top = 15
            Width = 24
            Height = 13
            AutoSize = False
            Caption = #31471#21475
          end
          object Label2: TLabel
            Left = 220
            Top = 15
            Width = 45
            Height = 13
            AutoSize = False
            Caption = #29992#25143#21517
          end
          object Label20: TLabel
            Left = 332
            Top = 15
            Width = 34
            Height = 13
            AutoSize = False
            Caption = #23494#30721
          end
          object lblTransitBarcode: TLabel
            Left = 424
            Top = 13
            Width = 49
            Height = 13
            AutoSize = False
            Caption = #26465#24418#30721
          end
          object lblTransitNetworkId: TLabel
            Left = 544
            Top = 13
            Width = 49
            Height = 13
            AutoSize = False
            Caption = #32593#32476'ID'
          end
          object edtServerIP: TEdit
            Left = 12
            Top = 30
            Width = 101
            Height = 21
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 0
            Text = '112.65.245.174'
          end
          object edtServerPort: TSpinEdit
            Left = 124
            Top = 30
            Width = 85
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 1
            Value = 6055
          end
          object edtUserName: TEdit
            Left = 220
            Top = 30
            Width = 101
            Height = 21
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = 'chenm'
          end
          object edtPassword: TEdit
            Left = 332
            Top = 30
            Width = 85
            Height = 21
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            PasswordChar = '*'
            TabOrder = 3
            Text = 'chenmin'
          end
          object edtTransitBarcode: TEdit
            Left = 424
            Top = 29
            Width = 113
            Height = 21
            Hint = #35831#28857#20987#32465#23450#26080#32447#35774#22791
            Color = clMenu
            Enabled = False
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 4
          end
          object edtTransitNetworkId: TEdit
            Left = 544
            Top = 29
            Width = 113
            Height = 21
            Color = clMenu
            Enabled = False
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 5
          end
          object btnBindWirelessDevice: TButton
            Left = 664
            Top = 26
            Width = 88
            Height = 25
            Caption = #32465#23450#26080#32447#35774#22791
            TabOrder = 6
            OnClick = btnBindWirelessDeviceClick
          end
        end
      end
    end
    object spnedt_PNo: TSpinEdit
      Left = 6
      Top = 34
      Width = 94
      Height = 22
      MaxValue = 65535
      MinValue = 1
      TabOrder = 7
      Value = 1
      OnChange = spnedt_PNoChange
    end
    object pnl_AddScreen: TPanel
      Left = 2
      Top = 123
      Width = 765
      Height = 28
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 8
      object btn_AddScreen: TBitBtn
        Left = 514
        Top = 2
        Width = 120
        Height = 25
        Caption = #28155#21152#23631#24149
        TabOrder = 0
        OnClick = btn_AddScreenClick
      end
      object btn_DeleteScreen: TButton
        Left = 640
        Top = 2
        Width = 120
        Height = 25
        Caption = #21024#38500#23631#24149
        TabOrder = 1
        OnClick = btn_DeleteScreenClick
      end
    end
  end
  object grp_AddDynamicArea: TGroupBox
    Left = 0
    Top = 202
    Width = 769
    Height = 217
    Align = alTop
    Caption = #31532#19977#27493'-----'#28155#21152#21160#24577#21306#22495
    TabOrder = 2
    object lbl_DYAreaID: TLabel
      Left = 6
      Top = 24
      Width = 72
      Height = 13
      Caption = #21160#24577#21306#22495#32534#21495
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_RunMode: TLabel
      Left = 398
      Top = 24
      Width = 48
      Height = 13
      Caption = #36816#34892#27169#24335
    end
    object lbl_TimeOut: TLabel
      Left = 550
      Top = 24
      Width = 68
      Height = 13
      Caption = #36229#26102#26102#38388'('#31186')'
    end
    object lbl_DYAreaX: TLabel
      Left = 92
      Top = 24
      Width = 6
      Height = 13
      Caption = 'X'
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_DYAreaY: TLabel
      Left = 169
      Top = 24
      Width = 6
      Height = 13
      Caption = 'Y'
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_DYAreaW: TLabel
      Left = 245
      Top = 24
      Width = 24
      Height = 13
      Caption = #23485#24230
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_DYAreaH: TLabel
      Left = 322
      Top = 24
      Width = 24
      Height = 13
      Caption = #39640#24230
      Color = clBtnFace
      ParentColor = False
    end
    object lbl_PlayPriority: TLabel
      Left = 626
      Top = 24
      Width = 60
      Height = 13
      Caption = #25773#25918#20248#20808#32423
    end
    object pnl_AddDynamicArea: TPanel
      Left = 2
      Top = 189
      Width = 765
      Height = 26
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      object btn_AddDynamicArea: TBitBtn
        Left = 632
        Top = 0
        Width = 120
        Height = 25
        Caption = #28155#21152#23631#24149#21160#24577#21306#22495
        TabOrder = 0
        OnClick = btn_AddDynamicAreaClick
      end
    end
    object spnedt_DYAreaID: TSpinEdit
      Left = 6
      Top = 42
      Width = 80
      Height = 22
      MaxValue = 4
      MinValue = 0
      TabOrder = 1
      Value = 0
      OnChange = spnedt_DYAreaIDChange
    end
    object cbb_RunMode: TComboBox
      Left = 398
      Top = 43
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 2
      Text = #21160#24577#21306#25968#25454#24490#29615#26174#31034
      Items.Strings = (
        #21160#24577#21306#25968#25454#24490#29615#26174#31034
        #26174#31034#23436#25104#21518#38745#27490#26174#31034#26368#21518#19968#39029
        #36229#26102#21518#26410#26356#26032#21024#38500#21160#24577#21306
        #39034#24207#26174#31034#23436#25104#26368#21518#39029#21518#23601#19981#20877#26174#31034' ')
    end
    object spnedt_TimeOut: TSpinEdit
      Left = 550
      Top = 43
      Width = 70
      Height = 22
      MaxValue = 65535
      MinValue = 1
      TabOrder = 3
      Value = 1
    end
    object grp_RelatePro: TGroupBox
      Left = 2
      Top = 133
      Width = 765
      Height = 56
      Align = alBottom
      Caption = #21160#24577#21306#22495#20851#32852#33410#30446
      TabOrder = 4
      object radbtn_AllRelatePro: TRadioButton
        Left = 135
        Top = 24
        Width = 132
        Height = 17
        Caption = #25152#26377#33410#30446#26174#31034#35813#21306#22495
        TabOrder = 0
      end
      object radbtn_SelRelatePro: TRadioButton
        Left = 280
        Top = 16
        Width = 265
        Height = 33
        Caption = #22312#25351#23450#33410#30446#20013#26174#31034'('#33410#30446#32534#21495#38388#29992'","'#38548#24320','#33410#30446#32534#21495#23450#20041#20026'LedshowTW'#36719#20214#20013'"P***"'#20013#30340'"***")'
        TabOrder = 1
        WordWrap = True
      end
      object edt_RelatePro: TEdit
        Left = 544
        Top = 24
        Width = 209
        Height = 21
        TabOrder = 2
      end
      object radbtn_NoRelate: TRadioButton
        Left = 8
        Top = 24
        Width = 113
        Height = 17
        Caption = #19981#20851#32852#33410#30446#26174#31034
        Checked = True
        TabOrder = 3
        TabStop = True
      end
    end
    object spnedt_DYAreaX: TSpinEdit
      Left = 92
      Top = 42
      Width = 70
      Height = 22
      MaxValue = 0
      MinValue = 0
      TabOrder = 5
      Value = 0
    end
    object spnedt_DYAreaY: TSpinEdit
      Left = 169
      Top = 42
      Width = 70
      Height = 22
      MaxValue = 0
      MinValue = 0
      TabOrder = 6
      Value = 0
    end
    object spnedt_DYAreaW: TSpinEdit
      Left = 245
      Top = 42
      Width = 70
      Height = 22
      MaxValue = 8192
      MinValue = 8
      TabOrder = 7
      Value = 256
    end
    object spnedt_DYAreaH: TSpinEdit
      Left = 322
      Top = 43
      Width = 70
      Height = 22
      MaxValue = 512
      MinValue = 8
      TabOrder = 8
      Value = 128
    end
    object grp_DYAreaF: TGroupBox
      Left = 2
      Top = 68
      Width = 765
      Height = 65
      Align = alBottom
      TabOrder = 9
      object lbl_DYAreaFSingle: TLabel
        Left = 53
        Top = 16
        Width = 48
        Height = 13
        Caption = #36793#26694#31867#22411
      end
      object lbl_DYAreaFSingleColor: TLabel
        Left = 145
        Top = 16
        Width = 48
        Height = 13
        Caption = #26174#31034#39068#33394
      end
      object lbl_DYAreaFMuli: TLabel
        Left = 298
        Top = 16
        Width = 48
        Height = 13
        Caption = #36793#26694#31867#22411
      end
      object lbl_DYAreaFStunt: TLabel
        Left = 407
        Top = 16
        Width = 48
        Height = 13
        Caption = #36793#26694#29305#25216
      end
      object lbl_DYAreaFRunSpeed: TLabel
        Left = 564
        Top = 16
        Width = 48
        Height = 13
        Caption = #36816#34892#36895#24230
      end
      object lbl_DYAreaFMoveStep: TLabel
        Left = 656
        Top = 16
        Width = 48
        Height = 13
        Caption = #31227#21160#27493#38271
      end
      object chk_DYAreaF: TCheckBox
        Left = 8
        Top = -3
        Width = 97
        Height = 17
        Caption = #26174#31034#21306#22495#36793#26694
        TabOrder = 0
      end
      object radbtn_DYAreaFSingle: TRadioButton
        Left = 8
        Top = 40
        Width = 49
        Height = 17
        Caption = #32431#33394
        Checked = True
        TabOrder = 1
        TabStop = True
      end
      object spnedt_DYAreaFSingle: TSpinEdit
        Left = 53
        Top = 37
        Width = 80
        Height = 22
        MaxValue = 23
        MinValue = 0
        TabOrder = 2
        Value = 0
      end
      object spnedt_DYAreaFSingleColor: TSpinEdit
        Left = 145
        Top = 37
        Width = 80
        Height = 22
        MaxValue = 0
        MinValue = 0
        TabOrder = 3
        Value = 255
      end
      object radbtn_DYAreaFMuli: TRadioButton
        Left = 253
        Top = 40
        Width = 49
        Height = 17
        Caption = #33457#33394
        TabOrder = 4
      end
      object spnedt_DYAreaFMuli: TSpinEdit
        Left = 298
        Top = 37
        Width = 80
        Height = 22
        MaxValue = 46
        MinValue = 0
        TabOrder = 5
        Value = 0
      end
      object cbb_DYAreaFStunt: TComboBox
        Left = 407
        Top = 38
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        ItemIndex = 1
        TabOrder = 6
        Text = '1 '#8211#39034#26102#38024#36716#21160' '
        Items.Strings = (
          '0-'#38378#28865' '
          '1 '#8211#39034#26102#38024#36716#21160' '
          '2 '#8211#36870#26102#38024#36716#21160' '
          '3 '#8211#38378#28865#21152#39034#26102#38024#36716#21160' '
          '4 '#8211#38378#28865#21152#36870#26102#38024#36716#21160' '
          '5 '#8211#32418#32511#20132#26367#38378#28865' '
          '6 '#8211#32418#32511#20132#26367#36716#21160' '
          '7 '#8211#38745#27490#25171#20986)
      end
      object spnedt_DYAreaFRunSpeed: TSpinEdit
        Left = 564
        Top = 37
        Width = 80
        Height = 22
        MaxValue = 0
        MinValue = 0
        TabOrder = 7
        Value = 0
      end
      object spnedt_DYAreaFMoveStep: TSpinEdit
        Left = 656
        Top = 37
        Width = 80
        Height = 22
        MaxValue = 32
        MinValue = 1
        TabOrder = 8
        Value = 1
      end
    end
    object cbb_PlayPriority: TComboBox
      Left = 626
      Top = 43
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 10
      Text = #19982#33410#30446#19968#36215#25773#25918'('#21160#24577#21306#20851#32852#24322#27493#33410#30446#25165#26377#25928')'
      Items.Strings = (
        #19982#33410#30446#19968#36215#25773#25918'('#21160#24577#21306#20851#32852#24322#27493#33410#30446#25165#26377#25928')'
        #33410#30446#20572#27490#25773#25918#65292#20165#25773#25918#35813#21160#24577#21306#22495)
    end
  end
  object grp_AddDYAreaFile: TGroupBox
    Left = 0
    Top = 419
    Width = 769
    Height = 167
    Align = alTop
    Caption = #31532#22235#27493'-----'#21160#24577#21306#22495#25991#20214#23646#24615
    TabOrder = 3
    object pnl_AddDYAreaFile: TPanel
      Left = 2
      Top = 116
      Width = 765
      Height = 49
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      object btn_UpDateDYArea: TBitBtn
        Left = 4
        Top = 9
        Width = 120
        Height = 25
        Caption = #26356#26032#21160#24577#21306#22495#20449#24687
        TabOrder = 0
        OnClick = btn_UpDateDYAreaClick
      end
      object btn_DeleteScreenDynamicAreas: TButton
        Left = 132
        Top = 9
        Width = 120
        Height = 25
        Caption = #21024#38500#24403#21069#21160#24577#21306#22495
        TabOrder = 1
        OnClick = btn_DeleteScreenDynamicAreasClick
      end
      object grp_DelDYAreaPage: TGroupBox
        Left = 384
        Top = 0
        Width = 381
        Height = 44
        TabOrder = 2
        object lbl_DYAreaPage: TLabel
          Left = 1
          Top = 15
          Width = 84
          Height = 13
          Caption = #21160#24577#21306#22495#39029#24207#21495
        end
        object spnedt_DYAreaPageOrd: TSpinEdit
          Left = 89
          Top = 11
          Width = 40
          Height = 22
          MaxValue = 255
          MinValue = 0
          TabOrder = 0
          Value = 0
        end
        object btn_UpdateDYAreaPage: TButton
          Left = 134
          Top = 9
          Width = 120
          Height = 25
          Caption = #26356#26032#21160#24577#21306#22495#24403#21069#39029
          TabOrder = 1
          OnClick = btn_UpdateDYAreaPageClick
        end
        object btn_DelDYAreaPage: TButton
          Left = 260
          Top = 9
          Width = 120
          Height = 25
          Caption = #21024#38500#21160#24577#21306#22495#24403#21069#39029
          TabOrder = 2
          OnClick = btn_DelDYAreaPageClick
        end
      end
      object btn_DeleteAllDYArea: TButton
        Left = 260
        Top = 9
        Width = 120
        Height = 25
        Caption = #21024#38500#25152#26377#21160#24577#21306#22495
        TabOrder = 3
        OnClick = btn_DeleteAllDYAreaClick
      end
    end
    object Panel1: TPanel
      Left = 2
      Top = 15
      Width = 765
      Height = 101
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object lbl_DYAreaStunt: TLabel
        Left = 594
        Top = 8
        Width = 24
        Height = 13
        Caption = #29305#25216
      end
      object lbl_DYAreaRunSpeed: TLabel
        Left = 594
        Top = 34
        Width = 48
        Height = 13
        Caption = #36816#34892#36895#24230
      end
      object lbl_ShowTime: TLabel
        Left = 594
        Top = 60
        Width = 48
        Height = 13
        Caption = #20572#30041#26102#38388
      end
      object PageControl2: TPageControl
        Left = 0
        Top = 4
        Width = 585
        Height = 97
        ActivePage = TabSheet3
        TabOrder = 0
        object TabSheet3: TTabSheet
          Caption = #28155#21152#25991#20214
          object Label3: TLabel
            Left = 8
            Top = 14
            Width = 48
            Height = 13
            Caption = #25991#20214#21517#31216
          end
          object btn6: TSpeedButton
            Left = 554
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
            Width = 491
            Height = 21
            ImeName = #20013#25991' - QQ'#25340#38899#36755#20837#27861
            TabOrder = 0
          end
          object btn3: TButton
            Left = 419
            Top = 43
            Width = 158
            Height = 25
            Caption = #28155#21152#25991#20214#21040#24403#21069#21160#24577#21306#22495
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
            Width = 577
            Height = 41
            TabOrder = 0
          end
          object Button17: TButton
            Left = 419
            Top = 43
            Width = 158
            Height = 25
            Caption = #28155#21152#25991#26412#21040#24403#21069#21160#24577#21306#22495
            TabOrder = 1
            OnClick = Button17Click
          end
        end
      end
      object GroupBox1: TGroupBox
        Left = 288
        Top = -5
        Width = 297
        Height = 33
        TabOrder = 1
        object Label14: TLabel
          Left = 9
          Top = 11
          Width = 100
          Height = 13
          Caption = #24403#21069#25991#20214'/'#25991#26412#24207#21495
        end
        object spnedt_curlFileOrd: TSpinEdit
          Left = 114
          Top = 8
          Width = 47
          Height = 22
          MaxLength = 128
          MaxValue = 126
          MinValue = 0
          TabOrder = 0
          Value = 0
        end
        object btn_DelFile: TButton
          Left = 168
          Top = 6
          Width = 121
          Height = 25
          Caption = #21024#38500#31995#32479#24403#21069#25991#20214
          TabOrder = 1
          OnClick = btn_DelFileClick
        end
      end
      object chk_SingleLine: TCheckBox
        Left = 592
        Top = 80
        Width = 97
        Height = 17
        Caption = #26174#31034#21333#34892
        TabOrder = 2
      end
      object spnedt_DYAreaShowTime: TSpinEdit
        Left = 648
        Top = 56
        Width = 113
        Height = 22
        MaxValue = 0
        MinValue = 0
        TabOrder = 3
        Value = 5
      end
      object spnedt_DYAreaRunSpeed: TSpinEdit
        Left = 648
        Top = 29
        Width = 113
        Height = 22
        MaxValue = 63
        MinValue = 0
        TabOrder = 4
        Value = 2
      end
      object cbb_DYAreaStunt: TComboBox
        Left = 648
        Top = 4
        Width = 113
        Height = 21
        Style = csDropDownList
        DropDownCount = 32
        ItemHeight = 13
        ItemIndex = 2
        TabOrder = 5
        Text = '2 '#8211#24555#36895#25171#20986' '
        Items.Strings = (
          '0 '#8211#38543#26426#26174#31034
          '1 '#8211#38745#27490#26174#31034' '
          '2 '#8211#24555#36895#25171#20986' '
          '3 '#8211#21521#24038#31227#21160' '
          '4 '#8211#21521#24038#36830#31227' '
          '5 '#8211#21521#19978#31227#21160' '
          '6 '#8211#21521#19978#36830#31227' '
          '7 '#8211#38378#28865' '
          '8 '#8211#39128#38634' '
          '9 '#8211#20882#27873' '
          '10 '#8211#20013#38388#31227#20986' '
          '11 '#8211#24038#21491#31227#20837' '
          '12 '#8211#24038#21491#20132#21449#31227#20837' '
          '13 '#8211#19978#19979#20132#21449#31227#20837' '
          '14 '#8211#30011#21367#38381#21512' '
          '15 '#8211#30011#21367#25171#24320' '
          '16 '#8211#21521#24038#25289#20280' '
          '17 '#8211#21521#21491#25289#20280' '
          '18 '#8211#21521#19978#25289#20280' '
          '19 '#8211#21521#19979#25289#20280' '
          '20 '#8211#21521#24038#38253#23556' '
          '21 '#8211#21521#21491#38253#23556' '
          '22 '#8211#21521#19978#38253#23556' '
          '23 '#8211#21521#19979#38253#23556' '
          '24 '#8211#24038#21491#20132#21449#25289#24149' '
          '25 '#8211#19978#19979#20132#21449#25289#24149' '
          '26 '#8211#20998#25955#24038#25289' '
          '27 '#8211#27700#24179#30334#39029' '
          '28 '#8211#22402#30452#30334#39029' '
          '29 '#8211#21521#24038#25289#24149' '
          '30 '#8211#21521#21491#25289#24149' '
          '31 '#8211#21521#19978#25289#24149' '
          '32 '#8211#21521#19979#25289#24149' '
          '33 '#8211#24038#21491#38381#21512' '
          '34 '#8211#24038#21491#23545#24320' '
          '35 '#8211#19978#19979#38381#21512' '
          '36 '#8211#19978#19979#23545#24320' '
          '37 '#8211#21521#21491#31227#21160' '
          '38 '#8211#21521#21491#36830#31227' '
          '39 '#8211#21521#19979#31227#21160' '
          '40 '#8211#21521#19979#36830#31227' ')
      end
    end
  end
  object mmo_FunResultInfo: TMemo
    Left = 0
    Top = 633
    Width = 769
    Height = 89
    Align = alTop
    TabOrder = 5
  end
  object grp_Initialize: TGroupBox
    Left = 0
    Top = 0
    Width = 769
    Height = 49
    Align = alTop
    Caption = #31532#19968#27493'-----'#21021#22987#21270#21160#24577#24211
    TabOrder = 0
    object btn_Initialize: TButton
      Left = 8
      Top = 17
      Width = 129
      Height = 25
      Caption = #21021#22987#21270#21160#24577#24211
      TabOrder = 0
      OnClick = btn_InitializeClick
    end
  end
  object grp_Uninitialize: TGroupBox
    Left = 0
    Top = 586
    Width = 769
    Height = 47
    Align = alTop
    Caption = #31532#20116#27493'-----'#37322#25918#21160#24577#24211
    TabOrder = 4
    object btn_Uninitialize: TButton
      Left = 8
      Top = 17
      Width = 129
      Height = 25
      Caption = #37322#25918#21160#24577#24211
      TabOrder = 0
      OnClick = btn_UninitializeClick
    end
  end
  object dlgOpen_File: TOpenDialog
    Left = 336
    Top = 560
  end
end
