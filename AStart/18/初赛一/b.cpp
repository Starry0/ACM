#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 150010;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Nod{
	int val;
	struct Nod *top, *tail;
	struct Nod *last, *next;
	Nod() {
		val = -1;
		top = tail = last = next = NULL;
	}
}que[N];
int main() {
	int n, Q;
	while(scanf("%d%d", &n, &Q) != EOF){
		int op, u, w, val, v;
		Nod *p, *q;
		while(Q--) {
			op = read();
			if(op == 1) {
				u = read(); w = read(); val = read();
				Nod * q = (Nod*)malloc(sizeof(Nod));
				q->val = val;
				if(que[u].val == -1) {
					que[u].top = q;
					que[u].tail = q;
					continue;
				}
				if(w == 0) {
					que[u].top->last = q;
					q->next = que[u].top;
					que[u].top = q;
				} else {
					que[u].tail->next = q;
					q->last = que[u].tail;
					que[u].tail = q;
				}
			} else if(op == 2) {
				u = read(); w = read();
				if(que[u].top->val == -1) {
					printf("-1\n");
					continue;
				}
				if(w == 0) {
					printf("%d\n",que[u].top->val);
					q = que[u].top;
					que[u].top = que[u].top->next;
					free(q);
				} else if(w == 1){
					printf("%d\n",que[u].tail->val);
					q = que[u].tail;
					que[u].tail = que[u].tail->last;
					free(q);
				}
			} else if(op == 3) {
				u = read(); v = read(); w = read();
				if(w == 0) {
					que[u].tail->next = que[v].top;
					que[v].top->last = que[u].tail;
					que[u].tail = que[v].tail;
					que[v].tail = que[v].top = NULL;
					que[v].val = -1;
				} else if(w == 1) {
					que[u].tail->next = que[v].
				}
			}
		}
	}
	return 0;
}