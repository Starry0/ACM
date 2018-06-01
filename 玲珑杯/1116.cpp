#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i ++)scanf("%d",&a[i]);
    while(m--){
        int num, x;
        scanf("%d",&num);
        if(num&1){
            scanf("%d %d",&num,&x);
            for(int i = 1; i <= n; i ++) if(a[i] == num)a[i]=x;
        }else{
            scanf("%d",&x);
            printf("%d\n",a[x]);
        }
    }
    return 0;
}
