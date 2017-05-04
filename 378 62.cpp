#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    bool numbers[50001];
    memset(numbers,false,50001);
    numbers[0]=true;
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        in>>a;
        for(int j=100*i; j>=0; j--)
        {
            if(numbers[j])
            numbers[j+a]=true;
        }
    }
    int k=0;
    for(int i=0; i<=50000; i++)
    {
        if(numbers[i]) 
        {
            k++;
        }
    }
    out<<k;
}


