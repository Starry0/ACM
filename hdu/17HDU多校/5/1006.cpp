#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        if(m <= n-1) {
            ll x = n-1-m;
            printf("%lld\n",2*m*m+x*n*m+x*n*n);
        } else if(m >= n*(n-1)/2) {
            printf("%lld\n",n*(n-1));
        } else {
            ll x = m - n + 1;
            printf("%lld\n",2*(n-1)*(n-1) - 2 * x);
        }
    }
    return 0;
}
