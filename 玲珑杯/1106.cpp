#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,r,x;
        scanf("%d%d%d",&n,&r,&x);
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            if(abs(x-i) <= r)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
