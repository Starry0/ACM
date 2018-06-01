#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <algorithm>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 1e6+10;
ll t,n,m,k,tree[MAX],tree1[MAX];
struct Nod{
	int x, y;
}nod[MAX];
bool cmp(Nod a, Nod b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
void add(ll x){
	while(x < MAX){
		tree[x] += 1;
		x += lowbit(x);
	}
}
ll query(int x){
	ll sum = 0;
	while(x > 0){
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	scanf("%d",&t);
	int cnt = 1;
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		ll ans = 0, l, r;
		for(int i = 1; i <= k; i ++){
			scanf("%d %d",&nod[i].x,&nod[i].y);
		}
		sort(nod+1,nod+1+k,cmp);
		memset(tree,0,sizeof(tree));
		memset(tree,0,sizeof(tree1));
		for(int i = 1; i <= k; i ++){
			//printf("%d==%d\n",nod[i].x,nod[i].y);
			ans += query(MAX-1) - query(nod[i].y);
			add(nod[i].y);
		}
		printf("Test case %d: %lld\n",cnt++,ans);
	}
	return 0;
}

