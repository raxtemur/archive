object Form1: TForm1
  Left = 438
  Top = 153
  Width = 407
  Height = 286
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 0
    Top = 29
    Width = 391
    Height = 219
    Align = alClient
    TabOrder = 0
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 391
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 1
    object ToolButton2: TToolButton
      Left = 0
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object BitBtn1: TBitBtn
      Left = 8
      Top = 2
      Width = 25
      Height = 22
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 33
      Top = 2
      Width = 24
      Height = 22
      TabOrder = 1
    end
    object ToolButton1: TToolButton
      Left = 57
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object ToolButton3: TToolButton
      Left = 65
      Top = 2
      Caption = 'ToolButton3'
      OnClick = ToolButton3Click
    end
    object ToolButton4: TToolButton
      Left = 88
      Top = 2
      Caption = 'ToolButton4'
      ImageIndex = 0
      OnClick = ToolButton4Click
    end
    object ToolButton5: TToolButton
      Left = 111
      Top = 2
      Caption = 'ToolButton5'
      ImageIndex = 1
      OnClick = ToolButton5Click
    end
    object ToolButton6: TToolButton
      Left = 134
      Top = 2
      Width = 8
      Caption = 'ToolButton6'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton7: TToolButton
      Left = 142
      Top = 2
      Caption = 'ToolButton7'
      ImageIndex = 2
    end
    object ToolButton8: TToolButton
      Left = 165
      Top = 2
      Caption = 'ToolButton8'
      ImageIndex = 3
    end
    object ToolButton9: TToolButton
      Left = 188
      Top = 2
      Caption = 'ToolButton9'
      ImageIndex = 4
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 256
  end
  object SaveDialog1: TSaveDialog
    Left = 280
  end
end
