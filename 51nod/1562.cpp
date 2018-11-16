#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 200010;
struct Nod{
	ll l, r;
}h[N],w[N];
struct op{
	char op; int x;
}o[N];
int hh[N], ww[N];
ll ans[N];
bool vish[N], visw[N];
int main() {
	int W, H, n;
	cin >> W >> H >> n;
	for(int i = 0; i < N; i ++) {
		h[i].l = w[i].l = 0;
		h[i].r = H; w[i].r = W;
	}
	char ch; int x;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> ch >> x;
		o[i].op = ch; o[i].x = x;
		if(ch == 'H') hh[cnt1++] = x, vish[x] = 1;
		else ww[cnt2++] = x, visw[x] = 1;
	}
	vish[0] = visw[0] = visw[W] = vish[H] = 1;
	sort(hh, hh+cnt1);
	sort(ww, ww+cnt2);
	for(int i = 0; i < cnt1; i ++) {
		if(i == 0) h[0].r = hh[0];
		if(i == cnt1-1) h[H].l = hh[i];
		if(i+1 < cnt1) h[hh[i]].r =hh[i+1];
		if(i > 0) h[hh[i]].l = hh[i-1];
	}
	for(int i = 0; i < cnt2; i ++) {
		if(i == 0) w[0].r = ww[0];
		if(i == cnt2-1) w[W].l = ww[i];
		if(i+1 < cnt2) w[ww[i]].r = ww[i+1];
		if(i > 0) w[ww[i]].l = ww[i-1];
	}
	ll MAXH = 0, MAXW = 0;
	for(int i = 0; i < N; i ++) {
		if(vish[i]) {
			MAXH = max(MAXH, max(h[i].r-i,i-h[i].l));
		}
	}
	for(int i = 0; i < N; i ++) {
		if(visw[i]) {
			MAXW = max(MAXW, max(w[i].r-i,i-w[i].l));
		}
	}
	ans[n] = MAXW*MAXH;
	for(int i = n; i > 1; i --) {
		if(o[i].op == 'H') {
			int x = o[i].x;
			MAXH = max(MAXH, h[x].r-h[x].l);
			h[h[x].r].l = h[x].l;
			h[h[x].l].r = h[x].r;
		} else {
			int x = o[i].x;
			MAXW = max(MAXW, w[x].r-w[x].l);
			w[w[x].r].l = w[x].l;
			w[w[x].l].r = w[x].r;
		}
		ans[i-1] = MAXW*MAXH;
	}
	for(int i = 1; i <= n; i ++) printf("%lld\n",ans[i]);
	return 0;
}