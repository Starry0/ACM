#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n, k, x, cnt;
map<int,int> mp;
struct Nod{
    int num, id;
}e[N];
bool ok(int m) {
    int ans = 0;
    for(int i = 0; i < cnt; i ++) {
        ans += e[i].num/m;
    }
    return ans >= k;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        mp[x]++;
    }
    cnt = 0;
    for(auto m : mp) {
        e[cnt].id = m.first;
        e[cnt++].num = m.second;
    }
    // for(int i = 0; i < cnt; i ++) printf("%d %d\n",e[i].id,e[i].num);
    int MAX = 0, l = 1, r = n/k;
    while(l <= r) {
        int m = (l+r)>>1;
        if(ok(m)) {
            MAX = max(MAX, m);
            l = m+1;
        } else r = m-1;
    }
    int ans = 0;
    for(int i = 0; i < cnt; i ++) {
        for(int j = 0; j < e[i].num/MAX; j ++) {
            if(ans == k) break;
            printf("%d%c",e[i].id," \n"[ans==k-1]);
            ans ++;
        }
    }
    return 0;
}
