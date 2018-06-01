#include <iostream>
using namespace std;
int main()
{
	int n,m,r,a,b,c,d;
	cin>>n>>m;
	c=n;d=m;
	while(m!=0)
	{
		r=n%m;
		n=m;
		m=r;
	}
	a=n;
	b=c/a*d;
	cout<<a<<' '<<b;
	return 0;
}
