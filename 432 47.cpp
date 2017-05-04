#include <fstream>
using namespace std;

int a[260][260];

int find(int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(a[i][j]==0) return i*1000+j;
    }
    return -1;
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,m;
    in>>n>>m;
    
    for(int i=0; i<=m+1; i++)
    {
        a[0][i]=-1;
        a[n+1][i]=-1;
    }
    for(int i=0; i<=n+1; i++)
    {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }
    char h;
    int x,y;
    int line[10000][2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            in>>h;
            if(h=='#') a[i][j]=0;
            if(h=='.') a[i][j]=-1;
        }
    }
    
    int ans=0;
    while(true)
    {
        int e=find(n,m);
        if(e<0) break;
        line[0][0]=e/1000;
        line[0][1]=e%1000;
        a[line[0][0]][line[0][1]]=1;
        int n1=1;
        while(n1>0)
        {
            
            int n2=0;
            for(int i=0; i<n1; i++)
            {
                if(a[line[i][0]+1][line[i][1]]==0)
                {
                    a[line[i][0]+1][line[i][1]]=1;
                    line[n1+n2][0]=line[i][0]+1;
                    line[n1+n2][1]=line[i][1];
                    n2++;
                }
                if(a[line[i][0]][line[i][1]+1]==0)
                {
                    a[line[i][0]][line[i][1]+1]=1;
                    line[n1+n2][0]=line[i][0];
                    line[n1+n2][1]=line[i][1]+1;
                    n2++;
                }
                if(a[line[i][0]-1][line[i][1]]==0)
                {
                    a[line[i][0]-1][line[i][1]]=1;
                    line[n1+n2][0]=line[i][0]-1;
                    line[n1+n2][1]=line[i][1];
                    n2++;
                }
                if(a[line[i][0]][line[i][1]-1]==0)
                {
                    a[line[i][0]][line[i][1]-1]=1;
                    line[n1+n2][0]=line[i][0];
                    line[n1+n2][1]=line[i][1]-1;
                    n2++;
                }
            }
            memcpy(&line[0][0],&line[n1][0],n2*2*sizeof(int));
            n1=n2;
        }
        ans++;
    }
    out<<ans;
}

