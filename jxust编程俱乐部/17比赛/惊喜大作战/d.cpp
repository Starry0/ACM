#include <iostream>
#include <stdio.h>
using namespace std;

int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

int main(){
    int n, m, x, y;
    scanf("%d%d",&m,&n);
    extgcd(m,n,x,y);
    printf("%d\n",(x+n)%n);
    return 0;
}
