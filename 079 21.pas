var
a,b,i,a1: integer;
begin
assign(input,'input.txt');
reset(input);
read(a1);
read(b);

a1:=a1 mod 10;
a:=a1;
for i:=1 to b-1 do
begin
if a>10 then a:=a mod 10;
a:=a*a1;

end;
if a>10 then a:=a mod 10;
assign(output,'output.txt');
rewrite(output);
write(a);

end. 

