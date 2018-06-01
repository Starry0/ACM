#include <bits/stdc++.h>
using namespace std;
struct mat{
    int m[2][2];
    mat() {
        memset(m, 0, sizeof(m));
    }
};

mat mul(mat &A, mat &B) {
    mat C;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                C.m[i][j] = (C.m[i][j]+A.m[i][k]*B.m[k][j]) % 10000;
            }
        }
    }
    return C;
}

mat pow(mat A, int n) {
    mat B;
    B.m[0][0] = B.m[1][1] = 1;
    while(n) {
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
double fun(int x) {
    return pow((1+sqrt(5))/2,x)/sqrt(5);
}
int main() {
    int n, num[40];
    num[0] = 0, num[1] = 1;
    mat A;
    A.m[0][0] = A.m[0][1] = A.m[1][0] = 1;
    for(int i = 2; i < 40; i ++) num[i] = num[i-1] + num[i-2];
    while(scanf("%d", &n) != EOF) {
        if(n < 40) cout << num[n] << endl;
        else {
            double y = fun(n);
            int len = log10(y)+1;
            mat B = pow(A, n-1);
            printf("%d....%d\n",int(y/ pow(10,len-4)),B.m[0][0]);
        }
    }
    return 0;
}
