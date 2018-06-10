#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[3];
char str[N];
int main() {
    int n, len;
    cin >> n;
    for(int i = 0; i < 3; i ++) {
        int b[130] = {0};
        cin >> str;
        len = strlen(str);
        for(int j = 0; str[j]; j ++) b[str[j]]++;
        int ans = *max_element(b,b+130);
        a[i] = min(len,ans+n);
        if(ans == len && n == 1) a[i]--;
    }
    if(a[0] > a[1] && a[0] > a[2]) printf("Kuro\n");
    else if(a[1] > a[2] && a[1] > a[0]) printf("Shiro\n");
    else if(a[2] > a[1] && a[2] > a[0]) printf("Katie\n");
    else printf("Draw\n");
    return 0;
}
