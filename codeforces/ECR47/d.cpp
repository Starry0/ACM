#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int, int> > v;
int main() {
	int n, m;	
	cin >> n >> m;
	if(m < n-1) return 0*printf("Impossible\n");
	for(int i = 1; i<n&&m; i ++) {
		for(int j = i+1; j<=n&&m; j ++) {
			if(__gcd(i,j) == 1) {
				m--;
				v.push_back(make_pair(i,j));
			}
		}
	}
	if(m) printf("Impossible\n");
	else {
		printf("Possible\n");
		for(auto p : v){
			printf("%d %d\n",p.first, p.second);
		}
	}
	return 0;
}