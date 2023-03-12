type
    mtx = Array[1..10, 1..15] of integer;
procedure Output(const arr:mtx; n, m:integer);
var
    i,j:integer;
begin
    for i:= 1 to n do // rows
    begin
        for j:= 1 to m do // cols in ros
            write(arr[i,j]:4);
        writeln();
    end;
end;
procedure FillSnakeStyle(var arr:mtx; n,m:integer);
var
    i, counter, offset, maxOffset:integer;
begin
    counter := 1;
    offset := 0;
    if n > m then
        maxOffset := (m) div 2
    else
        maxOffset := (n) div 2;
    for offset := 0 to maxOffset do
    begin
        
        // left
        for i := n - offset downto 1 + offset do
        begin
            arr[i, offset + 1] := counter;
            counter := counter + 1;
        end;
        
        // top
        for i := 2 + offset to m - offset do
        begin
            arr[offset + 1, i] := counter;
            counter := counter + 1;
        end;
        
        // right
        if offset < m div 2 then
            for i := 2 + offset to n - offset do
            begin
                arr[i, m - offset] := counter;
                counter := counter + 1;
            end;
        
        // bottom
        
        if offset < n div 2 then
            for i := m - offset - 1 downto offset + 2 do
            begin
                arr[n - offset, i] := counter;
                counter := counter + 1;
            end;
    end;
end;
var
    m, n:integer;
    arr:mtx;
begin
    write('Введите количество строк и колонок (n, m): ');
    readln(n, m);
    FillSnakeStyle(arr, n, m);
    writeln();
    Output(arr, n, m);
end.
