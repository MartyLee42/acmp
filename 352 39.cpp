#include <fstream>
#include <math.h>
using namespace std;




int main()
{
    ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");
	int n;
	
	in>>n;

	if(n%2==1) out<<n/2<<" "<<n/2+1;
	else
	{
		if(n%4!=0) out<<n/2-2<<" "<<n/2+2;
		else out<<n/2-1<<" "<<n/2+1;
	}
	
	
} 


 





