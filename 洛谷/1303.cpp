#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
char str1[N], str2[N];
int str3[N];
int mul(char *s, char *ss,int *num) {
    int len1 = strlen(s);
    int len2 = strlen(ss);
    int len3 = len1+len2;
    for(int i = 0; i < len1/2; i ++) swap(s[i],s[len1-i-1]);
    for(int i = 0; i < len2/2; i ++) swap(ss[i],ss[len2-i-1]);
    for(int i = 0; i < len1; i ++) {
        for(int j = 0; j < len2; j ++) {
            num[i+j] += (s[i]-'0')*(ss[j]-'0');
        }
    }
    for(int i = 0; i < len3; i ++) {
        if(num[i] >= 10) {
            num[i+1] += num[i]/10;
            num[i] %= 10;
        }
    }
    while(num[len3] == 0 && len3 >= 0) len3--;
    len3++;
    for(int i = 0; i < len3/2; i ++) {
        swap(num[i], num[len3-i-1]);
    }
    if(!len3) len3++;
    return len3;
}
int main() {
    cin >> str1 >> str2;
    int len = mul(str1,str2,str3);
    for(int i = 0; i < len; i ++) printf("%d",str3[i]);
    printf("\n");
    return 0;
}
