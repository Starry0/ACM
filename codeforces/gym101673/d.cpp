#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[100005] , pos = 0;
char s[10];
int Get(){
    int res = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i ++){
        if(s[i] != '-'){
            res = 10 * res + s[i] - '0';
        }
    }
    if(s[0] == '-') res *= -1;
    return res;
}
int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    int sum = 0;
    while(m --){
        scanf("%s",s);
        if(s[0] == 'u'){
            scanf("%s",s);
            int x = Get();
            while(pos && x --){
                sum -= a[-- pos];
            }
        }else{
            int x = Get();
            a[pos ++] = x;
            sum += x;
        }
        //printf("%d ",sum);
    }

    printf("%d\n",(sum % n + n) % n);
}