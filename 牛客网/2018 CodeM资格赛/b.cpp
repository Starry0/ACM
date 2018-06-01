#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int n, m, k, index, MAX = -INF, q, p;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i ++) {
        cin >> q >> p;
        if(MAX <= m*q+p*(n-m)) {
            MAX = m*q+p*(n-m);
            index = i;
        }
    }
    for(int i = 1; i <= k; i ++) printf("%d%c",i==index?n:0," \n"[i==k]);
    return 0;
}
