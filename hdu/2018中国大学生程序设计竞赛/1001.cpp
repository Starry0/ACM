#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N = 1e5+10;
using namespace std;
typedef pair<ll,bool> P;
multiset<P> st;
int t, p;
ll x, ans, res;
int main() {
	scanf("%d", &t);
	while(t--) {
		st.clear();
		scanf("%d", &p);
		ans = res = 0;
		for(int i = 0; i < p; i ++) {
			scanf("%lld", &x);
			if(st.size() && (*st.begin()).first < x) {
				ans += (x-(*st.begin()).first);
				if((*st.begin()).second) res++;
				st.erase(st.begin());
				st.insert(P(x,1));
				st.insert(P(x,0));
			} else st.insert(P(x,1));
		}
		printf("%lld %lld\n",ans, res*2);
	}
	return 0;
}