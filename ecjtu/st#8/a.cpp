#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;
int n, k, cnt, cnt1,res;
int vis[1100];

int main(){
    int kk = 1;
    while(scanf("%d",&n)&&n) {
        memset(vis,false,sizeof(vis));
        int a,b,c,d,e,f,g,h,ii,jj,k = 0;
        if(kk!=1)printf("\n");
        for(int i = 1234; i <= 98765; i ++) {
            memset(vis,0,sizeof(vis));
            a = i%10,b = i/10%10,c = i/100%10,d = i/1000%10,e = i/10000%10;
            int num = i*n;
            if(num > 98765)break;
            f = num%10,g = num/10%10,h = num/100%10,ii = num/1000%10,jj = num/10000%10;
            vis[a]++;vis[b]++;vis[c]++;vis[d]++;vis[e]++;
            vis[f]++;vis[g]++;vis[h]++;vis[ii]++;vis[jj]++;
            int j;
            for(j = 0; j < 10; j ++) {
                if(vis[j] > 1)break;
            }
            if(j == 10) {
                printf("%d%d%d%d%d / %d%d%d%d%d = %d\n",jj,ii,h,g,f,e,d,c,b,a,n);
                k++;
            }else continue;
        }
        if(k == 0) printf("There are no solutions for %d.\n",n);
        kk++;
    }
    return 0;
}
