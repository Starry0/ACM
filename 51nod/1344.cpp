#include <iostream>
#include <stdio.h>
#include <string>
#define ll long long
using namespace std;

int main() {
    int n;
    ll ans = 0, ans1 = 0, x;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) {
        scanf("%lld", &x);
        if(x < 0) {
            if(ans1 + x< 0) {
                ans += -ans1 - x;
                ans1 = 0;
            }else ans1 += x;
        }else ans1 += x;
    }
    scanf("%lld",&x);
    printf("%lld\n",ans);
    return 0;
}
