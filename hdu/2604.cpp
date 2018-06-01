// a[n] = a[n-1]+a[n-3]+a[n-4];
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct mat{
    int m[4][4];
    mat() {
        memset(m, 0, sizeof(m));
    }
};
mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            for(int k = 0; k < 4; k ++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k]*B.m[k][j]) % m;
            }
        }
    }
    return C;
}
mat pow(mat A, int n){
    mat B;
    for(int i = 0; i < 4; i ++) B.m[i][i] = 1;
    while(n) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
int main() {
    while(cin >> n >> m) {
        mat A;
        if(n==0) printf("%d\n",1%m);
        else if(n==1) printf("%d\n",2%m);
        else if(n==2) printf("%d\n",4%m);
        else if(n==3) printf("%d\n",6%m);
        else {
            A.m[0][0] = A.m[0][2] = A.m[0][3] = 1;
            A.m[1][0] = A.m[2][1] = A.m[3][2] = 1;
            A = pow(A,n-3);
            int ans = A.m[0][0]*6+A.m[0][1]*4+A.m[0][2]*2+A.m[0][3];
            printf("%d\n",ans%m);
        }
    }
    return 0;
}
