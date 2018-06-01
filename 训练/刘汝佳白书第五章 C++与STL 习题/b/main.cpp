#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[20];
int main()
{
    int n, t;
    cin>>t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        int flag = 1;
        while(ans <= 1000){
            for(int i = 0; i < n; i++){
                if(a[i] != 0){
                    flag = 0;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                a[i] = abs(a[i%n] - a[(i+1)%n]);
            }
            for(int )
        }
    }
    return 0;
}
