#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 200907;
const int N = 110;
char str[N];
int len, a[N];
struct mat{
    ll m[N][N];
    mat(){
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < len; i ++) {
        for(int j = 0; j < len; j ++) {
            for(int k = 0; k < len; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % 2;
            }
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat B;
    for(int i = 0; i < len; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() {
    int m;
    while(scanf("%d%s",&m,str) != EOF){
        memset(a, 0, sizeof(a));
        len = strlen(str);
        mat A;
        for(int i = 0; i < len; i ++) {
            A.m[i][i] = A.m[i][(i+1)%len] = 1;
        }
        A = pow(A, m);
        for(int i = 0; i < len; i ++) {
            for(int j = 0; j < len; j ++) {
                a[i] += A.m[len-i-1][j]*(str[(len-j-1)%len]-'0');
            }
        }
        for(int i = 0; i < len; i ++) printf("%d",a[i]%2);
        printf("\n");
    }
    return 0;
}
