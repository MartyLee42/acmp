var
a:array[1..10000] of longint;
m:longint;
n,i,j,k,t:integer;
begin
assign(input,'input.txt');
reset(input);
read(n,m);
for i:=1 to n do
read(a[i]);

close(input);

assign(output,'output.txt');
rewrite(output);
for i:=1 to n-1 do
begin
     k:=i;
     for j:=i to n do
     begin
     if a[k]>a[j] then
     begin
          t:=a[j]; a[j]:=a[k]; a[k]:=t;
     end;
     end;
end;
k:=1;

while m>0 do
begin
     if (a[k]<a[k+1]) or ( a[k+1]=0) then
     begin
          m:=m-k;
          inc(a[k]);

     end
     else
     begin
     k:=k+1;
     end;
end;

if m=0 then write(a[k])
else write(a[k]-1);

close(output);
end. 

