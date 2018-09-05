#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 5010;
struct Nod{
	ll l, r;
}e[N];
ll yy, y2, m1, m2, d1, d2, h1, h2, mm1, mm2;
bool ok() {
	if(y2%4==0&&y2%100!=0 || y2%400==0) return true;
	else return false;
}
void dayplus() {
	d2++;
	if(d2 == 32 && (m2==1 || m2==3 || m2==5 || m2==7 || m2==8 || m2==10 || m2 == 12)) {
		d2 = 1;
		m2++;
	} else if(d2 == 31 || (m2==4 || m2 == 6 || m2==9 || m2==11)) {
		d2 = 1;
		m2++;
	} else if(m2 == 2 && ((d2==29 && !ok())||(d2==30 && ok()))) {
		d2 = 1;
		m2++;
	}
	if(m2 == 13) {
		m2 = 1;
		y2++;
	}
}
bool cmp(Nod a, Nod b) {
	if(a.l != b.l) return a.l < b.l;
	else return a.r < b.r;
}
int main() {
	int t, b, c;
	char s[10];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &b, &c);
		for(int i = 1; i <= b; i ++) {
			scanf("%s %lld-%lld-%lld %lld:%lld %lld-%lld-%lld %lld:%lld",s,&yy,&m1,&d1,&h1,&mm1,&y2,&m2,&d2,&h2,&mm2);
			mm2 += c%60;
			if(mm2 >= 60) {
				h2++; mm2 %= 60;
			}
			h2 += c/60;
			if(h2 >= 24) {
				dayplus();
				h2 %= 24;
			}
			e[i].l = 1LL*mm1+h1*100+d1*10000+m1*1000000+yy*100000000;
			e[i].r = 1LL*mm2+h2*100+d2*10000+m2*1000000+y2*100000000;
			// printf("%lld %lld\n",e[i].l,e[i].r);
		}
		sort(e+1,e+1+b,cmp);
		int MAX = 1;
		queue<Nod> que;
		que.push(e[1]);
		for(int i = 2; i <= b; i ++) {
			while(!que.empty() && que.front().r <= e[i].l) que.pop();
			que.push(e[i]);
			MAX = max(MAX, (int)que.size());
			// printf("%d\n",que.size());
		}
		printf("%d\n",MAX);
	}
	return 0;
}