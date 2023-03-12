unit matrix;

{$mode ObjFPC}{$H+}

interface

type
  matr = array[1..50, 1..50] of integer;

implementation

procedure MatrixInput(var A: matr; m, n: integer);
var i, j: integer;
begin
  for i := 1 to m do
    for j := 1 to n do
      A[i,j] := random(100);
end;



end.

