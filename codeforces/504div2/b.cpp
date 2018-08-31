#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;

int main() {
	ll n, k;
	cin >> n >> k;
	printf("%lld\n",min(k-1,max(k/2,n))-k/2);
    return 0;
}
