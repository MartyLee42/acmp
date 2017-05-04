#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define Max 43

__int64 a[Max];
__int64 b[Max+1][10];

__int64 mench(int raz, int min)
{
    __int64 ans=0;
    if(min==0&& raz==1) return 9;
    if(raz==1) return 10-min;
    if(b[raz][min]!=0) return(b[raz][min]);
    for(int i=min; i<10; i++)
    {
        ans+=mench(raz-1,i);
    }
    b[raz][min]=ans;
    return(ans);
}
    
int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n,r;
    in>>n;

    for(int i=1; i<=Max; i++)
    {
        a[i]=mench(i,0);
        if(a[i]>=n && n>a[i-1]) r=i;
    }

    for(int i=1; i<=Max; i++)
    {
        for(int j=0; j<9; j++)
        {
            b[i][j]-=b[i][j+1];
        }
    }

    for(int i=1; i<=Max; i++)
    {
        for(int j=9; j>=0; j--)
        {
            for(int k=0; k<j; k++)
                b[i][j]+=b[i][k];
        }
    }
    
    for(int i=0; i<10; i++) b[1][i]=i;

    int k=0;
    for(int i=r; i>0; i--)
    {
        
        while(b[i][k]<n) k++;
        n=n-b[i][k-1]+b[i-1][k-1];
        out<<k;
    }
} 


