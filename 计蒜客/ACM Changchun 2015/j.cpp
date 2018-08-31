#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
int s[N];
struct Nod{
    int is;
    Nod *next[2];
    Nod(){
        is = 0;
        next[0] = next[1] = NULL;
    }
};
void mkTrie(Nod *root,int x){
    Nod*p = root;
    for(int i = 30; i >= 0; i --){
        int a = (x>>i)&1;
        if(p->next[a]==NULL)p->next[a] = new Nod;
        p = p->next[a];
        p->is++;
    }
}
void del(Nod *root, int x) {
	Nod*p = root;
	for(int i = 30; i >= 0; i --) {
		int a = (x>>i)&1;
		p = p->next[a];
		p->is--;
	}
}
int find(Nod *root, int x) {
	int MAX = 0;
	Nod *p = root;
	for(int i = 30; i >= 0; i --) {
		int a = (x>>i)&1;
		if(a) {
			if(p->next[0] != NULL && p->next[0]->is != 0) {
				MAX += (1<<i);
				p = p->next[0];
			} else p = p->next[a];
		} else {
			if(p->next[1] != NULL && p->next[1]->is != 0) {
				MAX += (1<<i);
				p = p->next[1];
			} else p = p->next[a];
		}
	}
	return MAX;
}
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		Nod *root = new Nod;
		for(int i = 1; i <= n; i ++) scanf("%d", &s[i]), mkTrie(root, s[i]);
		int MAX = 0;
		for(int i = 1; i <= n; i ++) {
			del(root, s[i]);
			for(int j = i+1; j <= n; j ++) {
				del(root, s[j]);
				MAX = max(MAX, find(root, s[i]+s[j]));
				mkTrie(root, s[j]);
			}
			mkTrie(root,s[i]);
		}
		cout << MAX << endl;
	}
	return 0;
}