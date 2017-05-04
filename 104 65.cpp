#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE *in, *out;
    in=fopen("INPUT.txt","r");
    out=fopen("OUTPUT.txt","w");
    char a[260],b[260];
    
    fscanf(in,"%s%s",a,b);
    int l1=0,l2=0;
    bool tr=false;
    while(a[l1]>0)
    {
        if(a[l1]=='*' || a[l1]=='?') tr=true;
        l1++;
    }
    while(b[l2]>0)l2++;
    
    if(tr)
    {
        swap(l1,l2);
        for(int j=0; j<260; j++)
        {
            swap(a[j],b[j]);
        }
    }
    int pere[260][2];
    int i;
    pere[0][1]=1;
    int k=0;
    int k1=1;
    for(i=0; i<l2;i++)
    {
        for(int j=0; j<=l1; j++)
        {
            if(b[i]=='*' && pere[j][k1]==1)
            {
                for(int l=j; l<=l1; l++)
                {
                    pere[l][k]=1;
                }
                break;
            }
            if(b[i]=='?' && pere[j][k1]==1)
            {
                pere[j+1][k]=1;
                continue;
            }
            if(b[i]==a[j] && pere[j][k1]==1)
            {
                pere[j+1][k]=1;
                continue;
            }
            pere[j+1][k]=0;
            pere[0][1]=0;
        }
        k1=k;
        k=(k+1)%2;
    }
    if(pere[l1][k1]==1) fprintf(out,"%s","YES");
    else fprintf(out,"%s","NO");
}


