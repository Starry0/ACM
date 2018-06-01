#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
using namespace std;
const int N = 5e5+10;
int n,q,cnt;
int vis[N],deep[N],dmin[N][30],f[N],pos[N];
map<string,int> mp;
string name[N];
vector<int> ve[N];


void dfs(int u, int pre, int de){
	f[++cnt] = u;
	pos[u] = cnt;
	deep[cnt] = de;
	for(int i = 0; i < ve[u].size(); i ++) {
		int v = ve[u][i];
		if(v == pre)continue;
		dfs(v,u,de+1);
		f[++cnt] = u;
		deep[cnt] = de;
	}
}
void st(){
	for(int i = 1; i <= cnt; i ++){reserve
		dmin[i][0] = i;
	}
	for(int j = 1; (1<<j) <= cnt; j ++){
		for(int i = 1; i + (1<<j) -1 <= cnt; i ++) {
			int m = i+(1<<(j-1));
			if(deep[dmin[i][j-1]] < deep[dmin[m][j-1]]) dmin[i][j] = dmin[i][j-1];
			else dmin[i][j] = dmin[m][j-1];
		}
	}
}
int rmq(int l, int r){
	l = pos[l];
	r = pos[r];
	if(l > r) swap(l,r);
	int len = r-l+1;
	int k = (int)((double)len)/log(2.0);
	if(deep[dmin[l][k]] < deep[dmin[r-(1<<k)+1][k]]) return dmin[l][k];
	else return dmin[r-(1<<k)+1][k];
}
int main(){
	scanf("%d",&n);
	string str1, str2;
	for(int i = 0; i < n; i ++) {
		cin>>str1>>str2;
		if(!mp.count(str1)){
			mp[str1] = ++cnt;
			name[cnt] = str1;
		}
		if(!mp.count(str2)){
			mp[str2] = ++cnt;
			name[cnt] = str2;
		}
		ve[mp[str1]].push_back(mp[str2]);
		vis[mp[str2]]++;
	}
	cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]){
			dfs(i,-1,0);
			break;
		}
	}
	st();
	scanf("%d",&q);
	while(q--) {
		cin>>str1>>str2;
		int a = mp[str1], b = mp[str2];
		int ans = rmq(a,b);
		cout << name[ans] << endl;
	}
	return 0;
}
