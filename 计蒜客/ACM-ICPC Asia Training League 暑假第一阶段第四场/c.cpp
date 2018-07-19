#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
char s1[N], s2[N], s3[N];
int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i ++) {
		int n, m;
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		memset(s3, 0, sizeof(s3));
		cin >> n >> m;
		cin >> s1 >> s2 >> s3;
		int ans = s1[0]-s2[0];
		for(int j = 0; s3[j]; j ++) {
			s3[j] += ans;
			if(s3[j] < 'A') s3[j] += 26;
			else if(s3[j] > 'Z') s3[j] -= 26;
		}
		printf("Case #%d: %s\n",i,s3);
	}
	return 0;
}