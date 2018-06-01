/*
这个要长整数型  不会答案错误
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> vs[N];
typedef pair<int, int> P;
map<P, int> mp;
bool vis[N];
ll ans1;
void dfs(ll x, ll de) {
	for(ll i = 0; i < vs[x].size(); i ++) {
		ll k = vs[x][i];
		if(!vis[k]){
			if(de%2 == 0) ans1++;
			vis[k] = true;
			dfs(k,de+1);
		}
	}
}
int main(){
	ll n, x ,y;
	cin >> n;
	for(ll i = 1; i < n; i ++) {
		cin >> x >> y;
		vs[x].push_back(y);
		vs[y].push_back(x);
	}
	ans1 = 1;
	vis[x] = 1;
	dfs(x,1);
	printf("%lld\n",ans1*(n-ans1)-n+1);
	return 0;
}