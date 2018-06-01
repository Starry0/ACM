#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1030;
int a[N];
int main() {
    int t, n, k;
    ios::sync_with_stdio(false);
    scanf("%d",&t);
    // cin>>t;
    while(t--) {
        // cin >> n >> k;
        scanf("%d%d",&n,&k);
        for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        while(k--) {
            next_permutation(a+1, a+1+n);
        }
        for(int i = 1; i < n; i ++) cout << a[i] << ' ';
        cout << a[n] << endl;
    }
    return 0;
}
