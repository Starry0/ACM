#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, ans[1010], u, v;
double MIN = 1e7;
struct Nod{
    int a, b;
}a[11];
bool vis[11];
void dfs(int x) {
    if(x == n) {
        int sum = 0;
        double cnt = 0, cnt1 = 0;
        for(int i = 1; i <= n; i ++) {
            if(vis[i]) sum+= a[i].a;
            else {
                cnt1 += a[i].a;
                if(a[i].b) cnt += a[i].a*0.8;
                else cnt += a[i].a;
            }
        }
        MIN = min(MIN,min(cnt+sum,cnt1+sum-ans[sum]));
        // for(int i = 1; i <= n; i ++) printf("%d%c",vis[i]," \n"[i==n] );
        // printf("%d %lf %lf\n",sum,cnt,MIN);
        return ;
    }
    vis[x+1] = 1;
    dfs(x+1);
    vis[x+1] = 0;
    dfs(x+1);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i].a >> a[i].b;
    for(int i = 0; i < m; i ++) {
        cin >> u >> v;
        ans[u] = max(ans[u],v);
    }
    for(int i = 1; i < 1010; i ++) ans[i] = max(ans[i],ans[i-1]);
    dfs(0);
    printf("%.2lf\n",MIN);
    return 0;
}
