#include <bits/stdc++.h>
using namespace std;
int a[25];
bool b[110];
int main(){
    int t,n,y;
    cin>>t;
    while(t--){
        cin>>n>>y;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        b[a[1]]=true;
        for(int i=2;i<=n;i++){
            for(int j=y;j>=a[i];j--){
                b[j] = b[j] || b[abs(j-a[i])];
            }
        }
        if(b[y])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
