#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, k;
    while(cin >> m, m) {
        int ans = 0;
        while(m--) {
            cin >> k;
            ans ^= k;
        }
        if(ans) printf("Rabbit Win!\n");
        else printf("Grass Win!\n");
    }
    return 0;
}
