#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

__int64 GCD(__int64 a,__int64 b)
{
	
	while(b!=0)
	{
		a=a%b;
		swap(a,b);
	}
	return a;
}

string cor(string a)
{

	string b;
	int beg=0;
	while(a[beg]>0 && a[beg]!='.') 
	{
		b+=a[beg];
		beg++;
	}

	int aa=0;
	int beg2=beg+1;
	while(beg<a.length() && a[beg2]>0 && a[beg2]!='(') 
	{
		aa+=a[beg2]-'0';
		beg2++;
	}
	int end=beg2+1;

	int aaa=0;
	while(end<a.length() && a[end]>0 && a[end]!=')') 
	{
		aaa+=a[end]-'0';
		end++;
	}
	if(aa+aaa==0) return b;
	string bb=b;
	b+='.';
	
	if(aaa==0) 
	{
		bool rr=false;
		string kk;
		for(int i=beg2-1; i>beg; i--)
		{
			if(a[i]!='0' || rr)
			{
				kk=a[i]+kk;
				rr=true;
			}
		}
		b+=kk;
		return b;	
	}
	for(int i=beg+1; i<beg2; i++) b+=a[i];

	
	for(int i=0; i<40; i++)
	{
		for(int j=beg2+1; j<end; j++)
		{
			b+=a[j];
		}
	}

	for(int i=beg+1; i<b.length(); i++)
	{
		for(int j=1; j<7; j++)
		{
			bool tr=true;
			for(int k=i; k<b.length()-j-1; k++)
			{
				if(b[k]!=b[k+j]) 
				{
					tr=false;
					break;
				}
			}
			if(tr)
			{
				bb+='.';
				for(int k=beg+1; k<i; k++)
				{
					bb+=b[k];
				}
				bb+='(';

				for(int k=i; k<i+j; k++)
				{
					bb+=b[k];
				}

				bb+=')';
				return bb;
			}
		}
	}
	

	
}

int main()
{
   ifstream in("INPUT.txt");
   ofstream out("OUTPUT.txt");

    __int64 n1,k1;
	in>>n1>>k1;
	out<<n1<<'=';

	__int64 k,n;
	n=n1;
	k=k1;

	__int64 aa=GCD(n,k);
	n/=aa;
	k/=aa;


	__int64 l1=0,nn2=2,l2=0,l;
	while(k%nn2==0)
	{
		nn2*=2;
		l1++;
	}
	nn2=5;
	while(k%nn2==0)
	{
		nn2*=5;
		l2++;
	}
	int predperiod=max(l1,l2);

	nn2=10;
	int ll=1;
	while(n/nn2!=0)
	{
		nn2*=10;
		ll++;
	}


	int a[200];
	nn2/=10;
	int nnn=n;
	for(int i=0; i<ll;i++)
	{
		a[i]=nnn/nn2;
		nnn-=a[i]*nn2;
		nn2/=10;
	}
	int x=0;

	int kk=0;
	int b[200];
	memset(b,0,20*4);
	int b1[200];
	memset(b1,0,20*4);
	int length=0;
	for (int y=0; y<ll; y++)
    {
        x = x*10+a[y];
        if(x < k && kk==0 && y >= 0) continue;
        kk=1;
        b[length]=x/k;
		length++;
        x = x % k;
    }
	int period=0;
	kk=0;
	if(x!=0)
	{
		for (int y=0; y<20; y++)
		{
			x = x*10;
			if(x < k && kk==0 && y >= 0) continue;
			kk=1;
			b1[y]=x/k;
			x = x % k;
		}
		if(k%3==0) period=1;
		if(k%7==0) period=6;
	}

	int j=0;
	for(int i=0; i<length; i++)
	{
		j=max(j,b[i]);
	}
	for(int i=0; i<period+predperiod; i++)
		j=max(j,b1[i]);

	
	string ans[100];
	for(int i=0; i<j; i++)
	{
		string h;
		for(int y=0;y<length; y++)
		{
			if(b[y]>0) 
			{
				h+=k1+'0';
				b[y]--;
			}
			else 
			{
				if(h!="")
				h+="0";
			}
		}
		if(h=="") h='0';
		if(period+predperiod>0) h+='.';

		for(int y=0;y<predperiod; y++)
		{
			if(b1[y]>0) 
			{
				h+=k1+'0';
				b1[y]--;
			}
			else h+="0";
		}
		if(period>0)h+='(';

		for(int y=predperiod; y<period+predperiod; y++)
		{
			if(b1[y]>0) 
			{
				h+=k1+'0';
				b1[y]--;
			}
			else h+="0";
		}
		if(period>0) h+=')';
		ans[i]=h;
	}


	for(int i=j-1; i>=0; i--)
	{
		ans[i]=cor(ans[i]);
		out<<ans[i];
		if(i!=0) out<<'+';
	}
} 

