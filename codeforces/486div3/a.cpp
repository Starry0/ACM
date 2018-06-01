#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[110];
set<int> st, st1;
int main() {
    int k, n;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int ans = 0;
    if(st.size() >= k) {
        printf("YES\n");
        for(int i = 1; i <= n; i ++) {
            if(!st1.count(a[i])) {
                printf("%d ",i);
                ans ++;
                st1.insert(a[i]);
            }
            if(ans == k) break;
        }
    }else printf("NO\n");
    return 0;
}
