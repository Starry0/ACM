#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[55];
int main() {
    ll n;
    cin >> n;
    for(int i = 1; i <= 50; i ++) {
        a[i] = n/50LL + i - 1;
    }
    n %= 50;
    for(int i = 1; 1LL*i <= n; i ++) {
        for(int j = 1; j <= 50; j ++)
            a[j]--;
        a[i] += 51;
    }
    cout << 50 << endl;
    for(int i = 1; i < 50; i ++)cout << a[i] << ' ';
    cout << a[50] << endl;
    return 0;
}
