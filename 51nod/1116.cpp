#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char s[N];
int len;
map<char,int> mp;
int pow_mod(int x, int n, int mod) {
	int y = 1;
	while(n) {
		if(n&1) y = y*x%mod;
		x = x*x%mod;
		n >>= 1;
	}
	return y;
}
bool ok(int k) {
    int ans = 0;
	for(int i = 0; i < len; i ++) {
		ans += pow_mod(k,(len-i-1)%(k-1),k-1)*mp[s[i]]%(k-1);
	}
	ans %= (k-1);
	return ans == 0;
}
int main() {
	cin >> s;
	len = strlen(s);
	for(int i = 0; i < 10; i ++) mp['0'+i] = i;
	for(int i = 0; i < 26; i ++) mp['A'+i] = i+10;
	int k = 2;
	for(int i = 0; i < len; i ++) k = max(k, mp[s[i]]);
	for( ++ k; k <= 36; k ++) {
		if(ok(k)) return 0*printf("%d\n",k);
	}
	printf("No Solution\n");
	return 0;
}