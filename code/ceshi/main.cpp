#include<stdio.h>
int main(){
    int a[1000],i,n;
    while(scanf("%d",&n)){
        int s=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        i=0;
        while(n--){
            s+=a[i];
            i++;}
        printf("%d",s);
    }
    return 0;
}
