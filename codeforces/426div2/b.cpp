#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+10;
char str[MAX];
bool vis[30];
int main() {
    int n, k;
    cin>>n>>k;
    scanf("%s",str);
    set<int> st;
    for(int i = n-1; i >= 0; i --){
        if(!vis[str[i]-'A']){
            st.insert(i);
            vis[str[i]-'A'] = true;
        }
    }
    int ans = 0,maxn = -1;
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < n; i ++) {
        if(!vis[str[i]-'A']){
            ans++;
            if(ans > maxn)maxn = ans;
            if(!st.count(i))
                vis[str[i]-'A'] = true;
            else ans--;
        }else {
            if(st.count(i)){
                ans--;
            }
        }
    }
    printf("%s\n",maxn>k?"YES":"NO");
    return 0;
}
