#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N];

int main() {
    int n, m;
    while(cin>>n>>m) {
        for(int i = 1; i <= n; i ++) a[i] = i;
        m--;
        while(m--) {
            next_permutation(a+1,a+n+1);
        }
        for(int i = 1; i <= n; i ++) printf("%d%c",a[i],(i==n)?'\n':' ');
    }
    return 0;
}
