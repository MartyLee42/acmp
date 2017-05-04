#include <iostream>
#include <utility>

using namespace std;

int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);

    int a[1000010], n,max=1, p=0,length=2;
    cin>>n;
    for(int i=0;i<n; i++)
        cin>>a[i];
    
    if(a[0]>a[1]) p=1;
    if(a[0]<a[1]) p=-1;
    if(a[0]==a[1]) length=1;


    for(int i=1; i<n-1; i++)
    {
        switch(p)
        {
            case  1:
                if(a[i]<a[i+1])
                {
                    p=-1;
                    length++;
                }
                else
                {
                    i-=1;
                    p=0;
                    length=1;
                }
                break;
            case -1:
                if(a[i]>a[i+1])
                {
                    p=1;
                    length++;
                }
                else
                {
                    i-=1;
                    p=0;
                    length=1;
                }
                break;
            case  0:
                if(a[i]>a[i+1])
                {
                    p=1;
                    length=2;
                }
                if(a[i]<a[i+1])
                {
                    p=-1;
                    length=2;
                }
                break;
        }
        if(max<length) max=length;
    }
    cout<<max;
}

