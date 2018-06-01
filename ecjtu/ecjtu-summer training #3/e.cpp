/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1
using namespace std;
const int MAX = 2e5+10;
int cow1[MAX<<2],cow2[MAX<<2];

void Push(int rt){
	cow1[rt] = min(cow1[rt<<1],cow1[rt<<1|1]);
	cow2[rt] = max(cow2[rt<<1],cow2[rt<<1|1]);
}
void build(int l,int r, int rt){
	if(r == l){
		scanf("%d",&cow1[rt]);
		cow2[rt] = cow1[rt];
		//printf(" %d  %d\n",l,rt);
		return;
	}
	int m = (l+r)/2;
	build(lson);
	build(rson);
	Push(rt);
}

int query(int l, int r, int rt, int LL, int RR){
	//cout << l << ' ' << r << endl;
	if(LL <= l && r <= RR){
		//printf("%d\n",rt);
		return cow2[rt];
	}
	int m = (l+r)/2;
	int MAX = -1;
	if(m >= LL) MAX = max(MAX,query(lson,LL,RR));
	if(m < RR) MAX = max(MAX,query(rson,LL,RR));
	return MAX;
}
int query1(int l, int r, int rt, int LL, int RR){
	if(LL <= l && r <= RR){
		//printf("%d\n",rt);
		return cow1[rt];
	}
	int m = (l+r)/2;
	int MIN = 100000000;
	if(m >= LL) MIN = min(MIN,query1(lson,LL,RR));
	if(m < RR) MIN = min(MIN,query1(rson,LL,RR));
	return MIN;
}
int main(){
	int n, q;
	cin >>n>>q;
	build(1,n,1);
	while(q--){
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		int MAX = query(1,n,1,ll,rr);
		int MIN = query1(1,n,1,ll,rr);
		//cout << MAX << ' ' << MIN << endl;
		printf("%d\n",MAX - MIN);
	}
}*/


#include <iostream>
#include <stdio.h>
using namespace std;
int n,q,dmin[50010][25],dmax[50010][25],a[50010];
void init(){
	for(int i = 1; i <= n; i ++){
		dmin[i][0] = dmax[i][0] = a[i];
	}
	for(int j = 1; (1<<j) <= n; j ++){
		for(int i = 1; i+(1<<j)-1<= n; i ++){
			dmin[i][j] = min(dmin[i][j-1],dmin[(1<<(j-1))+i][j-1]);
			dmax[i][j] = max(dmax[i][j-1],dmax[(1<<(j-1))+i][j-1]);
		}
	}
}
int getValue(int l, int r){
	int k = 0;
	while(1<<(k+1) <= (r-l+1))k++;
	//cout << max(dmax[l][k],dmax[r-(1<<k)+1][k]) << ' ' << min(dmin[l][k],dmin[r-(1<<k)+1][k]) << endl;
	return max(dmax[l][k],dmax[r-(1<<k)+1][k])-min(dmin[l][k],dmin[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i ++){
		scanf("%d",&a[i]);
	}
	init();
	while(q--){
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n",getValue(l,r));
	}
	return 0;
}