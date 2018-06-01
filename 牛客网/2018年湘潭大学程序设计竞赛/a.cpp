#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll d1, d2, h1, h2, m1, m2, s1, s2;
        scanf("%lldday%lld:%lld:%lld",&d1,&h1,&m1,&s1);
        scanf("%lldday%lld:%lld:%lld",&d2,&h2,&m2,&s2);
        printf("%lld\n",(s2-s1)+(m2-m1)*60+(h2-h1)*3600+(d2-d1)*86400);
    }
    return 0;
}
