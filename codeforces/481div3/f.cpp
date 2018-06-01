#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int a[N], b[N], n, k;
vector<int> vs[N];
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for(int i = 1, u, v; i <= k; i ++) {
        cin >> u >> v;
        vs[u-1].push_back(v-1);
        vs[v-1].push_back(u-1);
    }
    for(int i = 0; i < n; i ++) {
        int id = lower_bound(b,b+n,a[i])-b;
        for(int j = 0; j < vs[i].size(); j ++) {
            if(a[vs[i][j]] < a[i]) id--;
        }
        printf("%d ",id);
    }
    printf("\n");
    return 0;
}
