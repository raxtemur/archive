var
a:array[1..10000] of boolean;
sum, sumn,isummax,z, i,n:longint;
begin
sumn:=0;
sum:=0;
read(n);
for i:=n downto (n div 2) do
 if a[i]=false then
    begin
    sumn:=0;
    for z:=1 to (i div 2) do
      if (i mod z)=0 then
      begin
      a[z]:=true;
      sumn+=z;
      end;

    if (sumn+i)>sum then begin isummax:=i; sum:=sumn+i; end;
    end;
writeln(isummax);
end.