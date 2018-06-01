#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, v;
        cin >> a >> b >> c >> d >> v;
        int e = abs(5-v%10);
        int toc = b*5+c*10+d*50;
        if(e == 0 || e == 5) {
            cout << a << endl;
        } else {
            cout << a + e*(toc/(e+v)) << endl;
        }
    }
    return 0;
}