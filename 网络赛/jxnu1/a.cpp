#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
const int MAX = 1e4+10;
const int MOD = 1e9+7;
int vis[10010],b[MAX*10],k;
void init() {
    for(int i = 2; i < 10000; i ++) {
        if(!vis[i]){
            b[++k] = i;
            for(int j = i+i; j < 10000; j += i)
                vis[j] = 1;
        }
    }
}
int main() {
    int n,q;
    std::ios::sync_with_stdio(false);
    init();
    cin>>n>>q;
    set<ll> st;
    for(int i = 1; i <= n; i ++) {
        ll ans = 1;
        for(int j = 1; j <= i; j ++) {
            ans = 1LL*b[j]*ans%MOD;
        }
        st.insert(ans);
    }
    ll num;
    while(q--) {
        cin>>num;
        if(st.count(num)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
