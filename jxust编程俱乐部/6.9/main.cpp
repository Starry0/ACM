#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i;
	float M,N,h,m=0;
	cin>>M>>N;
	h=M;
	for(i=1;i<=N;i++)
	{
		h/=2;
		m+=(h*3);
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<h<<' ';
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<m-h;
	return 0;
}
