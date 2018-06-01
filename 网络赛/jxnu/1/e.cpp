#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        scanf("\n%d",&a[0]);
        for(int i = 1; i < n; i ++){
            scanf("%d",&a[i]);
        }
        int maxn = 1, ans = 1;
        for(int i = 0; i < n; i ++){
            if(a[i] < a[i+1]){
                ans++;
            }else{
                if(ans > maxn){
                    maxn = ans;
                }
                ans = 1;
            }
        }
        printf("%d\n",maxn);
    }
    return 0;
}
