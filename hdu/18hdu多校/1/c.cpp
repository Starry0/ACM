#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3030;
struct Nod{
	int x, y, id;
}e[N];
bool cmp(const Nod &a, const Nod &b) {
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < 3*n; i ++) scanf("%d%d", &e[i].x, &e[i].y), e[i].id = i+1;
		sort(e,e+3*n,cmp);
		for(int i = 0; i < n; i++) {
			printf("%d %d %d\n",e[i*3].id,e[i*3+1].id,e[i*3+2].id);
		}
	}
	return 0;
}