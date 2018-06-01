#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1e6+10;
int a[MAX];
bool vis[2*MAX];
int main(){
    int k = 0;
    memset(vis,false,sizeof(vis));
    for(int i = 2; i < 2*MAX; i ++){
        if(!vis[i]){
            a[++k] = i;
            for(int j = i+i; j < MAX*2; j +=i){
                vis[j] = true;
            }
        }
    }
    int n;
    cin>>n;
    for(int i = n; ; i ++){
        if(!vis[i]){
            int x = lower_bound(a,a+k,i) - a;
            //printf("%d   %d\n",i,x);
            if(!vis[x]){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
