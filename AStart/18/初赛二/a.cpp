/*#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
int a[N], fa[N];
struct Nod{
	int x, y;
}e[N];
int find(int x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}
int main() {
	ll t, n, m, k, x, y;
	// scanf("%lld", &t);
	cin >> t;
	while(t--) {
		// scanf("%lld%lld%lld", &n, &m, &k);
		cin >> n >> m >> k;
		for(int i = 0; i < k; i ++) {
			// scanf("%lld%lld",)
			cin >> e[i].x >> e[i].y;
			a[e[i].x]++;
			a[e[i].y]++;
		}

	}
	return 0;
}*/
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e5+10;
vector<int> vs[N];
int n, m, x, y, k, t;
int main(){
	cin >> t;
    while(t--){
        for(int i = 0; i < n; i ++) vs[i].clear();
        cin >> n >> m >> k;
        for(int i = 0; i < m; i ++){
            cin >> x >> y;
            vs[x].push_back(y); vs[y].push_back(x);
        }
        int res = 0;
        for(int i = 0; i < n; i ++){
            if(vs[i].size() > res){
                res = vs[i].size();
            }
        }
        int ans = m - res;
        if(ans >= k){
        	cout << n-(ans-k)-1 << endl;
        }else{
        	cout << n-1 << endl;
        }
    }
    return 0;
}
