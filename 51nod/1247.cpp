#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, x, y;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >>b >> x >> y;
        if(__gcd(a,b) == __gcd(x,y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
