#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
bool vis[N];
ll a[N], n, x, y;
set<int> st;
map<int,int> mp;
int main() {
	cin >> n >> x >> y;
	int cnt = 0;
	for(ll i = 2; i <= sqrt(x); i ++) {
		if(x%i == 0) {
			a[cnt++] = i;
			a[cnt++] = x/i;
		}
	}
	for(ll i = 2; i <= sqrt(y); i ++) {
		if(y%i == 0) {
			a[cnt++] = i;
			a[cnt++] = y/i;
		}
	}
	a[cnt++] = x; a[cnt++] = y;
	for(int i = 1; i < n; i ++) {
		scanf("%lld%lld", &x, &y);
		if(mp.count(x) && mp.count(y)) continue;
		for(int i = 0; i < cnt; i ++) {
			if(!(x%a[i] == 0 || y%a[i] == 0)) {
				vis[i] = 1;
			}
		}
		mp[x] = mp[y] = 1;
	}
	for(int i = 0; i < cnt; i ++) {
		if(a[i] != 1 && !vis[i]) return 0*printf("%lld\n",a[i]);
	}
	printf("-1\n");
	return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int N = 2e5+10;
ll n, x, y;
set<ll> st[2];
set<ll>::iterator it;
map<ll,ll> mp;
int main() {
	cin >> n >> x >> y;
	mp[x]++;mp[y]++;
	for(ll i = 2; i <= sqrt(x); i ++) {
		if(x%i == 0) {
			st[0].insert(i);
			st[0].insert(x/i);
		}
	}
	for(ll i = 2; i <= sqrt(y); i ++) {
		if(y%i == 0) {
			st[0].insert(i);
			st[0].insert(y/i);
		}
	}
	int last = 0;
	for(int i = 1; i < n; i ++) {
		scanf("%lld%lld", &x, &y);
		mp[x]++;mp[y]++;
		last = 1 - last;
		st[last].clear();
		for(it = st[1-last].begin(); it != st[1-last].end(); ++ it) {
			if(x%((*it)) == 0 || y%((*it)) == 0) {
				st[last].insert((*it));
			}
		}
	}
	for(it = st[last].begin(); it != st[last].end(); ++ it) {
		if(mp.count((*it))) continue;
		if((*it) != 1) return 0*printf("%lld\n",(*it));
	}
	printf("-1\n");
	return 0;
}*/