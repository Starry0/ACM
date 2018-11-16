#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
char s1[N], s2[N], s3[N];
int a[N], b[N];
int main() {
	int n, j;
	cin >> n >> s1 >> s2;
	for(int i = 0; i < n; i ++) a[s1[i]-'a']++, s3[i] = s1[i];
	for(int i = 0; i < n; i ++) b[s2[i]-'a']++;
	for(int i = 0; i < 26; i ++) {
		if(a[i] != b[i]) return 0*printf("-1\n");
	}
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		if(s1[i] != s2[i]) {
			for(j = i; j < n; j ++) {
				if(s1[j] == s2[i])break;
			}
			for(int k = j-1; k >= i; k --) {
				ans++;
				swap(s1[k],s1[k+1]);
			}
		}
	}
	printf("%d\n",ans);
	for(int i = 0; i < n; i ++) {
		if(s3[i] != s2[i]) {
			for(j = i; j < n; j ++) {
				if(s3[j] == s2[i])break;
			}
			for(int k = j-1; k >= i; k --) {
				printf("%d ",k+1);
				swap(s3[k],s3[k+1]);
			}
		}
	}
	return 0;
}