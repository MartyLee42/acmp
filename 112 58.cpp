#include <fstream>
#include <vector>
using namespace std;
__int64 count=0;

void merge(vector <int> &k,int b,int m, int e)
{
    int p1=b,p2=m+1,p3=0;
    vector <int> a(e-b+1);

    while(p1<=m && p2<=e)
    {
        if(k[p1]<k[p2])
        {
            a[p3++]=k[p1++];
        }
        else
        {
            a[p3++]=k[p2++];
            count+=m-p1+1;
        }
    }
    while(p1<=m)
    {
        a[p3++]=k[p1++];
    }
    while(p2<=e)
    {
        a[p3++]=k[p2++];
    }
    copy(a.begin(),a.end(),k.begin()+b);
}

void sort(vector <int> &k, int b, int e)
{
    if(b==e) return;
    
    int m=(b+e)>>1;
    sort(k,b,m);
    sort(k,m+1,e);
    merge(k,b,m,e);
}


int main()
{
   
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n,k;
    
    in>>n>>k;
    vector <int> a(n);
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            in>>a[j];
        }
        sort(a,0,n-1);
    }
    out<<count;
} 



