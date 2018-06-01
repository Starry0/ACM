#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char str[N];
int len;
int ok(int l, int r) {
    int len1 = r-l+1, ans = 0;
    for(int i = 0; i <= len-len1; i ++) {
        if(str[i] == str[l]) {
            int j;
            for(j = 0; j < len1; j ++) {
                if(str[i+j] == str[j+l]) continue;
                else break;
            }
            if(j == len1) {
                ans++;
                i = i+len1-1;

            }
        }
    }
    return ans;
}
int main() {
    cin >> str;
    len = strlen(str);
    int ans = len;
    for(int i = 0; i < len; i ++) {
        for(int j = i+1; j < len; j ++) {
            int x = ok(i,j);
            // printf("%d %d %d\n",i,j,x );
            ans = min(ans,len+j-i+1-x*(j-i));
        }
    }
    cout << ans << endl;
    return 0;
}
// WN EEN W EEN EEN E
// WNMWMME
