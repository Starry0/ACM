// #include<cstdio>
// #include<cstdlib>
// using namespace std;
// #define N 100050
// int v[N<<1],first[N],next[N<<1],en,col[N],f[N],fa[N];
// void AddEdge(int U,int V) {
// 	v[++en]=V;
// 	next[en]=first[U];
// 	first[U]=en;
// }
// void dfs(int U) {
// 	bool ok=1;
// 	for(int i=first[U];i;i=next[i]) if(v[i]!=fa[U]) {
// 	  	fa[v[i]]=U;
// 	  	dfs(v[i]);
// 	  	if(f[v[i]]!=col[U])
// 	  	  ok=0;
// 	  }
// 	if(ok)
// 	  f[U]=col[U];
// }
// void df2(int U) {
// 	bool Got=1;
// 	for(int i=first[U];i;i=next[i]) if(v[i]!=fa[U])
// 	if(!f[v[i]]) {
// 	    Got=0;
// 	    break;
// 	}
// 	if(Got){
// 	  	printf("YES\n%d\n",U);
// 	  	exit(0);
// 	}
// 	int cnt=0,vi;
// 	for(int i=first[U];i;i=next[i]) if(v[i]!=fa[U])
// 	  if(!f[v[i]]) {
// 	      ++cnt;
// 	      vi=v[i];
// 	    }
// 	if(cnt>1)
// 	  return;
// 	if(col[U]!=col[1])
// 	  return;
// 	for(int i=first[U];i;i=next[i]) if(v[i]!=fa[U] && v[i]!=vi)
// 	  if(f[v[i]]!=col[1])
// 	    return;
// 	df2(vi);
// }
// int n;
// int main() {
// 	int x,y;
// 	scanf("%d",&n);
// 	for(int i=1;i<n;++i)
// 	  {
// 	  	scanf("%d%d",&x,&y);
// 	  	AddEdge(x,y);
// 	  	AddEdge(y,x);
// 	  }
// 	for(int i=1;i<=n;++i)
// 	  scanf("%d",&col[i]);
// 	dfs(1);
// 	df2(1);
// 	puts("NO");
// 	return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e5+10;
int x[N], y[N], h[N], c[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i ++) scanf("%d %d",&x[i],&y[i]);
    for(int i = 1; i <= n; i ++) scanf("%d",&c[i]);
    int m = 0;
    for(int i = 1; i < n; i ++) {
        if(c[x[i]] != c[y[i]]){
            m++;
            h[x[i]]++;h[y[i]]++;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(h[i] == m){
            return 0*printf("YES\n%d\n",i);
        }
    }
    printf("NO\n");
    return 0;
}
