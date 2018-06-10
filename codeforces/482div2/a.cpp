#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if(n == 0) return 0*printf("0\n");
    if(n&1) printf("%lld\n",n/2+1);
    else printf("%lld\n",n+1);
    return 0;
}
