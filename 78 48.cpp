#include <fstream>
#include <string>
using namespace std;
int F,P;
int pre(int s)
{
	return ((s-F)/P+1)*(F-P)+s;
}

int main()
{
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");

	in>>F>>P;

	int ans=F;
	for(int i=0; i<4; i++)
		ans=pre(ans);

	out<<ans;
} 