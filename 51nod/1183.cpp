// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
// char str1[1010], str2[1010];
// int dp[1010][1010];
// int main(){
//     scanf("%s%s",str1,str2);
//     int len1 = strlen(str1), len2 = strlen(str2);
//     for(int i = 0; i <= len2; i ++) dp[i][0] = dp[0][i] = i;
//     for(int i = 1; i <= len1; i ++){
//         for(int j = 1; j <= len2; j ++){
//             if(str1[i-1] == str2[j-1]) dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
//             else dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
//         }
//     }
//     printf("%d\n",dp[len1][len2]);
//     return 0;
// }



#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str1[1010], str2[1010];
int dp[1010][1010];
int main(){
    scanf("%s%s",str1,str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i = 0; i <= len2; i ++) dp[i][0] = dp[0][i] = i;
    for(int i = 0; i < len1; i ++){
        for(int j = 0; j < len2; j ++){
            if(str1[i] == str2[j]) dp[i+1][j+1] = min(dp[i][j],min(dp[i][j+1]+1,dp[i+1][j]+1));
            else dp[i+1][j+1] = min(dp[i][j]+1,min(dp[i+1][j]+1,dp[i][j+1]+1));
        }
    }
    printf("%d\n",dp[len1][len2]);
    return 0;
}
