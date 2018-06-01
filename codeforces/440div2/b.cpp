#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int dmin[N][25], a[N], n;
void init() {
	for(int i = 1; i <= n; i ++){
        dmin[i][0] = a[i];
    }
	for(int j = 1; (1<<j) <= n; j ++){
        for(int i = 1; i+(1<<j)-1<= n; i ++){
            dmin[i][j] = min(dmin[i][j-1],dmin[(1<<(j-1))+i][j-1]);
        }
    }
}
int getValue(int l, int r){
    int k = 0;
    while(1<<(k+1) <= (r-l+1))k++;
    return min(dmin[l][k],dmin[r-(1<<k)+1][k]);
}
int main() {
	int k, MAX = -INF, MIN = INF;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i], MAX = max(MAX, a[i]), MIN = min(MIN, a[i]);
	if(k == 1) printf("%d\n",MIN);
	else if(k == 2) {
		if(a[1] == MAX || a[n] == MAX) printf("%d\n",MAX);
		else {
			init();
			int ans = -INF;
			for(int i = 1; i < n; i ++) {
				int cnt = max(getValue(1,i),getValue(i+1,n));
				if(cnt > ans) ans = cnt;
			}
			printf("%d\n",ans);
		}
	}else printf("%d\n",MAX);
	return 0;
}