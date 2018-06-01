#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	if(n == 1) printf("YES\n%d\n",x);
	else if(n == 2) {
		if(x == 0) printf("NO\n");
		else printf("YES\n0 %d\n",x);
	} else {
		printf("YES\n");
		int tmp = 0;
		for(int i = 1; i < n-2; i ++) {
			printf("%d ",i);
			tmp ^= i;
		}
		int ans = 1<<18;
		int ans1 = 1<<19;
		printf("%d %d %d\n", ans, ans1,ans1^ans^tmp^x);
	}
	return 0;
}