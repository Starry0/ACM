#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAX = 2e4+10;
int n,tree[MAX],tree1[MAX];
struct Nod{
	int y,x;
}nod[MAX];
bool cmp(Nod a, Nod b){
	return a.y < b.y;
}
void add(int x, int num){
	int i = x;
	while(x < MAX){
		tree[x] += num;
		x += lowbit(x);
	}
	while(i < MAX){
		tree1[i]++;
		i += lowbit(i);
	}
}
ll query(int x){
	ll sum = 0;
	while(x > 0){
		sum += 1LL*tree[x];
		x -= lowbit(x);
	}
	return sum;
}
int query1(int x){
	int sum = 0;
	while(x > 0){
		sum += 1LL*tree1[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	int x,num;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++){
		scanf("%d %d",&nod[i].y,&nod[i].x);
	}
	sort(nod+1,nod+1+n,cmp);
	ll ans = 0;
	for(int i = 1; i <= n; i ++){
		//printf("y:%d+++x:%d\n",nod[i].y,nod[i].x);
		ll xx = query(nod[i].x);
		ll xxx = query(MAX)-query(nod[i].x);
		int nn = query1(nod[i].x);
		//int mm = query1(MAX-1)-query1(nod[i].x);
		ll cnt = nn*nod[i].x-xx+xxx-(i-1-nn)*nod[i].x;
		//printf("%d ==\n",cnt);	
		ans += 1LL*nod[i].y*cnt;
		add(nod[i].x,nod[i].x);
	}
	cout << ans << endl;
	return 0;
}