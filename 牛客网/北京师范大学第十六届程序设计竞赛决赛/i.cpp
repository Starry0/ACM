#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000010;
char str[N];
ll a[N];
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k, ans = 0;
        cin >> n >> k;
        cin >> str+1;
        for(int i = 1; i <= n; i ++) {
            if(str[i] == 'D') {
                a[i] = 1;
                ans ++;
            }
            a[i] += a[i-1];
        }
        if(ans*(n-ans) < k) printf("-1\n");
        else{
            ll cnt = 0;
            for(int i = 1; i <= n; i ++) {
                cnt += str[i]=='M'?a[i]:0;
            }
            cout << abs(k-cnt) << endl;
        }
        memset(a,0,sizeof(a));
        memset(str,0,sizeof(str));
    }
    return 0;
}
