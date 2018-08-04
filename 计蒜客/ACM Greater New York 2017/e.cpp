#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
char s[30];
int main() {
	ll p, k, m;
	char ch;
	cin >> p;
	while(p--)  {
		cin >> k >> m >> s;
		double cnt = 0, cnt1 = 12;
		for(int i = 1; s[i]; i ++) {
			cnt += 1.0*(s[i]-'0')*pow(10,cnt1);
			cnt1 -= 1;
		}
		if(cnt == 0) {
			printf("0/1\n",cnt);
			continue;
		}
		ll tmp = 1;
		for(int i = 1; i <= 13; i ++) tmp *= 10;
		ll a = cnt, b = tmp;
		while(true) {
			bool flag = true;
			while(a+1 < b && fabs(1.0*tmp*(a+1)/b-cnt) < fabs(1.0*tmp*a/b-cnt)) {
				a++;
				flag = false;
			}
			while(a-1 >= 0 && fabs(1.0*tmp*(a-1)/b-cnt) < fabs(1.0*tmp*a/b-cnt)) {
				flag = false;
				a--;
			}
			// printf("%.6f %.6f %.5f\n", fabs(1.0*tmp*a/(b+1)),fabs(1.0*tmp*a/b),cnt);
			while(b+1 <=m  && fabs(1.0*tmp*a/(b+1)-cnt) < fabs(1.0*tmp*a/b-cnt)) {
				b++;
				flag = false;
			}
			while(b-1 > a && fabs(1.0*tmp*a/(b-1)-cnt) < fabs(1.0*tmp*a/b-cnt)) {
				b--;
				flag = false;
			}
			if(flag && b <= m) break;
			else if(flag) {
				a/=10;
				b/=10;
			}
			if(a == 14159 && b == 99998) printf("AA:%.6f %.6f %.6f\n",fabs(1.0*tmp*(a-1)/b),fabs(1.0*tmp*a/b),cnt);
		}
		printf("%lld %lld/%lld\n",k,a,b);
	}
	return 0;
}