#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define ll long long
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll Mod = 1000000007;

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
    ll f[100], a[110];
    f[1] = 1; f[2] = 2;
    for(int i = 3; i < 55; i ++) f[i] = f[i-1] +f[i-2];
    // for(int i = 1; i < 55; i ++) printf("%d %lld\n",i,f[i] );
    for(int i = 3; i < 100; i ++) {
    	if(i%2) printf("%d 1\n",i);
    	else {
    		if((i/2)%2) printf("%d 2\n",i);
    		else printf("%d 0\n",i);
    	}
    }
    for(int i = 1; i <= 30; i ++) {
    	int ans = 0;
    	for(int k = 1; k < (1<<i); k ++) {
    		if((k^(5*k)^(4*k))==0) ans++;
    	}
    	a[i] = ans;
    	if(i%2==0) {
    		printf("%d %d\n",i,a[i-1]+a[i-2]+(((i/2)&1)?2:0)-ans);
    	} else {
    		printf("%d %d\n",i,a[i-1]+a[i-2]+1-ans);
    	}
    	// printf("%d %d\n",i,ans);
    }
    cin >> n;
    mat A(2, vec(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n);
    printf("%lld\n",A[1][0]);
    return 0;
}