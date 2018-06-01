#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int> mp,mp1;
int main(){
    int n, m, a, b, ans = 0;
    string s[1010],ss[1010];
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
    }
    for(int i = 1; i <= m; i ++){
        cin >> ss[i];
    }
    for(int i = 1; i <= n; i ++) {
        mp[s[i]] = 1;
    }
    for(int i = 1; i <= m; i ++){
        if(mp[ss[i]])ans++;
    }
    a = n- (ans/2); b = m - (ans - ans /2);
    //cout << a << ' ' << b << ' ' << ans << endl;
    if(a > b) puts("YES");
    else puts("No");
    return 0;
}
