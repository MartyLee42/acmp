var
a,b,d,n,min,c:longint;
ch, pos, mbite, mbyte:longint;

mass:array[0..12500] of byte;
mask: byte;
res:boolean;

f:text;
oops: boolean;
number,bit,i:integer;
pr:array[1..12500] of byte;
row:array[0..7] of byte;


label Finish;

begin

row[7]:=128;
row[0]:=1;
row[1]:=2;
row[2]:=4;
row[3]:=8;
row[4]:=16;
row[5]:=32;
row[6]:=64;


assign(f,'input.txt');
reset(f);

read(f,a);
read(f,b);
n:=2;


 if b<a then
  begin
   c:=a;
   a:=b;
  end
 else
  c:=b;

while not EOF(f) do
begin
      n:=n+1;
      read(f,b);
      if b<a then
      begin
           c:=a;
           a:=b;
      end
      else
      begin
           if b<c then c:=b;
      end;

end;


reset(f);


d:=c-a;
min:=a;
       res:=true;

       if(d=0) then
       begin
            while not EOF(f) do
            begin
                 read(f,ch);
                 if ch<>min then res:=false;
            end;
            goto Finish;
       end;

       while not EOF(f) do
       begin
            read(f,ch);
            pos:=(ch-min) div d;
            mbyte:= pos div 8;
            mbite:= pos mod 8;

            mass[mbyte] := mass[mbyte] or row[mbite];
       end;

       mbyte := n div 8;
       mbite := n mod 8;


       for i:=0 to mbyte-1 do
       begin
            if(mass[i]<>255) then res:=false;
       end;

       mask := row[mbite]-1;

       if(mass[mbyte] and mask<>mask) then res:=false;












Finish:
       assign(output,'output.txt');
       rewrite(output);

       if res=true then write('Yes')
       else write('No');

       close(f);
       close(output);
end. 

