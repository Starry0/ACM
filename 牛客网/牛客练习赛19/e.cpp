#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
bool vis[1010];
map<int,int> mp;
int main() {
    int n, a, b, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a >> b;
        mp[b]++;
        if(i != b) vis[b] = 1;
    }
    for(int i = 1; i <= 1000; i ++)
        if(vis[i]) ans += mp[i];
    cout << n-ans << endl;
    return 0;
}
