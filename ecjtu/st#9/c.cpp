#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e5+10;
int x[N], y[N], h[N], c[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i ++) scanf("%d %d",&x[i],&y[i]);
    for(int i = 1; i <= n; i ++) scanf("%d",&c[i]);
    int m = 0;
    for(int i = 1; i < n; i ++) {
        if(c[x[i]] != c[y[i]]){
            m++;
            h[x[i]]++;h[y[i]]++;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(h[i] == m){
            return 0*printf("YES\n%d\n",i);
        }
    }
    printf("NO\n");
    return 0;
}
