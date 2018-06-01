#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll d = (float)pow(a*b,1.0/3);
        if(d*d*d == a*b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
