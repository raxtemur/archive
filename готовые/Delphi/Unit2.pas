unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, XPMan;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Label1: TLabel;
    XPManifest1: TXPManifest;
    procedure Button1Click(Sender: TObject);
  private
function sum(a, b: integer): integer;

    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var i:integer; //создаем переменную
begin
i:=sum(5,7); //ссумируем
Label1.Caption:=IntToStr(i);//выводим
end;

function TForm1.sum(a, b: integer): integer;
begin
sum:=a+b;
end;

end.
