#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 10010;
struct Nod{
	int v, w;
};
struct edge{
	int id, index;
}ed[N];
int MAX, t, n, m, d[N], vis[N], vis1[N];
vector<int> vs[N];
vector<Nod> g[N];
void init() {
	MAX = 0;
	memset(d, 0, sizeof(d));
	memset(vis, false, sizeof(vis));
	memset(vis1, false, sizeof(vis1));
	for(int i = 0; i < N; i ++) {
		g[i].clear();
		vs[i].clear();
	}
}

bool dfs(int x, int id) {
	ed[x].id = id;
	vis1[x] = true;
	for(int i = 0; i < vs[x].size(); i ++) {
		int son = vs[x][i];
		if(vis1[son]) {
			ed[x].id = ed[son].id - 1;
			return true;
		} else {
			bool flag = dfs(son, id+1);
			if(flag) {
				ed[x].id = ed[son].id - 1;
				return true;
			}
		}
	}
	return false;
}
void fun(){
	int id = 1;
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) {
			dfs(i,id);
		}
	}
}
bool cmp(edge a, edge b) {
	return a.id > b.id;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		init();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; i ++) {
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			vs[u].push_back(v);
			g[v].push_back((Nod){u,w});
			vis[v] = true;
		}
		for(int i = 1; i <= n; i ++) {
			ed[i].id = 0;	
			ed[i].index = i;
		}
		fun();
		sort(ed+1, ed+1+n, cmp);
		for(int i = 1; i <= n; i ++) {
			int index = ed[i].index;
			for(int j = 0; j < g[index].size(); j ++) {
				d[g[index][j].v] = max(d[g[index][j].v], g[index][j].w + d[index]);
			}
		}
		for(int i = 1; i <= n; i ++) {
			MAX = max(MAX, d[i]);
		}
		printf("%d\n",MAX);
	}
	return 0;
}