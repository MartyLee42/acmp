#include <fstream>
using namespace std;

double l[100][3];

int main()
{
    ifstream s("INPUT.txt");
    ofstream p("OUTPUT.txt");

    double R,x,y,h,g;
    int k,v=0;
    s>>R>>k;
    
    for(int i=0; i<k; i++)
    {
        s>>x>>y>>h>>g;
        l[i][0]=g-y;
        l[i][1]=x-h;
        l[i][2]=-x*g+h*y;
        v++;
        
        for(int j=0; j<i; j++)
        {
            x=-l[j][2]*l[i][1]+l[j][1]*l[i][2];
            y=l[j][2]*l[i][0]-l[i][2]*l[j][0];
            h=l[i][0]*l[j][1]-l[i][1]*l[j][0];
            
            if(x*x+y*y<R*R*h*h) v++;       
        }
    }
    p<<v+1;
} 


