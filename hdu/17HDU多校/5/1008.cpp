#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
using namespace std;
int dp[10005] , a[100000] , p;
ll b[100005];
int main(){
    int t;
    scanf("%d",&t);
    while(t --){
        ll n , m;
        p = 0;
        memset(dp , 0 ,sizeof(dp));
        scanf("%lld%lld",&n , &m);
        for(int i = 0 ; i <= m ; i ++){
            scanf("%lld",&b[i]);
        }
        dp[0] = 1;
        for(int i = 0 ; i <= m ; i ++){
            ll num = b[i] - dp[i];
            int cnt = 0;
            if(i == 0){
                while(num){
                    cnt ++;
                    num /= 2;
                }
            }else{
                cnt = num / dp[0];
            }
            for(int k = 0 ; k < cnt ; k ++){
                for(int j = m ; j >= i ; j --){
                    dp[j] += dp[j - i];
                }
                a[p ++] = i;

            }
        }
        for(int i = 0 ; i < p ; i ++){
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
