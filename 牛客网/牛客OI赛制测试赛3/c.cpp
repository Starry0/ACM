#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2e6+10;
char s1[N], s2[N];
int main() {
	int n;
	cin >> n >> s1 >> s2;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for(int i = 0; i < 2*n; i ++) {
		if(s1[i] == 'U' && s2[i] == 'U') ans1++;
		else if(s1[i] == 'U') ans2++;
		else if(s2[i] == 'U') ans3++;
	}
	int cnt1 = (ans1/2) + ans1%2?1:0;
	int cnt2 = ans1/2;
	if(cnt1+ans2 > cnt2+ans3) printf("clccle trl!\n");
	else if(cnt1+ans2 == cnt2+ans3) printf("orz sarlendy!\n");
	else if(cnt1+ans2 < cnt2+ans3) printf("sarlendy tql!\n");
	return 0;
}
