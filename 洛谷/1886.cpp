/*#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e6+10;
int a[N], b[N], c[N];
int n,k;
map<int,int> mp;
map<int,int> ::iterator it, it1;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		mp[a[i]]++;
		if(i > k) {
			if(mp[a[i-k]] == 1) mp.erase(a[i-k]);
			else mp[a[i-k]]--;
		}
		if(i >= k) {
			it = mp.begin();
			it1 = mp.end();
			--it1;
			b[i-k] = (*mp.begin()).first;
			c[i-k] = (*(--mp.end())).first;
		}
		// printf("---------------\n");
		// for(it = mp.begin(); it != mp.end(); ++ it) {
		// 	printf("%d %d\n",(*it).first,(*it).second);
		// }
		// printf("--------------\n");
	}
	for(int i = 0; i <= n-k; i ++) printf("%d%c",b[i]," \n"[i==n-k]); 
	for(int i = 0; i <= n-k; i ++) printf("%d%c",c[i]," \n"[i==n-k]); 
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N], n, k;
typedef pair<int,int> P;
deque<P> que;
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++) {
		while(!que.empty() && que.back().second > a[i]) que.pop_back();
		que.push_back(P(i,a[i]));
		if(i < k) continue;
		while(!que.empty() && que.front().first <= i-k) que.pop_front();
		printf("%d ",que.front().second);
	}
	printf("\n");
	while(!que.empty()) que.pop_front();
	for(int i = 1; i <= n; i ++) {
		while(!que.empty() && que.back().second < a[i]) que.pop_back();
		que.push_back(P(i,a[i]));
		if(i < k) continue;
		while(!que.empty() && que.front().first <= i-k) que.pop_front();
		printf("%d ",que.front().second);
	}
	return 0;
}