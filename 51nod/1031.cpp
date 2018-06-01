#include <iostream>
#include <stdio.h>
using namespace std;
const int Mod = 1e9+7;
int f[1010];
int main(){
	int n;
	cin >> n;
	f[1] = 1, f[2] = 2;
	for(int i = 3; i <= 1000; i ++) {
		f[i] = (f[i-1] + f[i-2])%Mod;
	}
	printf("%d\n",f[n]);
	return 0;
}