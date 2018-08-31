#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5+10;

int main() {
	for(int i = 1; i < 10; i ++) {
		int ans = 0;
		for(int j = 0; j < i; j ++) {
			for(int k = 0; k < i; k ++) {
				if(j*k % i != 0) ans++;
			}
		}
		printf("%d %d\n",i,ans);
	}
	return 0;
}