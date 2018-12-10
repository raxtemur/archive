var
    f1, f2: text;
    s: string;

begin
    assign (f1, '/hosts');
    reset (f1);

    assign (f2, 'C:\Windows\System32\Drivers\etc');
    rewrite (f2);

    while not eof (f1) do begin
        readln (f1, s);
        writeln (f2, s)
    end;

    close (f1);
    close (f2);

end.