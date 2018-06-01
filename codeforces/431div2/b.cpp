#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1110;
int a[N], n;
bool check(double k) {
    bool flag = false;
    int cnt = -1;
    for(int i = 2; i <= n; i ++) {
        if(a[i]-a[1] == k*(i-1)) continue;
        flag = true;
        if(cnt < 0) cnt = i;
        else if(a[i]-a[cnt] != k*(i-cnt)) {
            flag = false;
            break;
        }
    }
    return flag;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    if(check(1.0*(a[2]-a[1])) || check(1.0*(a[3]-a[2])) || check(0.5*(a[3]-a[1]))) printf("Yes\n");
    else printf("No\n");
    return 0;
}
