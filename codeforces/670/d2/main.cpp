#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1e5+7;
ll a[maxn], b[maxn];

int main()
{
    ll n, k;
    while(~scanf("%lld%lld",&n,&k)){
        for(int i = 0; i < n; i++)scanf("%lld",&a[i]);
        for(int i = 0; i < n; i++)scanf("%lld",&b[i]);
        ll mid, sum, flag, l = 0, r = 2e9+10;
        while(l <= r){
            mid = (l + r) >> 1;
            sum = 0;flag = 1;
            for(int i = 0; i < n; i++){
                if(a[i]*mid > b[i]){
                    sum += a[i]*mid - b[i];
                }
                if(sum > k){
                    flag = 0;
                }
            }
            //cout << l << ' ' << r << endl;
            if(flag) l = mid + 1;
            else r = mid - 1;
        }
        printf("%lld\n",l - 1);
    }

    return 0;
}
