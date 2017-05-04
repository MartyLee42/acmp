#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

struct radius{
    long double r;
    long double k;
};
radius r[300];
int n;

int cmp(radius a, radius b)
{
    if(a.r>b.r) return true;
    return false;
}
int num(long double a)
{
    int l,k;
    l=0;
    k=n;
    int m;
    while(true)
    {
        m=(l+k)/2;
        if(r[m].k<a)
            l=m+1;
        else 
            k=m;
        if(l>=k) break;
    }
    return max(n-k,0);
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    in>>n;
    
    
    for(int i=0; i<n; i++)
    {
        in>>r[i].r;
        r[i].k=1/r[i].r;
    }

    sort(r,r+n,cmp);
    for(int i=0; i<n; i++)
    {
        if(r[i].r==r[i+1].r)
            r[i].r=-1;
    }
    sort(r,r+n,cmp);
    int nn=0;
    while(r[nn].r>0  && nn<n) nn++;
    n=nn;
    __int64 count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            
            for(int l=j+1; l<n; l++)
            {
                long double max=r[i].k+r[j].k+r[l].k+2*sqrt(r[i].k*r[j].k+r[i].k*r[l].k+r[l].k*r[j].k);
                count+=num(max);
            }
        }
    }
    out<<count;
    
} 