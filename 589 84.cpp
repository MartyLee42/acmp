#include <fstream>
#include <math.h>
using namespace std;

long double b[55][8];
int n;
long double T;

long double delta[6];
long double eps=1E-10;

long double count(int i,int j)
{
	long double ans=0;
	for(int ii=0; ii<3; ii++)
	{
		ans+=(b[i][2+ii]-b[j][2+ii])*(b[i][2+ii]-b[j][2+ii]);
	}
	return ans;
}
void countSpeed(int c,int d)
{
	long double k2=0,k1=0,kk=0;
	long double mm=b[d][0]/b[c][0];
	long double m1=b[c][0],m2=b[d][0];

	for(int i=0; i<3; i++)
		delta[i]=b[c][2+i]-b[d][2+i];

	for(int i=0; i<3; i++)
		k2+=(b[c][5+i]-b[d][5+i])*delta[i];
	
	k2*=m2;

	for(int i=0; i<3; i++)
		kk+=delta[i]*delta[i];
	kk*=m2*(1+mm);

	k2/=kk;
	
	k2*=2;

	k1=-mm*k2;

	for(int i=0; i<3; i++)
	{
		b[c][i+5]+=k1*delta[i];
		b[d][i+5]+=k2*delta[i];
	}

}

void recountSpeed()
{

	for(int i=0; i<n-1; i++)
	{
		int ii,jj;
		double aaa=0,bbb=10;
		ii=-1;
		for(int j=i+1; j<n; j++)
		{
			aaa=count(i,j)-(b[i][1]+b[j][1])*(b[i][1]+b[j][1]);
			if(aaa<bbb)
			{
				ii=i;
				jj=j;
				bbb=aaa;
			}
			
		}
		if(ii>=0 && bbb<eps)
			countSpeed(ii,jj);
	}
}

void simulate(long double t)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
		b[i][2+j]+=b[i][5+j]*t;
	}
}

/*bool MoreThanZero(long double bb, long double cc)
{
	if(bb>0) return false;
	if(bb*bb>=cc) return true;
	return false;
}*/


double findMin()
{
	
	long double tt=1000;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			long double aa=0,bb=0,cc=0,dd;
			for(int k=0; k<6; k++)
				delta[k]=b[i][k+2]-b[j][k+2];

			
			for(int k=0; k<3; k++)
			{
				cc+=delta[k]*delta[k];
				bb+=delta[k]*delta[k+3];
				aa+=delta[k+3]*delta[k+3];
			}
			
			cc-=(b[i][1]+b[j][1])*(b[i][1]+b[j][1]);
			
			dd=bb*bb-aa*cc;

			/*if(MoreThanZero(bb,dd))
			{
				if(!MoreThanZero(bb+aa*tt,dd))
				{
					tt=(-bb-sqrt(dd))/aa;
				}
			}*/

			dd=(-bb-sqrt(dd))/aa;
			if(tt>dd & dd>0) tt=dd;
		}
	}
	return tt;
}

int main()
{
	ifstream in("INPUT.txt");
	FILE *out;
	out=fopen("OUTPUT.txt","w");
	
	in>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<8; j++)
			in>>b[i][j];
	in>>T;


	long double t;

	while(T>0)
	{
		t=findMin();
		t=min(t,T);
		T-=t;
		simulate(t);
		recountSpeed();
	}
	

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<6; j++)
			fprintf(out,"%.4f ",b[i][j+2]);
		fprintf(out,"\n");
	}
    
} 