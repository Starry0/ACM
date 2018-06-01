#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const int MAX = 5e4+5;
int num, n, a[MAX];
ll ans;
void dfs(int now) {
    int j;
    int temp = a[now-1] + a[now];
    ans += (ll)temp;
    for(int i = now; i < num -1; i ++) a[i] = a[i+1];
    num--;
    for(j = now-1; j > 0&& a[j-1] < temp; j --) a[j] = a[j-1];
    a[j] = temp;
    while(j >= 2 && a[j-2] <= a[j]){
        int d = num - j;
        dfs(j-1);
        j = num-d;
    }
}
int main() {
    while(scanf("%d",&n)&&n){
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        num = 1;
        ans = 0;
        for(int i = 1; i < n; i ++) {
            a[num++] = a[i];
            while(num >= 3 && a[num-3] <= a[num-1]) dfs(num-2);
        }
        while(num > 1) dfs(num-1);
        printf("%lld\n",ans);
        memset(a,0,sizeof(a));        
    }
    return 0;
}
