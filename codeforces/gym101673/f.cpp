#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
int dp[10000];
vector <int> vec[10005];
int ans1 = 0 , ans2 , n;
void dfs(int x , int pre){
    int tmp1 = 0 , tmp2 = 0 , inv = 0;
    dp[x] = 1;
    int len = vec[x].size();
    for(int i = 0 ; i < len ; i++){
        int y = vec[x][i];
        if(y == pre) continue;
        dfs(y , x);
        dp[x] += dp[y];
        if(dp[y] > tmp1){
            tmp2 = tmp1;
            tmp1 = dp[y];
        }else if(dp[y] > tmp2){
            tmp2 = dp[y];
        }
        inv += dp[y] * (n - dp[y] - 1);
    }

    if(n - dp[x] > tmp1){
        tmp2 = tmp1;
        tmp1 = n - dp[x];
    }else if(n - dp[x] > tmp2){
        tmp2 = n - dp[x];
    }
    inv += (n - dp[x]) * (dp[x] - 1);
    inv /= 2;
    //printf("%d %d %d %d\n",x, tmp1 , tmp2 , inv);
    if(tmp2 == 0) return ;
    if(inv > ans1){
        ans1 = inv;
        ans2 = (inv - (tmp1 * tmp2));
    }else if(inv == ans1){
        ans2 = min(ans2 ,(inv - (tmp1 * tmp2)));
    }
}
int main(){
    scanf("%d",&n);
    n ++;
    for(int i = 1 ; i < n ; i ++){
        int x , y;
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);

    }
    dfs(0 , -1);

    printf("%d %d\n",ans1 , ans2);
}