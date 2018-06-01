/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
const int N = 40010;
const int M = 220;
vector<int> ve[N];
vector<pair<int,int> > que[M];
map<int,int> mp[N];
int ans[M];
int par[N], vis[N];
int find(int x){
	return par[x]==x?x:find(par[x]);
}

int Cos(int x, int y){
	int fa = find(x);
	int sum = 0;
	while(x != fa){
		sum+= mp[x][par[x]];
		x = par[x];
	}
	while(y != fa){
		sum += mp[y][par[y]];
		y = par[y];
	}
	return sum;
}
void dfs(int u, int fa){
	par[u] = u;
	vis[u] = 1;
	for(int i = 0; i < ve[u].size(); i ++){
		int v = ve[u][i];
		if(v == fa)continue;
		dfs(v,u);
	}
	
	for(int i = 0; i < que[u].size(); i ++){
		int v = que[u][i].first;
		int id = que[u][i].second;
		if(vis[v] == 1){
			ans[id] = Cos(v,u);
			//ans[id] = find(v);
		}
	}
	par[u] = fa;
}

int main(){
	int t, n, m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		int x, y, cost;
		for(int i = 0; i < n-1; i ++){
			scanf("%d%d%d",&x,&y,&cost);
			ve[x].push_back(y);
			ve[y].push_back(x);
			mp[x][y] = mp[y][x] = cost;
			mp[x][x] = mp[y][y] = 0;
		}
		for(int i = 0; i < m; i ++) {
			scanf("%d%d",&x,&y);
			que[x].push_back({y,i});
			que[y].push_back({x,i});
		}
		dfs(1,-1);
		for(int i = 0; i < m; i ++){
			printf("%d\n",ans[i]);
		}
		memset(par,0,sizeof(par));
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < N; i ++){
			ve[i].clear();
			mp[i].clear();
		}
		for(int i = 0; i < M; i ++){
			que[i].clear();
		}
	}
	return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 40010;
struct Nod{
	int to, w;
	Nod(int a = 0, int b = 0){
		to = a; w = b;
	}
};
int ans[N];
int par[N],vis[N],mark[N],dis[N];
int n,m;
vector<Nod> mp[N];
vector<Nod> query[N];
void init(){
	for(int i = 0; i <= n; i ++){
		mp[i].clear();
		query[i].clear();
		vis[i] = mark[i] = 0;
		par[i] = i;
	}
	memset(ans,-1,sizeof(ans));
}
int findset(int x){
	if(x != par[x]) par[x] = findset(par[x]);
	return par[x];
}

void dfs(int u){
	for(int i = 0; i < query[u].size(); i ++){
		int v = query[u][i].to;
		if(vis[v]&&ans[query[u][i].w]==-1&&!mark[findset(v)]){
			ans[query[u][i].w] = dis[u]+dis[v]-2*dis[findset(v)];
		}
	}
	for(int i = 0; i < mp[u].size(); i++){
		int v = mp[u][i].to;
		if(!vis[v]){
			vis[v] = 1;
			dis[v] = dis[u]+mp[u][i].w;
			dfs(v);
			par[v] = u;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		int x, y, z;
		for(int i = 0; i < n-1; i ++){
			scanf("%d%d%d",&x,&y,&z);
			mp[x].push_back(Nod(y,z));
			mp[y].push_back(Nod(x,z));
		}
		for(int i = 1; i <= m; i ++){
			scanf("%d%d",&x,&y);
			query[x].push_back(Nod(y,i));
			query[y].push_back(Nod(x,i));
		}
		for(int i = 1; i <= n; i ++){			
			if(!vis[i]){
				printf("%d+++\n",i);
				vis[i] = 1;
				dis[i] = 0;
				dfs(i);
				mark[i] = 1;
			}
		}
		for(int i = 1; i <= m; i ++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}