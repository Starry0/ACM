#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char str[N];
int sum[N];
bool vis[27];
int main() {
	cin >> str;
	int len = strlen(str);
	int k = len;
	for(int i = 0; str[i]; i ++) {
		sum[i] = str[i] - 'a';
		vis[sum[i]] = true;
	}
	for(int i = 0; i < 26; i ++) {
		if(vis[i]) {
			int x = -1, tmp = 0, MAX = -1;
			for(int j = 0; j < len; j ++) {
				if(sum[j] != i) tmp ++;
				else {
					if(tmp + 1 > MAX) MAX = tmp + 1;
					tmp = 0;
				}
			}
			if(tmp + 1 > MAX) MAX = tmp + 1;
			if(MAX < k) k = MAX;
		}
	}
	printf("%d\n",k);
	return 0;
}