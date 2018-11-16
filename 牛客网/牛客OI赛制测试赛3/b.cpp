#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define lson l, m, rt<<1
#define rson m+1,r, rt<<1|1
using namespace std;
const int N = 1e5+10;
int sum[N<<2][31], ans[31], x;

void PushDP(int rt){
	for(int i = 0; i <= 30; i ++) {
		sum[rt][i] = sum[rt<<1][i] + sum[rt<<1|1][i];
	}
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%d",&x);
        for(int i = 0; i <= 30; i ++) {
        	if((x>>i)&1) sum[rt][i] ++;
        }
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushDP(rt);
}
void Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
    	for(int i = 0; i <= 30; i ++) {
    		ans[i] += sum[rt][i];
    	}
        return;
    }
    int m = (l + r) >> 1;
    if( m >= L) Query(L, R ,lson);
    if( m < R) Query(L, R, rson);
}
int main() {
	int n, q;
	cin >> n;
	build(1,n,1);
	cin >> q;
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		memset(ans, 0, sizeof(ans));
		Query(l,r,1,n,1);
		int x = 0;
		for(int i = 30; i >= 0; i --) {
			// printf("%d ",ans[i]);
			if((r-l+1-ans[i]) > ans[i]) x += (1<<i);
		}
		printf("%d\n",x);
	}
	return 0;
}