#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 2e5+10;
char s[MAX], ss[MAX];
int a[MAX];
int main(){
	scanf("%s",s);
	scanf("%s",ss);
	int len = strlen(s), len2 = strlen(ss);
	for(int i = 0; i < len2; i ++){
		if(ss[i] == '1')
			a[i+1] ++;
		a[i+1] += a[i];
	}
	ll ans = 0;
	int k = len2-len+1;
	for(int i = 0; i < len; i ++){
		if(s[i] == '1') ans += k-a[k+i]+a[i];
		else ans += a[k+i]-a[i];
	}
	cout << ans << endl;
	return 0;
}