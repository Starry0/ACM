#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3+10;
int f[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> f[i];
    for(int i = 1; i <= n; i ++) {
        if(i == f[f[f[i]]]) return 0*printf("YES\n");
    }
    printf("NO\n");
    return 0;
}
