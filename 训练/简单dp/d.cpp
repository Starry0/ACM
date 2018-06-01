#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e3+10;
int a[N][N];
char s[N], ss[N];
int main(){
    while(scanf("%s %s",s+1,ss+1)!=EOF){
        int i,j;
        for(i = 1; s[i]; i ++){
            for(j = 1; ss[j]; j ++){
                if(s[i] == ss[j]) a[i][j] = a[i-1][j-1] + 1;
                else a[i][j] = max(a[i-1][j],a[i][j-1]);
            }
        }
        printf("%d\n",a[i-1][j-1]);
        memset(s,0,sizeof(s));
        memset(ss,0,sizeof(ss));
        memset(a,0,sizeof(a));
    }
    return 0;
}
