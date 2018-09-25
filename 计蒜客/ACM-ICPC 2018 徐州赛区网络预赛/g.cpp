#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define lson l, m, rt<<1
#define rson m+1,r, rt<<1|1
using namespace std;
const int N = 5e4+10;
int x[N], y[N];
int MAX[N<<2];
int max(int a, int b){
    return a>b?a:b;
}
void PushDP(int rt){
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}
void update(int x, int y, int l, int r, int rt){
    if ( l == r){
        MAX[rt] = y;
        return ;
    }
    int m = (l + r) >> 1;
    if(x <= m) update(x, y, lson);
    else update(x, y, rson);
    PushDP(rt);
}
int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return MAX[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if( m >= L) ret = max(ret, Query(L, R ,lson));
    if( m < R) ret = max(ret, Query(L, R, rson));
    return ret;
}
struct Nod{
	int x, y;
}e[N];
bool cmp(Nod a, Nod b) {
	return a.x < b.y;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &x[i], &y[i]);
		e[i].x = x[i], e[i].y = y[i];
	}
	sort(e+1,e+1+n);
	ll ansx = 0, ansy = 0;
	for(int i = n; i >= 1; i --) {
		int MX = Query()
	}
	return 0;
}