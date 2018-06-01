#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2000010;
ll a[N];
int main() {
    for(int i = 1; i <= N; i ++) a[i] = a[i-1] + i;
    int m, j = 0;
    cin >> m;
    for(int i = 1; i < m; i ++) {
        for(; j < m; j ++) {
            ll x = a[i] - a[j];
            if(x == m) printf("%d %d\n",j+1,i);
            else if(x < m) break;
        }
    }
    return 0;
}
