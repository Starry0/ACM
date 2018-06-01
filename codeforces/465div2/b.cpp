#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[N];
int main() {
    int n, ans = 0, flag = -1, x = 0, y = 0;
    cin >> n >> str;
    for(int i = 0; i < n; i ++) {
        if(str[i] == 'U') {
            y++;
            if(i == 0) flag = 1;
            if(y > x && flag == 2) {
                ans++;
                flag = 1;
            }
        } else{
            x++;
            if(i == 0) flag = 2;
            if(x > y && flag == 1) {
                ans++;
                flag = 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
