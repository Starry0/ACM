#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int solve(int x) {
    for(int i = 1; ; i ++) {
        int y = x, ans = 0;
        while(y) {
            ans += min(i,y);
            y -= min(i,y);

            y -=
        }
    }
}
int main() {
    for(int i = 1; i <= 1010; i ++) {
        printf("%d %d\n",i,solve(i));
    }
    ll n;
    cin >> n;

    return 0;
}
