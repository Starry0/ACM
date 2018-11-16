#include <bits/stdc++.h>
using namespace std;

struct Nod{
	int a, b, c, d, id;
}e[310];

bool cmp(Nod a, Nod b) {
	if(a.d != b.d) return a.d > b.d;
	else if(a.a != b.a) return a.a > b.a;
	else return a.id < b.id;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> e[i].a >> e[i].b >> e[i].c;
		e[i].d = e[i].a+e[i].b+e[i].c;
		e[i].id = i+1;
	}	
	sort(e,e+n,cmp);
	for(int i = 0; i < min(5,n); i ++) {
		printf("%d %d\n",e[i].id,e[i].d);
	}
	return 0;
}