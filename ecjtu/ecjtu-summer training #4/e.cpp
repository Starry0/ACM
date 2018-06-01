/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1
const int MAX = 1e5+5;
int a[MAX],b[MAX],tree[MAX<<2];

struct Nod{
	int x,y;
}nod[MAX];

bool cmp(Nod a, Nod b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
void Push(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void build(int l, int r, int rt){
	tree[rt] = 0;
	if(l == r)return;
	int m = (l+r)/2;
	build(lson);
	build(rson);
}
int query(int l, int r, int rt, int LL, int RR){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int m = (l+r)/2;
	int sum = 0;
	if(m >= LL)sum+=query(lson,LL,RR);
	if(m < RR) sum+=query(rson,LL,RR);
	return sum;
}
void update(int l, int r, int rt, int x){
	if(l == r){
		tree[rt]++;
		return ;
	}
	int m = (l+r)/2;
	if(x < m)update(lson,x);
	else update(rson,x);
	Push(rt);
}
int main(){
	int n,x,y;
	cin>>n;
	for(int i =0; i<n; i++){
		cin>>nod[i].x>>nod[i].y;
	}
	sort(nod,nod+n,cmp);
	int tmp = 0;
	build(1,MAX,1);
	for(int i = 0; i < n; i ++){
		int ans = 0;
		printf("%d %d\n",nod[i].x,nod[i].y);
		printf("===%d===\n",query(1,MAX,1,1,nod[i].x));
		a[query(1,MAX,1,1,nod[i].x)]++;
		update(1,MAX,1,nod[i].x);
	}
	for(int i = 0; i < n; i ++){
		cout << a[i] << endl;
	}
	return 0;
}*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#define mid ((left+right)>>1)
#define lson rt<<1,left,mid
#define rson rt<<1|1,mid+1,right
using namespace std;

const int MAXN = 100001;

int sum[MAXN<<2],level[MAXN<<2];

void update(int rt,int left,int right,int data){
    ++sum[rt];
    if(left==right) return;
    if(data <= mid) update(lson,data);
    else update(rson,data);
}
int query(int rt,int left,int right,int l,int r){
    if(left==l && right==r) {
        return sum[rt];
    }
    int m = mid;
    if(r <= m) return query(lson,l,r);
    else if(l > m) return query(rson,l,r);
    else return query(lson,l,m)+query(rson,m+1,r);
}

int main(){
    int n,x,y;
    while(~scanf("%d",&n)){
        memset(sum, 0, sizeof(sum));
        memset(level, 0, sizeof(level));
        for(int i=0; i<n; ++i){
            scanf("%d%d",&x,&y);
            ++x;
            ++level[query(1,1,MAXN,1,x)];
            update(1,1,MAXN,x);
        }
        for(int i=0; i<n; ++i)
            printf("%d\n",level[i]);
    }
    return 0;
}*/


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX = 1e5;
int tree[MAX+10],a[MAX+10];

struct Nod{
	int x, y;
}nod[MAX];
bool cmp(Nod a, Nod b){
	if(a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int lowbit(int x){
	return x&(-x);
}
void add(int k, int d){
	while(k <= MAX){
		tree[k] = tree[k]+d;
		k = k+ lowbit(k);
	}
}
int getSum(int k){
	int t = 0;
	while(k > 0){
		t += tree[k];
		k -=lowbit(k);
	}
	return t;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		scanf("%d %d",&nod[i].x,&nod[i].y);
	}
	sort(nod,nod+n,cmp);
	for(int i = 0; i < n; i ++){
		//printf("%d %d \n",nod[i].x,nod[i].y);
		a[getSum(nod[i].x)]++;
		add(nod[i].x,1);
	}
	for(int i = 0; i < n; i ++){
		printf("%d\n",a[i]);
	}
	return 0;
}
