#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    int x = n%210;
    ll ans = 0;
    for(int i = 1; i <= x; i ++) {
        if(i%2==0 || i%3==0 || i%5==0 || i%7== 0)continue;
        ans++;
    }
    cout << n/210*48+ans<<endl;
    // ll ans = n;
    // ans -= n/2 + n/3 + n/5 + n/7;
    // ans += n/6 + n/10 + n/14 + n/15 + n/21 + n/35;
    // ans -= n/30 + n/42 + n/70 + n/105; //这四个是从2 3 5 7 总取三个组成的
    // ans += n/210;
    // cout << ans << endl;
    return 0;
}
