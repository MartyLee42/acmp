var

i,n,j,pere,kolich,k:integer;
d:array[1..3,1..560]of byte;
begin
assign(input,'input.txt');
reset(input);

read(n);
d[1,1]:=1;
d[2,1]:=1;
kolich:=1;
for i:=1 to n do
begin



pere:=0;
for j:=1 to kolich+1 do
begin
d[3,j]:=d[1,j];
d[1,j]:=d[2,j];
d[2,j]:=d[3,j]+d[2,j]+pere;
if d[2,j]>=10 then
begin
pere:=1;
d[2,j]:=d[2,j]-10;
end
else pere:=0;
if (j>=kolich) and (pere=1) then inc(kolich);


end;


end;
assign(output,'output.txt');
rewrite(output);
for k:=0 to kolich-1 do
write(d[2,kolich-k]);

close(input);
close(output);
end. 

