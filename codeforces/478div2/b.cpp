#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
ll a[15], b[15];
void init() {
    for(int i = 0; i < 14; i ++) b[i] = a[i];
}
int main() {
    for(int i = 0; i < 14; i ++) {
        cin >> a[i];
    }
    ll MAX = 0;
    for(int i = 0; i < 14; i ++) {
        init();
        ll x = b[i];
        b[i] = 0;
        for(int j = 0; j < 14; j ++) {
            b[j] += x/14;
        }
        x = x%14;
        for(int j = 0; j < x; j ++) {
            b[(i+j+1)%14] ++;
        }
        ll cnt = 0;
        for(int j = 0; j < 14; j ++) {
            if(b[j]%2==0) cnt += b[j];
        }
        MAX = max(MAX, cnt);
    }
    // for(int i = 0; i < 14; i ++) printf("%lld ",b[i]);printf("\n");
    cout << MAX << endl;
    return 0;
}
