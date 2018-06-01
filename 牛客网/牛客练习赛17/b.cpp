#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
char str[N], str1[N];
int nex[N];
int vis[N];
void init(){
    int j = nex[0] = -1, i = 0;
    int len = strlen(str);
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            nex[++i] = ++j;
        }else j = nex[j];
    }
}
void KMP(){
    int i  = 0, j = 0, sum = 0;
    int len = strlen(str), len1 = strlen(str1);
    while(j < len1){
        if(i == -1 || str[i] == str1[j]){
            i++;j++;
        }else i = nex[i];
        if(i == len) {
            // printf("j:%d %d %d\n",j,j+1,j-len+1);
            vis[j+1]--;
            vis[j-len+1]++;
        }
    }
}
int main() {
    cin >> str1 >> str;
    init();
    int len1 = strlen(str1);
    KMP();
    int ans = 0;
    for(int i = 1; i <= len1; i ++) {
        ans += vis[i];
        if(ans == 0) return 0*printf("No\n");
    }
    printf("Yes\n");
    return 0;
}
