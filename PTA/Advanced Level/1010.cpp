#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll tag, rad, n1, n2;
char str1[20], str2[20];
map<char,ll> mp;
ll f(char *str, ll y) {
    ll x = 0, ans = 1;
    int len = strlen(str);
    for(int i = len-1; i >= 0; i --) {
        x = x + ans*mp[str[i]];
        ans *= y;
    }
    return x;
}
int main() {
    for(int i = 0; i < 10; i ++) mp[i+'0'] = i;
    for(int i = 0; i < 26; i ++) mp['a'+i] = i+10;
    cin >> str1 >> str2 >> tag >> rad;
    if(tag == 2) swap(str1, str2);
    n1 = f(str1, rad);
    ll left = 1, right, ans = 0;
    for(int i = 0; str2[i]; i ++) left = max(left, mp[str2[i]]+1);
    right = (n1 > left) ? n1+1 : left+1;
    while(left <= right) {
        ll mid = (left + right) >> 1;
        ll n2 = f(str2, mid);
        if(n2 == n1) {
            ans = mid;
            right = mid - 1;
        } else if(n2 > n1 || n2 < 0) {
            right = mid - 1;
        }
        else if(n2 < n1){
            left = mid + 1;
        }
    }
    if(ans) printf("%lld\n",ans);
    else printf("Impossible\n");
    return 0;
}
// 412123ab 696405086 1 15
