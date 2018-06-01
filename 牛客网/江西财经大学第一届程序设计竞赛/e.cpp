#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000010;
int ans[N], id, t, m;
bool vis[N], del[N], vis1[N];
string s;
stack<int> st;
queue<int> que1, que2;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> m;
        while(m--) {
            cin >> s >> id;
            if(s == "recv") {
                st.push(id);
                ans[id]++;
                del[id] = false;
            }else if(s == "up") {
                vis[id] = true;
            }else if(s == "view") {
                ans[id] = 0;
            } else if(s == "down") {
                vis[id] = false;
            } else if(s == "delete") {
                del[id] = true;
                ans[id] = 0;
                vis[id] = false;
            }
        }
        while(st.size()) {
            id = st.top();
            st.pop();
            if(vis1[id]) continue;
            if(vis[id] && !del[id]) que1.push(id);
            if(!vis[id] && !del[id]) que2.push(id);
            vis1[id] = true;
        }
        while(que1.size()) {
            id = que1.front();
            que1.pop();
            printf("%06d %d\n",id,ans[id]);
        }
        while(que2.size()) {
            id = que2.front();
            que2.pop();
            printf("%06d %d\n",id,ans[id]);
        }
        memset(vis,0,sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        memset(del,0,sizeof(del));
        memset(ans,0,sizeof(ans));
        printf("\n");
    }
    return 0;
}
