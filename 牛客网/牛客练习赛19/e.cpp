#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
bool vis[1010];
map<int,int> mp;
int a[101], b[101];
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            if(a[j] == b[i]) vis[j] = 1;
        }
    }
    for(int i = 1; i <= n; i ++) if(!vis[i]) ans++;
    cout << ans << endl;
    return 0;
}
