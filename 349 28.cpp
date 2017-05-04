#include <iostream>
#include <fstream>
using namespace std;
const int o=1000000;
bool a[o+2];

int main()
{
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");

    memset(&a,true,o+2);
    bool t=false;
    int i,j,h;

    for(i=2; i<=1000; i++)
    {
        if(a[i])
        {
            for(j=2*i;j<=o; j+=i) a[j]=false;
        }
    }
    in>>i>>j;
    
    for(h=i; h<=j; h++)
    {
        if(a[h])
        {
              out<<h<<" ";
              t=true;
        }
    }
    if(!t) out<<"Absent";
} 

