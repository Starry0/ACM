#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 10010;
char str[N];
int a[30];
int main() {
    scanf("%s", str);
    for(int i = 0; str[i]; i ++) {
        char c = tolower(str[i]);
        a[c-'a']++;
    }
    sort(a,a+26);
    int ans = 0;
    for(int i = 25; i >= 0; i --) {
        ans += a[i]*(i+1);
    }
    printf("%d\n",ans);
    return 0;
}
