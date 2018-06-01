#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[110],b[110],vis[110];
int main(){
    int n,m,flag=1;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) cin >> b[i];
    for(int i = 0; i < m-1; i ++){
        int cnt = b[i+1] - b[i];
        if(cnt > n) cnt %= n;
        else if(cnt <= 0) cnt += n;
        if(a[b[i]] != 0 && cnt != a[b[i]] || a[b[i]] == 0 && vis[cnt]){
            flag = 0;
            break;
        }
        a[b[i]] = cnt;
        vis[cnt] = 1;
    }
    if(!flag){
        cout << -1 << endl;
    }else{
        int k = 1;
        for(int i = 1; i <= n; i ++){
            if(!a[i]){
                while(vis[k])k++;
                a[i] = k;
                k++;
            }
        }
        for(int i = 1; i <= n; i ++){
            if(i == 1)cout << a[i];
            else cout << ' ' << a[i];
        }
        cout << endl;
    }
    return 0;
}
