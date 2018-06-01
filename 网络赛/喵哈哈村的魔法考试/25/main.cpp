#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[4];
    while(cin>>n){
        cin>>a[1]>>a[2]>>a[3];
        int x[110],y[110];
        for(int i =1; i <= n; i++){
            cin>>x[i]>>y[i];
        }
        for(int i = n; i >= 1; i--){
            swap(a[x[i]],a[y[i]]);
        }
        printf("%d %d %d \n",a[1],a[2],a[3]);
    }
    return 0;
}
