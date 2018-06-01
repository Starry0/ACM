#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int m, kk = 1;
    while(scanf("%d",&m)!=EOF) {
        ll k = m*log10(2);
        printf("Case #%d: %lld\n",kk++,k);
    }
    return 0;
}
