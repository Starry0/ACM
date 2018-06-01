#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 33;
const int M = 10010;
const int mod = 2008;
int v1, v2, t1, t2, n, k;
map<ll, int> mp;
struct mat{
    int m[N][N];
    mat(){
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            for(int k = 0; k < N; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, int x) {
    mat B;
    for(int i = 0; i < N; i ++) B.m[i][i] = 1;
    while(x) {
        if(x&1) B = mul(B, A);
        A = mul(A, A);
        x >>= 1;
    }
    return B;
}
mat add(mat A, mat B) {
    mat C;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            C.m[i][j] = (A.m[i][j] + B.m[i][j]) % mod;
        }
    }
    return C;
}
mat dfs(mat A, int x) {
    if(x == 1) return A;
    mat B, C;
    if(x%2) {
        B = dfs(A, x/2);
        C = pow(A, x/2+1);
        return add(add(B, mul(C, B)), C);
    } else {
        B = dfs(A, x/2);
        C = pow(A, x/2);
        return add(B, mul(C,B));
    }
}
int sup(mat A, int x) {
    if(x == -1 || x == 0) return 0;
    int ans = 0;
    mat B = dfs(A, x);
    return B.m[mp[v1]][mp[v2]];
}
int main() {
    while(scanf("%d", &n) != EOF) {
		mp.clear();
        mat A;
		int cnt = 1;
        for(int i = 0; i < n; i ++) {
			ll u, v;
            scanf("%lld%lld", &u, &v);
			if(!mp[u]) mp[u] = cnt++;
			if(!mp[v]) mp[v] = cnt++;
			A.m[mp[u]][mp[v]]++;
        }
        mat B = dfs(A, 2);
        scanf("%d", &k);
        while(k--) {
            scanf("%d%d%d%d", &v1, &v2, &t1, &t2);
			if(t1 > t2) swap(t1, t2);
            printf("%d\n",(sup(A, t2) - sup(A, t1-1))%mod);
        }
    }
    return 0;
}
