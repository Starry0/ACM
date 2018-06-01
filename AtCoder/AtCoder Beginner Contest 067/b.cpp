#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[55];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; i ++)scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int ans = 0;
	for(int i = 0; i < min(n,k); i ++){
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}