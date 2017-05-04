#include <stdio.h>
#include <map>
#include <vector>

typedef std::map<int,int> Matrix;

int GCD(int a, int b)
{
    int c;
    while ( b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

__int64 LCF(int a, int b) 
{
    return (a / GCD(a, b) ) * (__int64)b;
}

void add(Matrix &arr, int NOK, int a)
{
    Matrix::iterator i = arr.find(NOK);
    if (i != arr.end() )
    {
         int n = i->second + a;
         if (n != 0)
             i->second = n;
         else
            arr.erase(i);
    }
    else
    {
        arr[NOK] = a;
    }
}
int main()
{
    FILE *in, *out;
    in  = fopen("INPUT.txt", "r");
    out = fopen("OUTPUT.txt", "w");
    Matrix  list;

    bool intervals[60];

    int n=0,k=0,j=0,f,p,i=0;
     __int64 ans = 0;

    fscanf(in, "%d%d", &n, &k);

    for (i=0;i<60;i++) intervals[i]=false;

    for (i=0; i<k; i++)
    {
        fscanf(in, "%d", &f);
        intervals[f]=!intervals[f];
    }

    for (int i = 1; i <=50 ; i++)
        if (intervals[i])
        {
            Matrix clist(list);
            for (Matrix::const_iterator j = list.begin(); j != list.end(); ++j)
            {
                __int64 NOK = LCF(j->first, i);
                if (NOK <= n)
                    add(clist, NOK, -2 * j->second);
            }
            list.swap(clist);
            add(list, i, 1);
        }

   
    for (Matrix::const_iterator i = list.begin(); i != list.end(); ++i)
        ans += (n / i->first) * i->second;
    
    fprintf(out, "%d",ans);
}


