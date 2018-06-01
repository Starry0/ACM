#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector <int> v[maxn];
bool vis[maxn];
int stk[maxn], res;
void dfs(int x){
    for(int i = 0; i < v[x].size(); i++){
        int tmp = v[x][i];
        if(vis[tmp])continue;
        stk[++res] = tmp;vis[tmp] = 1;
        dfs(tmp);return;
    }
}
int main(){
    int n, m, x, y;
    cin >> n >> m;
    while(m--){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    stk[res = 1] = 1;
    vis[1] = 1;
    dfs(1);
    cout << res << endl;
    for(int i = 1; i < res; i++)printf("%d ",stk[i]);cout << stk[res] <<endl;
    cout << endl;
    return 0;
}
