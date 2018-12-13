#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int x, n, a[N], cnt;
map<int,int> mp;
bool vis[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x, mp[x]++;
    for(auto m : mp) a[cnt++] = m.second;
    sort(a,a+cnt);
    // for(int i = 0; i < cnt; i ++) printf("%d ",a[i]);printf("\n");
    // printf("%d\n",lower_bound(a,a+cnt,9)-a);
    int MAX = 0;
    for(int i = 1; i <= a[cnt-1]; i ++) {
        int x = i, ans = 0, l = 0, r = cnt;
        while(1) {
            int id = lower_bound(a+l,a+cnt,x)-a;
            if(id >= cnt) break;
            ans += x;
            // printf("%d ",x);
            l = id+1;
            x *= 2;
        }
        // printf("\n");
        MAX = max(MAX, ans);
    }
    printf("%d\n",MAX);
    return 0;
}
