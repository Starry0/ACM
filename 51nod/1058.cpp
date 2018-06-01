#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	double ans = 0.0;
	for(int i = 1; i <= n; i ++){
		ans += log10(i);
	}
	cout << (int)ans + 1 << endl;
	return 0;
}