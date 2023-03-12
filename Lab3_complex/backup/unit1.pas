unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, matrix;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Memo1: TMemo;
    Memo2: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
var A: matr;
    m, n: integer;

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var i, j: integer;
    s, tmp: string;
begin
  s := '';
  m := strtoint(inputBox('Введите кол-во строк:', '', '0'));
  n := strtoint(inputBox('Введите кол-во столбцов:', '', '0'));

  MatrixInput(A, m, n);

  Memo1.Lines.Add('');
  for i := 1 to m do begin
    for j := 1 to n do begin
      str(A[i,j]:5, tmp);
      s := s + tmp;
    end;
    Memo1.Lines.Add(s);
    Memo1.Lines.Add('');
    s := '';
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
var i, j, min, x: integer;
    s, tmp: string;
begin
  x := strtoint(inputBox('Введите заданное число:', '', '0'));

  Memo2.Lines.Add('');

  for i := 1 to m do begin
    min := A[i,1];
    for j := 2 to n do begin
      if A[i,j] < min then
        min := A[i,j];
    end;
    Memo1.Lines[(i-1)*2+1] :=  Memo1.Lines[(i-1)*2+1] + '   ' + inttostr(min);

    if min > x then begin
      s := '';
      for j := 1 to n do begin
        str(A[i,j]:5, tmp);
        s := s + tmp;
      end;
      Memo2.Lines.Add(s);
      Memo2.Lines.Add('');
    end;
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Memo1.Clear;
  Memo2.Clear;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  Close;
end;

end.










