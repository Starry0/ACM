#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10], b[10], vis[10];
int n, s, flag;
bool ok() {
    for(int i = 0; i < n; i ++) b[i] = a[i];
    for(int i = n; i > 1; i --) {
        for(int j = 0; j < i-1; j ++) {
            b[j] = b[j] + b[j+1];
        }
    }
    return b[0] == s;
}
int main() {
    while(cin >> n >> s){
        for(int i = 0; i < n; i ++) a[i] = i+1;
        do{
            if(ok()) {
                break;
            }
        }while(next_permutation(a,a+n));
        for(int i = 0; i < n; i ++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
