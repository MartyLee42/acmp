#include <iostream>
#include <fstream>
using namespace std;
int last[101];
int horses[101][101];
int i,j,n;

int search()
{
    for(j=j; j<=n; j++)
    {
        if(horses[last[i]][j]==1)
        {
            horses[last[i]][j]=2;
            return(1);
        }
    }
    return(0);
}

int main()
{
    int k,a,b,answer;
    answer=1;
    ifstream l("INPUT.txt");
    ofstream o("OUTPUT.txt");
    
    l>>n;
    l>>k;
    
    l>>a;

    while (a!=0) 
    {
        l>>b;

        if (b==k)
        {
            answer=-1;
            break;
        }
        
        horses[a][b]=1;
        
        
        l>>a;
    }
    last[1]=k;

    
    i=1;
    j=1;
    while (i>0)
    {
        a=search();
        if (a==1)
        {
            horses[k][j]=2;
            i++;
            last[i]=j;
            j=1;
        }
        if (a==0)
        {
            j=last[i]+1;
            i--;
        }
    }
    horses[k][k]=1;
    for (i=1;i<=n;i++)
    {
        if(horses[k][i]==0) 
        {
            answer=-1;
            break;
        }
    }
    if (answer==-1) o<<"No";
    else
    o<<"Yes";
} 



