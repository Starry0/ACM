#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowvit(x) x&(-x)
#define N 1010
#define M 110
using namespace std;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b): a;
}
int main() {
    ios::sync_with_stdio(false);
    ll a, b;
    int k = 1;
    while(cin>>a>>b) {
        if(a==0&&b==0)break;
        ll n = (a+1)*(b+1);
        ll sum1 = n*(n-1)*(n-2)/6;
        ll sum2 = (a+1)*(b+1)*(b)*(b-1)/6 + (b+1)*(a+1)*a*(a-1)/6;
        ll sum3 = 0;
        for(int i = 2; i <= a; i ++) {
            for(int j = 2; j <= b; j ++) {
                sum3 += (gcd(i,j)-1)*(a-i+1)*(b-j+1);
            }
        }
        // printf("%lld++\n",sum3);
        ll ans = sum1 - sum2 - 2*sum3;
        printf("Case %d: %lld\n",k++,ans);
    }
    return 0;
}
