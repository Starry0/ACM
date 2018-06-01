#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
int a[N], aa[N];
struct Nod{
	int x, index;
}nod[N];
bool cmp(Nod a, Nod b) {
	return a.x > b.x;
}
int main() {
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i ++) scanf("%d", &nod[i].x),nod[i].index = i;
	sort(nod,nod+m,cmp);
	sort(a,a+m);
	for(int i = 0; i < m; i ++) {
		aa[nod[i].index] = a[i];
	}
	for(int i = 0; i < m; i ++) {
		printf("%d%c",aa[i],(i==m-1 ?'\n':' '));
	}
	return 0;
}