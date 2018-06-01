#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
const int N = 110;
string s;
int main() {
    int t, a, b, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 0) {
            cin >> a >> b;
            cout << a+b<< endl;
        } else  {
            cin >> s;
            cout <<s.length() << endl;
        }
    }
    return 0;
}
