#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int cnt = 0;
        while(s[i] =='x') {
            cnt++;
            i++;
        }
        if(cnt >= 3)ans += cnt-2;
    }
    cout << ans << endl;
    return 0;
}
