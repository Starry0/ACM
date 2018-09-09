#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
char s[N];
map<char,int> mp;
int main() {
	cin >> s;
	int len = strlen(s);
	int MIN = INF, l = 0;
	for(int i = 0; i < len; i ++) {
		mp[s[i]]++;
		if(mp.size() == 26) {
			while(mp[s[l]] > 1) {
				mp[s[l]]--;
				l++;
			}
			MIN = min(MIN, i-l+1);
		}
	}
	cout << MIN << endl;
	return 0;
}