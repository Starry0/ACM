#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
struct Nod{
	int x, y;
}e[N];
ll sumx[N], sumy[N], sx[N], sy[N];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> e[i].x >> e[i].y, sx[i] = e[i].x, sy[i] = e[i].y;
	sort(sx+1,sx+1+n);
	sort(sy+1,sy+1+n);
	sumx[0]=sumy[0]=0;
	for(int i = 1; i <= n; i ++) {
		sumy[i] = sumy[i-1] + sy[i];
		sumx[i] = sumx[i-1] + sx[i];
	}
	ll nx,ny,cntx,cnty;
	ll ans = 1e-17;
	for(int i = 1; i <= n; i ++) {
		nx = lower_bound(sx+1,sx+1+n,e[i].x) - sx;
		ny = lower_bound(sy+1,sy+1+n,e[i].y) - sy;
		cntx = e[i].x*(2*nx-n)-2*sumx[nx]+sumx[n];
		cnty = e[i].y*(2*ny-n)-2*sumy[ny]+sumy[n];
		ans = max(ans,cnty+cntx);
	}
	cout << ans << endl;
	return 0;
}