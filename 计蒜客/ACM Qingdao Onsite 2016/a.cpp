#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a, b, ans = 0;
        for(int i = 1; i <= n; i ++) {
            scanf("%d %d",&a,&b);
            ans += a*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}