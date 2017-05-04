#include <fstream>


using namespace std;
 int a[600][600];
   int line[10000][2];
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n=600;
   
   
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            a[i][j]=-1;
        }
    }
    char h[300];
    int x=300,y=300;
  
    in>>h;
    int pp=0;
    while(h[pp]>0)
    {
        if(h[pp]=='N') x+=1;
        if(h[pp]=='S') x-=1;
        if(h[pp]=='E') y-=1;
        if(h[pp]=='W') y+=1;
        a[x][y]=0;
        if(h[pp]=='N') x+=1;
        if(h[pp]=='S') x-=1;
        if(h[pp]=='E') y-=1;
        if(h[pp]=='W') y+=1;
        a[x][y]=0;
        pp++;
    }
    int n1=1;
    int step=0;
    line[0][0]=300;
    line[0][1]=300;
    while(n1>0)
    {
        step++;
        int n2=0;
        for(int i=0; i<n1; i++)
        {
            if(a[line[i][0]+1][line[i][1]]==0)
            {
                a[line[i][0]+1][line[i][1]]=step;
                line[n1+n2][0]=line[i][0]+1;
                line[n1+n2][1]=line[i][1];
                n2++;
            }
            if(a[line[i][0]][line[i][1]+1]==0)
            {
                a[line[i][0]][line[i][1]+1]=step;
                line[n1+n2][0]=line[i][0];
                line[n1+n2][1]=line[i][1]+1;
                n2++;
            }
            if(a[line[i][0]-1][line[i][1]]==0)
            {
                a[line[i][0]-1][line[i][1]]=step;
                line[n1+n2][0]=line[i][0]-1;
                line[n1+n2][1]=line[i][1];
                n2++;
            }
            if(a[line[i][0]][line[i][1]-1]==0)
            {
                a[line[i][0]][line[i][1]-1]=step;
                line[n1+n2][0]=line[i][0];
                line[n1+n2][1]=line[i][1]-1;
                n2++;
            }
        }
        if(a[x][y]!=0)break;
        memcpy(&line[0][0],&line[n1][0],n2*2*sizeof(int));
        n1=n2;
    }
        if(x==300 && y==300) return 0;
        for(int i=step;i>=0; i--)
        {
            if(a[x+1][y]==i)
            {
                x+=2;
                a[x][y]=-2;
                out<<"N";
                continue;
            }
            if(a[x][y-1]==i)
            {
                y-=2;
                a[x][y]=-2;
                out<<"E";
                continue;
            }
            if(a[x-1][y]==i)
            {
                x-=2;
                a[x][y]=-2;
                out<<"S";
                continue;
            }
            if(a[x][y+1]==i)
            {
                y+=2;
                a[x][y]=-2;
                out<<"W";
                continue;
            }
            
            
        }
       

    
}




