#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        set<ll> st;
        cin >> a >> b >> c;
        st.insert(a);
        st.insert(b);
        st.insert(c);
        ll d = gcd(a,gcd(b,c));
        ll MAX = max(a,max(b,c));
        cout << MAX/d - st.size()<< endl;
    }
    return 0;
}
