#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
pair<int,int> p[N];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> p[i].first, p[i].second = i;
	sort(p,p+n);
	int a = 1, b = 1, c = 1, d = 0;
	while(c < n) {
		if(p[c].first == b && p[d].first == a) {
			return 0*printf("%d %d\n",p[d].second+1,p[c].second+1);
		}
		a += b;swap(a,b);
		while(c < n && p[c].first < b) c++;
		while(c < n && p[d].first < a) d++;
	}
	printf("impossible\n");
	return 0;
}