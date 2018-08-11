#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int N = 1e6+10;
const ll mod = 1e9+7;
char str[N];
ll a[N], c[N], ans = 1, cnt = 1;
map<ll,ll> mp;
struct Nod{
    ll is;
    Nod *next[26];
    Nod(){
        is = 0;
        for(int i = 0; i < 26; i ++){
            next[i] = NULL;
        }
    }
};

void update(int x, ll y){
    while(x < N){
        c[x] += y;
        x += lowbit(x);
    }
}
ll query(int x){
    ll sum = 0;
    while(x > 0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void mkTrie(Nod *root,char *s, ll num){
    Nod*p = root;
    for(int i = 0; s[i]; i ++){
        int a = s[i] - 'a';
        if(p->next[a]==NULL)p->next[a] = new Nod;
        p = p->next[a];
    }
    p->is = num;
}
void dfs(Nod *root) {
	Nod *p = root;
	for(int i = 0; i < 26; i ++) {
		if(p->next[i] != NULL) {
			dfs(p->next[i]);
		} else if(p->is != 0) {
			mp[p->is] = cnt++;
			return;
		}
	}
}
void find(Nod *root, char *s, int k){
    Nod* p = root;
    for(int i = 0; s[i]; i ++){
        int b = s[i]-'a';
        p = p->next[b];
        if(p->is != 0) {
        	ans = (a[k--]*(mp[p->is]-query(mp[p->is])-1)+ans)%mod;
        	update(mp[p->is],1);
        	p = root;
        }
    }
}
int main() {
	ll n, k;
	cin >> n >> k;
	a[0] = 1;
	a[1] = n-k+1;
	for(ll i = 2; i <= k; i ++) {
		a[i] = a[i-1]*(n+i-k)%mod;
	}
	Nod *root = new Nod;
	for(int i = 1; i <= n; i ++) {
		cin >> str;
		mkTrie(root, str, i);
	}
	dfs(root);
	cin >> str;
	find(root,str,k-1);
	printf("%lld\n",ans);
	return 0;
}