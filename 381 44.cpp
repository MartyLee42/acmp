#include <fstream>

using namespace std;
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    in>>n;
    int a[260][260];
    for(int i=0; i<=n+1; i++)
    {
        a[0][i]=-1;
        a[i][0]=-1;
        a[n+1][i]=-1;
        a[i][n+1]=-1;
    }
    char h;
    int x,y;
    int line[10000][2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            in>>h;
            if(h=='.') a[i][j]=0;
            if(h=='O') a[i][j]=-1;
            if(h=='X') line[0][0]=i, line[0][1]=j,a[i][j]=-2;
            if(h=='@') x=i, y=j,a[i][j]=0;
        }
    }
    int n1=1;
    int step=0;
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
        memcpy(&line[0][0],&line[n1][0],n2*2*sizeof(int));
        n1=n2;
    }
    if(a[x][y]==0) out<<"No";
    else
    {
        char ch1=13, ch2=10;
        a[x][y]=-4;
        out<<"Yes";
        for(int i=step-2;i>=0; i--)
        {
            if(a[x+1][y]==i)
            {
                x++;
                a[x][y]=-2;
                continue;
            }
            if(a[x-1][y]==i)
            {
                x--;
                a[x][y]=-2;
                continue;
            }
            if(a[x][y+1]==i)
            {
                y++;
                a[x][y]=-2;
                continue;
            }
            if(a[x][y-1]==i)
            {
                y--;
                a[x][y]=-2;
            }
            
        }
        for(int i=1; i<=n; i++)
            {
                out<<ch1<<ch2;
                for(int j=1; j<=n ;j++)
                {
                    if(a[i][j]==-2) out<<"+";
                    if(a[i][j]==-4) out<<"@";
                    if(a[i][j]==-1)out<<"O";
                    if(a[i][j]>=0) out<<".";

                }
                
            }
    }

    
}



