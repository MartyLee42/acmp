#include <iostream>
#include <fstream>

using namespace std;

int Enter[200000][2];

void Q(int L, int R) 
  { 
    int i, j, x;  
    x = Enter[(L+R)>>1][0]; 
    i = L, j = R; 
    while (i <= j) 
    { 
      while (Enter[i][0] < x) i++; 
      while (x < Enter[j][0]) j--; 
      if (i <= j)
      {
        swap(Enter[i][0],Enter[j][0]);
        swap(Enter[i][1],Enter[j][1]);
        i++, j--;
      }
    } 
    if (L < j) Q(L, j); 
    if (i < R) Q(i, R);      
} 



int Time(char t[5])
{
    int ans=0;
    ans+=60*(10*(t[0]-'0')+t[1]-'0')+(10*(t[3]-'0')+t[4]-'0');
    return ans;
}


int main()
{
    
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    int n;

    in>>n;
    char time[5];
    for(int i=0; i<2*n; i++)
    {
        in>>time;
        Enter[i][0]=Time(time);
        Enter[i][1]=1;
        in>>time;
        i++;
        Enter[i][0]=Time(time);
        Enter[i][1]=-1;
    }
    Q(0,2*n-1);
    
    int j=0,count=0;
    int Max=0;
    while(j<2*n)
    {    
        count+=Enter[j][1];

        int pere=count-Enter[j][1];
        
        if(Enter[j][1]>0) pere++;

        while(Enter[j][0]==Enter[j+1][0] && j<2*n-1 )
        {
            if(Enter[j+1][1]>0) pere++;

            if(pere>Max) Max=pere;

            count+=Enter[j+1][1];
            j++;
        }
        
        if(count>Max) Max=count;
        j++;
    }
    out<<Max;
} 

