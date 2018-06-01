#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int N,a,i;
	float x1,x2,sn=0,b=0;
	cin>>N;
	x1=1.0;x2=2.0;
	for(i=1;i<=N;i++)
	{
		sn+=x2/x1;
		b=x2;
		x2+=x1;
		x1=b;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sn;
	return 0;
}
