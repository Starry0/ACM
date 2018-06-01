#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
set<int> st[2];
bool vis[N];
int x, n, last, ans;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        last = 1 - last;
        st[last].clear();
        set<int> :: iterator it = st[1-last].begin();
        for(; it != st[1-last].end(); ++ it) {
            int y = (*it)|x;
            vis[y] = true;
            st[last].insert(y);
        }
        st[last].insert(x);
        vis[x] = true;
    }
    for(int i = 0; i < N; i ++) if(vis[i]) ans++;
    cout << ans << endl;
    return 0;
}
