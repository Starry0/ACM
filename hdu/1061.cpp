#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 10;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, ans = 1;
        cin >> a;
        b = a;
        while(b) {
            if(b&1) ans = ans*a%mod;
            a = a*a % mod;
            b >>= 1;
        }
        cout << ans << endl;
    }
	return 0;
}
