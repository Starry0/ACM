#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll a[N], sum[N];
int main() {
    int q, n = 0, t, k = 1;
    cin >> q;
    while(q--) {
        cin >> t;
        if(t == 1) {
            cin >> a[++n];
            sum[n] = sum[n-1] + a[n];
        }else {
            while(k<n && (a[n]+sum[k+1])*(k+1)<(k+2)*(a[n]+sum[k])) k++;
            printf("%.10lf\n",a[n]-1.0*(a[n]+sum[k])/(k+1));
        }
    }
    return 0;
}
