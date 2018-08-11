#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 150010;
int n, m, t, x, k, q;
struct Nod{
	char s[201];
	int id, v;
	bool friend operator < (const Nod &a , const Nod &b) {
		return ((a.v == b.v && a.id > b.id) || (a.v < b.v));
	}
}e[N];
struct Node{
	int t, p;
	bool friend operator < (const Node &a, const Node &b) {
		return a.t < b.t;
	}
}b[N];
Nod str[50000];
int main() {
	cin >> t;
	priority_queue<Nod> que;
	while(t--) {
		while(que.size()) que.pop();
		cin >> k >> m >> q;
		for(int i = 1; i <= k; i ++) {
			cin >> e[i].s >> e[i].v;
			e[i].id = i;
		}
		for(int i = 0; i < m; i ++) {
			scanf("%d%d",&b[i].t,&b[i].p);
		}
		sort(b,b+m);
		int cnt = 1, cnt1 = 1;
		for(int i = 0; i < m; i ++) {
			while(cnt <= b[i].t) que.push(e[cnt++]);
			for(int j = 0; j < b[i].p; j ++) {
				if(que.empty()) break;
				str[cnt1++] = que.top(), que.pop();
			}
		}
		while(cnt <= k) que.push(e[cnt++]);
		while(que.size()) str[cnt1++] = que.top(), que.pop();
		for(int i = 1; i <= q; i ++) {
			scanf("%d", &x);
			printf("%s%c",str[x].s," \n"[i==q]);
		}
	}
	return 0;
}