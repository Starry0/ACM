#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
char s[N], t[N];
int main() {
    int n, m, id;
    cin >> n >> m;
    cin >> s >> t;
    bool flag = false;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '*') {
            flag = true;
            id = i;
            break;
        }
    }
    if(!flag) {
        if(n != m) return 0*printf("NO\n");
        for(int i = 0; i < n; i ++) {
            if(s[i] != t[i]) return 0*printf("NO\n");
        }
        printf("YES\n");
    } else {
        int l = 0, r = n-1, i = 0;
        while(s[l] == t[l]) l ++;
        while(s[r] == t[m-1-i]) {
            r--;i++;
        }
        // printf("%d %d %d\n",l,r,id);
        if(n <= m+1 && l == id && r == id) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}