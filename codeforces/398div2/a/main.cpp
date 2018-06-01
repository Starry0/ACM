#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int n,j,b;
    scanf("%d",&n);
    int ans = n;
    for(int i=1;i<=n;i++){
        scanf("%d",&b);
        a[b]++;
        if(b==ans){
            printf("%d",ans);
            ans--;
            for(j=ans;j>0;j--){
                if(a[j]){
                    printf(" %d",j);
                    ans--;
                }
                else break;
            }
            printf("\n");
        }
        else printf("\n");
    }
    return 0;
}
