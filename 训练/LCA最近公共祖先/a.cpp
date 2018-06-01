/*#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e4+5;
vector <int> vec[N] ;
vector <pair<int,int> > query[N];

int vis[N] , pre[N] , ans[N];
int Find(int x){
	if(pre[x] == x){
		return x;
	}else{
		pre[x] = Find(pre[x]);
		return pre[x];
	}
}
void dfs(int u , int fa){

	pre[u] = u;
	vis[u] = 1;
	for(int i = 0 ; i < vec[u].size() ; i ++){
		int v = vec[u][i];
		if(v == fa) continue;
		dfs(v , u);
	}

	for(int i = 0 ; i < query[u].size() ; i++){
		int v = query[u][i].first;
		int id = query[u][i].second;
		if(vis[v] == 1){
			ans[id] = Find(v);
		}
	}

	pre[u] = fa;
}

int main(){
	int T;
	scanf("%d" ,&T);
	while(T --){
		int n , x, y;
		scanf("%d" , &n);
		for(int i = 0 ; i < n - 1 ; i ++){
			scanf("%d%d" , &x , &y);
			vec[x].push_back(y);
			vec[y].push_back(x);
			vis[y] = 1;
		}
		int q = 1;
		for(int i = 0 ; i < q ; i ++){
			scanf("%d%d" , &x , &y);
			query[x].push_back({y , i});
			query[y].push_back({x , i});
		}
		for(int i = 1 ; i <= n ; i ++){
			if(vis[i] == 0){
				memset(vis , 0 ,sizeof(vis));
				dfs(i , -1);
				break;
			}
		}
		for(int i = 0 ; i < q ; i ++){
			printf("%d\n" ,ans[i]);
		}

		for(int i = 0; i < N; i ++){
			vec[i].clear();
			query[i].clear();
		}
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
		memset(ans,0,sizeof(ans));
	}
}*/

/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 1e4+5;
vector<int> ve[N];
int ans, pre[N],vis[N];
vector<pair<int,int> > que[N];
int find(int x){
	if(x == pre[x]){
		return x;
	}else {
		pre[x] = find(pre[x]);
		return pre[x];
	}
}
void dfs(int u, int fa){
	pre[u] = u;
	vis[u] = 1;
	for(int i = 0; i < ve[u].size(); i ++){
		int v = ve[u][i];
		if(v == fa)continue;
		dfs(v,u);
	}
	for(int i = 0; i < que[u].size(); i ++){
		int v = que[u][i].first;
		if(vis[v] == 1){
			ans = find(v);
		}
	}
	pre[u] = fa;
}
int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x, y;
		for(int i = 0; i < n-1; i ++){
			scanf("%d%d",&x,&y);
			ve[x].push_back(y);
			ve[y].push_back(x);
			vis[y] = 1;
		}
		scanf("%d%d",&x,&y);
		que[x].push_back({y,0});
		que[y].push_back({x,0});
		for(int i = 1; i <= n; i ++){
			if(vis[i] == 0){
				memset(vis,0,sizeof(vis));
				dfs(i,-1);
				break;
			}
		}
		printf("%d\n",ans);
		for(int i = 0; i < N; i ++){
			ve[i].clear();
			que[i].clear();
		}
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
	}
	return 0;
}
*/


/*
基于二分搜索的算法
*/
/*
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int N = 1e4+10;
vector<int> G[N];
int vis[N], parent[30][N], depth[N], t, n;

void dfs(int v, int p, int d){
	parent[0][v] = p;
	depth[v] = d;
	for(int i = 0; i < G[v].size(); i ++){
		if(G[v][i] != p) dfs(G[v][i],v,d+1);
	}
}
int lca(int u, int v){
	if(depth[u] > depth[v]) swap(u,v);
	for(int k = 0; k < 30; k ++){
		if((depth[v]-depth[u]) >> k&1){
			v = parent[k][v];
		}
	}
	if(v == u) return u;
	for(int k = 29; k >= 0; k--){
		if(parent[k][u] != parent[k][v]){
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
void init(){
	memset(parent,-1,sizeof(parent));
	for(int i = 1; i < N; i ++){
		parent[0][i] = i;
		G[i].clear();
	}
	memset(vis,0,sizeof(vis));
	memset(depth,0,sizeof(depth));
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		int x, y;
		for(int i = 1; i < n; i ++){
			scanf("%d %d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
			vis[y] = 1;
		}
		for(int i = 1; i <= n; i ++){
			if(!vis[i]){
				dfs(i,-1,0);
				for(int k = 0; k+1 < 30; k ++){
					for(int v = 0; v < N; v ++){
						if(parent[k][v] < 0) parent[k+1][v] = -1;
						else parent[k+1][v] = parent[k][parent[k][v]];
					}
				}
			}
		}
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
*/



/*
基于RMQ来做。
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int N = 1e4+10;
int t, n, vis[N], vs[N*2], depth[N*2], id[N];
vector<int> G[N];

void dfs(int u, int p, int d, int &k){
	id[v] = k;
	vs[k] = u;
	depth[k++] = d;
	for(int i = 0; i < G[u].size(); i ++){
		if(G[u][i] != p){
			dfs(G[u][i],u,d+1,k);
			vs[k] = u;
			depth[k++] = d;
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x, y;
		for(int i = 1; i < n; i ++){
			scanf("%d %d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
			vis[y] = 1;
		}
		int root, k = 0;
		for(int i = 1; i <= n; i ++){
			if(!vis[i])
				root = i,break;
		}
		dfs(root, -1, 0, k);
	}
	return 0;
}
