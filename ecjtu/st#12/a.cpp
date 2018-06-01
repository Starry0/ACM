#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define N 10010
#define M 110
using namespace std;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    int n;
    bool flag = false;
    while(cin>>n) {
        if(n == 0) break;
        memset(a,0,sizeof(a));
        for(int i = 1; i <= n; i ++) cin >> a[i];
        sort(a+1,a+n+1);
        int k = -1, ans = 1;
        for(int i = 2; i <= n; i ++) {
            if(a[i] == a[i-1]) {
                ans++;
                if(i == n && ans > k) k = ans;
            }else {
                if(ans > k) k = ans;
                ans = 1;
            }
        }
        if(flag) printf("\n");
        else flag = true;
        printf("%d\n",k);
        for(int i = 1; i <= k; i ++) {
            bool flag1 = false;
            for(int j = i; j <= n; j += k) {
                if(!flag1) {
                    printf("%d",a[j]);
                    flag1 = true;
                }else printf(" %d",a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
