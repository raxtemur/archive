unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Menus, XPMan, ComCtrls, TeEngine, Series, ExtCtrls,
  TeeProcs, Chart, ImgList;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    N3: TMenuItem;
    N4: TMenuItem;
    N5: TMenuItem;
    N6: TMenuItem;
    N7: TMenuItem;
    ImageList1: TImageList;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    Label1: TLabel;
    RadioButton4: TRadioButton;
    RadioButton3: TRadioButton;
    RadioButton2: TRadioButton;
    RadioButton1: TRadioButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Button1: TButton;
    TabSheet2: TTabSheet;
    TabSheet3: TTabSheet;
    CheckBox1: TCheckBox;
    ListBox1: TListBox;
    Chart1: TChart;
    Series1: TPieSeries;
    PopupMenu1: TPopupMenu;
    N8: TMenuItem;
    N9: TMenuItem;
    N10: TMenuItem;
    N11: TMenuItem;
    TabSheet4: TTabSheet;
    Edit3: TEdit;
    Button2: TButton;
    Memo1: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure N3Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
    procedure N6Click(Sender: TObject);
    procedure N7Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

uses Unit2;

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
a:Real;
begin

if (RadioButton1.Checked = True) Then begin
a:=StrToFloat(Edit1.Text)+StrToFloat(Edit2.Text);
Label1.Caption:='Результат = '+FloatToStr(a);
Series1.AddPie(a,'Сложить',clred);
if CheckBox1.Checked=True then
ListBox1.Items.Add(Edit1.Text+'+'+Edit2.Text+'='+FloatToStr(a));
end;

if (RadioButton2.Checked = True) Then begin
a:=StrToFloat(Edit1.Text)-StrToFloat(Edit2.Text);
Label1.Caption:='Результат = '+FloatToStr(a);
Series1.AddPie(a,'Вычесть',clgreen);
if CheckBox1.Checked=True then
ListBox1.Items.Add(Edit1.Text+'-'+Edit2.Text+'='+FloatToStr(a));
end;


if (RadioButton3.Checked = True) Then begin
a:=StrToFloat(Edit1.Text)*StrToFloat(Edit2.Text);
Label1.Caption:='Результат = '+FloatToStr(a);
Series1.AddPie(a,'Умножить',clblue);
if CheckBox1.Checked=True then
ListBox1.Items.Add(Edit1.Text+'*'+Edit2.Text+'='+FloatToStr(a));
end;


if (RadioButton4.Checked = True) Then begin
a:=StrToFloat(Edit1.Text)/StrToFloat(Edit2.Text);
Label1.Caption:='Результат = '+FloatToStr(a);
Series1.AddPie(a,'Разделить',clyellow);
if CheckBox1.Checked=True then
ListBox1.Items.Add(Edit1.Text+'/'+Edit2.Text+'='+FloatToStr(a));
end;
end;


procedure TForm1.N3Click(Sender: TObject);
begin
ListBox1.Items.Clear;
end;

procedure TForm1.N2Click(Sender: TObject);
begin
close;
end;

procedure TForm1.N6Click(Sender: TObject);
begin
Form2.ShowModal;
end;

procedure TForm1.N7Click(Sender: TObject);
begin
Series1.Clear;
end;



end.
