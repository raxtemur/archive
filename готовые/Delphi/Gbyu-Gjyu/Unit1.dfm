object Form1: TForm1
  Left = 185
  Top = 79
  BorderStyle = bsNone
  Caption = 'Form1'
  ClientHeight = 363
  ClientWidth = 732
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 331
    Top = 96
    Width = 38
    Height = 41
    Shape = stCircle
  end
  object Shape2: TShape
    Left = 712
    Top = 24
    Width = 17
    Height = 300
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 504
    Top = 8
  end
  object Timer2: TTimer
    Interval = 3000
    OnTimer = Timer2Timer
    Left = 480
    Top = 8
  end
end
