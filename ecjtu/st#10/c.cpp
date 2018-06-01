#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#define ll long long
using namespace std;
struct Nod{
    int c,q;
}t;
map<string,int>mp;
vector<Nod> vs[1010];
int a[1010], T, n, k, b;
bool check(int m) {
    ll x = 0;
    for(int i = 0; i < k; i ++){
        int mins = 0x3f3f3f3f;
        for(int j = 0; j < vs[i].size(); j ++) {
            if(vs[i][j].q >= m){
                mins = min(mins,vs[i][j].c);
            }
        }
        if(mins == 0x3f3f3f3f)return false;
        x += mins;
        if(x > b) return false;
    }
    return x <= b;
}
int main() {
    std::ios::sync_with_stdio(false);
    scanf("%d",&T);
    while(T--) {
        mp.clear();
        char ss[100], s[100];
        string sss;
        k = 0;
        scanf("%d%d",&n,&b);
        for(int i = 0; i <= n; i ++)vs[i].clear();
        for(int i = 0; i < n; i ++){
            scanf("%s%s%d%d",ss,s,&t.c,&t.q);
            sss = ss;a[i] = t.q;
            if(!mp.count(sss)){
                mp[sss] = k++;
            }
            vs[mp[sss]].push_back(t);
        }
        sort(a,a+n);
        int l = 0, r = n-1,ans = 0;
        while(l <= r) {
            int m = (l+r)>>1;
            if(check(a[m])){
                ans = a[m];
                l=m+1;
            }
            else r = m-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
