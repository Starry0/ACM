#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 22;

char str[N][N];

int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i ++) scanf("%s", str[i]);
		int ans1 = 0, ans2 = 0, ans3 = 0, move = 0, w, b, j;
		for(int i = 0; i < m; i ++) {
			for(j = 0; str[j][i] != 'B'; j ++);
			b = j;
			for(j = n-1; str[j][i] != 'W'; j --);
			w = j;
			if(b == 0 && w == n-1 && n > 3) ans3++;
			else {
				if(b == 0 && w > 2) ans1 += w-2;
				else if(w == n-1 && b < n-3) ans2 += n-3-b;
				move += w-b-1;
			}
		}
		printf((n==4 && ans3%2==1) || ans2 > ans1 || (ans2 >= ans1-1 && move%2==1)?"White wins\n":"Black wins\n");
	}
	return 0;
}