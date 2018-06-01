#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int N = 2e5+10;
char str[N];
struct Nod {
	string s, ss;
	string sss;
}nod[N];
inline bool cmp(Nod a, Nod b) {
	if(a.sss != b.sss) return a.sss > b.sss;
	else return a.s < b.s;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> nod[i].s >> nod[i].ss;
		int len = nod[i].ss.length()-1;
		while(nod[i].ss[len] == '0') len--;
		nod[i].sss = nod[i].ss.substr(0,len+1);
	}
	sort(nod,nod+n,cmp);
	for(int i = 0; i < n; i ++) {
		cout << nod[i].s << ' ' << nod[i].ss << endl;
	}
	return 0;
}