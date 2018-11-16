#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define lson l, m, rt<<1
#define rson m+1,r, rt<<1|1
using namespace std;
const int N = 3e3+10;
int n, m;
int MAX[N<<2];
int max(int a, int b){
    return a>b?a:b;
}
void PushDP(int rt){
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}
void update(int x, int y, int l, int r, int rt){
    if (l == r){
        MAX[rt] = y;
        return ;
    }
    int m = (l + r) >> 1;
    if(x <= m) update(x, y, lson);
    else update(x, y, rson);
    PushDP(rt);
}
int Query(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r){
        return MAX[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if( m >= L) ret = max(ret, Query(L, R ,lson));
    if( m < R) ret = max(ret, Query(L, R, rson));
    return ret;
}
struct Nod{
	int p, c, id;
}e[N];
struct cmp {
	bool operator()(Nod a, Nod b){
		return a.c > b.c;
	}
};
priority_queue<Nod, vector<Nod>, cmp> que[N];
bool vis[N];
bool cmp1(Nod a, Nod b) {
	return a.c < b.c;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> e[i].p >> e[i].c;
		que[e[i].p].push(e[i]);
		if(e[i].p) {
			vis[i] = 1;
			continue;
		}
		update(e[i].p, 1, 1, n, 1);
	}
	sort(e+1,e+1+n, cmp1);
	ll MIN = 0, one = que[1].size();
	while(true) {
		int First = MAX[1];
		if(one == First) {
			int cnt1 = 0;
			for(int i = 1; i <= n; i ++) {
				if(vis[i] == 0) {
					cnt1 = e[i].c;
					break;
				}
			}
			MIN += cnt1;
			one ++;
		} else if(one+1 == First) {
			ll cnt1 = INF, cnt2 = INF;
			int id1 = -1, id2 = -1;
			for(int i = 1; i <= n; i ++) {
				if(vis[i]) continue;
				if(e[i].c < cnt1) {
					cnt2 = cnt1;
					cnt1 = e[i].c;
					id2 = id1;
					id1 = e[i].p;
				} else if(e[i].c < cnt2) {
					cnt2 = e[i].c;
					id2 = e[i].p;
				}
			}
			ll cnt3 = INF, id3 = -1;
			for(int i = 1; i <= n; i ++) {
				if(First == Query(i,i,1,n,1)) {
					id3 = i;
					break;
				}
			}
			cnt3 = que[id3].top();
			if(id3 == id1 || id3 == id1) {
				MIN += cnt3;
			} else {
				MIN += min(cnt1+cnt2,cnt3);
			}
			one += 2;
		} else if(one + 1 < First) {
			ll cnt1 = INF, cnt2 = INF;
			int id1 = -1, id2 = -1;
			int index1 = -1, index2 = -1;
			for(int i = 1; i <= n; i ++) {
				if(vis[i]) continue;
				if(e[i].c < cnt1) {
					cnt2 = cnt1;
					cnt1 = e[i].c;
					id2 = id1;
					id1 = e[i].p;
					index2 = index1;
					index1 = i;
				} else if(e[i].c < cnt2) {
					cnt2 = e[i].c;
					id2 = e[i].p;
					index2 = i;
				}
			}
			int cnt3 = INF, id3 = -1, index3 = -1;
			for(int i = 1; i <= n; i ++) {
				if(First == Query(i,i,1,n,1)) {
					if(que[i].top() < cnt3) {
						id3 = i;
						cnt3 = que[i].top();
					}
				}
			}
			if(id3==id1 || id3==id2) {
				MIN += cnt;
			}
		}
		First = MAX[1];
		if(one > First) break;
	}
	cout << MIN << endl;
	return 0;
}