#include <iostream>
#include <fstream>

using namespace std;
int num[200000],num2[200000];

void Q(int *r,int L, int R) 
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
        i++, j--;
      }
    } 
    if (L < j) Q(r,L, j); 
    if (i < R) Q(r,i, R);      
} 

int main()
{
    int i,j,n,length,max,number;
    
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    
    in>>n;
    
    for (i=0;i<n;i++)
    {
        in>>num[i];
        num2[i]=num[i];
    }
    
    Q(num,0,n-1);

    j=num[0];
    number=j;
    max=1;
    length=1;

    for (i=1;i<n;i++)
    {
        if(num[i]==j)
        {
            length++;    
        }
        else
        {
            if(length>max) 
            {
                swap(length,max);
                number=j;
            }
            length=1;
            j=num[i];
        }
    }

    if(length>max) 
    {
        swap(length,max);
        number=j;
    }
    
    for (i=0;i<n;i++)
    {
        if(num2[i]!=number) 
        {
            out<<num2[i];
            out<<" ";
        }
    }
    out<<number;
    for(i=1;i<max;i++)
    {
        out<<" ";
        out<<number;
    }
} 

