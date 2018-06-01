/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string.h>
#include <vector>
using namespace std;
const int MAX = 1e5+10;
set<int> st,st1;
int n;
vector<int> vs[MAX],vv;
bool vis[MAX], flag;
void dfs(int x,int pos){
	vis[x] = true;
	vv.push_back(x);
	if(x == pos){
		flag = true;
	}
	for(int i = 0; i < vs[x].size(); i ++){
		if(!vis[vs[x][i]])dfs(vs[x][i],pos);
	}
}
int main(){
	cin>>n;
	int l, r;
	for(int i = 0; i < n-1; i ++){
		scanf("%d %d",&l,&r);
		vs[l].push_back(r);
		vs[r].push_back(l);
	}
	for(int i = 0; i < vs[1].size(); i ++){
		vis[1] = true;
		dfs(vs[1][i],n);
		if(!flag){
			for(int j = 0; j < vv.size(); j ++){
				st.insert(vv[j]);
			}
		}
		vv.clear();
	}
	memset(vis,false,sizeof(vis));
	for(int i = 0; i < vs[n].size(); i ++){
		flag = false;
		dfs(vs[n][i],1);
		if(!flag){
			for(int j = 0; j < vv.size(); j ++){
				st1.insert(vv[j]);
			}
		}
		vv.clear();
	}
	int ans = n - st.size()-st1.size()-2;
	if((ans&1 && st.size() >= st1.size()) || (ans%2==0 && st.size() > st1.size()))
		cout << "Fennec\n";
	else cout << "Snuke\n";
	return 0;
}*/



#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1e5+10;
vector<int> vs[MAX];
int df[MAX], ds[MAX],n;
int pastf[MAX], pasts[MAX];
void bfs(int s, int dare){
	memset(pastf,0,sizeof(pastf));
	memset(pasts,0,sizeof(pasts));
	pastf[0] = 1;pasts[n-1] = 1;
	queue<pair<int, int> > que;
	que.push(make_pair(s,0));
	while(!que.empty()){
		int now = que.front().first;
		int cost = que.front().second;
		que.pop();
		if(dare == 1)df[now] = cost;
		else ds[now] = cost;
		int nowsize = (int)vs[now].size();
		for(int i = 0; i < nowsize; i ++){
			int nex = vs[now][i];
			if(dare == 1 && !pastf[nex]){
				pastf[nex] = 1;
				que.push(make_pair(nex,cost+1));
			}else if(dare != 1 && !pasts[nex]){
				pasts[nex] = 1;
				que.push(make_pair(nex,cost+1));
			}
		}
	}
}
int main(){
	int l, r;
	scanf("%d",&n);
	for(int i = 0; i < n-1; i ++){
		scanf("%d %d",&l,&r);
		l--;r--;
		vs[l].push_back(r);
		vs[r].push_back(l);
	}
	bfs(0,1);
	bfs(n-1,-1);
	int countf = 0, counts = 0;
	for(int i = 0; i < n; i ++){
		if(df[i] > ds[i]) counts++;
		else countf++;
	}
	if(countf > counts)cout << "Fennec\n";
	else cout << "Snuke\n";
	return 0;
}