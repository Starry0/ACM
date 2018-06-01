#include <bits/stdc++.h>
using namespace std;
int a[10], n;
void dfs(int sum, int ans, int pre){
    if(sum > n) return ;
    if(sum == n && ans != 1) {
        printf("%d",a[1]);
        for(int i = 2; i <= ans; i ++) {
            printf("+%d",a[i]);
        }printf("\n");
    }
    for(int i = pre; i <= n; i ++) {
        a[ans+1] = i;
        dfs(sum+i, ans+1, i);
    }
}
int main() {
    cin >> n;
    dfs(0,0,1);
    return 0;
}
