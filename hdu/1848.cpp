#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int SG[N], f[20], s[N];
int n, m, p;
void getSG(int x) {
    memset(SG, 0, sizeof(SG));
    for(int i = 1; i <= x; i ++) {
        memset(s, 0, sizeof(s));
        for(int j = 0; f[j] <= i && j < 20; j ++)
            s[SG[i-f[j]]] = 1;
        for(int j = 0; ; j++) {
            if(!s[j]) {
                SG[i] = j;
                break;
            }
        }
    }
}
int main() {
    f[0] = f[1] = 1;
    for(int i = 2; i < N; i ++) f[i] = f[i-1] + f[i-2];
    getSG(1000);
    while(cin >> n >> m >> p) {
        if(n==0&&m==0&&p==0) break;
        if(SG[m]^SG[n]^SG[p]) printf("Fibo\n");
        else printf("Nacci\n");
    }
    return 0;
}
