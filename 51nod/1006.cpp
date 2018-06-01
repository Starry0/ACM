#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e3+10;
int a[N][N];
char s[N], ss[N], sss[N];
int main(){
    scanf("%s %s",s+1,ss+1);
    int i,j;
    for(i = 1; s[i]; i ++){
        for(j = 1; s[j]; j ++){
            if(s[i] == ss[j]) a[i][j] = a[i-1][j-1] + 1;
            else a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    }
    i--;j--;
    int k = N -1;
    while(i > 0 && j > 0){
        if(s[i] == ss[j]){
            sss[k--] = s[i];
            i--;j--;
        }else if(a[i-1][j] > a[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    printf("%s\n",sss+k+1);
    return 0;
}
