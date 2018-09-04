#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 <= x2 && y1 <= y2) printf("Polycarp\n");
	else if(x1 >= x2 && y1 >= y2) printf("Vasiliy\n");
	else {
		int ans1 = x1+y1, ans2 = max(y2,x2);
		if(ans1 <= ans2) printf("Polycarp\n");
		else printf("Vasiliy\n");
	}
	return 0;
}