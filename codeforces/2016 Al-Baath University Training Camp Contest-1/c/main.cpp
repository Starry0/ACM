#include <iostream>
#define ll long long
const int mod=1e9+7;
const int N=110;
char a[N],b[N];
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>a>>b;
        ll ans =1;
        for(int i=0;i<n&&ans;i++){
            if(a[i]=='1'){
                if(b[i]=='1')
                    ans = (ans*2)%mod;
                else ans=0;
            }
        }
        if(ans)
            cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
