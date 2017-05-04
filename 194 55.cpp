#include <fstream>

int main()
{
	std::ifstream p("INPUT.txt");
	std::ofstream o("OUTPUT.txt");

	int n,a[90],i;
	p>>n;
	a[1]=a[2]=1;
	a[3]=2;

	for(i=4; i<=n; i++)
		a[i]=a[i-1]+a[i-3]+1;

	o<<a[n];

}



