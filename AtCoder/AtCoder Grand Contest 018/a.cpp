#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    set<int> st;
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]),st.insert(a[i]);
    sort(a,a+n);
    if(n == 1){
        if(a[0] == k) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
        return 0;
    }
    if(a[n-1] < k){
        cout << "IMPOSSIBLE\n";
    }else{
        int ans = __gcd(a[n-2],a[n-1]);
        for(int i = 0; i < n-1; i ++){
            int ans1 = __gcd(a[i],a[i+1]);
            if(ans1 < ans) ans = ans1;
        }
        bool flag = true;
        for(int i = 0; i < n; i ++) {
            if(a[i]%ans != 0){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << "POSSIBLE\n";
        }else{
            if(__gcd(ans,k) == ans){
                cout << "POSSIBLE\n";
            } else cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
