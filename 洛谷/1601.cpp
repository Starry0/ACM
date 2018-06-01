#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
char str1[N], str2[N], str3[N];
char * add(char *s, char *ss) {
    memset(str3, 0, sizeof(str3));
    int len1 = strlen(s)-1;
    int len2 = strlen(ss)-1;
    int len3 = 0, x, y, flag = 0;
    while(len1 >= 0 || len2 >= 0) {
        if(len1 >= 0) x = s[len1] - '0';
        else x = 0;
        if(len2 >= 0) y = ss[len2] - '0';
        else y = 0;
        str3[len3++] = (x+y+flag)%10 + '0';
        flag = (x+y+flag)/10;
        len2--;len1--;
    }
    if(flag) str3[len3++] = '1';
    for(int i = 0; i < len3/2; i ++) {
        swap(str3[i],str3[len3-i-1]);
    }
    return str3;
}
int main() {
    cin >> str1 >> str2;
    printf("%s\n",add(str1,str2));
    return 0;
}
