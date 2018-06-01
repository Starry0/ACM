#include <bits/stdc++.h>
#define ll long long
const int N = 110;
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if(n == 1) return 0*printf("0\n");
	printf("%d\n",min(a,b)+(n-2)*(min(a,min(b,c))));
	return 0;
}