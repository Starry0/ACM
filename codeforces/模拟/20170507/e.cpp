#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int N = 1e6+10;
int main(){
    char s[N];
    cin >> s;
    ll len = strlen(s);
    ll res = 0, ans = 0;
    for(int i = len -1; i >= 0; i --){
        if(s[i] == 'a'){
            ans = (res+ans) %mod;
            res = (res*2) % mod;
        }
        else res++;
    }
    cout << ans % mod << endl;
    return 0;
}
