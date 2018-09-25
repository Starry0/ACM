#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2010;
char s[N][N];
int main() {
    ll q, n, r;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]+1);
    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 1;
        int l = y-1, r = y+1;
        while(l >= 1 && r <= n && s[x][l] = s[x][r]) {
            l--;r++; ans1 += 2;
        }
        l = x-1; r = x + 1;
        while(l >= 1 && r <= n && s[l][y] = s[r][y]) {
            l--;r++; ans2 += 2;
        }
        
    }
    return 0;    
} 