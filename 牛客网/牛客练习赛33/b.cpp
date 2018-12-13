#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int sum[N], sum1[N];

int main() {
	int n, k, x;
	cin >> n >> k;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		sum[x] ++;
	}
	for(int i = 1; i <= k; i ++) {
		for(int j = i; j <= k; j += i) {
			sum1[j] += sum[i];
		}
	}
	int MAX = 0, num = 0;
	for(int i = 1; i <= k; i ++) MAX = max(MAX, sum1[i]);
	for(int i = 1; i <= k; i ++) if(sum1[i] == MAX) num++;
	printf("%d %d\n",MAX,num);
	return 0;
}