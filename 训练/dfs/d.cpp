#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main(){
    ll a, b;
    a = (ll)(1 << 31);
    cout << a << endl;
        int ans = 0;
        /*for(ll i = 2; i < 62; i ++){
            for(ll j = 0; j < i -1; j ++){
                ll x = (1 << i) - 1 - (1 << j);
                cout << x << endl;
            }
        }*/
    return 0;
}
