#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 6010;
const int M = 1e6+10;
char s[N][N];
typedef pair<int,int> P;
map<P, int> mp;
vector<int> vs[M];
bool vis[M];
int S, E;
int dx[] = {-1, -2, -1, 1, 2, 1};
int dy[] = {-3, 0, 3, 3, 0, -3};

int bfs(int S) {
	queue<P> que;
	que.push(P(S, 1));
	while(que.size()) {
		P p = que.front(); que.pop();
		if(p.first == E) return p.second;
		if(vis[p.first]) continue;
		vis[p.first] = 1;
		for(auto x : vs[p.first]) {
			que.push(P(x, p.second+1));
		}		
	}
	return -1;
}

int main() {
	int t, r, c, rr, cc;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&rr,&cc);
		mp.clear();
		for(int i = 1; i <= rr*cc; i ++) {
			vs[i].clear();
			vis[i] = 0;
		}
		getchar();
		r = 4*rr+3;
		c = 6*cc+3;
		for(int i = 1; i <= r; i ++) cin.getline(s[i]+1,N);
		int ans = 1;
		for(int i = 3; i < r; i += 4) {
			for(int j = 5; j <= c; j += 12) {
				mp[P(i,j)] = ans;
				ans++;
			}
			ans += (cc+1)/2;
		}
		ans = (cc+1)/2+1;
		for(int i = 5; i <= r; i += 4) {
			for(int j = 11; j <= c; j += 12) {
				mp[P(i,j)] = ans;
				ans++;
			}
			ans += cc/2;
		}
		// for(auto p : mp){
			// printf("(%d,%d)-->%d\n",p.first.first,p.first.second,p.second);
		// }
		for(int i = 1; i <= r; i ++) {
			for(int j = 1; j <= c; j ++) {
				if(s[i][j] == 'S') S = mp[P(i,j)];
				if(s[i][j] == 'T') E = mp[P(i,j)];
			}
		}
		// printf("%d %d\n",S,E);
		for(int i = 3; i < r; i += 4) {
			for(int j = 5; j <= c; j += 12) {
				for(int k = 0; k < 6; k ++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(s[nx][ny] == ' ') {
						vs[mp[P(i,j)]].push_back(mp[P(i+2*dx[k],j+2*dy[k])]);
					}
				}
			}
		}
		for(int i = 5; i <= r; i += 4) {
			for(int j = 11; j <= c; j += 12) {
				for(int k = 0; k < 6; k ++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(s[nx][ny] == ' ') {
						vs[mp[P(i,j)]].push_back(mp[P(i+2*dx[k],j+2*dy[k])]);
					}
				}
			}
		}
		// for(int i = 1; i <= rr*cc; i ++) {
		// 	if(vs[i].size()) {
		// 		for(auto x: vs[i]) printf("%d-->%d\n",i,x);
		// 	}
		// }
		printf("%d\n",bfs(S));
	}
	return 0;
}