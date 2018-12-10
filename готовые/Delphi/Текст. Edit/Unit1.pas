unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ToolWin, ComCtrls, StdCtrls, Buttons;

type
  TForm1 = class(TForm)
    RichEdit1: TRichEdit;
    ToolBar1: TToolBar;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;
    BitBtn1: TBitBtn;
    BitBtn2: TBitBtn;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton4: TToolButton;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure ToolButton3Click(Sender: TObject);
    procedure ToolButton4Click(Sender: TObject);
    procedure ToolButton5Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.BitBtn1Click(Sender: TObject);
begin
if OpenDialog1.Execute then
RichEdit1.Lines.LoadFromFile(OpenDialog1.FileName);

end;

procedure TForm1.BitBtn2Click(Sender: TObject);
begin
if SaveDialog1.Execute then
RichEdit1.Lines.SaveToFile(SaveDialog1.FileName);

end;

procedure TForm1.ToolButton3Click(Sender: TObject);
begin
RichEdit1.SelAttributes.Style:=[fsBold];
end;

procedure TForm1.ToolButton4Click(Sender: TObject);
begin
 RichEdit1.SelAttributes.Style:=[fsItalic];
end;

procedure TForm1.ToolButton5Click(Sender: TObject);
begin
 RichEdit1.SelAttributes.Style:=[fsUnderline];
end;


end.
