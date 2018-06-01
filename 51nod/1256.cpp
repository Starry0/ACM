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
int mod(int a, int m){
    int x, y;
    extgcd(a,m,x,y);
    // cout << x << ' ' << y << endl;
    return (m+x)%m;
}
int main(){
    int n, m;
    scanf("%d%d",&m,&n);
    printf("%d\n",mod(m,n));
    return 0;
}
