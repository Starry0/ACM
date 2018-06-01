#include <iostream>
#include <stdio.h>
using namespace std;
int n, a[50010], b[50010], ans;

void Merge(int *a, int *b,int l, int mid, int r){
	int i = l, j = mid+1, k = l;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}else{
			b[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= r){
		b[k++] = a[j++];
	}
	
}

void Msort(int *a, int *b, int l, int r){
	int mid;
	if(l < r){
		mid = (l+r)>>1;
		Msort(b,a,l,mid);
		Msort(b,a,mid+1,r);
		Merge(a,b,l,mid,r);
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++) scanf("%d",&a[i]),b[i] = a[i];
	Msort(a,b,1,n);
	printf("%d\n",ans);
	return 0;
}