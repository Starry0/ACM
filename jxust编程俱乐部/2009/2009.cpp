#include <bits/stdc++.h>
using namespace std;
int a[33];
bool b[20010];
int main(){
    int n,v;
    cin>>v>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=v;i++)
        b[i]=false;
    sort(a,a+n);
    b[0]=true;
    for(int i=1;i<=n;i++){
        for(int j=v;j>=a[i];j--){
            b[j] = b[j] || b[j-a[i]];
        }
    }
    /*for(int i=1;i<=v;i++)
        cout<<i<<" "<<b[i]<<endl;*/
    int m = v;
    while(!b[m])m--;
    cout<<v-m<<endl;
}
