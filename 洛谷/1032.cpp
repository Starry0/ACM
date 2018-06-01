#include <bits/stdc++.h>
using namespace std;
string be[7], en[7];
int n, cnt = 1;
struct Nod {
	string str;
	int step;
}nod,q;
map<string,int> mp;
int bfs() {
	queue<Nod> que;
	nod.str = be[0];
	nod.step = 0;
	mp[be[0]] = 1;
	que.push(nod);
	while(que.size()) {
		q = que.front();
		que.pop();
		if(q.str == en[0]) return q.step;
		if(q.step > 10) return 11;
		for(int i = 1; i < cnt; i ++) {
			int tmp = -1;
			while((tmp=q.str.find(be[i],tmp+1)) != string::npos) {
				nod.str = q.str.substr(0,tmp) + en[i] + q.str.substr(tmp+be[i].length());
				if(mp[nod.str])continue;
				nod.step = q.step + 1;
			//	cout << nod.str << ' ' << nod.step << endl;
				que.push(nod);
				mp[nod.str] = 1;
			}
		}
	}
	return 11;
}

int main() {
	cin >> be[0] >> en[0];
	while(cin >> be[cnt] >> en[cnt]) cnt++;
	int ans = bfs();
	if(ans > 10) printf("NO ANSWER!\n");
	else printf("%d\n",ans);
	return 0;
}