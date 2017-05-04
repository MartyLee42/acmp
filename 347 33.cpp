#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int i,j,t;
    int a[5];
    
    ifstream l("INPUT.txt");
    ofstream o("OUTPUT.txt");
    
    string answer="Nothing";
    for (i=0;i<5;i++) l>>a[i];
    for (i=0;i<4;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (a[i]>a[j]) swap(a[i],a[j]);
        }    
    }
    if (a[0]==a[4]) answer="Impossible";
    else
    {
        if ((a[0]==a[3]) || (a[1]==a[4])) answer="Four of a Kind";
        else
        {
            for (i=0;i<3;i++)
            {
                if (a[i]==a[i+2]) t=1;
            }
            if (t==1)
            {
                if (((a[0]==a[1]) & (a[1]!=a[2]))||((a[3]!=a[2]) & (a[3]==a[4]))) answer="Full House";
                else
                    answer="Three of a Kind";
            }
            else
            {
                int p=0;
                for (i=0;i<4;i++)
                {
                    if(a[i]==a[i+1]) p++;
                }
                if (p!=0)
                {
                    if (p==1) answer="One Pair";
                    if (p==2) answer="Two Pairs";
                }
                else
                {
                    if (a[4]-a[0]==4) answer="Straight";
                }
            }
        }
    }
    o<<answer; 
    
    
} 

