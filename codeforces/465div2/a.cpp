#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n/2; i ++) {
        if((n-i)%i==0) ans++;
    }
    cout << ans << endl;
    return 0;
}
