#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
int G[N][N], a[N], d[N], vis[N];
int t, n;
int prim() {
    for(int i = 1; i <= n; i ++) {
        d[i] = INF, vis[i] = 0;
    }
    d[1] = 0;
    int res = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        res += d[v];
        for(int i = 1; i <= n; i ++)
            d[i] = min(d[i], G[v][i]+a[v]+a[i]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1; i <= n; i ++) cin>>a[i];
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) cin>>G[i][j];
        }
        printf("%d\n",prim());
    }
    return 0;
}
