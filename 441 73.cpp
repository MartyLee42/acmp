#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

__int64 a=0;
int e[2000100];
pair<int, int> q[100100];
vector<int> x;

int w(int n, int k)
{
    int l=0,m;
    while(1)
    {
        m=(l+n)>>1;
        if(k<q[m].second) n=m-1;
        else 
        {
            if(k==q[m].second)
            {
                while(m>0 && q[m-1].second==k) m--;
                return m;
            }
             l=m+1;
        }
        if(l==n)return l;
    }
}

void v( int l, int m, int r) 
{
    vector<int> b(r - l + 1);
    int z = l,p=m+1,k=0;
 
    while (z<=m && p<=r) 
    {
        if (x[z] <= x[p]) b[k++] = x[z++];
        else 
        {
            a +=abs(p-l-k);
            b[k++] = x[p++];
        }
    }
    while (z<=m)
        b[k++] = x[z++];
    while (p<=r)
        b[k++] = x[p++];
    copy(b.begin(),b.end(),x.begin()+l);
}

void s( int l, int r) 
{
    if (l == r) return;
 
    int m = (l+r)>>1;
    s(l,m);
    s(m+1,r);
 
    v(l, m, r);
    return;
}
    

bool sr(pair<int, int> c, pair <int, int > b)
{
    if(c.second<b.second ||(c.second==b.second && c.first<b.first)) return true;
    return false;
}

int main()
{
    ifstream f("INPUT.txt");
    ofstream o("OUTPUT.txt");

   
    int n,i, h,g,t=1000002;
    f>>n;
    
    x.resize(n);

    for(i=0; i<n; i++)
    {
        f>>q[i].second;
        e[q[i].second+t]++;
        q[i].first=i;
    }
    sort(q,q+n,sr);

    
    for(i=0; i<n ;i++)
    {
        f>>h;
        if(e[h+t]==0) 
        {
             o<<-1;
            return 0;
        }
        e[h+t]--;
        g=w(n-1,h);
        x[i]=q[g].first;
        q[g].second--;
    }
    
    s(0,n-1);
    o<<a;
} 


