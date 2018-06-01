#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], t, n, m, xi, ti;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) a[i] = i-1;
        for(int i = 0; i < m; i ++) {
            cin >> xi >> ti;
            if(ti >= xi-1) continue;
            if(a[xi] > ti) {
                int j = 0;
                while(xi+j <= n) {
                    if(a[xi+j] > ti+j) {
                        a[xi+j] = ti+j;
                    }
                    j++;
                }
                j = 1;
                while(xi-j >= 1) {
                    if(a[xi-j] > ti+j) {
                        a[xi-j] = ti+j;
                    }
                    j++;
                }
            }
        }
        int MAX = -1;
        for(int i = 1; i <= n; i ++) MAX = max(MAX, a[i]);
        printf("%d\n",MAX);
    }
    return 0;
}
