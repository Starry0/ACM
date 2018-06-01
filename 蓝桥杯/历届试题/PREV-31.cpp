/*
#include <bits/stdc++.h>
#define lowbit(x) ((-x)&x)
#define ll long long
using namespace std;
const int N = 100010;
int n, tree[N], index[N];
map<int,int> mp;
ll sum[N];
struct Nod{
	int num,id;
}nod[N];
bool cmp(Nod a, Nod b) {
	return a.num < b.num;
}
void add(int x, int y) {
	while(x < N) {
		tree[x] += y;
		x += lowbit(x);
	}
}
int query(int x) {
	int s = 0;
	while(x > 0) {
		s += tree[x];
		x -= lowbit(x);
	}
	return s;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> nod[i].num;
		mp[nod[i].num] ++;
		nod[i].id = i;
	}
	for(int i = 1; i <= n; i ++) sum[i] += sum[i-1] + i;
	sort(nod+1,nod+1+n,cmp);
	for(int i = 1; i <= n; i ++) index[nod[i].id] = i;
	//for(int i = 1; i <= n; i ++) printf("%d ",index[i]);
	//printf("\n");
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		add(index[i],1);
		int tmp = i - query(index[i]);
		cout << tmp << ' ';
		tmp += (n-tmp-mp[nod[index[i]].num]);
		cout << tmp << endl;
		ans += sum[tmp];
	}
	cout << ans << endl;
	return 0;
}
*/


#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (-x)&x
using namespace std;
const int N = 100010;
const int M = 1000010;
int tree[M], sum[N], n, x, a[N];

void add(int x, int y) {
	while(x < M) {
		tree[x] += y;
		x += lowbit(x);
	}
}
int query(int x) {
	int s = 0;
	while(x > 0) {
		s += tree[x];
		x -= lowbit(x);
	}
	return s;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i]++;
	}
	for(int i = 1; i <= n; i ++) {
		add(a[i],1);
		int tmp = query(a[i]);
		sum[i] += i-tmp;
	}
	memset(tree,0,sizeof(tree));
	for(int i = n; i > 0; i --) {
		add(a[i],1);
		int tmp = query(a[i]-1);
		sum[i] += tmp;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += 1LL*(1+sum[i])*sum[i]/2;
	}
	cout << ans << endl;
	return 0;
}
