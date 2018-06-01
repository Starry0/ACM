#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
ll a[1010];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; i ++)scanf("%lld",&a[i]);
	sort(a,a+n);
	int i = 0;
	while(a[i] <= k && i < n)i++;
	if(i == n){
		cout << 0 << endl;
	}else if(i == 0){
		cout << n << endl;
	}else {
		while((a[i]+1)/2 <= a[i-1] && i < n){
			++i;
		}
		cout << n-i << endl;
	}
	return 0;
}