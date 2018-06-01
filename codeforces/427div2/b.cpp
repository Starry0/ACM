#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
char str[MAX];
int main() {
    int k;
    cin >> k >> str;
    int sum = 0, len = strlen(str);
    for(int i = 0; i < len; i ++) {
        sum += str[i] - '0';
    }
    int ans = 0;
    sort(str,str+len);
    if(sum >= k) return 0*printf("0\n");
    for(int i = 0; i < len; i ++) {
        if(str[i] != '9') {
            sum += '9' - str[i];
            ans++;
            if(sum >= k)return 0*printf("%d\n",ans);
        }
    }
    return 0;
}
