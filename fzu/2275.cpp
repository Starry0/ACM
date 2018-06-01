#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str1[100010], str2[100010], nex[100010];
int len1, len2;
void init() {
    int j = nex[0] = -1, i = 0;
    while(i < len2) {
        if(j == -1 || str2[j] == str2[i]) nex[++i] = ++j;
        else j = nex[j];
    }
}
bool KMP() {
    int i = 0, j = 0;
    while(j < len1) {
        if(i == -1 || str2[i] == str1[j]){
            i++;j++;
        }else i = nex[i];
        if(i == len2) return true;
    }
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s %s",str1,str2);
        len1 = strlen(str1), len2 = strlen(str2);
        while(str2[len2-1] == '0') {
            str2[len2-1] = '\0';
            len2--;
        }
        if(len1 < len2) {
            printf("Bob\n");
        }else {
            if(len2 == 0){
                printf("Alice\n");
                continue;
            }
            init();
            bool flag1 = KMP();
            for(int i = 0; i < len2/2; i ++)
                swap(str2[i],str2[len2-i-1]);
            memset(nex,0,sizeof(nex));
            init();
            bool flag2 = KMP();
            if(flag2 || flag1) printf("Alice\n");
            else printf("Bob\n");
        }
        memset(nex,0,sizeof(nex));
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
    }
    return 0;
}
