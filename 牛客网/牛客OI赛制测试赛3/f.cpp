#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6+10;
char s1[N];
char s2[] = {"suqingnianloveskirito"};
int main() {
	cin >> s1;
	int len1 = strlen(s1), len2 = strlen(s2);
	if(len1 == 1) return 0*printf("Yes\n1 1\n");
	int ans1 = -1, ans2 = -1;
	for(int i = 0; i <= len1-len2; i ++) {
		if(s1[i] == s2[0]) {
			bool flag = true;
			for(int j = 0; j < len2; j ++) {
				if(s1[i+j] != s2[j]) {
					flag = false;break;
				}
			}
			if(flag) {
				if(ans1 == -1) ans1 = i;
				else if(ans2 == -1) ans2 = i;
				else return 0*printf("No\n");
				i += len2-1;
			}
		}
	}
	if(ans1 == -1) printf("Yes\n1 2\n");
	else if(ans2 == -1) printf("Yes\n%d %d",ans1+1,ans1+2);
	else printf("Yes\n%d %d\n",ans1+1,ans2+2);
	return 0;
}