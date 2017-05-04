#include <fstream>
#include <math.h>
using namespace std;
int d[13][32];

bool data(int n,int m)
{
    if(n>12 || m>31) return false;
    if(m<=29) return true;
    if(n==2 && m>29) return false;
    if((n+6)%7%2==0 && m<=31) return true;
    if((n+6)%7%2==1 && m<=30)return true;
    return false;
}



int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,m;
    in>>n>>m;

    
    memset(d,0,4*13*32);
    
    d[12][31]=1;
    for(int i=12; i>0; i--)
    {
        for(int j=31; j>0; j--)
        {
            if(!data(i,j)|| (i==12 && j==31))continue;
            if(data(i+1,j) && d[i+1][j]==-1) d[i][j]=1;
            if(data(i+2,j) && d[i+2][j]==-1) d[i][j]=1;
            if(data(i,j+1) && d[i][j+1]==-1) d[i][j]=1;
            if(data(i,j+2) && d[i][j+2]==-1) d[i][j]=1;
            if(d[i][j]!=1) d[i][j]=-1;
        }
    }
    if(d[m][n]==-1) out<<2;
    else out<<1;
}



