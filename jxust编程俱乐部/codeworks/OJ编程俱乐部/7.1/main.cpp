#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N,i,j,k;
	cin>>N;
	for(i=2;i<=N;i++)
	{
		k=1;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			k=0;
		}
		if(k==1)
		cout<<i<<endl;
	}
	return 0;
}
