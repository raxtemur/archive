unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, MPlayer, StdCtrls, XPMan, IdBaseComponent, IdComponent,
  IdTCPConnection, IdTCPClient, IdRemoteCMDClient, IdRSH, ComCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    Button10: TButton;
    Button11: TButton;
    Button12: TButton;
    Button13: TButton;
    Button14: TButton;
    Button15: TButton;
    Button16: TButton;
    Button17: TButton;
    Button18: TButton;
    Button19: TButton;
    Button20: TButton;
    Button21: TButton;
    Button22: TButton;
    MediaPlayer1: TMediaPlayer;
    MediaPlayer2: TMediaPlayer;
    MediaPlayer3: TMediaPlayer;
    MediaPlayer4: TMediaPlayer;
    MediaPlayer5: TMediaPlayer;
    MediaPlayer6: TMediaPlayer;
    MediaPlayer7: TMediaPlayer;
    MediaPlayer8: TMediaPlayer;
    MediaPlayer9: TMediaPlayer;
    MediaPlayer10: TMediaPlayer;
    MediaPlayer11: TMediaPlayer;
    MediaPlayer12: TMediaPlayer;
    MediaPlayer13: TMediaPlayer;
    MediaPlayer14: TMediaPlayer;
    MediaPlayer15: TMediaPlayer;
    MediaPlayer16: TMediaPlayer;
    MediaPlayer17: TMediaPlayer;
    MediaPlayer18: TMediaPlayer;
    MediaPlayer19: TMediaPlayer;
    MediaPlayer20: TMediaPlayer;
    MediaPlayer21: TMediaPlayer;
    MediaPlayer22: TMediaPlayer;
    Button23: TButton;
    Button24: TButton;
    MediaPlayer23: TMediaPlayer;
    Button25: TButton;
    MediaPlayer24: TMediaPlayer;
    Button26: TButton;
    MediaPlayer25: TMediaPlayer;
    Button27: TButton;
    MediaPlayer26: TMediaPlayer;
    procedure Button23Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button23Click(Sender: TObject);
begin
Close;
end;

end.
