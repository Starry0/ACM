#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n, m, k;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
char str[550][550];
bool vis[550][550];
typedef pair<int,int> P;
set<P> st;
struct Nod{
	int x, y, c;
}nod[510*510];
bool cmp(Nod a, Nod b) {
	return a.c > b.c;
}
void dfs(int x, int y, int c) {
	vis[x][y] = true;
	st.insert(make_pair(x,y));
	if(c == 0) return;
	for(int i = 0; i < 4; i ++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if(0 <= nx && nx < n && 0 <= ny && ny <= m && vis[nx][ny] == false && str[nx][ny] == '.') {
			dfs(nx, ny, c-1);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k) ;
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			cin >> str[i][j];
		}
	}
	for(int i = 0; i < k; i ++){
		int x, y, c;
		scanf("%d %d %d", &nod[i].x, &nod[i].y, &nod[i].c);
		
	}
	sort(nod,nod+k,cmp);
	for(int i = 0; i < k; i ++) {
		if(str[nod[i].x-1][nod[i].y-1] == '.') {
			// memset(vis, false, sizeof(vis));
			dfs(nod[i].x-1, nod[i].y-1, nod[i].c);
		}
	}
	printf("%d\n",(int)st.size());
	return 0;
}