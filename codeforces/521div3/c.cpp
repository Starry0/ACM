#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll a[N], n;
vector<ll> v;
int main() {
    cin >> n;
    ll sum = 0;
    priority_queue<ll> que;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum += a[i], que.push(a[i]);
    int ans = 0;
    // cout << sum << ' ' << que.top() << endl;
    for(int i = 1; i <= n; i ++) {
        if(que.top() == a[i]) {
            que.pop();
            sum -= a[i];
            if(sum == que.top()*2) ans++, v.push_back(i);
            sum += a[i];
            que.push(a[i]);
        } else {
            sum -= a[i];
            if(sum == que.top()*2) ans++, v.push_back(i);
            sum += a[i];
        }
    }
    printf("%d\n",ans);
    for(auto x : v) printf("%lld ", x);printf("\n");
    return 0;
}
