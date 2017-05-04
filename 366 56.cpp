#include <fstream>

using namespace std;
int n,t, p[60], x[30];



int v(int b,int s)
{
    if(b!=n)
    {
        if(v(b+1,s+x[b])==0) 
        {
            p[2*b]=1;
            p[2*b+1]=x[b];
            return 0;
        }
        if(v(b+1,s-x[b])==0 && b!=0) 
        {
            p[2*b]=0;
            p[2*b+1]=x[b];
            return 0;
        }
    }
    else if(s==0) return 0;
    
    
    return 1;
}


int main()
{
    ifstream u("INPUT.txt");
    ofstream o("OUTPUT.txt");


    u>>n>>t;

    
    for(int i=0; i<n ;i++)
        u>>x[i];
    if(v(0,-t)==1) o<<"No solution";
    else
    {
        o<<x[0];
        for(int i=2; i<2*n; i+=2)
        {
            if(p[i]==1) o<<'+';
            else o<<'-';
            o<<p[i+1];
        }
        o<<"="<<t;
    }
    
}



