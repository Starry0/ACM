#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
char s[N];
map<char,int> mp;
int main() {
	int n, k;
	cin >> n >> k;
	cin >> s;
	int MAX = INF;
	for(int i = 0; i < n; i ++) {
		mp[s[i]]++;
	}
	map<char,int>::iterator it;
	for(it = mp.begin(); it != mp.end(); ++ it) MAX = min(MAX, (*it).second);
	if(mp.size() == k) printf("%d\n",MAX*k);
	else printf("0\n");
	return 0;
}