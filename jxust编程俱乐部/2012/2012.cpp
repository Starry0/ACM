#include <bits/stdc++.h>
int a[10010],b[10010];
using namespace std;
int main(){
    int n;
    long long sum = 0;
    cin>>n;
    for(int i = 0;i < n;i++)
        //scanf("%d",a[i]);
        cin>>a[i];
    for(int i = 0;i < n;i++)
        //scanf("%d",b[i]);
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0;i < n; i++){
        //cout<<a[i]<<' '<<b[n-i-1]<<endl;
        sum += abs(a[i] -b[n-i-1]);
    }
    cout<<sum<<endl;
    return 0;
}
