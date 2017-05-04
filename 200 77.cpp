#include <iostream>

using namespace std;
__int64 n,k;

int P()
{
    __int64 i;
    for (i=2;i<k;i++)
    {
        if (k%i==0)
        {
            k=k/i;
            return(i);
        }
    }
    i=k;     
    k=1;
    return(i);
}



int main()
{
   FILE *z, *o;
   z  = fopen("INPUT.txt", "r");
   o = fopen("OUTPUT.txt", "w");
   int i,j;
   __int64 f,l,a=4000000000;
   int p[11][2];
   for (i=0;i<11; i++)
   {
       p[i][0]=0;
       p[i][1]=1;
   }

   fscanf(z,"%d%d",&n,&k);

   for (i=0; i<11;i++)
   {   
       f = P();
       if (f!=1)
       {
       for(j=0; j<11;j++)
       {
            if(p[j][0]==f)
            {
                p[j][1]++;
                break;
            }
            if(p[j][0]==0)
            {
                 p[j][0]=f;
                 break;
            }
       }
       }
       
   }
   for(i=0; i<11;i++)
   {
       if(p[i][0])
       {
           f=p[i][0];
           l=0;
           while(f<=n)
           {
                l+=n/f;
                f*=p[i][0];
           }
           l=l/p[i][1];
           if (l<a) a=l;
       }
   }
   fprintf(o,"%d",a);
} 

