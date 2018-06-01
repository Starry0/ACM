#include <bits/stdc++.h>
using namespace std;
int a[1002];
int main(){
    int n,m,x,y,ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        a[i]=i;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        while(x!=a[x])
            x = a[x];
        while(y!=a[y])
            y = a[y];
        if(x==y)
            ans++;
        else a[x] = y;
    }
    cout<<ans<<endl;
    return 0;
}
