#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#pragma comment(linker, "/stck:1024000000,1024000000")
#define lowbit(x) (x&(-x))
#define max(x,y) (x>=y?x:y)
#define min(x,y) (x<=y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos(-1.0)
#define ei exp(1)
#define PI 3.1415926535897932384626433832
#define ios() ios::sync_with_stdio(true)
#define INF 0x3f3f3f3f
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
ll n,a[200005];
map<ll,ll>m;
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		m[a[i]]=1;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=32;j++)
		{
			ll y=1<<j;
			if(m[a[i]+y] && m[a[i]+y+y])
			{
				printf("3\n");
				printf("%lld %lld %lld\n",a[i],a[i]+y,a[i]+y+y);
				return 0;
			}
			if(a[i]+y>a[n-1]) break;
			if(a[i]+y+y>a[n-1]) break;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=32;j++)
		{
			ll y=1<<j;
			if(m[a[i]+y])
			{
				printf("2\n");
				printf("%lld %lld\n",a[i],a[i]+y);
				return 0;
			}
			if(m[a[i]+y+y])
			{
				printf("2\n");
				printf("%lld %lld\n",a[i],a[i]+y+y);
				return 0;
			}
			if(a[i]+y>a[n-1]) break;
			if(a[i]+y+y>a[n-1]) break;;
		}
	}
	printf("1\n");
	printf("%lld\n",a[0]);
	return 0;
}
/*
3
100000002
100000004
100000006
*/
