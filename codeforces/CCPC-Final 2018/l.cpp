#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll  N = 1000100;
int t;
ll n;
vector<ll>ve;
set<ll>se;
bool check(ll x)
{
	if(x==1) return 0;
	for(ll i =2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

void init()
{
	
    for(ll i=2;i*i<=N;i++)
    {
        if(se.count(i)==0)
        {
        	ve.push_back(i);
            for(ll j=i*i;j<=N;j+=i)
                se.insert(j);//i是素数，则下一个起点是i*i,把后面的所有的i*i+2*n*i筛掉
        }
    }

}
void f(ll n)
{
	for(int i =0;i<ve.size();i++){
		if(check(n-ve[i])){
			printf(" %lld %lld\n",ve[i],n-ve[i]);
			break;
		}
	}
	return ;
}
int main()
{
	scanf("%d",&t);
	init();
	for(int ca = 1; ca <= t; ca ++)
	{
		scanf("%lld",&n);
		printf("Case %d: ",ca);
		if(n<12) 
		{printf("IMPOSSIBLE\n");
	continue;
		}
		if(n%2==0){
			n-=8;
			printf("2 2 2 2");
			f(n);
		}
		else{
			n-=9;
			printf("2 2 2 3");
			f(n);
		}
	}
	return 0;
}
