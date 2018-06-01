#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const int N = 1e5;
int pre[N];
int fun(int x){
    int res = 0;
    for(int i = 2; i <= sqrt(x); i ++){
        if(x%i==0){
            res++;
            while(x%i==0)x/=i;
        }
    }
    if(x > 1) res++;
    return res;
}
int main(){
    for(int i = 1; i < N; i ++){
        pre[i] = i*i;
    }
    int n;
    scanf("%d",&n);
    int i = 2;
    while(pre[i] <= n){
        if(n%pre[i] ==0){
            return 0*printf("%d\n",0);
        }
        i++;
    }
    int k = fun(n);
    //cout << k << endl;
    printf("%d\n",k&1?-1:1);
    return 0;
}
