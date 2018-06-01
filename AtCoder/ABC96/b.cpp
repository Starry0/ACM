#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int a[3], k;
    cin >> a[0] >> a[1] >> a[2] >> k;
    sort(a, a+3);
    cout << a[0]+a[1]+a[2]*pow(2,k) << endl;
    return 0;
}
