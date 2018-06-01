#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
typedef pair<int,ull>P;
const int N = 1e5+5;
ull Hash[N], s[N],S[N];
map<ull,int>pre[200005];
P query[N];
bool ok[N];

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		Hash[i] = (ll)rand()*rand()*rand();
	}
	S[0] = 0;
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&s[i]);
		S[i] = S[i-1] +  Hash[s[i]];
	}
	int m;
	cin >> m;
	for(int j = 0; j < m; j ++){
		int k;
		scanf("%d",&k);
		ull sum = 0;
		for(int i = 1; i <= k; i ++){
			int x;
			scanf("%d",&x);
			sum += Hash[x];
		}
		query[j] = P(k,sum);
	}
	memset(ok,false,sizeof(ok));
	for(int i = 0; i < m; i ++){
		int len = query[i].first;
		if(ok[len]) continue;
		for(int j = len; j <= n; j ++){
			ull tmp = S[j] - S[j-len];
			pre[len][tmp]++;
		}
		ok[len] = true;
	}
	for(int i = 0; i < m; i ++){
		int len = query[i].first;
		ull sum = query[i].second;
		printf("%lld\n",pre[len][sum]);
	}
	return 0;
}