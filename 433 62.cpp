#include <fstream>


const p=1000004;

int main()
{
    std::ifstream t("INPUT.txt");
    std::ofstream o("OUTPUT.txt");
    __int64 n=0,k=0,l=0,i,s[2*p];
    char a;
    
    memset(s,0,16*p);
    s[p-4]=1;
    
    t>>n;
    for(i=0; i<n; i++)
    {
    t>>a;
        if(a<'b') k++;
        else k--;
        l+=s[p-4+k];
        s[p-4+k]++;    
    } 
    o<<l;   
}

