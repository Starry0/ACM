#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    int ans = n/k;
    if(ans%2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
