#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >>y;
	if(y==0||(y==1&&x)||x<y-1||(x-y)%2==0)printf("No\n");
	else printf("Yes\n");
	return 0;
}