#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
struct Point{
	ll x, y;
}a[4];
ll dist(Point aa, Point b) {
	return (aa.x-b.x)*(aa.x-b.x)+(aa.y-b.y)*(aa.y-b.y);
}
bool cmp(Point x, Point y) {
	return x.x < y.x;
}
bool check(){
	sort(a+1,a+4,cmp);
	if((a[2].y-a[1].y)*(a[3].x-a[2].x) == (a[3].y-a[2].y)*(a[2].x-a[1].x)) return true;

	return false;
}
int main(){
    cin >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y;
    if(dist(a[1],a[2]) != dist(a[2],a[3])){
    	return 0*printf("No\n");
    } else if(check()){
    	return 0*printf("No\n");
    }else {
    	printf("Yes\n");
    }
    return 0;
}
