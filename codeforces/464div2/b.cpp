#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll n, k, a[N];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= k; i ++) cin >> a[i];
    ll id, MIN = 1e18;
    for(int i = 1; i <= k; i ++) {
        if(n-n/a[i]*a[i] < MIN) {
            id = i;
            MIN = n-n/a[i]*a[i];
        }
    }
    cout << id << ' ' << n/a[id] << endl;
    return 0;
}
