#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const ll Mod = 1e9+7;
const int MAX = 100010;
ll a[MAX], b[MAX];
int main() {
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n) {
        for(int i = 1; i <= n; i ++) cin>>a[i];
        for(int i = 1; i <= n; i ++) cin>>b[i];
        ll ans = 1;
        for(int i = 1; i <= n; i ++) {
            ans *= (a[i]+b[i]);
            ans %= Mod;
        }
        ll x = 1, y = 1;
        for(int i = 1; i <= n; i ++) {
            x *= a[i];
            x %= Mod;
        }
        for(int i = 1; i <= n; i ++) {
            y *= b[i];
            y %= Mod;
        }
        cout << (ans+Mod-x-y+Mod)%Mod << endl;
    }
    return 0;
}


#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 100010;
const int mod = 1e9+7;
ll a[MAX], b[MAX];
int main() {
    int n;
    std::ios::sync_with_stdio(false);
    while(cin>>n) {
        ll ans = 1;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            ans *= a[i];
            ans %= mod;
        }
        ll cnt = 1;
        for(int i = 1; i <= n; i ++) {
            cin >> b[i];
            cnt *= b[i];
            cnt %= mod;
        }
        ll sum = 1;
        for(int i = 1; i <= n; i ++) {
            sum *= (a[i]+b[i]);
            sum %= mod;
        }
        cout << (sum+mod-ans+mod-cnt)%mod << endl;
    }
    return 0;
}
