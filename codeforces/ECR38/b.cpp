#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] > 5e5) a[i] = 1e6-a[i]+1;
    }
    sort(a,a+n);
    cout << a[n-1]-1 << endl;
    return 0;
}
