#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lowbit(x) x&(-x)
#define ll long long
using namespace std;
const int MAX = 1e6+10;
int n,tree[MAX],index[MAX];
int nex[MAX],pre[MAX];
struct Nod{
	int val,id;
}nod[MAX];
bool cmp(Nod a, Nod b){
	return a.val < b.val;
}
bool cmp1(Nod a, Nod b){
	return a.val > b.val;
}
void add(int x){
	while(x < MAX){
		tree[x] ++;
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
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)scanf("%d",&nod[i].val),nod[i].id=i;
	sort(nod+1,nod+1+n,cmp1);
	for(int i = 1; i <= n; i ++)index[nod[i].id] = i;
	ll ans = 0,k;
	for(int i = 1; i <= n; i ++){
		k = query(index[i]);//由于k是第i个数前面比第i个数大的数量，所以后面比第i个数小的数量
							//为(n-index[i])-(i-1-k)就是n-i-index[i]+k+1,(n-index[i])是比第i个数小的
							//总数，把它减去前面比第i个数小的数量就是后面的数量了，前面比第i个数小的
							//数量为(i-1-k),所以(n-index[i])-(i-1-k)就推来了
		cout << n-i-index[i]+k+1 << "++++" << k << endl;
		ans += k*(n-i-index[i]+k+1);
		add(index[i]);
	}
	/*for(int i = 1; i <= n; i ++){
		add(index[i]);
		pre[i] = i-query(index[i]);
	}
	memset(tree,0,sizeof(tree));
	for(int i = n; i > 0; i --){
		add(index[i]);
		nex[i] = query(index[i]-1);
	}
	for(int i = 1; i <= n; i ++){
		//printf("%d====%d\n",pre[i],nex[i]);
		ans += (ll)(pre[i]*nex[i]);
	}*/
	cout << ans << endl;
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1e6 + 9;
ll fen1[Maxn],fen2[Maxn];
pair<ll,ll> sr[Maxn];
void update(int v,ll x,ll *fen){
	v++;
	for(v;v < Maxn;v += v & -v) fen[v] += x;
}
ll query(int v,ll * fen){
	ll res = 0;
	v++;
	for(v;v;v -= v & -v) res += fen[v];
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n;i++) scanf("%d",&sr[i].first),sr[i].second = i;
	sort(sr,sr+n);
	reverse(sr,sr+n);
	ll ans = 0;
	for(int i = 0 ; i < n;i++){
		ll id = sr[i].second;
		ans += query(id,fen2);
		ll x = query(id,fen1);
		update(id,x,fen2);
		update(id,1,fen1);
	}
	cout << ans << endl;
	return 0;
}


*/