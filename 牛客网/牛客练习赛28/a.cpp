#include <bits/stdc++.h>
using namespace std;
struct Nod{
	char s[10];
	int y, m;
}e[1010];
bool cmp(Nod a, Nod b) {
	if(a.m == b.m) return a.y < b.y;
	else return a.m < b.m;
}
int main() {
	int n, m, x;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		scanf("%s %d",e[i].s,&x);
		e[i].y = x/10000;
		e[i].m = x%10000;
	}
	sort(e,e+n,cmp);
	int y;
	while(m--) {
		scanf("%d%d",&x,&y);
		for(int i = 0; i < n; i ++) {
			if(e[i].m == y){
				printf("%s\n",e[i+x-1].s);
				break;
			}
		}
	}
	return 0;
}