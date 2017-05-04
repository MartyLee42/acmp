#include <fstream>
using namespace std;

int a[11];
int next(int n)
{
    int i=n-1;
    while(a[i]<=a[i-1]) i--;

    if(i<=0) return -1;
    
    int m=10000,k=i;

    for(int j=i+1; j<n; j++)
        if(a[j]<=m && a[j]>a[i-1]) 
        {
            m=a[j];
            k=j;
        }

    swap(a[i-1],a[k]);
    int l=n-1;
    while(i<l)

    {
        swap(a[i],a[l]);
        i++;
        l--;
    }
    return 1;
}


int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    int n=0;

    char b[10];
    in>>b;
    while(b[n]>0)n++;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j ++)
        {
            if(b[i]<b[j]) swap(b[i],b[j]);
        }
    }
    int k=0;
    for(int i=0; i<n ;i++)
    {
        k++;
        if(b[i]==b[i-1]) k--;
        a[i]=k;
    }
    int p=n;
    for(int i=0; i<p ;i++)
    {
        if(b[i]==b[i+1]) 
        {
            memcpy(&b[i],&b[i+1],(p-i+1)*sizeof(char));
            i--;
            p--;    
        }
    }    
        
    int x=1000000;
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<n ;j++)
            out<<b[a[j]-1];
        out<<"\n";
        int y=next(n);
        if(y<0) x=0;
    }
} 

