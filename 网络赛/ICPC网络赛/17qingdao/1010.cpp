#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
int a[N];
bool vis[N];
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--) {
		memset(vis, false, sizeof(vis));
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i ++) {
			if(i == 0) {
				if(a[i] > a[i+1]) vis[i] = true;
			} else if(i == n-1) {
				if(a[i-1] > a[i]) vis[i] = true;
			} else {
				if(a[i-1] > a[i] || a[i] > a[i+1]) vis[i] = true;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i ++) if(!vis[i]) ans++;
		printf("%d\n",ans);
		for(int i = 0; i < n; i ++) {
			if(!vis[i]) printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}