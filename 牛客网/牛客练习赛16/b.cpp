#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], c[N*2];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= (n+1)/2; i ++) b[i] = i;
    for(int i = (n+1)/2+1; i <= n; i ++) b[i] = n-i+1;
    for(int i = 1; i <= n; i ++) c[a[i]-b[i]+N] ++;
    int MAX = 0;
    for(int i = 0; i < 2*N; i ++) {
        MAX = max(MAX,c[i]);
    }
    cout << n-MAX << endl;
    return 0;
}
