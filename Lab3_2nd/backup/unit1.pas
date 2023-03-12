unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Grids, StdCtrls,
  matrix;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
var
  A: matr;
  m, n: integer;

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
begin
  With StringGrid1 do begin
    ColCount := 8;
    RowCount := 8;
    FixedCols := 1;
    FixedRows := 1;
    Cells[0,0] := 'MARTIX1';
  end;

  With StringGrid2 do begin
    ColCount := 8;
    RowCount := 8;
    FixedCols := 1;
    FixedRows := 1;
  end;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  i, j: integer;
begin
  m := strtoint(InputBox('Введите кол-во строк:','','0'));
  n := strtoint(InputBox('Введите кол-во столбцов:','','0'));

  MatrixInput(A, m, n);

  for i := 1 to m do
    StringGrid1.Cells[0,i] := inttostr(i);

  for j := 1 to n do
    StringGrid1.Cells[j,0] := inttostr(j);

  for i := 1 to m do
    for j := 1 to n do begin
      StringGrid1.Cells[j,i] := inttostr(A[i,j]);
    end;
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  i, i_, j: integer;
  min, x: integer;
begin
  x := strtoint(InputBox('Введите заданное число:','','0'));

  StringGrid1.Cells[n+1,0] := 'MIN';
  i_ := 0;
  for i := 1 to m do begin
    min := A[i,1];
    for j := 1 to n do begin
       if A[i,j] < min then
         min := A[i,j];
    end;
    StringGrid1.Cells[n+1,i] := inttostr(min);

    if min > x then begin
      i_ := i_ + 1;
      for j := 1 to n do
        StringGrid2.Cells[j,0] := inttostr(j);

      StringGrid2.Cells[0,i_] := inttostr(i_);
      for j := 1 to n do begin
        StringGrid2.Cells[j,i_] := inttostr(A[i,j]);
      end;
    end;
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  StringGrid1.Clean;
  StringGrid2.Clean;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  Close;
end;

end.

















