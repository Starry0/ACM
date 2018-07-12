/*#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct Nod{
	int r[3];
}nod[N];

bool cmp(const Nod &a, const Nod &b) {
	return a.r[2] < b.r[2];
}
set<int> st[2];
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) {
			scanf("%d%d%d", &nod[i].r[0], &nod[i].r[1], &nod[i].r[2]);
		}
		int last = 0;
		st[0].insert(n-1);
		sort(nod,nod+n,cmp);
		set<int> :: iterator it;
		for(int i = n-2; i >= 0; i --) {
			last = 1 - last;
			for(it = st[1-last].begin(); it != st[1-last].end(); ++it) {
				int v = (*it);
				if(nod[v].r[0] < nod[i].r[0] || nod[v].r[1] < nod[i].r[1]) {
					st[last].insert(v);
				}
			}
			st[last].insert(i);
			st[1-last].clear();
		}
		cout << st[last].size() << endl;
	}
	return 0;
}*/


/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct node {
	int r1, r2, r3;
}E[N];

struct comparefirst {
	bool operator() (node A, node B) {
		return A.r1 < A.r1;
	}
} cmp;

struct comparesecond {
	bool operator() (node A, node B) {
		return A.r2 < B.r2;
	}
};

set<node, comparesecond> st;

int main() {
	int t, n;
	cin >>t;
	set<node> :: iterator it, itprev, itnext;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i ++) cin >> E[i].r1 >> E[i].r2 >> E[i].r3;
		sort(E,E+n,cmp);
		int ans = 1;
		st.clear();
		st.insert(E[0]);
		for(int i = 1; i < n; i ++) {
			itnext = st.lower_bound(E[i]);
			itprev = itnext;
			itprev--;
			if(itnext == st.begin() || E[i].r3 < itprev->r3) {
				ans ++;
				for(it = itnext; it != st.end() && E[i].r3 < it->r3;)
					st.erase(it++);
				st.insert(E[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct engineer{
	int r1, r2, r3;
	engineer(){}
	engineer(int r1, int r2, int r3) :r1(r1), r2(r2), r3(r3){}
};

struct comparefirst {
	bool operator() (engineer A, engineer B) {
		return A.r1 < B.r1;
	}
}cmp1;

struct comparesecond {
	bool operator() (engineer A, engineer B) {
		return A.r2 < B.r2;
	}
};

engineer E[N];
set<engineer, comparesecond> S;

int main() {
	set<engineer> :: iterator it, itprev, itnext;
	int t, n, r1, r2, r3;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i ++) {
			cin >> r1 >> r2 >> r3;
			E[i] = engineer(r1,r2,r3);
		}
		sort(E, E+n, cmp1);
		int ans = 1;
		S.clear();
		S.insert(E[0]);
		for(int i = 1; i < n; i ++) {
			itnext = S.lower_bound(E[i]);
			itprev = itnext;
			itprev--;
			if(itnext == S.begin() || E[i].r3 < itprev->r3) {
				ans++;
				for(it = itnext; it != S.end() && E[i].r3 < it->r3;)
					S.erase(it++);
				S.insert(E[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}