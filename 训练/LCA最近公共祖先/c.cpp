#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 100010;
struct Nod{
	int to,w;
	Nod(int a = 0, int b = 0){
		to = a; w = b;
	}
};
int n,m,k;
vector<Nod>ve[N],query[N];
int pre[N], vis[N], ans[N], dis[N], mark[N];
void init(){
	for(int i = 0; i <= n; i ++){
		query[i].clear();
		ve[i].clear();
		dis[i] = mark[i] = vis[i] = 0;
		pre[i] = i;
	}
	memset(ans,-1,sizeof(ans));
}
int find(int x){
	if(pre[x] != x) pre[x] = find(pre[x]);
	return pre[x];
}
void dfs(int u){
	for(int i = 0; i < query[u].size(); i ++){
		int v = query[u][i].to;
		if(vis[v]&&ans[query[u][i].w]==-1&&!mark[find(v)]){
			ans[query[u][i].w] = dis[u]+dis[v]-2*dis[find(v)];
		}
	}
	for(int i = 0; i < ve[u].size(); i ++){
		int v = ve[u][i].to;
		if(!vis[v]){
			vis[v] = 1;
			dis[v] = dis[u]+ve[u][i].w;
			dfs(v);
			pre[v] = u;
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		int x, y, z;
		char str[10];
		for(int i = 0; i < m; i ++){
			scanf("%d%d%d%s",&x,&y,&z,str);
			ve[x].push_back(Nod(y,z));
			ve[y].push_back(Nod(x,z));
		}
		scanf("%d",&k);
		for(int i = 1; i <= k; i ++){
			scanf("%d%d",&x,&y);
			query[x].push_back(Nod(y,i));
			query[y].push_back(Nod(x,i));
		}
		for(int i = 1; i <= n; i ++){
			if(!vis[i]){
				vis[i] = 1;
				dis[i] = 0;
				dfs(i);
				mark[i] = 1;
			}
		}
		for(int i = 1; i <= k; i ++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}