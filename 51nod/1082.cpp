#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#define ll long long
using namespace std;
const int N = 1e6+10;
bool vis[N];
ll ans[N];
void init() {
    for(int i = 1; i < N; i ++) {
        if(i%7 == 0) {
            vis[i] = false;
            continue;
        }
        int x = i;
        vis[i] = true;
        while(x) {
            if(x%10 == 7){
                vis[i] = false;
                break;
            }
            x /= 10;
        }
    }
    for(ll i = 1; i < N; i ++) {
        ans[i] = ans[i-1] + (vis[i]? i*i: 0);
    }
}
int main() {
    init();
    int t, n;
    cin >> t;
    while(t--) {
        // cin >> n;
        scanf("%d", &n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
