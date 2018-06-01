#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, a[1010], b[1010];
const int INF = 1<<30;

int difference(int x){
	int sum = 0;
	for(int i = 0; i < n; i ++){
		sum += (a[i]-b[i+x])*(a[i]-b[i+x]);
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i = 0; i < m; i ++) scanf("%d",&b[i]);
	int sum = INF;
	for(int i = 0; i < m-n+1; i ++){
		sum = min(sum,difference(i));
	}
	printf("%d\n",sum);
	return 0;
}