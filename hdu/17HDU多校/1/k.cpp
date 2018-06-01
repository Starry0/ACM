#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main() {
    int ca = 1;
    ll n, k;
    while(scanf("%lld%lld",&n,&k)!=EOF) {
        if(k <= n){
            printf("Case #%d: %lld\n",ca++,k);
        }else {
            int a = (k-n)/(n-1);
            if(a&1){
                int w = (k-n)%(n-1);
                if(w)printf("Case #%d: %d\n",ca++,w);
                else printf("Case #%d: %lld\n",ca++,n-1LL);
            }else{
                int w = (k-n)%(n-1);
                if(w)printf("Case #%d: %d\n",ca++,w);
                else printf("Case #%d: %lld\n",ca++,n);
            }
        }
    }
    return 0;
}
