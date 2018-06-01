#include <iostream>
#include <stdio.h>
#include <string.h>
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 110;
int a[MAX][MAX][MAX],x1,x2,y1,y2,z1,z2,n,m;
void add(int x, int y, int z,int num){
	for(;x < MAX; x+=lowbit(x)){
		for(int j = y; j < MAX; j += lowbit(j)){
			for(int k = z; k < MAX; k +=lowbit(k)){
				a[x][j][k] += num;
			}
		}
	}
}
int query(int x, int y, int z){
	int sum = 0;
	for(; x > 0; x -= lowbit(x)){
		for(int j = y; j > 0; j -=lowbit(j)){
			for(int k = z; k > 0; k -= lowbit(k)){
				sum += a[x][j][k];
			}
		}
	}
	return sum;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		while(m--){
			scanf("%d",&x1);
			if(x1 == 1){
				scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
				add(x1,y1,z1,1);add(x2+1,y1,z1,1);
				add(x1,y2+1,z1,1);add(x2+1,y2+1,z1,1);
				add(x1,y1,z2+1,1);add(x1,y2+1,z2+1,1);
				add(x2+1,y1,z2+1,1);add(x2+1,y2+1,z2+1,1);
				
			}else if(x1 == 0){
				scanf("%d %d %d",&x1,&y1,&z1);
				printf("%d\n",query(x1,y1,z1)&1);
			}
		}
		
	}
	return 0;
}