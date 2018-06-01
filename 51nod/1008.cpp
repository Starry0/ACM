#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int main(){
    ll n, p, ans = 1;
    cin >> n >> p;
    for(ll i = 1; i <= n; i ++){
        ans = (ans*i)%p;
    }
    cout << ans%p << endl;
    return 0;
}
