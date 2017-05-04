#include <fstream>
using namespace std;

#define Max 5000

int a[Max];

int  period(int *q,int beg)
{
    bool tr=true;
    for(int i=1; i<Max/2; i++)
    {
        tr=true;
        for(int j=beg; j<Max/2; j++)
        {
            if(q[j]!=q[j+i]) 
            {
                tr=false;
                break;
            }
        }
        if(tr) return i;
    }
    return -1;
}





int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int b=0;
    char q[1000];

    in>>q;
    int o=0;
    while(q[o]!=0 && q[o]!='/')
    {
        a[o]=q[o]-'0';
        
        o++;
    }
    int l=o;
    o++;
    while(q[o]!=0)
    {
        b=b*10+(q[o]-'0');
        o++;
    }

    int x=0,h=0,k=0;
    if(a[0]==0)
    {
        out<<0;
        return 0;
    }

    for (int y=0; y<l; y++)
    {
        x = x*10+a[y];
        if(x < b && k==0 && y >= 0) continue;
        k=1;
        h=x/b;
        out<<h;
        x = x % b;
    }
    
    if(k==0) out<<0;

    int per[Max];
    memset(per,0,4*Max);
    for (int y=l; y<Max; y++)
    {
        x = x*10+a[y];
        if(x < b && k==0 && y >= 0) continue;
        k=1;
        per[y-l]=x/b;
        x = x % b;
    } 
    int beg=-1;
    for(int i=0; i<Max; i++)
    {
        if(period(per,i)!=-1) 
        {
            beg=i;
            break;
        }
    }
    
    
        int p=Max-1;
        while(per[p]==0 && p>=0) p--;
        if(p>=0)
        out<<".";

        if(p<Max-100)
        for(int l=0; l<=p; l++) out<<per[l];

    int peri =period(per,beg);
    if(peri==1 && per[beg]==0) return 0;
    
    
    

    
    for(int i=0; i<beg;i++) out<<per[i];

    out<<'(';


    for(int i=beg; i<beg+peri; i++) out<<per[i];

    out<<')';

} 


