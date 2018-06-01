#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
const int M = 10010;
int n, m;

int main() {
	int t;
	cin >> t;
	while(t--){
		double a, b;
		cin >> a >> b;
		int c = floor(a/b);
		if(c*1.0 == (a/b)) c--;
		cout << c << endl;
	}
	return 0;
}