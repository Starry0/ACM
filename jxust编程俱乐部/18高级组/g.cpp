#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Nod{
	int x, y, z, id;
}e[N];
struct Node{
	int v, u, w;
}nod[N*4];
int fa[N];
bool cmp(Node a, Node b) { return a.w < b.w;}
bool cmp1(Nod a, Nod b) { return a.x+a.y < b.x+b.y;}
bool cmp2(Nod a, Nod b) { return a.x+a.z < b.x+b.z;}
bool cmp3(Nod a, Nod b) { return a.z+a.y < b.z+b.y;}
bool cmp4(Nod a, Nod b) { return a.x+a.y+a.z < b.x+b.y+b.z;}
int find(int x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}

int main() {
	ll n, k;
	scanf("%lld%lld",&n,&k);
//	cin >> n >> k;
	for(int i = 1; i <= n; i ++) 
		scanf("%d%d%d",&e[i].x, &e[i].y, &e[i].z), e[i].id = i;
	int cnt = 0;
	sort(e+1,e+1+n,cmp1);
	for(int i = 2; i <= n; i ++) {
		nod[cnt].v = e[i-1].id, nod[cnt].u = e[i].id;
		nod[cnt++].w = abs(e[i-1].x+e[i-1].y - e[i].x - e[i].y);
	}
	sort(e+1,e+1+n,cmp2);
	for(int i = 2; i <= n; i ++) {
		nod[cnt].v = e[i-1].id, nod[cnt].u = e[i].id;
		nod[cnt++].w = abs(e[i-1].x+e[i-1].z - e[i].x - e[i].z);
	}
	sort(e+1,e+1+n,cmp3);
	for(int i = 2; i <= n; i ++) {
		nod[cnt].v = e[i-1].id, nod[cnt].u = e[i].id;
		nod[cnt++].w = abs(e[i-1].z+e[i-1].y - e[i].z - e[i].y);
	}
	sort(e+1,e+1+n,cmp4);
	for(int i = 2; i <= n; i ++) {
		nod[cnt].v = e[i-1].id, nod[cnt].u = e[i].id;
		nod[cnt++].w = abs(e[i-1].x+e[i-1].y+e[i-1].z - e[i].x-e[i].y-e[i].z);
	}
	for(int i = 1; i <= n; i ++) fa[i] = i;
	ll ans = 0;
	sort(nod,nod+cnt,cmp);
	for(int i = 0; i < cnt; i ++) {
		if(find(nod[i].v) != find(nod[i].u)) {
			fa[find(nod[i].v)] = find(nod[i].u);
			ans += 1LL*nod[i].w;
		}
	}
	printf("%lld\n",ans*k);
	return 0;
}