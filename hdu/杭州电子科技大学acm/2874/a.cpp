#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 10010;
const int M = 1000010;
struct Nod{
	int to, w;
	Nod(int a = 0, int b = 0){
		to = a; w = b;
	}
};
int ans[M];
int par[N],vis[N],mark[N],dis[N];
int n,m,k;
vector<Nod> mp[N];
vector<Nod> query[N];
void init(){
	for(int i = 0; i <= n; i ++){
		mp[i].clear();
		vis[i] = mark[i] = 0;
		par[i] = i;
	}
	for(int i = 0; i <= k; i ++)query[i].clear();
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
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		int x, y, z;
		for(int i = 0; i < m; i ++){
			scanf("%d%d%d",&x,&y,&z);
			mp[x].push_back(Nod(y,z));
			mp[y].push_back(Nod(x,z));
		}
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
			if(ans[i] != -1){
				printf("%d\n",ans[i]);
			}else printf("Not connected\n");
		}
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 10010
#define M 1000010

struct node{
   int to,w;
   node (int a=0,int b=0){to=a,w=b;}
};

int ans[M];
int par[N],vis[N],mark[N],dis[N];
int n,m,k;
vector<node>mp[N];
vector<node>query[N];

void init(){
     for(int i=0;i<=n;i++){
     mp[i].clear();
     query[i].clear();
     vis[i]=mark[i]=0;
     par[i]=i;
     }
     memset(ans,-1,sizeof(ans));
}
int findset(int x){
    if(x!=par[x]) par[x]=findset(par[x]);
    return par[x];
}

void dfs(int u){
     //	printf("%d\n",u);
     for(int i=0;i<query[u].size();i++){
       int v=query[u][i].to;
       if(vis[v]&&ans[query[u][i].w]==-1&&!mark[findset(v)]){
        ans[query[u][i].w]=dis[u]+dis[v]-2*dis[findset(v)];
        //printf("lca（%d->%d）：%d\n",u,v,findset(v));
       }
     }
     for(int i=0;i<mp[u].size();i++){
         int v=mp[u][i].to;
         if(!vis[v]){
         vis[v]=1;
         dis[v]=dis[u]+mp[u][i].w;
         dfs(v);
         par[v]=u;
         }
     }
}

int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
    init();
    int x,y,z;
     for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            mp[x].push_back(node(y,z));
            mp[y].push_back(node(x,z));
        }
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d",&x,&y);
            query[x].push_back(node(y,i));
            query[y].push_back(node(x,i));
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dis[i]=0;
                dfs(i);
                mark[i]=1;
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(ans[i]!=-1)
                printf("%d\n",ans[i]);
            else
                printf("Not connected\n");
        }
    }
    return 0;
}
*/