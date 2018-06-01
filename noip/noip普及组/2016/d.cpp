/*
#include <bits/stdc++.h>
using namespace std;
const int M = 40010;
struct Nod{
	int num, value;
}nod[M];
int a[M][5], aa, bb, cc, dd, n, m;
bool cmp(Nod a, Nod b) {
	a.value < b.value;
}
void dfs(int k, int index) {
	if(k == 4) {
		a[nod[aa].num][1] ++;
		a[nod[bb].num][2] ++;
		a[nod[cc].num][3] ++;
		a[nod[dd].num][4] ++;
		return 0;
	}
	for(int i = index; i <= m; i ++) {
		if(k == 1) {
			aa = i;
		}
		if(k == 2) {
			bb 
		}
		dfs(k+1, index+1);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++) {
		nod[i].num = i;
		scanf("%d", &nod[i].value);
	}
	sort(nod, nod+m, cmp);
	dfs(1, 1);
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct Nod {
	int num, valu;
}nod[N];
bool cmp(Nod a, Nod b) {
	return a.valu < b.valu;
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		nod[i].num = i;
		cin >> nod[i].valu;
	}
	sort(nod+1, nod+1+m, cmp);
	for(int i = 1; i <= m; i ++) {
		printf("%d %d\n", nod[i].num, nod[i].valu);
	}
	for(int i = )
	return 0;
}