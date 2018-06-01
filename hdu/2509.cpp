#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    while(cin >> m) {
        int ans = 0, x, flag = 0;
        while(m--) {
            cin >> x;
            ans ^= x;
            if(x > 1) flag = 1;
        }
        if((ans&&flag)||(!ans&&!flag)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
