#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b,c;
    cin >> a >> b >> c;
    for(int x = 1; x <= a; x ++) {
        int y = a/x;
        int z = c/x;
        if(x*y == a && y*z == b && x*z == c) {
            return 0*printf("%d\n",4*(x+y+z));
        }
    }

    return 0;
}
