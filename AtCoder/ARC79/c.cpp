#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[55];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    ll k = 0;
    while(1) {
        ll MAX = -1,id;
        for(int i = 1; i <= n; i ++) {
            if(MAX < a[i]){
                MAX = a[i];
                id = i;
            }
        }
        if(MAX < n)break;
        for(int i = 1; i <= n; i ++) {
            if(i == id) a[i] %= n;
            else a[i] += MAX/n;
        }
        k += MAX / n;
    }
    printf("%lld\n",k);
    return 0;
}
