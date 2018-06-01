#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main() {
    ll a, p, ans = 0;
    cin >> p >> a;
    for(ll i = 0; i <= p; i ++) {
        if(i*i%p == a) {
            printf("%lld ",i);
            ans++;
        }
    }
    if(ans == 0) printf("No Solution\n");
    else printf("\n");
    return 0;
}
