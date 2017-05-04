var
n,m,i,b:longint;
a: array[1..50001] of byte;


begin
assign(input,'input.txt');
reset(input);
read(n);
read(m);
i:=1;
while i<=n do
begin

     read(b);
     inc(i);
     inc(b);
     if b<50002 then
     begin
          if (a[b]<>3) and (a[b]<>4) then a[b]:=1
          else
          begin

          if a[b]<>0 then a[b]:=4;
          end;
     end

     else
     begin
          b:=b-50001;
          if (a[b]<>1) and (a[b]<>4) then a[b]:=3
          else
          begin
          if a[b]<>0 then a[b]:=4;
          end;
     end;
end;
i:=1;
while i<=m do
begin
     read (b);
     inc(i);
     inc(b);
     if b<50002 then
     begin

     if (a[b]=1)  then a[b]:=2;
     if (a[b]=4)  then a[b]:=5;
     if (a[b]=6)  then a[b]:=7
     end
     else
     begin
     b:=b-50001;

     if (a[b]=4) then a[b]:=6;
     if (a[b]=5) then a[b]:=7;
     if (a[b]=3) then a[b]:=8;

     end;

end;
assign(output,'output.txt');
rewrite(output);
b:=1;
while b<50002 do
begin

if (a[b]=2) or (a[b]=5) then write(b-1,' ');

if (a[b]=7) then write(b-1, ' ');
inc(b);
end;
b:=1;
while b<50002 do
begin

if (a[b]=6) or (a[b]=8) then write(b+50000,' ');
if a[b]=7 then write(b+50000,' ' );
inc(b);
end;

close(output);
close(input);
end.




