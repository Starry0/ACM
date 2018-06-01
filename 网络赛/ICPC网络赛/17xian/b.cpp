#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9+7;
using namespace std;
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b){
        x = 1; y = 0;
    }else{
        exgcd(b, a%b, y, x);
        y -= x*(a/b);
    }
}
ll inv(ll a, ll n) {
    ll x, y;
    exgcd(a, n, x, y);
    return (x+n)%n;
}
int main() {
    int t, q, p, k;
    // printf("%lld\n",5*inv(9,mod));   
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &p, &q, &k);
        for(int i = 0; i <= k; i += 2) {
            
        }
    }
    return 0;
}