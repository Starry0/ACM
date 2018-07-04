#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5+10;
int n, k;
char str[N];
int a[30];
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s",str);
    if(n == k) return 0;
    for(int i = 0; i < n; i ++) {
        a[str[i]-'a']++;
    }
    for(int i = 1; i < 26; i ++) a[i] += a[i-1];
    // for(int i = 0; i < 26; i ++) printf("%d%c",a[i]," \n"[i==25]);
    int b;
    for(b = 0; b < 26; b ++) {
        if(a[b] >= k) break;
    }
    // printf("i:%d\n",b);
    if(b != 0) k = k - a[b-1];
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i]-'a' > b) printf("%c",str[i]);
        else if(str[i]-'a' == b) {
            if(ans < k) ans++;
            else printf("%c",str[i]);
        } else if(str[i]-'a' < b) {
            continue;
        }
    }
    return 0;
}
