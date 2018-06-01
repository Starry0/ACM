#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
map<char,int> mp;
char str[N];
vector<int> vs;
int n;
ll C(ll a, ll b) {
    ll ans = 1;
    if(a > b-a) a = b-a;
    for(ll i = 1; i <= a; i ++) {
        ans *= b-i+1;
        ans /= i;
    }
    return ans;
}

int main() {
    cin >> n >> str;
    for(int i = 0; i < n; i ++) {
        mp[str[i]]++;
    }
    map<char,int> ::iterator it = mp.begin();
    for(; it != mp.end(); ++ it) {
        vs.push_back((*it).second);
    }
    ll ans = 1;
    for(int i = 0; i < vs.size(); i ++) {
        // ll tmp = C(vs[i],n);
        // cout << tmp << endl;
        ans *= C(vs[i],n);
        n -= vs[i];
    }
    printf("1/%lld\n",ans);
    return 0;
}
