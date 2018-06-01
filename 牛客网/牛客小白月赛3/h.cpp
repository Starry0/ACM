#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n;
    while(cin >> n) {
        int x = (n+7)%10, y = (n+9)%12;
        if(x == 0) x = 10;
        if(y == 0) y = 12;
        printf("%d %d\n",x,y);
    }
    return 0;
}
