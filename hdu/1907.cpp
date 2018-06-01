#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m;
    cin >> t;
    while(t--) {
        cin >> m;
        int ans = 0, x, flag = 0;
        while(m--) {
            cin >> x;
            ans ^= x;
            if(x > 1) flag = 1;
        }
        if((ans&&!flag)||(!ans&&flag)) printf("Brother\n");
        else printf("John\n");
    }
    return 0;
}
