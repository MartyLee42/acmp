#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    int a[52][52][52];
    int l[10000][4];

    
    for(int q=0; q<52; q++)
    {
        for(int w=0; w<52; w++)
        {
            for(int e=0; e<52; e++)
            {
                a[q][w][e]=0;
            }
        }
    }
    
    int h,n,m,x2,y2,z2;
    char q;
    in>>h>>m>>n;

    for(int z=1; z<=h; z++)
    {
        for(int y=1; y<=m; y++)
        {
            for(int x=1; x<=n; x++)
            {
                in>>q;
                if(q=='.') a[z][y][x]=10000000;
                else
                {
                    if(q=='1') 
                    {
                        l[0][0]=x;
                        l[0][1]=y;
                        l[0][2]=z;
                        l[0][3]=1;
                        a[z][y][x]=0;
                    }
                    if(q=='2')
                    {
                        x2=x;
                        y2=y;
                        z2=z;
                        a[z][y][x]=10000000;
                    }
                }
            }
        }
    }
    int x1,y1,z1,p;
    int line=1;
    while(line>0)
    {
        
        x1=l[0][0];
        y1=l[0][1];
        z1=l[0][2];
        p=l[0][3];
        
        if(a[z1][y1][x1-1]>p)
        {
            a[z1][y1][x1-1]=p;
            l[line][1]=y1;
            l[line][2]=z1;
            l[line][0]=x1-1;
            l[line][3]=p+1;
            line++;
        }
        if(a[z1][y1-1][x1]>p)
        {
            a[z1][y1-1][x1]=p;
            l[line][0]=x1;
            l[line][1]=y1-1;
            l[line][2]=z1;
            l[line][3]=p+1;
            line++;
        }
        if(a[z1][y1][x1+1]>p)
        {
            a[z1][y1][x1+1]=p;
            l[line][0]=x1+1;
            l[line][1]=y1;
            l[line][2]=z1;
            l[line][3]=p+1;
            line++;
        }
        if(a[z1][y1+1][x1]>p)
        {
            a[z1][y1+1][x1]=p;
            l[line][0]=x1;
            l[line][1]=y1+1;
            l[line][2]=z1;
            l[line][3]=p+1;
            line++;
        }
        if(a[z1+1][y1][x1]>p)
        {
            a[z1+1][y1][x1]=p;
            l[line][0]=x1;
            l[line][1]=y1;
            l[line][2]=z1+1;
            l[line][3]=p+1;
            line++;
        }
        line--;
        memcpy(&l[0],&l[1],16*line);    
    }
    out<<5*a[z2][y2][x2];
} 

