#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 80010;
char str1[MAX], str2[MAX];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, x, y;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s%s",str1,str2);
        int k = 0;
        for(int i = 0; i < n; i ++) {
            if(str1[i] == str2[i]) k++;
        }
        if(abs(x-y) > n-k || x+y > n+k) printf("Lying\n");
        else printf("Not lying\n");
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
    }
    return 0;
}
