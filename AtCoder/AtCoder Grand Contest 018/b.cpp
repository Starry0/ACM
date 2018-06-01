#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[330][330];
int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    int ans = n;
    
    return 0;
}
