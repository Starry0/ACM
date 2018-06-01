#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 1010;
double dp[MAX][MAX];
int main() {
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i = n; i >= 0; i --) {
            for(int j = s; j >= 0; j --) {
                if(i == n && j == s)continue;
                dp[i][j] = (i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(n*s-i*j);
            }
        }
        //printf("+++\n");
        printf("%.4f\n",dp[0][0]);
    }
    return 0;
}
