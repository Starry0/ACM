#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;
int n, m;

int main() {
	int n, h, a, b, k;
	int ta, tb, fa, fb;
	cin >> n >> h >> a >> b >> k;
	while(k--) {
		cin >> ta >> fa >> tb >> fb;
		if(ta == tb){
			printf("%d\n",abs(fa-fb));
			continue;
		}
		int ans = abs(ta-tb);
		if(fa < fb) swap(fa,fb);
		if(fa <= a) ans += abs(a-fa)+abs(a-fb);
		else if(fa <= b) ans += abs(fa-fb);
		else if(fa > b) ans += abs(fb-b)+fa-b;
		printf("%d\n",ans);
	}
	return 0;
}