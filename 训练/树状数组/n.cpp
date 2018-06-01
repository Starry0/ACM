/*#include <iostream>
#include <stdio.h>
#include <string.h>
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 100010;
int n,c[MAX];

void update(int x, int y){
	while(x < MAX){
		c[x] += y;
		x += lowbit(x);
	}
}
int query(int x){
	int sum = 0;
	while(x > 0){
		sum += c[x];
		x -= lowbit(x);
	}
	return x;
}
int main(){
	while(scanf("%d",&n)&&n){
		memset(c,0,sizeof(c));
		int a, b;
		for(int i = 1; i <= n; i ++){
			scanf("%d %d",&a,&b);
			
		}
		for(int i = 1; i <= n; i ++){
			printf("%d%c",c[i],(i==n)?'\n':' ');
		}
	}
	return 0;
}*/


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 100010;
int n,a[MAX];
int main(){
	while(scanf("%d",&n)&&n){
		for(int i = 1; i <= n; i ++){
			int l, r;
			scanf("%d %d",&l,&r);
			a[l]++;
			a[r+1]--;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			ans += a[i];
			printf("%d%c",ans,(i==n)?'\n':' ');
		}
		memset(a,0,sizeof(a));
	}	
	return 0;
}