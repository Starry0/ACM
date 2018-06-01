#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 300010;
int ans[MAX], n, k, num;
int check(int pos){
    int l = pos, r = n;
    while(l <= r){
        int m = (l+r)>>1;
        if(m-pos+1 <= k+ans[m]-ans[pos-1])l=m+1;
        else r = m-1;
    }
    return l-1;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i ++)
        scanf("%d",&num), ans[i] = ans[i-1]+num;
    int Max = 0;
    for(int i = 1; i <= n; i ++){
        int x = check(i);
    //    printf("%d   %d\n",i,x);
        if(Max < (x-i+1)){
            Max = x-i+1;
        }
    }
    printf("%d\n",Max);
    return 0;
}
