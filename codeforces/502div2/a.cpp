#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct Nod{
	int id,s;
}e[N];
int a, n, b, c, d;
bool cmp(const Nod &a, const Nod &b) {
	if(a.s != b.s) return a.s > b.s;
	else return a.id < b.id;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a >> b >> c >> d;
		e[i].id = i;
		e[i].s = a+b+c+d;
	}
	sort(e+1,e+1+n,cmp);
	for(int i = 1; i <= n; i ++) 
		if(e[i].id == 1) return 0*printf("%d\n",i);
	return 0;
}