/*
用printf会超时,而用cout就不会。
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
char str[10];
int ans1[10], ans[10];
bool vis[10];
int len,k;
set<string> st;
inline void dfs(int x){
    if(x == len){
        for(int i = 0; i < len; i ++){
            cout << ans1[i];
        }
        cout << endl;
        return ;
    }
    for(int i = 0; i < len; i ++){
        if(!vis[i]){
            vis[i] = true;
            ans1[x] = ans[i];
            dfs(x+1);
            vis[i] = false;
            while(i < len-1 && ans[i+1] == ans[i])i++;
        }
    }
}
int main(){
    //std::ios::sync_with_stdio(false);
    scanf("%s",str);
    len = strlen(str);
    for(int i = 0; i < len; i ++) ans[i] = str[i] - '0';
    sort(ans,ans+len);
    dfs(0);
    return 0;
}
