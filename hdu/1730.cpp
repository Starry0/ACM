#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m)!= EOF) {
        int ans = 0, a, b;
        while(n--) {
            cin >> a >> b;
            ans ^= abs(a-b)-1;
        }
        if(ans) printf("I WIN!\n");
        else printf("BAD LUCK!\n");
    }
    return 0;
}
