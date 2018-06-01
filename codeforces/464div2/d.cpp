#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char str1[N], str2[N];
int fa[30], ll[30], rr[30];
int find(int x) {
    return fa[x] == x ? x: find(fa[x]);
}
int main() {
    int n, ans = 0;
    for(int i = 0; i < 26; i ++) fa[i] = i;
    cin >> n >> str1 >> str2;
    for(int i = 0; i < n; i ++) {
        int l = str1[i]-'a', r = str2[i] - 'a';
        l = find(l), r = find(r);
        if(l != r) {
            ans ++;
            fa[l] = r;
            ll[ans] = l;
            rr[ans] = r;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= ans; i ++) {
        printf("%c %c\n",ll[i]+'a',rr[i]+'a');
    }
    return 0;
}
