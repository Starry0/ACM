#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;

int main() {
    int a, b;
    while(cin >> a >> b) {
        if(a == -1 && b == -1) break;
        if(a == 0 && b == 0) printf("1\n");
        else if (a == 0 && b == 1) printf("owatta\n");
        else {
            int ans = 0;
            if(b == 0) a = -a;
            for(int i = 0; i <= 21; i ++) {
                if(i == abs(a)) continue;
                if(i == 0) {
                    ans++;
                } else {
                    if(a+i<0)ans++;
                    if(a-i<0)ans++;
                }
                // printf("%d %d\n",i,ans);
            }
            // printf("%d\n",ans);
            if(ans==0)printf("owatta\n");
            else if(ans == 42) printf("1\n");
            else {
                printf("%d/%d\n",ans/__gcd(ans,42),42/__gcd(ans,42));
            }
        }
    }
    return 0;
}
