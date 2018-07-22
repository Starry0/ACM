/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int n, x;
int main() {
	cin >> n;
	int tmp = 0, MIN1 = 0, MIN2 = 1e9;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		tmp = x - tmp;
		if(i&1) MIN2 = min(MIN2, tmp);
		else MIN1 = min(MIN1, tmp);
	}
	if(MIN1+MIN2 < 0) printf("0\n");
	else if(MIN2 < 0 && MIN1 > 0) printf("0\n");
	else if(MIN1 > 0 && MIN2 >= 0) printf("%d\n",MIN2+1);
	else printf("%d\n",MIN2+MIN1+1);
	return 0;
}*/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, x, MIN1 = INF, MIN2 = -INF;
int main() {
	cin >> n;
	int tmp = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> x;
		tmp = x - tmp;
		if(i&1) MIN1 = min(MIN1, tmp);
		else MIN2 = max(MIN2,-tmp);
	}
	if(MIN2>MIN1) printf("0\n");
	else if(MIN2 < 0 && MIN1 < 0) printf("0\n");
	else if(MIN2 < 0 && MIN1 >= 0) printf("%d\n",MIN1+1);
	else printf("%d\n",MIN1-MIN2+1);
	return 0;
}
