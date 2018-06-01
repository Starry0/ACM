#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
const int N = 11;
int main() {
    int t;
    cin >> t;
    while(t--) {
        double L, v1, v2;
        cin >> L >> v1 >> v2;
        double t = L/(v1);
        cout << t<<endl;
        printf("%.6lf %.6lf\n",9.8*t*t/2,v2*t);
    }
    return 0;
}
