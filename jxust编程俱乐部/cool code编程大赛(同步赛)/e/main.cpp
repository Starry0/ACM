#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    while(cin >>n){
        ll sum = 0, tm = 3;
        while(n >= tm){
            sum += (n/tm);
            tm *=3;
        }
        cout << sum << endl;
    }
    return 0;
}
