#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool a[11], b[22], c[22], vis[11][11];
int d[11];
int ans = 0, n;
void dfs(int x){
    if(x == n){
        ans ++;
        return;
    }
    for(int i = 0; i < n; i ++){
        if(a[i] || b[x+i] || c[x-i+n])continue;
        a[i] = b[x+i] = c[x-i+n] = vis[x][i] = true;
        dfs(x+1);
        a[i] = b[x+i] = c[x-i+n] = vis[x][i] = false;
    }
}
int main(){
    for(int i = 1; i < 11; i ++){
        memset(a,false,sizeof(a));
        memset(b,false,sizeof(b));
        memset(c,false,sizeof(c));
        memset(vis,false,sizeof(vis));
        ans = 0;
        n = i;
        dfs(0);
        d[i] = ans;
    }
    while(~scanf("%d",&n)&&n){
        cout << d[n] << endl;
    }
}
