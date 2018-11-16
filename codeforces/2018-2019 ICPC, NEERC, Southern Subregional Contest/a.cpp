#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
struct Nod{
	int d, s;
	string str;
};
bool vis[N/2][N*5];
int d, s;
void bfs() {
	queue<Nod> que;
	que.push({0,0,""});
	vis[0][0] = 1;
	while(que.size()) {
		Nod nod = que.front();
		que.pop();
		if(nod.s > s) continue;
		if(nod.d == 0 && nod.s == s) {
			cout << nod.str << endl;
			return;
		}
		for(int i = 0; i < 10; i ++) {
			int dd = (nod.d*10+i)%d;
			int ss = nod.s + i;
			if(!vis[dd][ss]) {
				vis[dd][ss] = 1;
				que.push({dd,ss,nod.str+char(i+'0')});
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	cin >> d >> s;
	bfs();
	return 0;
}