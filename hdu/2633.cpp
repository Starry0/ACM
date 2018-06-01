/*
这题还没做出来。可能有细节没考虑
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        int ans = 0, cnt = 0, flag = 0, cnt1 = 0;
        for(int i = 0; i < n; i ++) {
            cin >> x;
            if(cnt1 == 4) continue;
            if(!flag && x < 90) {
                cnt ++;
            } else if(!flag && x >= 90) {
                if(cnt > 0) ans += cnt;
                else ans += 1;
                cnt = 0;
                cnt1 = flag = 1;
            } else if(flag && x < 80) {
                cnt++;
            } else if(flag && x > 80) {
                if(cnt > 0) ans += cnt;
                else ans += 1;
                cnt = 0;
                cnt1 ++;
            }
        }
        if(cnt1 == 4 && ans < 24) printf("It takes about %d months to get a driving license.\n",ans);
        else printf("He failed to get a driving license within 2 years! \n");
    }
    return 0;
}
