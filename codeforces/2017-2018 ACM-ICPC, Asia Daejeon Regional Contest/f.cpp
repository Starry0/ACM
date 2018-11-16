#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int N = 1e5+10;
struct Point{
	int x, y;
};
Point dfs(int n, int m) {
	Point a;
	if(n == 2) {
		if(m == 0) a.x = 1, a.y = 1;
		else if(m == 1) a.x = 1, a.y = 2;
		else if(m == 2) a.x = 2, a.y = 2;
		else if(m == 3) a.x = 2, a.y = 1;
		return a;
	}
	int ans = n*n/4;
	int cnt = m%ans;
	a = dfs(n/2, cnt);
	if(m < ans) {
		swap(a.x, a.y);
	} else if(m < 2*ans) {
		a.y += n/2;	
	} else if(m < 3*ans) {
		a.x += n/2;
		a.y += n/2;
	} else {
		int x = n+1-a.y;
        int y = n/2+1 - a.x;
        return (Point){x, y};
	}
	return a;
}

int main() {
	int n, m;
	cin >> n >> m;
	Point p = dfs(n, m-1);
	printf("%d %d\n",p.x,p.y);
	return 0;
}