#include <bits/stdc++.h>
const int maxn = 2e5+10;
using namespace std;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int b = n/2;
    for(int i=1;i<=b;i++)
        if(i%2!=0)
            swap(a[i],a[n-i+1]);
    for(int i =1;i<=n;i++){
        if(i==1)
            printf("%d",a[i]);
        else printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}
