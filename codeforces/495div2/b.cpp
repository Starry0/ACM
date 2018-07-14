#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> l >> r;
    }
	for(int i = 0; i < n; i ++) {
		if(i&1)printf("0");
		else printf("1");
	}
	printf("\n");
    return 0;
}
