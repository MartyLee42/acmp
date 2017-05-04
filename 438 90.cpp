#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
 
 
#define Max 50
#define MaxIteration 3000
#define eps 1E-12
#define eps2 1E-12
 
//making new struct to work with 
//a number of the company while sorting
struct point{
    long double first;
    int second;
};
 
 
//arrays of companies and objects
point v[Max],s[Max];
long double vv[Max];
 
//function comparing points
int sr(point a,point b)
{
    if(a.first>b.first) return 1;
    return 0;
}
int sr2(long double a,long double b)
{
    if(a>b) return 1;
    return 0;
}
 
long double ab(long double abs)
{
    if(abs>=0) return abs;
    return -abs;
}
 
long double max(long double a,long double b)
{
    if(a>b) return a;
    return b;
}
 
//counting max((s1+...+si)/(v1+...+vi)) for all i's
long double countMax(long double ss[],int n)
{
    long double ans=0,l=0;
    for(int i=0; i<n; i++)
    {
        l+=ss[i];
        ans=max(ans,l/vv[i]);
    }
    return ans;
}
 
//counting T foe one placement for t days
//and then another one till the end
long double CriticalT(long double t, int n)
{
    long double ss[Max];
    for(int i=0; i<Max; i++)
        ss[i]=0;
 
    for(int i=0; i<n; i++)
        ss[i]=max(0.00, s[i].first-t*v[i].first);
 
    sort(ss,ss+n,sr2);
 
    long double ans=countMax(ss,n);
 
    return ans+t;
}
 
long double BinarySearch(int n)
{
    long double ans=CriticalT(0,n)+eps;
    long double l=0,r=ans;
    for(int i=0; i<MaxIteration; i++)
    {
        long double m=(l+r)/2;
        long double a=CriticalT(m,n);
 
        if(ans<a) r=m;
        else l=m;
    }
    return r;
}
 
int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
 
    int n,k;
    //reseting
    for(int i=0; i<Max; i++)
    {
        s[i].first=0;
        v[i].first=0;
    }
 
    //making virtual companies
    for(int i=0; i<Max; i++)
    {
        v[i].second=-1;
        s[i].second=-1;
    }
 
    //reading data
    cin>>n;
    //objects
    for(int i=0; i<n; i++)
    {
        cin>>s[i].first;
        s[i].second=i+1;
    }
 
    cin>>k;
    //companies
    for(int i=0; i<k; i++)
    {
        cin>>v[i].first;
        v[i].second=i+1;
    }
 
    //sorting
    sort(s,s+n,sr);
    sort(v,v+k,sr);
 
    //making array of sums of v1+v2+...+vi
    vv[0]=v[0].first;
    for(int i=1; i<Max; i++)
        vv[i]=v[i].first+vv[i-1];
 
    //counting answer
    long double ans=CriticalT(0,max(n,k));
 
    //writing the answer
    printf("%.4f\n",ans);
 
    //all time
    long double T=0;
 
    //writing first placement
    for(int i=0; i<min(n,k); i++)
        cout<<"0.0000000000"<<" "<<s[i].second<<" "<<v[i].second<<"\n";
 
    //main part
    int N=n;
    while(T-ans<-1E-12)
    {
        //finding critical t
        long double tt=BinarySearch(max(k,n));
        T+=tt;
 
        //"building" for t days
        int nn=0;
        for(int i=0; i<n; i++)
        {
            s[i].first-=tt*v[i].first;
            if(s[i].first<-eps)
            {
                nn++;
                s[i].second=-1;
                s[i].first=-1;
            }
        }
 
        sort(s,s+n,sr);
        n-=nn;
 
        for(int i=0; i<min(n,k); i++)
            printf("%.18f %d %d \n",T,s[i].second,v[i].second);
    }
 
} 
