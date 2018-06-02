#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
string s[110];
bool cmp(string a, string b) {
    return a.length() < b.length();
}
int main() {
    int n, flag = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> s[i];
    sort(s,s+n,cmp);
    for(int i = 1; i < n; i ++) {
        if(s[i].find(s[i-1]) == string::npos)
        return 0*printf("NO\n");
    }
    printf("YES\n");
    for(int i = 0; i < n; i ++) cout << s[i] << endl;
    return 0;
}
