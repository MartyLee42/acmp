#include <iostream>
#include <fstream>
using namespace std;
int u[200000], h[200000];
int g[100000], p[100001], a[100000];
void Q(int *r, int *e,int L, int R) 
  { 
    int i, j, x;  
    x = r[(L+R)>>1]; 
    i = L, j = R; 
    while (i <= j) 
    { 
      while (r[i] < x) i++; 
      while (x < r[j]) j--; 
      if (i <= j)
      {
        swap(r[i],r[j]);
        swap(e[i],e[j]);
        i++, j--;
      }
    } 
    if (L < j) Q(r,e,L, j); 
    if (i < R) Q(r,e,i, R);      
} 
int main()
{
    int v,i,n,k,m,z=0,d=0;
    ifstream l("INPUT.txt");
    ofstream o("OUTPUT.txt");
    l >>n;
    l >>m;
    n=n<<1;
    for (k=0; k<n;k++)
    {
        l>>u[k];
        h[k]=1;
        k++;
        l>>u[k];
        h[k]=-1;
        if (u[k-1]>u[k]) swap(h[k-1],h[k]);
    }
    for (k=0; k<m; k++)
    {
        l>>p[k];
        g[k]=k;
    }
    Q(u,h,0,n-1);
    Q(p,g,0,m-1);
    while (p[z]<u[0])
    {
        a[g[z]]=d;
        z++;
    }
    for (k=0; k<n; k++)
    {
        if (p[z]>u[k])
        {
            d=d+h[k];
            while (p[z]<u[k+1])
            {
                a[g[z]]=d;
                z++;
                if (z==m) break;
            }    
            continue;
        }
        if (p[z]==u[k])
        {
            v=d;
            while (u[k]==u[k+1])
            {    
                if (h[k]==1) v++;    
                d=d+h[k];
                k++;
            }
            if (h[k]==1) v++;
            while (p[z]==u[k])
            {
                a[g[z]]=v;
                z++;
            }
            k--;
            continue;
        }
        d=d+h[k];
    }
    for (k=0; k<m; k++)
    {
        o<<a[k];
        o<<' ';
    }
} 

