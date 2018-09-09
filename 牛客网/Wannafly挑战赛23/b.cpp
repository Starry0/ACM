#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int SG[N], mex[200], a[N];
vector<int> vs[N];
int MAX = 0;
void getSG(int n) {
	for(int i = 1; i < N; i ++) {
		for(int j = i; j < N; j += i) {
			vs[j].push_back(i);
		}
	}
	for(int i = 1; i <= n; i ++) {
		memset(mex,0,sizeof(mex));
		for(int j = 0; j < vs[i].size(); j ++) mex[SG[i-vs[i][j]]] = 1;
		for(int j = 0; ; j ++) {
			if(!mex[j]) {
				SG[i] = j;
				break;
			}
		}
	}
}
int main() {
	int n, x, ans = 0;
	getSG(N);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		ans ^= SG[a[i]];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < vs[a[i]].size(); j ++) {
			if((ans^SG[a[i]]) == SG[a[i]-vs[a[i]][j]]) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}