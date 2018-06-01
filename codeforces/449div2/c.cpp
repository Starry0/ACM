#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAX = 1e5+10;
char str0[80] = {"What are you doing at the end of the world? Are you busy? Will you save us?"};
char str1[80] = {"What are you doing while sending \"\"? Are you busy? Will you send \"\"?"};

ull min(ull x, ull y) {
	return x<y?x:y;
}
ull cnt[MAX];
char dfs(ull n, ull k) {
	if(k >= cnt[n]) return '.';
	if(n == 0) return str0[k];
	if(k < 34) return str1[k];
	k -= 34;
	if(k < cnt[n-1]) return dfs(n-1,k);
	k -= cnt[n-1];
	if(k < 32) return str1[34+k];
	k -= 32;
	if(k < cnt[n-1]) return dfs(n-1,k);
	k -= cnt[n-1];
	return str1[k+66];
}
int main(){
	ull q, n, k;
	cnt[0] = 75;
	for(int i=1; i<MAX; ++i) cnt[i] = cnt[i-1]*2 + 68;
	cin >> q;
	while(q--) {
		cin >> n >> k;
		printf("%c",dfs(n,k-1));
	}
	return 0;
}

/*
What are you doing at the end of the world? Are you busy? Will you save us?

What are you doing while sending "
What are you doing at the end of the world? Are you busy? Will you save us?
"? Are you busy? Will you send "
What are you doing at the end of the world? Are you busy? Will you save us?
"?

What are you doing while sending "fi-1"? Are you busy? Will you send "fi-1"?
*/