#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[30], vis[30];
bool prime(int x){
    bool flag = true;
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }
    if(x >= 2 && flag)
        return true;
    else return false;
}
void dfs(int n,int m){
    if(n >= m && prime(a[0] + a[m-1])){
        for(int i = 0; i < m; i ++){
          if(i) cout<<' ';
            cout << a[i];
        }
        cout << endl;
    }
    for(int i = 1; i <= m; i ++){
        if(vis[i] == 0){
            a[n] = i;
            if(n==0 || prime(i+a[n-1])){
                vis[i] = 1;
                dfs(n+1,m);
                vis[i] = 0;
            }
        }
    }
}

int main(){
    int n;
    int ans = 1;
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));memset(vis,0,sizeof(vis));
        a[0] = 1;vis[1] = 1;
        printf("Case %d:\n",ans++);
        dfs(1,n);
        cout << endl;
    }
}
