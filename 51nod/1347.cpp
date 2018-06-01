/*
这题想复杂了，如果是对串，不管怎么变都是对串，下面的代码可以更简单。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1000010;
char str[N];
int main() {
    while(scanf("%s", str) != EOF) {
        int len = strlen(str);
        if(len&1)printf("NO\n");
        else {
            int i = 0, j = len/2, k = 0;
            while(k < len/2 && i < len/2) {
                if(str[i+k] == str[(j+k)%len]) k++;
                else {
                    i++; j = (j+1)%len;
                }
            }
            if(k == len/2) {
                printf("YES\n");
            }else printf("No\n");
        }
    }
    return 0;
}
