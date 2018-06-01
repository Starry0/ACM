#include <iostream>
#include <stdio.h>
using namespace std;
int n, m;
const int M = 70;
int dp[32000], v[M], p[M], q[M], son[70][2];
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		cin >> v[i] >> p[i] >> q[i];
		if(q[i]) {
			if(son[q[i]][0])son[q[i]][1] = i;
			else son[q[i]][0] = 1;
		}
	}
	for(int i = 0; i < m; i ++) {
		if(q[i]) {
			for(int j = n; j >= 0; j --) {
				int s1 = son[i][0], s2 = son[i][1];
				if (i-v[k]>=0)                   f[i]=max(f[i], f[i-v[k]]+v[k]*p[k]);               
                if (s1 && i-v[k]-v[s1]>=0)       f[i]=max(f[i], f[i-v[k]-v[s1]] +v[k]*p[k] +v[s1]*p[s1]);
                if (s2 && i-v[k]-v[s2]>=0)       f[i]=max(f[i], f[i-v[k]-v[s2]] +v[k]*p[k] +v[s2]*p[s2]);
                if (s2 && i-v[k]-v[s2]-v[s1]>=0) f[i]=max(f[i], f[i-v[k]-v[s2]-v[s1]] +v[k]*p[k] +v[s1]*p[s1] +v[s2]*p[s2]);
			}
		}
	}
	printf("%d", dp[n]);
	return 0;
}