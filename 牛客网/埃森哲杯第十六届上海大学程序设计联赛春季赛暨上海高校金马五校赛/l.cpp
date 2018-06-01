#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll a[N];
int main() {
	int n, k;
	scanf("%d %d",&n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
		a[i] += a[i-1];
	}
	int MAX = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = n; j >= 1; j --) {
			if(MAX >= j-i+1) break;
			if((a[j]-a[i-1])%k==0 && j-i+1 > MAX) {
				//printf("%d %d %d %d\n",i,j,a[j],a[i-1]);
				MAX = j-i+1;
			}
		}
	}
	cout << MAX << endl;
	return 0;
}