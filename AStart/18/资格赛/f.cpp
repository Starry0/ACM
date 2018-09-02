/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 220;
struct Nod{
	int v, u, w, id;
}e[N], e1[N];
bool cmp(const Nod &a, const Nod &b) {
	return a.w < b.w;
}
int a[N], b[N], fa[N];
int t, n, m, v, u, w;
vector<int> v1, v2;

void init() {
	for(int i = 1; i <= m; i ++) a[i] = b[i] = INF;
	v1.clear(), v2.clear();
	for(int i = 1; i <= n; i ++) fa[i] = i;
}
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}
int main() {
	char ch[2];
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ++ ca) {
		scanf("%d%d", &n, &m);
		init();
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= m; i ++) {
			scanf("%d%d%d%s",&u, &v, &w, ch);
			if(ch[0] == 'R') {
				e[cnt1].u = u, e[cnt1].v = v;
				e[cnt1].w = w; e[cnt1++].id = 1;
			} else if(ch[0] == 'G') {
				e[cnt1].u = u, e[cnt1].v = v;
				e[cnt1].w = w; e[cnt1++].id = 2;
				e1[cnt2].u = u, e1[cnt2].v = v;
				e1[cnt2].w = w; e1[cnt2++].id = 2;
			} else {
				e1[cnt2].u = u, e1[cnt2].v = v;
				e1[cnt2].w = w; e1[cnt2++].id = 3;
			}
		}
		sort(e,e+cnt1,cmp);
		sort(e1,e1+cnt2,cmp);
		int ans = 0;
		for(int i = 0; i < cnt1; i ++) {
			if(find(e[i].u) == find(e[i].v)) {
				v1.push_back(e[i].w);
			} else {
				ans += e[i].w;
				fa[find(e[i].u)] = find(e[i].v);
			}
		}
		for(int i = 0; i < cnt2; i ++) {
			if(e1[i].id == 3) v2.push_back(e1[i].w);
		}
		a[n-1] = ans;
		int id1 = 0, id2 = 0, len1 = v1.size(), len2 = v2.size();
		for(int i = n; i <= m; i ++) {
			if(id1 >= len1) {
				a[i] = a[i-1]+v2[id2++];
			} else if(id2 >= len2) {
				a[i] = a[i-1]+v1[id1++];
			} else {
				if(v1[id1] > v2[id2]) a[i] = a[i-1]+v2[id2++];
				else a[i] = a[i-1]+v1[id1++];
			}
		}
		ans = 0;
		v1.clear(), v2.clear();
		for(int i = 1; i <= n; i ++) fa[i] = i;
		for(int i = 0; i < cnt2; i ++) {
			if(find(e1[i].u) == find(e1[i].v)) {
				v1.push_back(e1[i].w);
			} else {
				ans += e1[i].w;
				fa[find(e1[i].u)] = find(e1[i].v);
			}
		}
		for(int i = 0; i < cnt1; i ++) {
			if(e[i].id == 1) v2.push_back(e[i].w);
		}
		a[n-1] = min(a[n-1], ans);
		id1 = 0, id2 = 0, len1 = v1.size(), len2 = v2.size();
		for(int i = n; i <= m; i ++) {
			if(id1 >= len1) {
				b[i] = b[i-1]+v2[id2++];
			} else if(id2 >= len2) {
				b[i] = b[i-1]+v1[id1++];
			} else {
				if(v1[id1] > v2[id2]) b[i] = b[i-1]+v2[id2++];
				else b[i] = b[i-1]+v1[id1++];
			}
		}
		printf("Case #%d:\n",ca);
		for(int i = 1; i <= m; i ++) {
			printf("%d\n",i<n-1?-1:min(a[i],b[i]));
		}
	}
	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct nod{
	int v, u, w, id;
}e[N];
int a[N], fa[N];
bool vis[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? fa[x]: find(fa[x]));
}
bool cmp(const nod &a, const nod &b) {
	return a.w < b.w;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t, n, m, u, v, w;
	char ch[2];
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) fa[i] = i;
		memset(a, -1, sizeof(a));
		for(int i = 0; i < m; i ++) {
			cin >> e[i].u >> e[i].v >> e[i].w >> ch;
			if(ch[0] == 'R') e[i].id = 1;
			else if(ch[0] == 'G') e[i].id = 2;
			else e[i].id = 3;
		}
		sort(e,e+m, cmp);
		int ans = 0, tmp = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < m; i ++) {
			if(e[i].id == 3) continue;
			if(find(e[i].v) != find(e[i].u)) {
				ans += e[i].w;
				fa[find(e[i].v)] = find(e[i].u);
				vis[i] = 1; tmp++;
			}
		}
		if(tmp == n-1) {
			a[n-1] = ans;
			int cnt = n;
			for(int i = 0; i < m; i ++) {
				if(!vis[i]) {
					ans += e[i].w;
					a[cnt++] = ans;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i ++) fa[i] = i;
		ans = 0, tmp = 0;
		for(int i = 0; i < m; i ++) {
			if(e[i].id == 1) continue;
			if(find(e[i].u) != find(e[i].v)) {
				ans += e[i].w;
				fa[find(e[i].u)] = find(e[i].v);
				vis[i] = 1; tmp++;
			}
		}
		if(tmp == n-1) {
			if(a[n-1] != -1)a[n-1] = min(a[n-1], ans);
			else a[n-1] = ans;
			int cnt = n;
			for(int i = 0; i < m; i ++) {
				if(!vis[i]) {
					ans += e[i].w;
					if(a[cnt] != -1)a[cnt] = min(a[cnt], ans);
					else a[cnt] = ans;
					cnt++;
				}
			}
		}
		printf("Case #%d:\n",ca);
		for(int i = 1; i <= m; i ++) printf("%d\n",a[i]);
	}
	return 0;
}