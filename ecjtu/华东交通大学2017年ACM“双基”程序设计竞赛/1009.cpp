#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,ll>mp;
const int N=1e5+10;
int n,j,t,a,q;
int ans[N],ls[N],vis[N];
void init(){
    mp.clear();
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> ans[i];
    for(int i = 1;i <= n;i ++) {
        for(vis[i] = ans[i],j = ls[i]=i; j; j=ls[j]-1){
            vis[j]=__gcd(vis[j],ans[i]);
        while(ls[j] > 1&& __gcd(ans[i], vis[ls[j]-1]) == __gcd(ans[i], vis[j]))
            ls[j] = ls[ls[j]-1];
        mp[vis[j]] += j-ls[j]+1;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        init();
        cin >> q;
        while(q--){
            cin >> a;
            ll len = n*(n+1)/2;
            printf("%lld\n",len-mp[a]);
        }
    }
    return 0;
}