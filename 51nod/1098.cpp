#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int a[N];
int main() {
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < m; i ++) cin >> a[i];
    sort(a, a+m);
    double s = 0, sum = 0;
    for(int i = 0; i < n; i ++) sum += a[i];
    double k = sum/n;
    for(int i = 0; i < n; i ++) {
        s += 1.0*(a[i]-sum/n)*(a[i]-sum/n);
    }
    double ss = s;
    for(int i = n; i < m; i ++) {
        double x = 1.0*(a[i]-a[i-n])/n;
        s = s + (a[i]-k-x)*(a[i]-k-x)-(a[i-n]-k)*(a[i-n]-k)+2*x*(a[i-n]-k)+x*x*(n-1);
        ss = min(ss,s);
        k = x+k;
    }
    printf("%.0f\n",floor(ss));
    return 0;
}
