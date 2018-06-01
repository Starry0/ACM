#include <bits/stdc++.h>
using namespace std;
int a[22];
int main() {
    int n, k;
    set<int> st[2];
    set<int> ::iterator it;
    cin >> n >> k;
    int last = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        last = 1 - last;
        it = st[1-last].begin();
        for(; it != st[1-last].end(); ++it) {
            if((*it)+a[i] < k) {
                st[last].insert((*it)+a[i]);
            } else if((*it)+a[i] == k) return 0*printf("Yes\n");
            st[last].insert((*it));
        }
        st[last].insert(a[i]);
    }
    if(st[last].count(k)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
