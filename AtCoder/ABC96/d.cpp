#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55565;
bool vis[N];
int prime[N];
int sum[60];
void init() {
	vis[1] = vis[0] = 1;
	for(int i = 2; i < N; i ++) {
		if(!vis[i]) {
			for(int j = i+i; j < N; j += i)
				vis[j] = 1;
		}
	}
}
bool isPrime(int x) {
	for(int i = 2; i <= sqrt(x); i ++) {
		if(x%i==0) return 0;
	}
	return 1;
}
int main() {
	init();
	int n;
	cin >> n;
	for(int i = 2; i < N; i ++) {
		if(!vis[i] && i%5 == 1) {
			printf("%d%c",i," \n"[--n==0]);
			if(n == 0) break;
		}
	}
    return 0;
}
