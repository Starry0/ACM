#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
char str[N][12];
struct Nod{
    int ans;
    Nod *next[26];
    Nod(){
        ans = 0;
        for(int i = 0; i < 26; i ++){
            next[i] = NULL;
        }
    }
};
void mkTrie(Nod *root,char *s, int vis){
    Nod*p = root;
    for(int i = 0; s[i]; i ++){
    	if(((vis>>i)&1) == 0)continue;
        int a = s[i] - 'A';
        if(p->next[a]==NULL)p->next[a] = new Nod;
        p = p->next[a];
    }
    p->ans += 1;
}
void deleTrie(Nod *p){
    if(p == NULL) return;
    for(int i = 0; i < 26; i ++){
        if(p->next[i] != NULL){
            deleTrie(p->next[i]);
        }
    }
    free(p);
    return ;
}
int find(Nod *root,char *s, int vis){
    Nod* p = root;
    for(int i = 0; s[i]; i ++){
    	if(((vis>>i)&1) == 0)continue;
        int a = s[i]-'A';
        if(p->next[a]==NULL) return 0;
        p = p->next[a];
    }
    return p->ans;
}
int main() {
	int t, n, m, k;
	cin >> t;
	for(int ca = 1; ca <= t; ca ++) {
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i ++) cin >> str[i]+1;
		int ans = 0;
		if(k <= n*(n-1)/2) {
			bool flag = true;
			for(int i = 1; i < (1<<m); i ++) {
				Nod *root = new Nod;
				int cnt = 0;
				for(int j = 1; j <= n; j ++) {
					cnt += find(root, str[j]+1, i);
					mkTrie(root, str[j]+1, i);
				}
				if(n*(n-1)/2 - cnt >= k) ans++;
				deleTrie(root);
			}
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}