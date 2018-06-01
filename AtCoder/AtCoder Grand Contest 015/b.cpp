#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char a[N];
int b[N];
int main(){
    cin >> a;
    int flag = 0, flag1 = 0;
    ll ans = 0, len = strlen(a);
    for(int i = len-1; i >= 0; i--){
        if(a[i] == 'D'){
            flag = 1;
        }
        if(flag) b[i] = 1;
        else b[i] = 0;
    }
    for(int i = 0; i < len; i ++){
        if(a[i] == 'U'){
            flag1 = 1;
            ans += (len-i-1);
            if(b[i]){
                ans += 2*i;
            }
        }else if(a[i] == 'D'){
            ans += i;
            if(flag1){
                ans += 2*(len-i-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
