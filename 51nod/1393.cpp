#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000010;
char str[N];
int main() {
    map<int,int> mp;
    cin >> str+1;
    int ans = 0, cnt = 0;
    for(int i = 1; str[i]; i ++) {
        if(str[i]-'0') cnt++;
        else cnt--;
        if(cnt == 0) ans = i;
        else{
            if(mp[cnt]) ans = max(ans,i-mp[cnt]);
            else mp[cnt] = i;
            // cout << mp[cnt] << ' ' << cnt << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
