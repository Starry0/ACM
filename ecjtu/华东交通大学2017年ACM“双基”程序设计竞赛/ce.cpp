#include<cstdio>
#include<algorithm>
#include<map>
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
typedef long long ll;
map<int,ll>mp;
const int N=1e5+7;
int n,i,j,a[N],l[N],v[N],tr[N<<2];

void init(){
	mp.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)for(v[i]=a[i],j=l[i]=i;j;j=l[j]-1){
		v[j]=__gcd(v[j],a[i]);
		while(l[j]>1&&__gcd(a[i],v[l[j]-1])==__gcd(a[i],v[j]))l[j]=l[l[j]-1];
		mp[v[j]]+=j-l[j]+1;
	}
}

void build(int l=1,int r=n,int rt=1){
	if(l==r){tr[rt]=a[l];return;}
	int m=(l+r)>>1;
	build(ls),build(rs);
	tr[rt]=__gcd(tr[rt<<1],tr[rt<<1|1]);
}

int ask(int L,int R,int l=1,int r=n,int rt=1){
	if(L<=l&&r<=R)return tr[rt];
	int m=(l+r)>>1;
	if(R<=m)return ask(L,R,ls);
	if(L>m)return ask(L,R,rs);
	return __gcd(ask(L,R,ls),ask(L,R,rs));
}

int main(){
	int t,ic=1,k,x,y;
	scanf("%d",&t);
	while(t--){
		init(),build();
		scanf("%d",&k);
		printf("Case #%d:\n",ic++);
		while(k--){
			scanf("%d%d",&x,&y);
			int tp=ask(x,y);
			printf("%d %lld\n",tp,mp[tp]);
		}
	}
	return 0;
}