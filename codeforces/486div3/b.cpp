#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
string s[110], ss[110];
int a[110];
bool ok(string a, string b) {
    int lena = a.length(), lenb = b.length();
    for(int i = 0; i < lenb-lena+1; i ++) {
        if(b[i] == a[0]) {
            int j = 0;
            for(; j < lena; j ++) {
                if(b[i+j] != a[j]) break;
            }
            if(j == lena) return 1;
        }
    }
    return 0;
}
struct Nod {
    int a, id;
}nod[110];
bool cmp(Nod a, Nod b) {
    return a.a > b.a;
}
int main() {
    int n, flag = 0;
    // cout << ok("baa","aba") << endl;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> s[i], ss[i] = s[i];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i == j) continue;
            if(ok(s[i],s[j])) a[i]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        ans += a[i];
        nod[i].a = a[i];
        nod[i].id = i;
    }
    if(ans >= n*(n-1)/2) {
        printf("YES\n");
        sort(nod,nod+n,cmp);
        for(int i = 0; i < n; i ++) cout << s[nod[i].id] << endl;
    }else printf("NO\n");
    return 0;
}
