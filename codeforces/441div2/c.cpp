#include <bits/stdc++.h>
#define ll long long
const int N = 110;
using namespace std;
vector<int> vs;
int fun(int x) {
	int sum = x;
	while(x > 0) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	for(int i = max(1,n-81); i < n; i ++) {
		if(fun(i) == n) vs.push_back(i);
	}
	if((int)vs.size() == 0) return 0*printf("0\n");
	int len = vs.size();
	printf("%d\n", len);
	for(int i = 0; i < len-1; i ++) {
		printf("%d ", vs[i]);
	}
	printf("%d\n",vs[len-1]);
	return 0;
}