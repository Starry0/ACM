#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int x){
    if(x <2) return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int ans = n;
    if(n <= 2) cout << 1 << endl;
    else if(is_prime(n)) cout << 2 << endl;
    else{
        for(int i = 2; i <= n; i++){
            if(n%i == 0){
                ans = ans*(i-1)/i;
                while(n%i == 0) n/=i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
