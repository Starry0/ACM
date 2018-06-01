#include <bits/stdc++.h>
using namespace std;
int a[10010],b[10010];
int main(){
    int n,m,z,ans = 0;
    cin>>n>>m>>z;
    for(int i=1;i*n<=z;i++)
        a[i*n] = 1;
    for(int i=1;i*m<=z;i++)
        b[i*m] = 1;
    for(int i=1;i<=z;i++){
        if(a[i]==1&&b[i]==1)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
