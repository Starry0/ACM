#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lowbit(x) x&(-x)
#define ll long long
using namespace std;
const int MAX = 5e5+5;
int n, tree[MAX],index[MAX];
struct Nod{
	int num,id;
}nod[MAX];
bool cmp(Nod a, Nod b){
	return a.num < b.num;
}
void add(int x, int y){
	while(x < MAX){
		tree[x] += y;
		x += lowbit(x);
	}
}

int query(int x){
	int sum = 0;
	while(x > 0){
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	while(scanf("%d",&n)&&n){
		for(int i = 1; i <= n; i ++){
			scanf("%d",&nod[i].num);
			nod[i].id = i;
		}
		sort(nod+1,nod+1+n,cmp);
		for(int i = 1; i <= n; i ++)index[nod[i].id] = i;
		memset(tree,0,sizeof(tree));
		ll ans = 0;
		for(int i = 1; i <= n; i ++){
			add(index[i],1);
			//printf("%d+++++%d\n",index[i],query(index[i]));
			ans += i-query(index[i]);//index[i]为原来的第i个排序后排第几了，i-query(index[i]),
									//一开始i包括本身前面有i个现在只有query(index[i])个了，说明比它大的插到i后面了，
									//差值就第i个前面比i大的数量了。
			//printf("%lld++\n",ans);
		}
		printf("%lld\n",ans);
	}
}