#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int main(int argc, char const *argv[]) {
    int n,q, tmp = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> ans[i];
        tmp^= ans[i];
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        tmp ^= ans[x];
        tmp ^= y;
        ans[x] = y;
        if(tmp) cout << "Kan\n";
        else cout << "Li\n";
    }
    return 0;
}
