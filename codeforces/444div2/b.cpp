#include <bits/stdc++.h>
using namespace std;
set<int> st[4];
bool ok(int x) {
	int cnt = 0, b[4];
	while(x) {
		b[cnt++] = x%10;
		x /= 10;
	}
	switch(cnt){
		case 1:
			for(int i = 1; i <= 3; i ++) {
				if(st[i].count(b[0])) return true;
			}
			return false;
			break;
		case 2:
			for(int i = 1; i <= 3; i ++) {
				for(int j = 1; j <= 3; j ++) {
					if(i == j) continue;
					if(st[i].count(b[0]) && st[j].count(b[1])) return true;
				}
			}
			return false;
			break;
		case 3:
			for(int i = 1; i <= 3; i ++) {
				for(int j = 1; j <= 3; j ++) {
					for(int k = 1; k <= 3; k ++) {
						if(i == j || i == k || i == k) continue;
						if(st[i].count(b[0]) && st[j].count(b[1]) && st[k].count(b[2])) return true;
					}
				}
			}
			return false;
			break;
	}
}
int main() {
	int n, x;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= 6; j ++) {
			cin >> x;
			st[i].insert(x);
		}
	}
	for(int i = 1; ; i ++) {
		if(!ok(i)) return 0*printf("%d\n",i-1);
	}
	return 0;
}