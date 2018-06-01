#include <iostream>
#define ll long long
using namespace std;
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x = 1; y = 0;
    }
    return d;
}
int main() {
	ll x, y, n, m, l;
	cin >> x >> y >> m >> n >> l;
	
	return 0;
}