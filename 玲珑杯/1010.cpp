#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int MAX = 4e5;
int a[MAX],vis[MAX];
int main(){
    int t,n,k=1;
    for(int i = 2; i < MAX; i ++){
        if(!vis[i]){
            a[k++] = i;
            for(int j = i+i; j < MAX; j +=i){
                vis[j] = 1;
            }
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        printf("%lld\n",1LL*a[n]*a[n] - 1LL*n);
    }
    return 0;
}
