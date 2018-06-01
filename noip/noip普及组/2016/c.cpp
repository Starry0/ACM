/*
70分程序

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
set<int> st[N], stt;
set<int>::iterator it;
int main(){
	int n, index = 0;
	cin >> n;
	while(n--) {
		int t, k, x;
		cin >> t >> k;
		a[index] = t;
		for(int i = 1; i <= k; i ++) {
			cin >> x;
			st[index].insert(x);
		}
		index++;
		for(int i = lower_bound(a, a+index,t-86400+1)-a; i < index; i ++) {
			for(it = st[i].begin(); it != st[i].end(); ++ it) {
				stt.insert((*it));
			}
		}
		cout << stt.size() << endl;
		stt.clear();
	}
	return 0;
}


