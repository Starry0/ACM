#include <iostream>
#include <algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N = 2e5+10;
const int M = 2e3+10;
int n, m, k, h[N], tree[N<<2];
pair<int,int> room[M];
void Push_up(int rt){
	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l, int r, int rt){
	if(l == r){
		tree[rt] = h[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lson);
	build(rson);
	Push_up(rt);
}
int query(int l, int r, int rt,int LL, int RR){
	if(LL <= l && r <= RR){
		return tree[rt];
	}
	int cnt = 22;
	int mid = (l+r)>>1;
	if(mid >= LL) cnt = min(cnt,query(lson,LL,RR));
	if(mid < RR) cnt = min(cnt,query(rson,LL,RR));
	return cnt;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i ++){
		scanf("%d",&h[i]);
	}
	build(1,n,1);
	scanf("%d",&m);
	int a,b;
	for(int i = 1; i <= m; i ++){
		scanf("%d %d",&a,&b);
		room[i] = make_pair(a,b);
	}
	sort(room+1,room+1+m);
	int ans = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = i+1; j <= m; j ++){
			int x1 = room[i].first, y1 = room[i].second;
			int x2 = room[j].first, y2 = room[j].second;
			if(x1 == x2){
				if((y2-y1) <= k) ans++;
			}else{
				int cnt = x2-x1+y1+y2-2*query(1,n,1,x1,x2);
				if(cnt <= k)ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}