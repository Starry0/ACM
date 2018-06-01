#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
using namespace std;
const int N = 110;
vector<int> mo[N], ba[N];
set<int> st;
int t, n, m, x, y;
void init() {
	for(int i = 0; i < N; i ++) {
		mo[i].clear();
		ba[i].clear();
	}
}
void fun(int xx) {
	st.clear();
	for(int i = 0; i < mo[xx].size(); i ++) {
		int yy = mo[xx][i];
		for(int j = 0; j < ba[yy].size(); j ++) {
			st.insert(ba[yy][j]);
		}
	}
} 
void print(int xx) {
	set<int>::iterator it = st.begin();
	for(; it != st.end(); ++ it) {
		printf("%d %d\n",xx,(*it));
	}
}
int main() {
	scanf("%d", &t);
	while(t--) {
		init();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i ++) {
			scanf("%d %d", &x, &y);
			mo[x].push_back(y);
		}
		for(int i = 1; i <= m; i ++) {
			scanf("%d %d", &x, &y);
			ba[x].push_back(y);
		}
		for(int i = 1; i <= 55; i ++) {
			fun(i);
			print(i);
		}
		printf("\n");
	}
	return 0;
}