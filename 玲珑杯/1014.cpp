#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 2e5+10;
int a[MAX];
int main(){
    int t,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1; i <= n; i ++)scanf("%d",&a[i]);
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] < m){
                int x = m-a[i];
                ans += x;
                for(int j = 0; j < k; j ++){
                    a[i+j] += x;
                }
            }
        }
        printf("%d\n",ans);
        memset(a,0,sizeof(a));
    }
    return 0;
}
