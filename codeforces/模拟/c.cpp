#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4+10;
int a[maxn];
int fa[maxn];
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
void uni(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a!=b) fa[a] = b;
}
int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        fa[i] = i;
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= n; i ++){
        uni(i,a[i]);
    }
    for(int i = 1; i <= n; i ++){
        if(fa[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}
