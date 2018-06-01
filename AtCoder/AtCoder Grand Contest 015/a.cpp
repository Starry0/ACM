#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b || (a < b && n == 1)){
        cout << 0 << endl;
    }else if(a == b || (a < b && n == 2)){
        cout << 1 << endl;
    }else if(a < b && n >= 2){
        cout << (n-1)*b+a-(n-1)*a-b+1<<endl;
    }
    return 0;
}
