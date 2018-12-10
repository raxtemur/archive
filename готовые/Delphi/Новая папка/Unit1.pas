unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  F: integer;
  Form1: TForm1;
  SS: string[8];
implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
AssignFile(F, 'Сайты.txt');
Reset(F);
Read(F, SS);
end;

end.
