#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        if(x == 25) ans += x;
        if(x == 50) {
            if(ans < 25) return 0*printf("NO\n");
            ans -= 25;
        } else if(x == 100) {
            if(ans < 75) return 0*printf("NO\n");
            ans -= 75;
        }
    }
    printf("YES\n");
    return 0;
}
