#include <iostream>
using namespace std;
int main()
{
	int a[10],i,j,m;
	for(i=0;i<10;i++)
	cin>>a[i];
	for(i=0;i<10;i++)
	for(j=i+1;j<10;j++)
	{
		if(a[i]>a[j])
		{
			m=a[i];
			a[i]=a[j];
			a[j]=m;
		}
	}
	for(i=0;i<10;i++)
	cout<<a[i]<<endl;
	return 0;
}
