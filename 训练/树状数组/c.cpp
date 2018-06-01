#include <iostream>
#include <stdio.h>
#include <string.h>
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 1010;
int c[MAX][MAX];
void add(int x,int y,int k){
	for(int i = x; i < MAX; i += lowbit(i)){
		for(int j = y; j < MAX; j += lowbit(j)){
			c[i][j] += k;
		}
	}
}
int query(int x, int y){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		for(int j = y; j > 0; j -= lowbit(j)){
			sum += c[i][j];
		}
	}
	return sum;
}
int main(){
	int x,n,t,x1,x2,y1,y2;
	scanf("%d",&x);
	while(x--){
		scanf("%d %d",&n,&t);
		memset(c,0,sizeof(c));
		while(t--){
			char str[10];
			scanf("%s",str);
			if(str[0] == 'C'){
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				add(x1,y1,1);//把下面三个变成加-1也行，0和2 &1都是0
				add(x1,y2+1,1);
				add(x2+1,y1,1);
				add(x2+1,y2+1,1);
			}else {
				scanf("%d %d",&x1,&y1);
				printf("%d\n",query(x1,y1)&1);
			}
		}
		if(x)printf("\n");
	}
	return 0;
}