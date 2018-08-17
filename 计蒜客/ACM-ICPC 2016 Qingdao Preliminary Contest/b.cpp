#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
const ll MAX = 1e9+10;
double a[N];
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1; i < N; i ++) {
		a[i] = a[i-1] + 1.0/(1.0*i*i);
		// printf("%d %.5lf\n",i,1.0/(tmp*tmp));
	}
	int n;
	while(cin >> s) {
		if(s.size() > 7) printf("%.5lf\n",a[N-1]);
		else{
			n = 0;
			for(int i = 0; i < s.length(); i ++) {
				n = n*10 + s[i]-'0';
			}
			if(n >= N) printf("%.5lf\n",a[N-1]);
			else printf("%.5lf\n",a[n]);
		}
	}
	return 0;
}