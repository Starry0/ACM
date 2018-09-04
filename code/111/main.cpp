#include<stdio.h>
int main(){
    int i,n;
    scanf("%d",&n);
    while(n){
        int s=0,a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        i=0;
        while(n--)
            s+=a[i++];
        printf("%d\n",s);
        scanf("%d",&n);
    }
    return 0;
}
