#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n;
int a[N], b[N];
int main() {
	int x;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	int id = b[0] - a[0];
	if(id < 0) return 0*printf("0\n");
	for(int i = 1; i < n; i ++) {
		if(b[i] - a[i] > id) {
			return 0*printf("%d\n",id+1);
		} else if(b[i] - a[i] < id) {
			return 0*printf("%d\n",id);
		}
	}
	printf("%d\n",id);
	return 0;
}