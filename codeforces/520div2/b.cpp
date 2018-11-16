#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int main() {
	int n;
	cin >> n;
	if(n == 1) return 0*printf("1 0\n");
	int res = 0;
	for(int i = 2; i <= n; i ++) {
		if(n%i == 0) {
			v.push_back(i);
			while(n%i == 0) {
				mp[i] ++;
				n /= i;
			}
		}
	}
	int MAX = 0, ans = 1, MIN = 1;
	set<int> st;
	for(auto x : v) {
		ans *= x;
		MAX = max(MAX, mp[x]);
		st.insert(mp[x]);
		printf("%d %d\n",x,mp[x]);
	}
	int bit;
	for(bit = 0; (1<<bit) < MAX; bit ++) ;
	if((1<<bit) == MAX && st.size() == 1) MIN = 0;
	printf("%d %d\n",ans,MIN+bit);
	return 0;
}