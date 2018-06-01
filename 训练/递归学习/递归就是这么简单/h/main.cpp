#include <iostream>
#define ll long long
using namespace std;
ll f(int m, int n){
    int ans = 0;
    if(m==0 || n==1) return 1;
    if(n > m) return f(m, m);
    else return f(m, n -1) + f(m-n, n);
}
int main(){
    int t, m, n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        cout << f(m, n) << endl;
    }
    return 0;
}
