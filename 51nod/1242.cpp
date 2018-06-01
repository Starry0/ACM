// #include <stdio.h>
// #include <iostream>
// #include <map>
// #define ll long long
// using namespace std;
// const int mod = 1000000009;
// map<ll,ll> mp;
// //f(n+m-1) = f(n)*f(m)+f(n-1)*f(m-1);
// ll fic(ll x){
//     if(x == 1 || x == 2) return 1;
//     if(x == 0) return 0;
//     if(mp[x] != 0) return mp[x];
//     if(x&1LL) {
//         ll a = x/2LL;
//         ll ans = ((fic(a+1LL)*fic(a+1LL))%mod+(fic(a)*fic(a)))%mod;
//         return mp[x] = ans;
//     }else{
//         ll a = x/2LL;
//         ll ans = ((fic(a)*fic(a+1LL))%mod+(fic(a-1LL)*fic(a)))%mod;
//         return mp[x] = ans;
//     }
// }
// int main(){
//     ll n;
//     cin >> n;
//     cout << fic(n) << endl;
//     return 0;
// }



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define ll long long
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll Mod = 1000000009;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int k = 0; k < B.size(); k ++) {
            for(int j = 0; j < B[0].size(); j ++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % Mod;
            }
        }
    }
    return C;
}
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i ++) {
        B[i][i] = 1;
    }
    while(n > 0) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
int main() {
    ll n;
    cin >> n;
    mat A(2, vec(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n);
    printf("%lld\n",A[1][0]);
    return 0;
}
