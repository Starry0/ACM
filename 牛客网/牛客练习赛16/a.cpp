#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char str[N], str1[N];
int main() {
    cin >> str;
    int ans = 0;
    char MAX = 'a';
    for(int len = strlen(str)-1; len >= 0; len--) {
        if(str[len] >= MAX) {
            MAX = str[len];
            str1[ans++] = str[len];
        }
    }
    for(int i = ans-1; i >= 0; i --) {
        printf("%c",str1[i]);
    }
    printf("\n");
    return 0;
}
