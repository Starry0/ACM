#include <bits/stdc++.h>
using namespace std;
const int N = 20;
double x[N], y[N], MIN = 1e6;
bool vis[N];
int n;
double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void dfs(double xx, double yy, int cnt, double ans) {
	if(MIN < ans) return;
    if(cnt == n) {
        MIN = min(MIN, ans);
        return;
    }
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            vis[i] = true;
			double tmp = dis(xx, yy, x[i], y[i]);
            dfs(x[i], y[i], cnt+1, ans+tmp);
            vis[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> x[i] >> y[i];
    dfs(0,0,0,0);
    printf("%.2lf\n",MIN);
    return 0;
}
