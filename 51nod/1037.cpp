#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 110;
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i ++){
		for(int j = 0;  j< n; j ++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0;  j< n; j ++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			int ans = 0;
			for(int k = 0; k < n; k ++){
				ans += a[i][k]*b[k][j];
			}
			printf("%d%c",ans,j==n-1?'\n':' ');
		}
	}
	return 0;
}