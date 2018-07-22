#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], b[N];
int t, n;
typedef pair<int,int> P;
vector<P> vs;
bool ok1(int l, int r) {
	bool flag = 1;
	for(int i = l; i <= r; i ++) {
		if(b[i] != r-i+l) {
			flag = 0;
			break;
		}
	}
	if(flag) printf("1\n%d %d\n",l,r);
	return flag;
}

bool ok2(int l, int r) {
	int x, y;
	for(int i = l; i <= r; i ++) {
		if(b[i] == l) x = i;
	}
	for(int i = l; i <= (x+l)/2; i ++) swap(b[i],b[x-i+l]);
	while(b[r] == r) r--;
	for(int i = l; i <= r; i ++) {
		if(b[i] == r) y = i;
	}
	for(int i = y; i <= (r+y)/2; i ++) swap(b[i],b[r-i+y]);
	bool flag = 1;
	for(int i = 1; i <= n; i ++) if(b[i] != i) {flag = 0;break;}
	if(flag) {
		vs.push_back(P(l,x));
		vs.push_back(P(y,r));
		// printf("2\n%d %d\n%d %d\n",l,x,y,r);
		return true;
	}
	for(int i = 1; i <= n; i ++) b[i] = a[i];
	for(int i = l; i <= r; i ++) {
		if(b[i] == r) y = i;
	}
	for(int i = y; i <= (r+y)/2; i ++) swap(b[i],b[r-i+y]);
	while(b[l] == l) l++;
	for(int i = l; i <= r; i ++) {
		if(b[i] == l) x = i;
	}
	for(int i = l; i <= (x+l)/2; i ++) swap(b[i],b[x-i+l]);
	flag = 1;
	for(int i = 1; i <= n; i ++) if(b[i] != i) {flag = 0;break;}
	if(flag) {
		vs.push_back(P(y,r));
		vs.push_back(P(l,x));
		// printf("2\n%d %d\n%d %d\n",l,x,y,r);
		return true;
	}
	return false;
}

void ok3(int l, int r) {
	vs.clear();
	for(int i =)
	int x, y;
	for(int i = 1; i <= n; i ++) b[i] = a[i];
	for(int i = l; i <= r; i ++) {
		if(b[i] == l) {x = i;}
		if(b[i] == r) {y = i;}
	}
	bool flag = 1;
	for(int i = 1; i <= l; i ++) {
		if()
	}
	vs.push_back(P(l,x));
	for(int i = l; i <= (l+x)/2; i ++) swap(b[i], b[x-i+l]);
	while(b[l] == l) l++;
	// for(int i = 1; i <= n; i ++) printf("%d%c",b[i]," \n"[i==n]);
	// printf("l:%d\n",l);
	if(ok2(l,r)){
		printf("3\n");
		for(int i = 2; i >= 0; i --) printf("%d %d\n",vs[i].first,vs[i].second);
		return;
	}
	for(int i = 1; i <= n; i ++) b[i] = a[i];
	vs.clear();
	for(int i = l; i <= r; i ++) {
		if(b[i] == r) {y = i; break;}
	}
	vs.push_back(P(y,r));
	for(int i = y; i <= (r+y)/2; i ++) swap(b[i], b[r-i+y]);
	while(b[r] == r) r--;
	if(ok2(l,r)) {
		printf("3\n");
		for(int i = 2; i >= 0; i --) printf("%d %d\n",vs[i].first,vs[i].second);
		return;
	}
}

int main() {
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i];
		int l = 1, r = n;
		while(b[l] == l && l < n) l++;
		while(b[r] == r && r > 1) r--;
		if(l == n) {
			printf("0\n");
			continue;
		}
		if(ok1(l,r)) continue;
		if(ok2(l,r)) {
			printf("2\n");
			printf("%d %d\n%d %d\n",vs[1].first,vs[1].second,vs[0].first,vs[0].second);
			continue;
		}
		ok3(l,r);
		vs.clear();
	}
	return 0;
}