// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
// char str1[110], str2[110], dp[110][110];
// int main(){
//     while(scanf("%s%s",str1,str2)!=EOF) {
//         int len1 = strlen(str1), len2 = strlen(str2);
//         for(int i = 0; i < len1; i ++) {
//             for(int j = 0; j < len2; j ++) {
//                 if(str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j]+1;
//                 else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
//             }
//         }
//         int ans1 = 0, ans2 = 0;
//         for(int i = 1; i <= len2; i ++){
//             if(dp[len1][i] == i) ans2 = i;
//         }
//         for(int i = 1; i <= len1; i ++){
//             if(dp[i][len2] == i) ans1 = i;
//         }
//         if(ans1 > ans2){
//             printf("%s%s\n",str2,str1+ans1);
//         }else printf("%s%s\n",str1,str2+ans2);
//         memset(str2,0,sizeof(str2));
//         memset(str1,0,sizeof(str1));
//         memset(dp,0,sizeof(dp));
//     }
//     return 0;
// }



#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 110;
int dp[N][N], mark[N][N], len1, len2;
char str1[N], str2[N];

void LCS(){
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= len1; i ++)
        mark[i][0] = 1;
    for(int i = 0; i <= len2; i ++)
        mark[0][i] = -1;
    for(int i = 1; i <= len1; i ++){
        for(int j = 1; j <= len2; j ++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                mark[i][j] = 0;
            }else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 1;
            }else {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = -1;
            }
        }
    }
}
void printLCS(int i, int j) {
    if(!i && !j)return;
    if(mark[i][j] == 0){
        printLCS(i-1,j-1);
        printf("%c",str1[i-1]);
    }else if(mark[i][j] == 1){
        printLCS(i-1,j);
        printf("%c",str1[i-1]);
    }else {
        printLCS(i,j-1);
        printf("%c",str2[j-1]);
    }
}
int main() {
    while(scanf("%s%s",str1,str2)!=EOF){
        len1 = strlen(str1); len2 = strlen(str2);
        LCS();
        printLCS(len1,len2);
        printf("\n");
    }
    return 0;
}
