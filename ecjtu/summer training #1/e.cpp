#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[3000],n;
ll num[20];
void init(){
    num[0] = 0; num[1]=num[2] = 9;
    for(int i = 3; i < 20; i+=2){
        num[i] = num[i+1] = num[i-1]*10;
    }
}
int main(){
    init();
    while(scanf("%d",&n)!=EOF&&n){
        int len = 1;
        while(n > num[len]){
            n -= num[len];
            len++;
        }
        n--;
        int cnt = len/2 + 1;
        while(n){
            a[cnt++] = n%10;
            n/=10;
        }
        for(int i = cnt; i <= len; i ++)
            a[i] = 0;
        a[len]++;
        for(int i = 1; i <= len/2; i ++)
            a[i] = a[len-i+1];
        for(int i = 1; i <= len; i ++)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
