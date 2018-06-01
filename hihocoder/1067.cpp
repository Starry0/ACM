#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> P;
const int N = 1e5+10;
struct Nod{
	int to,nex;
	Nod(int x = 0, int y = -1){
		to = x;nex = y;
	}
};
Nod nod[N];
int head[N], uf[N], fa[N], ans[N];
int tot, cnt, n, m;
bool vis[N];
vector<P> query[N];
void add(int u, int v){
	nod[tot] = Nod(v,head[u]);
	head[u] = tot++;
}
int find(int x){
	if(x != uf[x]) uf[x] = find(uf[x]);
	return uf[x];
}
void dfs(int u){
	fa[u] = u;
	for(int i = head[u]; ~i; i = nod[i].nex){
		dfs(nod[i].to);
		int x = find(nod[i].to);
		uf[x] = uf[find(u)];
		fa[find(u)] = u;
	}
	vis[u] = true;
	for(int i = query[u].size()-1; i >= 0; i--){
		if(vis[query[u][i].first]) ans[query[u][i].second] =fa[find(query[u][i].first)];
	}
}
void init(){
	for(int i = 0; i < N; i ++){
		head[i] = -1;
		vis[i] = false;
		uf[i] = i;
	}
	tot = 0;
	cnt = 1;
}
map<string,int> mp;
string name[N],str1,str2;
int main(){
	init();
	int u, v;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		cin>>str1>>str2;
		if(mp[str1])u = mp[str1];
		else{
			u = mp[str1] = cnt;
			name[cnt++] = str1;
		}
		if(mp[str2]) v = mp[str2];
		else{
			v = mp[str2] = cnt;
			name[cnt++] = str2;
		}
		add(u,v);
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i ++){
		cin>>str1>>str2;
		query[mp[str1]].push_back(make_pair(mp[str2],i));
		query[mp[str2]].push_back(make_pair(mp[str1],i));
	}
	for(int i = 1; i < cnt; i ++){
		if(!vis[i])dfs(i);
	}
	for(int i = 0; i < m; i ++){
		//printf("%d\n",ans[i]);
		cout << name[ans[i]] << endl;
	}
	return 0;
}