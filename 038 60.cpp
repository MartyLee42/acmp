#include <iostream>
#include <utility>

using namespace std;

int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);

    int n,s=0;
    int b[110][110],h1[110];
    memset(b,0,110*sizeof(b[0]));
    memset(h1,0,110*sizeof(h1[0]));

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>b[i][i];
        s+=b[i][i];
    }
    h1[1]=b[1][1];
    for(int i=1; i<=n; i++)
    {
        b[i][i+1]=max(b[i][i],b[i+1][i+1]);
        h1[i]=h1[i-1]+b[i][i];
    }


    for(int i=n-2; i>=1; i--)
    {
        for(int j=1; j<=i; j++ )
        {
            int k=n+j-i;
            b[j][k]=max(h1[k]-h1[j-1]-b[j+1][k],h1[k]-h1[j-1]-b[j][k-1]);
        }
    }
    int ans=b[1][n];

    if(2*ans>s) cout<<1;
    if(2*ans<s) cout<<2;
    if(2*ans==s) cout<<0;

} 




