#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int main() {
    ll n, q, x;
    cin >> n >> q;
    while(q--) {
        scanf("%lld",&x);
        while(x%2==0) x = n+x/2;
		cout << (x+1)/2 << endl;
    }
    return 0;
}
