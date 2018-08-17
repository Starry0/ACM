/*#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e5+10;
int MAX[N<<2], dp1[N], dp2[N], a[N], cnt[N];
int t, n, m, x;
void read(int &x){
    char ch = getchar();x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
void PushUP(int rt) {
	MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}
void build(int l, int r, int rt) {
	if(l == r) {
		MAX[rt] = a[l];
		return;
	}
	int m = (l+r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return MAX[rt];
	}
	int m = (l+r)>>1;
	int ans = 0;
	if(m >= L) ans = max(ans, query(L, R, lson));
	if(m < R) ans = max(ans, query(L, R, rson));
	return ans;
}
int dmax[N][25];
void init(){
    for(int i = 1; i <= n; i ++){
        dmax[i][0] = a[i];
    }
     for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<(j-1))<=n;i++)
            dmax[i][j]=max(dmax[i][j-1], dmax[i+(1<<(j-1))][j-1]);

}
int getValue(int l, int r){
    int k = 0; if (l > r) return 0;
    while((1<<(k+1))<=r-l+1)k++;
    return max(dmax[l][k] ,dmax[r-(1<<k)+1][k]);
}
int bin(int l, int r, int x) {
	int pos = -1;
	while(l <= r) {
		int m = (l+r) >> 1;
		if(getValue(m, r) > x) {
			pos = m;
			r = m-1;
		} else l = m+1;
	}
	return pos;
}
int que[N];
int main() {
	// cin >> t;
	read(t);
	while(t--) {
		read(n);read(m);
		// scanf("%d%d", &n, &m);
		int mx = 0;
		for(int i = 1; i <= n; i ++) {
			read(a[i]);
			// scanf("%d", &a[i]);
			if(a[i] > mx) {
				mx = a[i];
				dp1[i] = dp1[i-1] + 1;
			} else dp1[i] = dp1[i-1];
			cnt[i] = max(a[i], cnt[i-1]);
		}
		init();
		dp2[n] = 1;
		for(int i = n-1; i >= 1; i --) {
			int ans = bin(i+1,n,cnt[i]);
			if(ans != -1) dp2[i] = dp2[ans]+1;
			else dp2[i] = dp2[i+1];
		}
		int l, v;
		while(m--) {
			// scanf("%d%d", &l, &v);
			read(l);read(v);
			int ans = dp1[l-1];
			if(v > dp1[l-1]) ++ ans;
			v = max(v, cnt[l-1]);
			int cnt = bin(l+1, n, v);
			if(cnt != -1) ans += dp2[cnt];
			printf("%d\n",ans);
		}
	}
	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dmax[N][25],a[N], cnt[N], dp1[N], dp2[N];
int que[N], t, v, l, n, m;
void init(){
    for(int i = 1; i <= n; i ++){
        dmax[i][0] = a[i];
    }
    for(int j = 1; (1<<j) <= n; j ++){
        for(int i = 1; i+(1<<j)-1<= n; i ++){
            dmax[i][j] = max(dmax[i][j-1],dmax[(1<<(j-1))+i][j-1]);
        }
    }
}
int getValue(int l, int r){
    int k = 0;
    while(1<<(k+1) <= (r-l+1))k++;
    return max(dmax[l][k],dmax[r-(1<<k)+1][k]);
}
int find(int l, int r, int x) {
	int pos = -1;
	while(l <= r) {
		int m = (l+r) >> 1;
		if(getValue(l, m) > x) {
			pos = m;
			r = m-1;
		} else l = m+1;
	}
	return pos;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		int mx = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if(mx < a[i]) {
				mx = a[i];
				dp1[i] = dp1[i-1]+1;
			} else dp1[i] = dp1[i-1];
			cnt[i] = max(a[i], cnt[i-1]);
		}
		init();
		int tail = 0, head = 1;
		for(int i = n; i >= 1; i --) {
			while(head <= tail && que[tail] <= a[i]) tail --;
			que[++tail] = a[i];
			dp2[i] = (tail- head + 1);
		}
		while(m--) {
			scanf("%d%d", &l, &v);
			int ans = dp1[l-1];
			if(v > cnt[l-1]) ++ ans;
			v = max(v, cnt[l-1]);
			int pos = find(l+1, n, v);
			if(pos != -1) ans += dp2[pos];
			printf("%d\n",ans);
		}
	}
	return 0;
}