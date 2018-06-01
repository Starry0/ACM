#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
void Cal(char *s, int *num) {
    int i, j, k, t, m = atoi(s), n = strlen(s);
    for(i = k = 1; i < n; i ++)
        k*=10,num[0]-=k;
    for(i = 0; i < n; i ++, k/=10){
        for(j = 0;j < s[i]-'0'; j ++)
            num[j] += k;
        for(t = 0; t < 10; t ++)
            num[t] += k/10*(n-i-1)*j;
        if(i+1 < n) num[j] += atoi(s+i+1);
        num[j]++;
    }
}
int main(){
    char s[22];
    int n,m,vis[11]={0},vis1[11]={0};
    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        if(n>m)swap(n,m);
        memset(vis,0,sizeof(vis));
        sprintf(s,"%d",n-1);
        Cal(s,vis);
        memset(vis1,0,sizeof(vis1));
        sprintf(s,"%d",m);
        Cal(s,vis1);
        for(int i = 0; i < 10; i ++)
            printf("%d%c",vis1[i]-vis[i],i==9?'\n':' ');
    }
    return 0;
}
