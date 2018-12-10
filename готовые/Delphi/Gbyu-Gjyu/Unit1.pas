unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls;

type
  TForm1 = class(TForm)
    Shape1: TShape;
    Timer1: TTimer;
    Timer2: TTimer;
    Shape2: TShape;
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Timer2Timer(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,      Y: Integer);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  PosX, PosY, VelX, VelY:Single;
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  PosX:= 30;
  PosY:= 50;
  VelX:= 1;
  VelY:= 2;

Randomize;
end;

procedure TForm1.Timer1Timer(Sender: TObject);
var
Overlay: TRect;
begin

PosX:=PosX+VelX;
PosY:=PosY+VelY;

  if PosX > ClientWidth - Shape1.Width then
  VelX:= -VelX;

  if PosY > ClientHeight - Shape1.Height then
    VelY:= -VelY;

  if PosX < 0 then
    VelX:= -VelX;

  if PosY < 0 then
    VelY:= -VelY;


Shape1.Left:=Round(PosX);
Shape1.Top:=Round(PosY);

if InterSectRect(Overlay, Shape2.BoundsRect, Shape1.BoundsRect) then
Begin
VelX:=-VelX-Random(5);
VelY:=-VelY;
end;

end;

procedure TForm1.Timer2Timer(Sender: TObject);
begin
if Shape2.Height>50 then
Shape2.Height:=Shape2.Height-1;

if VelX>0 then
 VelX:=VelX+0.01;
if VelY>0 then
 VelY:=VelY+0.01;
if VelX<0 then
 VelX:=VelX-0.01;
if VelY<0 then
 VelY:=VelY-0.01;
end;

procedure TForm1.FormMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
if Mouse.CursorPos.Y+Shape2.Height<Form1.Height+Form1.ClientOrigin.Y then
Shape2.Top:= Mouse.CursorPos.Y - Form1.ClientOrigin.Y;

end;




end.
