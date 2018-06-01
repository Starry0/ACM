#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 1026;
int s[MAX][MAX],u,x1,x2,S,y1,y2,num;
void add(int x, int y,int k){
	for(;x < MAX; x+=lowbit(x)){
		for(int j = y; j < MAX; j +=lowbit(j)){
			s[x][j] += k;
		}
	}
}
ll query(int x, int y){
	ll sum = 0;
	for(;x > 0; x -= lowbit(x)){
		for(int j = y; j > 0; j -= lowbit(j)){
			sum += (ll)s[x][j];
		}
	}
	return sum;
}
int main(){
	while(scanf("%d",&u)!=EOF){
		if(u >= 3)break;
		else if(u == 2){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++;x2++;y1++;y2++;
			//printf("%d++++\n",query(3,3));
			ll ans = query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
			printf("%lld\n",ans);
		}else if(u == 1){
			scanf("%d %d %d",&x1,&y1,&num);
			x1++;y1++;
			add(x1,y1,num);
		}else if(u == 0){
			memset(s,0,sizeof(s));
			scanf("%d",&S);
		}
	}
	return 0;
}