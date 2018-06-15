#include <bits/stdc++.h>
using namespace std;
int a[10], n;
int main() {
    int MIN = 1e6, cnt;
    cin >> n;
    for(int i = 1; i < 10; i ++) {
        cin >> a[i];
        if(a[i] <= MIN) {
            MIN = a[i];
            cnt = i;
        }
    }
    int ans = n / MIN;
    if(ans == 0) return 0*printf("-1\n");
    n %= MIN;
    for(int i = 9; i >= 1; i --) {
        if(i <= cnt) break;
        int num = n / (a[i]-MIN);
        n -= num*(a[i]-MIN);
        while(num) {
            printf("%d",i);
            ans--;num--;
        }
    }
    for(int i = 1; i <= ans; i ++) printf("%d",cnt);
    printf("\n");
    return 0;
}
