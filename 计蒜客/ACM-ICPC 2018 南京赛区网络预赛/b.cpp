/*#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int n, m, k, x, y, cnt[N][110];
bool vis[N][110];
ll dp[N][110];
struct Nod{
	int h, w;
};
int main() {
	int t;
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++) {
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < k; i ++) {
			scanf("%d%d", &x, &y);
			vis[x][y] = 1;
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				dp[i][j] = cnt[i][j] = 0;
				if(vis[i][j]) continue;
				cnt[i][j] = 1;
				if(vis[i][j] == vis[i-1][j]) cnt[i][j] += cnt[i-1][j];
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i ++) {
			stack<Nod> st;
			for(int j = 1; j <= m; j ++) {
				if(vis[i][j]) {
					while(!st.empty()) st.pop();
					continue;
				}
				int left = j;
				while(st.size()) {
					if(st.top().h >= cnt[i][j]) {
						left = st.top().w; st.pop();
					} else break;
				}
				dp[i][j] += cnt[i][j]*(j-left+1);
				st.push((Nod){cnt[i][j], left});
				if(!vis[i][left-1]) dp[i][j] += dp[i][left-1];
				ans += dp[i][j];
			}
		}
		printf("Case #%d: %lld\n", ca, ans);
	}
	return 0;
}*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n, m, t, k, x, y;
ll c[N][110], U[N], S[N], cur;
bool vis[N][110];
int main() {
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++ ) {
		memset(vis,1,sizeof(vis));
		memset(c,0,sizeof(c));
		memset(U,0,sizeof(U));
		memset(S,0,sizeof(S));
		scanf("%d%d%d",&n,&m,&k);
		for(int j = 1; j <= k; j ++) {
			scanf("%d%d",&x,&y);
			vis[x][y] = 0;
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) U[j] = vis[i][j]?U[j]+1:0;
			cur = 0;
			S[++cur] = 0;
			for(int j = 1; j <=m+1; ++ j) {
				while(U[j] < U[S[cur]]) {
					c[max(U[S[cur-1]], U[j])+1][j-S[cur-1]-1]++;
					c[U[S[cur]]+1][j-S[cur-1]-1] --;
					--cur;
				}
				while(cur >= 1 && U[j] == U[S[cur]]) --cur;
				S[++cur] = j;
			}
		}
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++) c[i][j] += c[i-1][j];
		for(int i = 1; i <= n; i ++) {
			for(int j = m-1; j >= 1; j --) c[i][j] += c[i][j+1];
			for(int j = m-1; j >= 1; j --) c[i][j] += c[i][j+1];
		}
		ll ans = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) ans += c[i][j];
		}
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}