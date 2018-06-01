#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n, k;
    while(cin >> n >> k){
        ll d = 0, c = 0, a = 0;
        d = n/2/(1+k);
        c = d*k;
        a = n-d-c;
        cout << d << ' ' << c << " " << a << endl;
    }
    return 0;
}
