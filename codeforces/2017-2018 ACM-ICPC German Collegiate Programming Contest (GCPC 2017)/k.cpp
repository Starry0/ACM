#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
struct Nod{
	char s[10];
	int c, id;
}e[N];

bool cmp(Nod a, Nod b) {
	if(a.c != b.c) return a.c > b.c;
	else return a.id < b.id;
}

int main() {
	int n, k, d;
	cin >> n >> d >> k;
	for(int i = 0; i < n; i ++) {
		cin >> e[i].s >> e[i].c;
		e[i].id = i;
	}
	sort(e,e+n,cmp);
	int ans = 0, sum = 0;
	for(int i = 0; i < n; i ++) {
		sum += e[i].c;
		ans ++;
		if(sum >= d) break;
	}
	// printf("%d %d\n",sum,d);
	if(sum < d || ans > k) printf("impossible\n");
	else {
		printf("%d\n",ans);
		for(int i = 0; i < ans; i ++) {
			printf("%s, YOU ARE FIRED!\n",e[i].s);
		}
	}
	return 0;
}