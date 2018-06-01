#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
int main(){
	ll n,num;
	priority_queue<ll, vector<ll>, greater<ll> >que;
	cin>>n;
	for(int i = 1; i <= n; i ++)cin>>num,que.push(num);
	if(que.size()==1){
		cout << 0 << endl;
		return 0;
	}
	ll sum = 0;
	while(que.size() != 1){
		ll a = que.top();
		que.pop();
		ll cnt = que.top();
		que.pop();
		//cout << a << ' ' << cnt << endl;
		ll ans = a+cnt;
		sum+=ans;
		que.push(ans);
	}
	cout << sum << endl;
	return 0;
}