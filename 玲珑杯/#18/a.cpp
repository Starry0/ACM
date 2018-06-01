#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define ll long long
using namespace std;
ll a[13][13][13];
ll AA[33];
void init(){
	for(int x1 = 0; x1 <= 10; x1 ++){
		for(int y1 = 0; y1 <= 10; y1 ++){
			for(int z1 = 0; z1 <= 10; z1 ++){
				for(int x2 = 0; x2 <= 10; x2 ++){
					for(int y2 = 0; y2 <= 10; y2 ++){
						for(int z2 = 0; z2 <= 10; z2 ++){
							if(x1==x2&&y1==y2&&z1==z2){
								AA[0] += a[x1][y1][z1]*(a[x1][y1][z1]-1);
							}else{
								int cnt = abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
								AA[cnt] += a[x1][y1][z1]*a[x2][y2][z2];
							}
						}
					}
				}
			}
		}
	}
	
	/*for(int i = 0; i < 4; i ++){
		printf("%d ",AA[i]/2);
	}printf("\n");*/
}
int main(){
	int t,q,n;
	ll r;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		ll x,y,z;
		for(int i = 1; i <= n; i ++){
			scanf("%lld %lld %lld",&x,&y,&z);
			a[x][y][z]++;
		}
		init();
		while(q--){
			scanf("%lld",&r);
			if(r > 30) r = 30;
			ll ans = 0;
			for(int i = 0; i <= r; i ++){
				ans += AA[i]/2;
			}
			printf("%lld\n",ans);
		}
		for(int i = 0; i < 33; i ++)AA[i] = 0;
		for(int i = 0; i <= 10; i ++){
			for(int j = 0; j <= 10; j ++){
				for(int k = 0; k <= 10; k ++){
					a[i][j][k] = 0;
				}
			}
		}
	}
	return 0;
}