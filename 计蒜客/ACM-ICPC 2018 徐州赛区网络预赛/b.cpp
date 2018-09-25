#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, k, l, a, b, c;
set<int> st[2];
set<int>::iterator it;
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &l);
	int last = 0, x;
	st[last].insert(m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d",&a,&b,&c);
		last = 1 - last;
		bool flag = false;
		st[last].clear();
		for(it = st[1-last].begin(); it != st[1-last].end(); ++ it) {
			if(a != 0) {
				x = (*it)+a;
				if(x > 100) x = 100;
				st[last].insert(x);
				if(x > l && x < k) flag = true;
			}
			if(b != 0) {
				x = (*it)-b;
				if(x < -100) x = -100;
				st[last].insert(x);
				if(x > l && x < k) flag = true;
			}
			if(c != 0) {
				x = -(*it);
				st[last].insert(x);
				if(x > l && x < k) flag = true;
			}
		}
		if(flag) {
			st[1-last].clear();
			for(it = st[last].begin(); it != st[last].end(); it ++) {
				if((*it) > l && (*it) < k) st[1-last].insert((*it));
			}
			last = 1-last;
		} else {
			if(i&1) {
				for(int i = k; i <= 100; i ++) {
					if(st[last].count(i)) return 0*printf("Good Ending\n");
				}
				return 0*printf("Bad Ending\n");
			} else {
				for(int i = -100; i <= l; i ++) {
					if(st[last].count(i)) return 0*printf("Bad Ending\n");
				}
				return 0*printf("Good Ending\n");
			}
		}
	}
	printf("Normal Ending\n");
	return 0;
}