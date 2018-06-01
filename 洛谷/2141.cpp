#include <iostream>
using namespace std;
int a[200];
int ans;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(i==j||k==j||k==i)continue;
				if(a[k]+a[j]==a[i]){
					ans++;
					goto tt;
				}
			}
		}
		tt:;
	}
	cout<<ans;
	return 0;
}
