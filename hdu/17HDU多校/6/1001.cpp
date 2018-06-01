#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int N = 500010;
char str[N], str1[N];
struct Nod {
	int num;
	int id;
	Nod *next[26];
	Nod() {
		for(int i = 0; i < 26; i ++) {
			next[i] = NULL;
		}
		id = num = 0;
	}
};
void mkTree(Nod *root, char *str) {
	Nod *p = root;
	for(int i = 0; str[i]; i ++) {
		int x = str[i] - 'a';
		if(p->next[x] == NULL) p->next[x] = new Nod;
		p = p->next[x];
		p->num++;
	}
	p->id++;
}
int len;
int dfs(Nod *p, int dept) {
	if(dept == len) {
		return p->id;
	}
	int num = 0;
	int x = str1[dept] - 'a';
	for(int i = 0; i < 26; i ++) {
		if(p->next[i] != NULL) {
			if(x == i) {
				num += dfs(p->next[i], dept+1);
			}else {
				num += dfs(p->next[i], dept);
			}
		}
	}
	return num;
}
int find(char *str, char *str1, Nod *root) {
	Nod *p = root;
	for(int i = 0; str[i]; i ++) {
		int x = str[i] - 'a';
		if(p->next[x] == NULL) return 0;
		p = p->next[x];
	}
	return dfs(p, 0);
}
void dele(Nod *p) {
	for(int i = 0; i < 26; i ++) {
		if(p->next[i] != NULL) dele(p->next[i]);
	}
	free(p);
	return;
}
int main() {	
	int t, n, q;
	scanf("%d", &t);
	while(t--) {
		Nod *root = new Nod;
		scanf("%d %d", &n, &q);
		while(n--) {
			scanf("%s", str);
			mkTree(root, str);
		}
		while(q--) {
			scanf("%s %s",str, str1);
			len = strlen(str1);
			printf("%d\n",find(str, str1, root));
		}
		dele(root);
	}
	return 0;
}