// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N = 3010;
// vector<int> vs[N][2];
// bool vis1[N], vis2[N], flag, flag1;
// void dfs(int v) {
// 	if(vis1[v]) {
// 		flag = false;
// 		return;
// 	}
// 	vis1[v] = 1;
// 	if(vs[v][0].size() == 0 && vs[v][1].size() == 0) return;
// 	if(vs[v][0].size() == 1 && vs[v][1].size() == 1) {
// 		dfs(vs[v][0][0]);
// 		dfs(vs[v][1][0]);
// 	} else if(vs[v][0].size() == 1 && vs[v][1].size() == 0) {
// 		if(flag1) {
// 			flag1 = false;
// 			dfs(vs[v][0][0]);
// 		} else flag = false;
// 	} else flag = false;
// }
// int main() {
// 	int n, a, b, root = -1;
// 	string s;
// 	cin >> n;
// 	for(int i = 0; i < n; i ++) {
// 		cin >> a >> b >> s;
// 		vis1[a] = vis2[b] = true;
// 		if(s[0] == 'L') {
// 			vs[a][0].push_back(b);
// 		} else {
// 			vs[a][1].push_back(b);
// 		}
// 	}
// 	flag1 = flag = true;
// 	for(int i = 1; i < N; i ++) {
// 		if(vis1[i] && !vis2[i]) {
// 			if(root == -1) root = i;
// 			else flag = false;
// 		}
// 	}
// 	if(!flag || root == - 1) return 0*printf("No\n");
// 	memset(vis1, 0, sizeof(vis1));
// 	dfs(root);
// 	if(flag) printf("Yes\n");
// 	else printf("No\n");
// 	return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3010;
vector<int> vs[N][2];
bool vis1[N], vis2[N], flag;

int main() {
	int n, a, b, root = -1;
	string s;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> a >> b >> s;
		vis1[a] = vis2[b] = true;
		if(s[0] == 'L') {
			vs[a][0].push_back(b);
		} else {
			vs[a][1].push_back(b);
		}
	}
	flag = true;
	for(int i = 1; i < N; i ++) {
		if(vis1[i] && !vis2[i]) {
			if(root == -1) root = i;
			else flag = false;
		}
	}
	if(!flag || root == - 1) return 0*printf("No\n");
	memset(vis1, 0, sizeof(vis1));
	
	int ans = 0;
	for(int i = 1; i <= 3000; i ++) {
		if(vs[i][0].size()==1&&vs[i][1].size()==1)continue;
		if(vs[i][0].size()==0&&vs[i][1].size()==0)continue;
		if(vs[i][0].size()==1&&vs[i][1].size()==0)ans++;
		else if(vs[i][0].size()==0&&vs[i][1].size()!=0)flag = false;
		else flag = false;
	}
	if(flag&&ans<=1) printf("Yes\n");
	else printf("No\n");
	return 0;
}