// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <vector>
// #include <map>
// #include <set>
// #define ll long long
// #define lowbit(x) x&(-x)
// using namespace std;
// const int N = 3010;
// int g[N][4*N];
// void add(int x, int y) {
// 	for(int i = y; i < 4*N; i += lowbit(i)) {
// 		g[x][i] ++;
// 	}
// }
// int query(int x, int y) {
// 	int sum = 0;
// 	while(y > 0) {
// 		sum += g[x][y];
// 		y -= lowbit(y);
// 	}
// 	return sum;
// }
// int main() {
// 	int t, n, x;
// 	scanf("%d", &t);
// 	while(t--) {
// 		memset(g, 0, sizeof(g));
// 		scanf("%d", &n);
// 		for(int i = 1; i <= n; i ++) {
// 			for(int j = i+1; j <= n; j ++) {
// 				scanf("%d", &x);
// 				if(x == 1) {
// 					add(i,j);
// 					add(j,i);
// 				}
// 			}
// 		}
// 		int ans = 0, ans1 = 0;
// 		for(int i = 1; i <= n; i ++) {
// 			int sum = query(i,n);
// 			if(sum == n-1) ans1++;
// 			if(sum == 0) ans ++;
// 		}
// 		if(ans >= 3 || ans1 >= 3) printf("Bad Team!\n");
// 		else printf("Great Team!\n");
// 	}
// 	return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 5000;
int sum[N];
int main() {
	int t, n, x;
	scanf("%d", &t);
	while(t--) {
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			for(int j = i+1; j <= n; j ++) {
				scanf("%d", &x);
				if(x == 1) {
					sum[i]++;
					sum[j]++;
				}
			}
		}
		int ans = 0, ans1 = 0;
		for(int i = 1; i <= n; i ++) {
			if(sum[i] == 0) ans++;
			if(sum[i] == n-1) ans1++;
		}
		if(ans >= 3 || ans1 >= 3) printf("Bad Team!\n");
		else printf("Great Team!\n");
	}
}
there are three or more members are not friends with each other 
there are three or more members who are friends with each other