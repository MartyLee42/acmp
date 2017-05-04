#include <fstream>
using namespace std;

#define Max 3010

void plusTen(int *a,int *b,int n)
{
    int pere=0;
    for(int i=Max-n-1; i>0; i--)
    {
        int c=a[i]+2*b[i+n]+pere;
        a[i]=c%10;
        pere=c/10;
    }
}
void plusOne(int *a,int n)
{
    int pere=1;
    for(int i=Max-n-1; i>0; i--)
    {
        int c=a[i]+pere;
        a[i]=c%10;
        pere=c/10;
    }
}

bool greater(int *a,int *b)
{
    int i=0;
    while(a[i]==b[i] && i<Max) i++;
    if(i==Max) return false;
    if(a[i]>b[i]) return true;
    return false;
}

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    char aa[Max];
    int a[Max];
    memset(a,0,Max*sizeof(int));
    in>>aa;

    int length=0;

    while(aa[length]>0) length++;

    for(int i=Max-length; i<Max; i++)
        a[i]=aa[i+length-Max]-'0';

    length=(length+1)/2;

    int ans[Max];
    memset(ans,0,Max*sizeof(int));
    int bb[Max];
    memset(bb,0,Max*sizeof(int));

    for(int i=Max-length; i<Max; i++)
    {
        int c[Max];
        for(int j=1; j<10; j++)
        {
            memcpy(c,bb,Max*sizeof(int));
            
            plusTen(bb,ans,Max-i-1);
     
            plusOne(bb,2*(Max-i-1));
            ans[i]=j;
            if(greater(bb,a))
            {
                ans[i]--;
                memcpy(bb,c,Max*sizeof(int));
                break;
            }
        }
        out<<ans[i];
    }
} 