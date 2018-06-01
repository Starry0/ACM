#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int a[10000];
void Factorial(int n){
	a[0] = 1;
	int k = 0, flag = 0;
	for(int i = 1; i <= n; i ++){
		flag = 0;
		for(int j = 0; j <= k; j ++){
			a[j] = a[j]*i+flag;
			flag = a[j]/10000;
			a[j] = a[j]%10000;
		}
		if(flag) a[++k] = flag;
	}
	cout << a[k];
	for(int i = k-1; i >= 0; i --){
		cout << setfill('0')<<setw(4)<<a[i];
	}
	cout << endl;
}

int main(){
	int n;
	scanf("%d",&n);
	Factorial(n);
	return 0;
}