#include <iostream>
using namespace std;

__int64 space(__int64 trees, __int64 free)
{
    return  trees+(trees-1)*free ;
}

__int64 pos(__int64 space , __int64 maxSpace)
{
    __int64 ans=maxSpace-space+1;
    if(ans<0) ans=0;
    return ans;
}


int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);

    __int64 n,m,ans=0;

    cin>>n>>m;
    if(m==0)
    {
        cout<<1;
        return 0;
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(n<m)
    {
        cout<<0;
        return 0;
    }

    for(int i=0; i<=n; i++)
    {
        ans+=pos(space(m,i),n);
    }
    cout<<ans;
} 

