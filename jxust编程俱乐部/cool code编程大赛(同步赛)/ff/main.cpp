#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;

int a[maxn],M[maxn];
int MIN(int a,int b){
    return a>b?b:a;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        M[n] = a[n];
        for(int i = n - 1; i > 0; i--) M[i] = MIN(M[i+1],a[i]);
        for(int i = 1; i <= n; i++){
            int ans = -1,l = i + 1,r = n;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(a[i] > M[mid]){
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(ans == -1) printf("-1");
            else printf("%d",ans - i - 1);
            if(i == n) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

