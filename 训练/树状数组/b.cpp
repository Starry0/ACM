#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define lowbit(x) x&(-x)
#define mem(a,x) memset(a,x,sizeof(a))
const int MAX = 50010;
int c[MAX];
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
	return sum;
}
int main(){
	int t,n,num,k=1;
	scanf("%d",&t);
	while(t--){
		mem(c,0);
		printf("Case %d:\n",k++);
		scanf("%d",&n);
		for(int i = 1; i <= n; i ++){
			scanf("%d",&num);
			update(i,num);
		}
		char s[10];
		int x,y;
		while(scanf("%s",s)!=EOF){
			if(s[0] == 'E')break;
			scanf("%d %d",&x,&y);
			if(s[0] == 'Q'){
				printf("%d\n",query(y)-query(x-1));
			}else if(s[0] == 'A'){
				update(x,y);
			}else update(x,-y);
		}
	}
	return 0;
}