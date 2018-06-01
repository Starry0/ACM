#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, k, ans, res;
char v[10][10];
int a[10];
void dfs(int x){
    if(res == k){
        ans++;
        return;
    }
    if(x >= n) return;
    for(int i = 0; i < n; i ++){
        if(!a[i] && v[x][i] == '#'){
            a[i] = 1;
            res ++;
            dfs(x+1);
            res--;
            a[i] = 0;
        }
    }
    dfs(x+1);
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        if(n == -1 && k == -1)break;
        ans = res = 0;
        for(int i = 0; i < n; i ++) cin >> v[i];
        dfs(0);
        cout << ans << endl;
    }
}
