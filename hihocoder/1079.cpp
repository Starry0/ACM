/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 11111;
bool Hash[MAX];
int col[MAX<<4], x[MAX*3],li[MAX],ri[MAX],ans;
void PushDown(int rt){
	if(col[rt] != -1){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		col[rt] = -1;
	}
}
void update(int LL, int RR, int c, int l, int r, int rt){
	if(LL <= l && r <= RR){
		col[rt] = c;
		return ;
	}
	PushDown(rt);
	int m = (l+r)>>1;
	if(LL <= m)update(LL,RR,c,lson);
	if(m < RR) update(LL,RR,c,rson);
}
void query(int l, int r, int rt){
	if(col[rt] != -1){
		if(!Hash[col[rt]])ans++;
		Hash[col[rt]] = true;
		return ;
	}
	if(l == r) return;
	int m = (l+r)>>1;
	query(lson);
	query(rson);
}
int Bin(int key, int len){
	int l = 0, r = len-1;
	while(l <= r){
		int m = (l+r)>>1;
		if(x[m] == key)return m;
		if(x[m] > key) r = m-1;
		else l = m+1;
	}
	return -1;
}
int main(){
	int n,l;
	scanf("%d %d",&n,&l);
	int nn = 0;
	for(int i = 0; i < n; i ++){
		scanf("%d %d",&li[i],&ri[i]);
		x[nn++] = li[i]; x[nn++] = ri[i];
	}
	sort(x,x+nn);
	int m = 1;
	for(int i = 1; i < nn; i ++){
		if(x[i] != x[i-1])x[m++] = x[i];
	}
	for(int i = m-1; i > 0; i --){
		if(x[i] != x[i-1]+1)x[m++] = x[i-1]+1;
	}
	sort(x,x+m);
	memset(col,-1,sizeof(col));
	for(int i = 0; i < n; i ++){
		int l = Bin(li[i],m);
		int r = Bin(ri[i],m);
		update(l,r,i,0,m,1);
	}
	ans = 0;
	memset(Hash,false,sizeof(Hash));
	query(0,m,1);
	printf("%d\n",ans);
	return 0;
}*/




/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 20010;
bool Hash[MAX];
int li[MAX], ri[MAX];
int x[MAX*3], col[MAX<<4], cnt;
void PushDown(int rt){
	if(col[rt]!=-1){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		col[rt] = -1;
	}
}
void update(int LL, int RR, int c, int l, int r, int rt){
	if(LL <= l && r <= RR){
		col[rt] = c;
		return;
	}
	PushDown(rt);
	int m = (l+r)>>1;
	if(LL <= m) update(LL, RR, c, lson);
	if(m < RR) update(LL, RR, c, rson);
}
void query(int l, int r, int rt) {
	if(col[rt] != -1){
		if(!Hash[col[rt]]) cnt++;
		Hash[col[rt]] = true;
		return;
	}
	if(l == r)return;
	int m = (l+r)>>1;
	query(lson);
	query(rson);
}
int Bin(int key, int n, int x[]){
	int l = 0, r = n-1;
	while(l <= r){
		int m = (l+r)>>1;
		if(x[m] == key)return m;
		if(x[m] < key) l = m+1;
		else r = m-1;
	}
	return -1;
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int nn = 0;
		for(int i = 0; i < n; i ++) {
			scanf("%d %d",&li[i],&ri[i]);
			x[nn++] = li[i];
			x[nn++] = ri[i];
		}
		sort(x,x+nn);
		int m = 1;
		for(int i = 1; i < nn; i ++){
			if(x[i] != x[i-1]) x[m++] = x[i];
		}
		for(int i = m-1; i > 0; i --) {
			if(x[i] != x[i-1]+1)x[m++] = x[i-1] + 1;
		}
		sort(x,x+m);
		for(int i = 0; i < m; i ++){
			printf("%d  ",x[i]);
		}
		printf("\n");
		memset(col,-1,sizeof(col));
		for(int i = 0; i < n; i ++){
			int l = Bin(li[i], m, x);
			int r = Bin(ri[i], m, x);
			printf("%d   %d\n",l,r);
			update(l, r, i, 0, m, 1);
		}
		cnt = 0;
		memset(Hash, false, sizeof(Hash));
		query(0,m,1);
		printf("%d\n",cnt);
	}
	return 0;
}
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 11111;
int col[MAX<<4],li[MAX],ri[MAX],x[MAX*3],ans;
bool Hash[MAX];
void PushDown(int rt){
	if(col[rt] != -1){
		col[rt<<1] = col[rt<<1|1] = col[rt];
		col[rt] = -1;
	}
}
void update(int LL, int RR, int c, int l, int r, int rt){
	if(LL <= l && r <= RR){
		col[rt] = c;
		return;
	}
	PushDown(rt);
	int m = (l+r)>>1;
	if(LL <= m)update(LL,RR,c,lson);
	if(m < RR) update(LL,RR,c,rson);
}
void query(int l, int r, int rt){
	if(col[rt] != -1){
		if(!Hash[col[rt]])ans++;
		Hash[col[rt]] = true;
		return;
	}
	if(l == r)return;
	int m = (l+r)>>1;
	query(lson);
	query(rson);
}
int Bin(int key,int len){
	int l = 0, r = len-1;
	while(l <= r){
		int m = (l+r)>>1;
		if(x[m] == key)return m;
		if(x[m] > key)r = m-1;
		else l = m+1;
	}
	return -1;
}
int main(){
	int t,n;
	scanf("%d",&n);
		scanf("%d",&t);
		int nn = 0;
		for(int i = 0; i < n; i ++){
			scanf("%d %d",&li[i],&ri[i]);
			x[nn++] = ++li[i];x[nn++] = ++ri[i];
		}
		sort(x,x+nn);
		int m = 1;
		for(int i = 1; i < nn; i ++){
			if(x[i]!=x[i-1])x[m++] = x[i];
		}
		for(int i = m-1; i > 0; i --){
			if(x[i] != x[i-1]+1)x[m++] = x[i-1]+1;
		}
		sort(x,x+m);
		memset(col,-1,sizeof(col));
		for(int i = 0; i < n; i ++){
			int l = Bin(li[i],m);
			int r = Bin(ri[i],m);
			update(l,r,i,0,m,1);
		}
		ans = 0;
		memset(Hash,false,sizeof(Hash));
		query(0,m,1);
		printf("%d\n",ans);
	return 0;
}