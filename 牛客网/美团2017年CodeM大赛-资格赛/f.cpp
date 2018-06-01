#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
int main() {
    int m, x;
    string ch;
    while(cin>>m){
        memset(vis, 0, sizeof(vis));
        int ans = 0, flag = -1;
        map<int,int> mp;
        for(int i = 1; i <= m; i ++) {
            cin >> ch;
            if(ch == "?" || ch == "？") {
                ans++;
                continue;
            }
            cin >> x;
            if(flag != -1) continue;
            if(ch[0] == 'I') {
                if(mp[x] == 1) {
                    flag = i;
                } else mp[x] = 1;
            } else if(ch[0] == 'O') {
                if(mp[x] != 1) {
                    if(ans != 0) ans--;
                    else {
                        flag = i;
                    }
                }
            }
        }
        cout << flag << endl;
    }
    return 0;
}
