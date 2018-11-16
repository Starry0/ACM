#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
const int M = 1e5+10;
int n, a[N], flag;
bool vis[N];
vector<int> vs[N];
struct nod{
	int val;
	struct nod *lchild, *rchild;
	nod() {
		lchild = rchild = NULL;
	}
};
bool cmp(int x, int y) {
	return x > y;
}
int insert(nod *p, int x) {
	if(p->val > a[x]) {
		if(p->lchild == NULL) {
			if(__gcd(a[p->val], a[x]) > 1) {
				p->lchild = (nod*)malloc(sizeof(nod));
				p->lchild->val = x;
				return x;
			} else return -1;
		} else {
			return insert(p->lchild, x);
		}
	} else if(p->val < a[x]){
		if(p->rchild == NULL) {
			if(__gcd(a[p->val], a[x]) > 1) {
				p->rchild = (nod*)malloc(sizeof(nod));
				p->rchild->val = x;
				return x;
			} else return -1;
		} else {
			return insert(p->rchild, x);
		}
	} else return -1;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		for(int j = i+1; j <= n; j ++) {
			if(__gcd(a[i],a[j]) > 1) {
				vs[i].push_back(j);
				vs[j].push_back(i);
			}
		}
	}
	for(int i = 1; i <= n; i ++) sort(vs[i].begin(),vs[i].end(), cmp);
	for(int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		queue<int> que;
		que.push(i);
		nod *root = (nod*)malloc(sizeof(nod));
		root->val = i;
		while(!que.empty()) {
			int v = que.front();que.pop();
			for(int j = 0; j < vs[v].size(); j ++) {
				int u = vs[v][j];
				if(vis[u]) continue;
				printf("%d\n",u);
				flag = insert(root,u);
				if(flag == -1) break;
				else {
					vis[u] = 1;
					que.push(u);
				}
			}
			if(flag == -1) break;
		}
		for(int j = 1; j <= n; j ++) if(vis[j] == 0) flag = -1;
		if(flag != -1) {
			return 0*printf("Yes\n");
		}
	}
	printf("No\n");
	return 0;
}