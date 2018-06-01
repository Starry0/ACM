#include <iostream>
#include <stdio.h>
using namespace std;
int n,q,dmax[10010][25],a[10010];
void init(){
    for(int i = 1; i <= n; i ++){
        dmax[i][0] = a[i];
    }
    for(int j = 1; (1<<j) <= n; j ++){
        for(int i = 1; i+(1<<j)-1<= n; i ++){
            dmax[i][j] = max(dmax[i][j-1],dmax[(1<<(j-1))+i][j-1]);
        }
    }
}
int getValue(int l, int r){
    int k = 0;
    while(1<<(k+1) <= (r-l+1))k++;
    return max(dmax[l][k],dmax[r-(1<<k)+1][k]);
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }
    init();
	scanf("%d",&q);
    while(q--){
        int l, r;
        scanf("%d%d",&l,&r);
        printf("%d\n",getValue(++l,++r));
    }
    return 0;
}