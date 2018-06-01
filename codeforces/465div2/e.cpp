#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
char str[N];
int p, m, len, MAX = -1e8, ans = 0;
stack<int> st;
void dfs(int x) {
    if(x == len) {
        MAX = max(MAX,ans);
        return;
    }
    for(int i = x; i < len; i ++) {
        if(str[i] == '(') {
            st.push('(')
        } else{
            
        }
    }
}
int main() {
    cin >> str >> p >> m;
    len = strlen(str);
    dfs(0);
    return 0;
}
