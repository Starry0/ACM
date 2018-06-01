#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N,i,k,j,m,n;
	cin>>N;
	int a[N];
	for(i=1;i<=N;i++)
	{
		j=0;
		for(k=1;k<i;k++)
		{
			if(i%k==0)
			{
				a[j]=k;
				j++;
			}
		}
		for(n=0;n<j;n++)
		{
			m+=a[n];
		}
		if(m==i)
		{
			cout<<i<<" its factors are ";
			for(k=0;k<j;k++)
			cout<<a[k]<<' ';
		}
	}
	return 0;
}
