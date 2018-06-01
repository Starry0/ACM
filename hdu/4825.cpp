#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
const int N = 100010;

struct Nod {
    int id;
    Nod *next[2];
    Nod() {
        next[0] = next[1] = NULL;
        id = 0;
    }
};
int t, n, m, x, cas;
void mkTree(Nod *root,int x) {
    Nod *p = root;
    for(int i = 31; i >= 0; i --) {
        int a = (x>>i)&1;
        if(p->next[a] == NULL) p->next[a] = new Nod;
        p = p->next[a];
    }
    p->id = x;
}
int find(Nod *root,int x) {
    Nod *p = root;
    for(int i = 31; i >= 0; i --) {
        int a = (x>>i)&1;
        if(p->next[a^1] != NULL) p = p->next[a^1];
        else p = p->next[a];
    }
    return p->id;
}
void dele(Nod *p) {
    for(int i = 0; i < 2; i ++) {
        if(p->next[i])
            dele(p->next[i]);
    }
    free(p);
    return;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        Nod *root = new Nod;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &x);
            mkTree(root,x);
        }
        printf("Case #%d:\n",++cas);
        while(m--) {
            scanf("%d", &x);
            printf("%d\n",find(root,x));
        }
        dele(root);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 3500005;
int sz, tree[N], sum[N][2];

void mkTree(int x) {
    int root = 0;
    for(int i = 31; i >= 0; i --) {
        int a = (x>>i)&1;
        if(!sum[root][a]) sum[root][a] = sz++;
        root = sum[root][a];
    }
    tree[root] = x;
}
int find(int x) {
    int root = 0;
    for(int i = 31; i >= 0; i --) {
        int a = (x>>i)&1;
        if(sum[root][a^1]) root = sum[root][a^1];
        else root = sum[root][a];
    }
    return tree[root];
}
int main() {
    int t, n, m, x, cas = 1;
    scanf("%d", &t);
    while(t--) {
        sz = 1;
        memset(sum, 0, sizeof(sum));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &n, &m);
        while(n--) {
            scanf("%d", &x);
            mkTree(x);
        }
        printf("Case #%d:\n", cas++);
        while(m--) {
            scanf("%d", &x);
            printf("%d\n",find(x));
        }
    }
    return 0;
}