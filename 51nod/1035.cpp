#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int cal(int x) {
    mp.clear();
    mp[1] = 1;
    int ans = 0, a = 1, tmp;
    while(a) {
        while(a < x) {
            ans++;
            a *= 10;
        }
        a -= a/x*x;
        if(mp[a]) break;
        mp[a] ++;
    }
    return ans;
}
int main() {
    // cout << cal(12) << endl;
    int n, MAX = 6, index = 7;
    cin >> n;
    for(int i = 10; i <= n; i ++) {
        int ans = cal(i);
        if(ans > MAX) {
            MAX = ans;
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}
