#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s[100005];
int main(){
    scanf("%s",s);
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0 ; i < len ; i ++){
        cnt += s[i] - 'A';
    }
    for(int i = 0 ; i < len / 2 ; i ++){
        printf("%c",(char)((s[i] - 'A' + s[i + len / 2] - 'A' + cnt)%26 + 'A'));
    }
    printf("\n");
}