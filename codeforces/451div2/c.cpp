#include <bits/stdc++.h>
using namespace std;
vector<string> vs[22];
map<string, int> mp;
map<int, string> mp1;
int main() {
	int n, m;
	string s, ss;
	cin >> n;
	int ans = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> s >> m;
		if(mp[s] == 0) {
			mp1[ans] = s;
			mp[s] = ans++;
		}
		for(int j = 1; j <= m; j ++) {
			cin >> ss;
			reverse(ss.begin(), ss.end());
			int len = vs[mp[s]].size();
			bool flag = true;
			for(int k = 0; k < len; k ++) {
				if(vs[mp[s]][k].find(ss) == 0) {
					flag = false;
					break;
				} 
				if(ss.find(vs[mp[s]][k]) == 0) {
					flag = false;
					vs[mp[s]].erase(vs[mp[s]].begin()+k);
					vs[mp[s]].push_back(ss);
					break;
				}
			}
			if(flag) vs[mp[s]].push_back(ss);
		}
	}
	printf("%d\n",ans-1);
	for(int i = 1; i < ans; i ++) {
		cout << mp1[i];
		printf(" %d", vs[i].size());
		for(int j = 0; j < vs[i].size(); j ++) {
			reverse(vs[i][j].begin(), vs[i][j].end());
			cout << " " << vs[i][j];
		}
		cout << endl;
	}
	return 0;
}
/*
2
l 25 02 8 62 13 31 7 27 80 81 10 92 50 4 5 98 26 19 39 22 90 75 76 82 34 63
e 22 0 91 60 2 44 69 66 70 15 3 09 7 62 65 36 34 57 13 02 73 07 20

2
e 18 66 15 13 36 44 91 02 62 65 20 60 73 57 34 09 70 07 69 
l 21 39 22 10 26 81 27 62 76 80 50 02 19 75 92 98 63 90 82 13 34 31 




e 18 66 15 13 36 44 91 02 62 65 20 60 73 57 34 09 70 07 69 
e 22 0 91 60 2 44 69 66 70 15 3 09 7 62 65 36 34 57 13 02 73 07 20

*/

