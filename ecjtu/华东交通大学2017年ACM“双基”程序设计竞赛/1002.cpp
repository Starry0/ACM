/*
比较显然就是，奇数和偶数位置的数的相对位置是不会变的，
那么我们只要知道1和2这两个位置的数是啥就好了
然后交换的时候，我们就模拟一下这两个位置的交换就好了
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;

int main() {
	int T, n, q;
	cin >> T;
	while(T--) {
		cin >> n >> q;
		int flag, x;
		int a = 0, b = 0;
		while(q --) {
			cin >> flag;
			if(flag == 1) {
				scanf("%d",&x);
				a = (n+a-x)%n;  
				b = (n+b-x)%n;  
				if(x&1) swap(a,b);
			} else {
				a = (a+n-1)%n;  
				b = (b+n+1)%n;  
				swap(a,b);
			}
		}
		printf("%d %d\n",a,b);
		for (int i = 1;i <= n; i ++) {  
			if (i&1)printf("%d%c",(a+i-1+n)%n+1,(i==n?'\n':' '));  
			else printf("%d%c",(b+i-1+n)%n+1,(i==n?'\n':' '));  
		}
	}
	return 0;
}