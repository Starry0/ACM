#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[5][101];
int main() {
    int n, k;
    cin >> n >> k;
    printf("YES\n");
    if(k%2) {
        if(k <= n-2) {
            str[1][n/2] = '#';
            for(int i = 1; i <= k/2; i ++) {
                str[1][n/2-i] = str[1][n/2+i] = '#';
            }
        } else {
            for(int i = 1; i < n-1; i ++) str[1][i] = '#';
            for(int i = 1; i <= (k-n+2)/2; i ++)
                str[2][n/2-i] =  str[2][n/2+i] = '#';
        }
    } else {
        for(int i = 1; i <= k/2; i ++) {
            str[1][i] = str[2][i] = '#';
        }
    }
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < n; j ++) {
            printf("%c",str[i][j]=='#'?'#':'.');
        }
        printf("\n");
    }
    return 0;
}
