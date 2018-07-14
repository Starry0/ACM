/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[10], b[4];
set<int> st;
map<int,int> mp;
int main() {
	for(int i = 0; i < 6; i ++) {
		cin >> a[i];
		st.insert(a[i]);
		mp[a[i]] ++;
	}
	map<int,int> ::iterator it = mp.begin();
	if(st.size() == 3) {
		int cnt = 0;
		for(; it != mp.end(); it ++) {
			b[cnt++] = (*it).second;
		}
		sort(b,b+3);
		if(b[0] == 1 && b[1] == 1 && b[2] == 4) printf("Bear\n");
		else printf("Hernia\n");
	} else if(st.size() == 2) {
		int cnt = 0;
		for(; it != mp.end(); it ++) {
			b[cnt++] = (*it).second;
		}
		sort(b,b+2);
		if(b[0] == 2 && b[1] == 4) printf("Elephant\n");
		else printf("Elephant\n");
	} else printf("Hernia\n");

	return 0;
}*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[10],x;
int main() {
	for(int i = 0; i < 6; i ++) {
		cin >> x;
		a[x]++;
	}
	sort(a,a+10);
	if(a[9] >= 4) {
		a[9] -= 4;
		sort(a,a+10);
		if(a[9] == 2) printf("Elephant\n");
		else if(a[9] == 1 && a[8] == 1) printf("Bear\n");
	} else printf("Hernia\n");
	return 0;
}