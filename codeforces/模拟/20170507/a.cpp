#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1e5+19;
int a[N];
int main(){
    int n, c, k;
    while(~scanf("%d %d %d",&n,&c,&k)){
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a,a+n);
        int ans = 1;
        int st = a[0], res = 1;
        for(int i = 1; i < n; i ++){
            if(res < c && a[i] <= st+k){
                res++;
            }
            else{
                ans++;
                st = a[i];
                res = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
