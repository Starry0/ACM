#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;
int a[maxn];
bool prime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % 2 == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int k = 1;
    for(int i = 2; i <= n+1; i++)
        a[i] = 1;
    for(int i = 2; i <= n+1; i++){
        if(prime(i)){
            for(int j = 2; i*j <= n+1; j++){
                a[i*j] += 1;
            }
        }
    }
    for(int i = 2; i <= n+1; i++)
        k = max(k,a[i]);
    cout<<k<<endl;
    for(int i = 2; i <= n+1; i++){
        if(i == 2)
            cout<<a[i];
        else cout<<' '<<a[i];
    }
    cout<<endl;
    return 0;
}
