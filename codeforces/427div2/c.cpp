#include <bits/stdc++.h>
using namespace std;
int a[110][110][110];
int main() {
    int n,q,c;
    cin>>n>>q>>c;
    for(int i = 1; i <= n; i ++) {
        int x, y, s;
        cin>>x>>y>>s;
        for(int j = 0; j <= c; j ++) {
            a[j][x][y] += (s+j)%(c+1);
        }
    }
    for(int i = 1; i <= 100; i ++) {
        for(int j = 1; j <= 100; j ++) {
            for(int k = 0; k <= c; k ++) {
                a[k][i][j] += a[k][i-1][j]+a[k][i][j-1]-a[k][i-1][j-1];
            }
        }
    }
    while(q--) {
        int x1,x2,y1,y2,t;
        cin>>t>>x1>>y1>>x2>>y2;
        t%=(c+1);
        printf("%d\n",a[t][x2][y2]-a[t][x2][y1-1]-a[t][x1-1][y2]+a[t][x1-1][y1-1]);
    }
    return 0;
}
