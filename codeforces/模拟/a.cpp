#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int m = 1;
    // cout << isPrime(4)<< endl;
    while(true){
        if(!isPrime(n*m+1)){
            cout << m << endl;
            break;
        }
        m++;
    }
    return 0;
}
