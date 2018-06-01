#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
std::vector<int> vs[N];
bool dfs(int u, int f){
    for(int i = 0;  i< vs[u].size(); i ++) {
        int v = vs[u][i];
        if(v == f) continue;
        if(!dfs(v,u)) return 1;
    }
    return 0;
}
int main( ){
    int t;
    cin >> t;
    while(t--) {
        int n, r;
        cin >> n >> r;
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            vs[u].push_back(v);
            vs[v].push_back(u);
        }
        if(dfs(r,-1))printf("Gen\n");
        else printf("Dui\n");
        for(int i = 0;  i< N; i++) vs[i].clear();
    }
    return 0;
}
