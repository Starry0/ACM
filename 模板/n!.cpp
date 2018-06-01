#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
void factorial(int n){
    int a[N];
    a[0] = 1;
    int res = 0;
    for(int i = 1; i <= n; i ++){
        int flag = 0;
        for(int j = 0; j <= res; j ++){
            a[j] = a[j]*i + flag;
            flag = a[j]/10000;
            a[j]%=10000;
        }
        if(flag > 0){
            a[++res] = flag;
        }
    }
    cout << a[res];
    for(int i = res-1; i >= 0; i--){
        cout << setw(4) << setfill('0') << a[i];
    }
    cout << endl;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        factorial(n);
    }
    return 0;
}
