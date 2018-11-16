#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int x[N], y[N];
bool flag[5];
struct nod{
	int x, y;
}e[N], e1[N];
bool cmp1(const nod &a, const nod &b) {
	return a.x < b.x;
}
bool cmp2(const nod &a, const nod &b) {
	return a.y < b.y;
}

int main() {
	int n, t;
	cin >> t;
	while(t--) {
		memset(flag, 1, sizeof(flag));
		cin >> n;
		for(int i = 0; i < n; i ++) scanf("%d%d", &e[i].x, &e[i].y), e1[i].x = e[i].x, e1[i].y = e[i].y;
		sort(e,e+n,cmp1);
		sort(e1,e1+n,cmp2);
		if(e[0].y == e1[0].y || e[0].y == e1[n-1].y || e[n-1].x == e1[0].y || e[n-1].y == e1[n-1].y) {
			printf("Yes\n");
			continue;
		}
		if(e1[0].x == e[0].x || e1[0].x == e[n-1].x || e1[n-1].x == e[0].x || e1[n-1].x == e[n-1].x) {
			printf("Yes\n");
			continue;
		}
		for(int i = 0; i < n; i ++) {
			if(abs(e[i].y-e[0].y) > abs(e[i].x-e[0].x)) flag[0] = 0;
			if(abs(e[i].y-e[n-1].y) > abs(e[i].x-e[n-1].x)) flag[1] = 0;
			if(abs(e[i].y-e1[0].y) < abs(e[i].x-e1[0].x)) flag[2] = 0;
			if(abs(e[i].y-e1[n-1].y) < abs(e[i].x-e1[n-1].x)) flag[3] = 0;
		}
		if(flag[0] || flag[1] || flag[2] || flag[3]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}