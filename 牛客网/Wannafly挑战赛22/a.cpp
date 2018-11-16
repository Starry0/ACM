#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;

int gcd(int a, int b) {
	return b?gcd(b,a%b):a;
}
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int ans = x;
    for(int i = 1; i < n; i ++) {
    	cin >> x;
    	ans = gcd(ans, x);
    }
    printf("%d\n",m/ans);
    return 0;
}