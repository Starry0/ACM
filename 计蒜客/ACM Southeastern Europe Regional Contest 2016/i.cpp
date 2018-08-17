#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int  n;
map<int,int> mp, mp1, mp2;
int main() {
	for(int i = 1; i <= 355; i ++) mp2[i*i*i] = i;
	cin >> n;
	queue<int> que;
	que.push(0);
	mp[0] = 0, mp[n] = INF;
	while(!que.empty()) {
		int v = que.front();que.pop();
		if(v >= n || mp[v] >= mp[n]) continue;
		for(int i = 355; i >= 1; i --) {
			int u = v+i*i*i;
			if(u <= n) {
				if(!mp.count(u) || (mp.count(u) && mp[v]+1 < mp[u])) {
					if(u != n && mp[v] >= mp[n]-2) continue;
					printf("%d\n",u);
					mp[u] = mp[v] + 1;
					mp1[u] = v;
					que.push(u);
				}
			}
		}
	}	
	cout << mp[n] << endl;
	while(n != 0) {
		printf("%d ",mp2[n-mp1[n]]);
		n = mp1[n];
	}
	return 0;
}