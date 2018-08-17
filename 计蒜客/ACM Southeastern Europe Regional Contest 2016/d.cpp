#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int main() {
	int n, pos;
	cin >> n >> pos;
	string s1, s2;
	cin >> s1;
	while(n--) {
		int cnt = 0;
		s2 = "";
		for(int i = 0; i < s1.length(); i += 2) {
			int a = s1[i]-'0', b = s1[i+1] - '0';
			for(int j = 0; j < a; j ++) {
				s2 += '0'+b;
			}
		}
		s1 = s2;
	}
	cout << s1[pos] << endl;
	return 0;
}