#include<iostream>
using namespace std;
int main()
{
	int a[50],*p,i,b,c,n;
	cin>>n;
	p=a;
	for (i=0;i<n;i++)
	*(p+i)=i+1;
	i=0;b=0;c=0;
	
	while (b<n-1)
	{
		if(*(p+i)!=0)c++;
		if(c==3)
		{
			*(p+i)=0;
			c=0;
			b++;
		}
		i++;
		if(i==n)i=0;
	}
	while(*p==0)p++;
	cout<<*p;
	return 0;
}