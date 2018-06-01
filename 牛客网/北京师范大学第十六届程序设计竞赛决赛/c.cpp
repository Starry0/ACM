#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        printf("%.12f\n",1.0*(n*n-1)/3.0);
    }
    return 0;
}
