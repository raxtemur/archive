unit Unit3;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, XPMan;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Button1: TButton;
    Label1: TLabel;
    XPManifest1: TXPManifest;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
mas: array[1..3] of string;
i: integer;
begin
mas[1]:='Первя строка';
mas[2]:='Вторая строка';
mas[3]:='Третья строка';
Label1.Caption:=mas[2];
for i:=1 to 3 do
Memo1.Lines.Add(mas[i]);
end;

end.
