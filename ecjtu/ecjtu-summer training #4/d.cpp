#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;
const int MAX = 2e5+10;
int a[MAX],fa[MAX],b[MAX];
map<int,int>mp[MAX];
set<int>st;
bool vis[MAX];
int find(int x){
	if(fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
int uni(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx > yy)
		fa[xx] = yy;
	else fa[yy] = xx;
}
int main(){
	int n,m,k,l,r;
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i ++)scanf("%d",&a[i]);
	for(int i = 1; i <= n; i ++)
		fa[i] = i;
	for(int i = 1; i <= m; i ++){
		scanf("%d %d",&l,&r);
		uni(l,r);
		vis[l] = true;
		vis[r] = true;
	}
	for(int i = 1; i <= n; i ++){
		if(!vis[i])continue;
		int x = find(i);
		st.insert(x);
		b[x]++;
		mp[x][a[i]]++;
	}
	int ans = 0;
	set<int>::iterator sit;
	map<int,int>::iterator mit;
	for(sit = st.begin(); sit != st.end(); ++sit){
		int k = (*sit);
		int MAX = 0;
		for(mit = mp[k].begin(); mit!=mp[k].end();++mit){
			if((*mit).second > MAX)
				MAX = (*mit).second;
		}
		ans += (b[k]-MAX);
	}
	cout << ans << endl;
	return 0;
}