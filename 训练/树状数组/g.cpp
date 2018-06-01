#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lowbit(x) x&(-x)
#define ll long long
using namespace std;
const int MAX = 1e5+10;
struct Nod{
	int x,y,pos;
}nod[MAX];
bool cmp(Nod a, Nod b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y > b.y;
}
int tree[MAX], a[MAX];
void add(int x,int y){
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
	int n;
	while(scanf("%d",&n)&&n){
		memset(tree,0,sizeof(tree));
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i ++){
			scanf("%d %d",&nod[i].x,&nod[i].y);
			nod[i].x++;nod[i].y++;
			nod[i].pos = i;
		}
		sort(nod+1,nod+1+n,cmp);
		int tmp = 0;
		for(int i = 1; i <= n; i ++){
			//printf("%d:===%d++++%d\n",nod[i].pos,nod[i].x,nod[i].y);
			if(i != 1){
				if(nod[i].x == nod[i-1].x && nod[i].y == nod[i-1].y){
					tmp++;
				}else tmp = 0;
			}
			int ans = query(MAX-1)-query(nod[i].y-1);
			//printf("%d ++++%d=======%d\n",ans,tmp,ans-tmp);
			a[nod[i].pos] = ans-tmp;
			add(nod[i].y,1);
		}
		for(int i = 1; i <= n; i ++){
			printf("%d%c",a[i],(i==n)?'\n':' ');
		}
	}
	return 0;
}