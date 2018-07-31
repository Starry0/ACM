/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010;
int a[N], dp[N][N];
int cnt[N], pre[N];
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(cnt,0,sizeof(cnt));
		memset(pre,0,sizeof(pre));
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i ++) dp[i][i] = 1;
		for(int len = 2; len <= n; len ++) {
			for(int l = 1; l <= n-len+1; l ++) {
				int r = l+len-1;
				if(a[r] <= a[r-1] && a[l] >= a[l+1] && dp[l][r-1] == len-1 && dp[l+1][r] == len-1)
					dp[l][r] = len;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] >= a[i-1]) ans++;
			else ans = 1;
			cnt[i] = ans;
		}
		ans = 0;
		for(int i = n; i >= 1; i --) {
			if(a[i] <= a[i+1]) ans++;
			else ans = 1;
			pre[i] = ans;
		}
		// for(int i = 1; i <= n; i ++) printf("%d ",cnt[i]);printf("\n");
		// for(int i = 1; i <= n; i ++) printf("%d ",pre[i]);printf("\n");
		int MAX = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				int tmp = dp[i][j] + (a[i]<=a[j+1]?pre[j+1]:0) + (a[j]>=a[i-1]?cnt[i-1]:0);
				MAX = max(MAX,tmp);
			}
		}
		printf("%d\n",MAX);
	}
	return 0;
}*/


#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 2010;
int tree[N<<2];
int a[N], b[N];
int sum1[N], sum2[N], sum3[N], sum4[N];
int t, n;
void PushUp(int rt) {
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}
void build(int l, int r, int rt) {
	if(l == r) {
		tree[rt] = b[l];
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return tree[rt];
	}
	int m = (l+r)>>1;
	int MAX = -INF;
	if(m >= L) MAX = max(MAX, query(L, R, lson));
	if(m < R) MAX = max(MAX, query(L, R, rson));
	return MAX;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		memset(sum3,0,sizeof(sum3));
		memset(sum4,0,sizeof(sum4));
		for(int i = 1; i <= n; i ++) {
			sum1[i] = sum1[i-1] + (a[i]==1?1:0);
			sum3[i] = sum3[i-1] + (a[i]==2?1:0);
		}
		for(int i = n; i >= 1; i --) {
			sum2[i] = sum2[i+1] + (a[i]==1?1:0);
			sum4[i] = sum4[i+1] + (a[i]==2?1:0);
		}
		for(int i = 1; i <= n; i ++) {
			b[i] = sum3[i-1] + sum2[i];
		}
		build(1,n,1);
		int MAX = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				MAX = max(MAX, sum1[i-1]+sum4[j+1]+query(i,j,1,n,1)-sum3[i-1]-sum2[j+1]);
			}
		}
		printf("%d\n",MAX);
	}
	return 0;
}