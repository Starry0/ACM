#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
    int a, b, k, a_k;
    while(cin>>a>>b){
        k = abs(a-b);
        a = min(a,b);
        a_k = floor(k*(1+sqrt(5))/2);
        printf("%d\n",a_k != a);
    }
    return 0;
}
