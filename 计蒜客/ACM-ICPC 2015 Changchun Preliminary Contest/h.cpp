#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int t, n, q, x;
struct Nod{
	int num;
	bool is;
	Nod *lchild, *rchild;
	Nod() {
		num = -1;
		is = false;
		lchild = rchild = NULL;
	}
};
void mkTree(Nod *p, int val) {
	if(p->num == -1) {
		p->num = val;
		return;
	}
	if(p->num > val) {
		if(p->rchild==NULL)p->rchild = new Nod;
		mkTree(p->rchild,val);
	} else {
		if(p->lchild==NULL)p->lchild = new Nod;
		mkTree(p->lchild,val);
	}
}
void find(Nod *p, int x) {
	if(p->num == x) {
		if(!p->is) {
			p->is = true;
			return;
		}
	}
	if(p->num > x) {
		printf("E");
		find(p->rchild,x);
	} else {
		printf("W");
		find(p->lchild, x);
	}
}
int main() {
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		Nod *root = new Nod;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			mkTree(root,x);
		}
		scanf("%d", &q);
		while(q--) {
			scanf("%d", &x);
			find(root,x);printf("\n");
		}
	}
	return 0;
}