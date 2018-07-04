#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int n, sum, ans;
struct Nod{
	int id,num;
}nod[11];
bool cmp(Nod a, Nod b) {
	a.num < b.num;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> nod[i].num;
		nod[i].id = i;
		sum += nod[i].num;
	}
	sort(nod+1,nod+1+n,cmp);
	if(n == 1) return 0*printf("-1\n");
	for(int i = 1; i < n; i ++) {
		ans += nod[i].num;
		if(ans*2 != sum) {
			printf("%d\n",i);
			for(int j = 1; j <= i; j ++) printf("%d ",nod[j].id);
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}