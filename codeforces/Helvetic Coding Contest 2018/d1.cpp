#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+10;
int a[M], m, b[4];
typedef pair<int,int> P;
map<P,int> mp;
vector<P> vs;
char str[20];
int main() {
	cin >> m;
	for(int i = 1; i <= m; i ++) {
		cin >> str;
		memset(b, 0, sizeof(b));
		int cnt = 1;
		int len = strlen(str);
		for(int i = 1; i < len; i ++) {
			if(str[i] >= '0' && str[i] <= '9') {
				if(str[i+1] >= '0' && str[i+1] <= '9' && i+1 < len) {
					b[cnt++] = (str[i]-'0')*10+str[i+1]-'0';
					i++;
				}else b[cnt++] = str[i] -'0';
			}
		}
		b[1] += b[2];
		int tmp = __gcd(b[1],b[3]);
		b[1] /= tmp; b[3] /= tmp;
		vs.push_back(make_pair(b[1],b[3]));
		mp[make_pair(b[1],b[3])]++;
	}
	for(int i = 0; i < m; i ++) {
		cout << mp[make_pair(vs[i].first,vs[i].second)] << ' ';
	}
	return 0;
}

