#include <stdio.h>
int gcd(int a, int b){
    int c = a%b;
    while(c){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main(){
    int a, b;
    scanf("%d%d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
