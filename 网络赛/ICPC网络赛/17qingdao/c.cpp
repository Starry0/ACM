// #pragma comment(linker, "/STACK:1024000000,1024000000")
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N = 1100;
// const int M = 100000;
// char str[N][M];
// vector<int> vs;
// int a[N], nex[M];
// void init() {
// 	// for(int i = 0; i < N; i ++) str[i] = "";
// 	memset(a, 0, sizeof(a));
// 	vs.clear();
// }
// void init1(int x) {
// 	memset(nex, 0, sizeof(nex));
// 	int j = nex[0] = -1, i = 0;
// 	int len = a[x];
// 	while(i < len) {
// 		if(j == -1 || str[i] == str[j]) {
// 			nex[++i] = ++j;
// 		} else j = nex[j];
// 	}
// }
// bool KMP(int x, int y) {
// 	int i = 0, j = 0;
// 	int len = a[x], len1 = a[y];
// 	while(j < len1) {
// 		if(i == -1 || str[i] == str[j]) {
// 			i++;j++;
// 		} else i = nex[i];
// 		if(i == len) return true;
// 	}
// 	return false;
// }
// int main(){
// 	std::ios::sync_with_stdio(false);
// 	int t, n;
// 	scanf("%d", &t);
// 	while(t--) {
// 		init();
// 		scanf("%d", &n);
// 		int Max = -1;
// 		for(int i = 0; i < n; i ++) {
// 			// cin >> str[i];
// 			scanf("%s", str[i]);
// 			a[i] = strlen(str[i]);
// 			Max = max(Max, a[i]);
// 		}
// 		for(int i = 0; i < N; i ++) {
// 			if(a[i] == Max) vs.push_back(i);
// 		}
// 		int len = vs.size();
// 		if(len > 1) {
// 			bool flag = true;
// 			for(int i = 0; i < len-1; i ++) {
// 				if(str[vs[i]] != str[vs[i+1]]) {
// 					flag = false;
// 					break;
// 				}
// 			}
// 			if(!flag){
// 				printf("No\n");
// 				continue;
// 			}
// 		}
// 		int y = vs[0];
// 		for(int i = 0; i < n; i ++) {
// 			init1(i);
// 			if(!KMP(i,y)) {
// 				printf("No\n");
// 				goto tt;
// 			}
// 		}
// 		printf("%s\n",str[y]);
// 		// cout << str[y] << endl;
// 		tt:;
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
string str[N];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while(t --) {
		cin >> n;
		int MAX = 0, id = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> str[i];
			if(str[i].size() > MAX) {
				MAX = str[i].size();
				id = i;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(str[id].find(str[i]) != -1) cnt++;
		}
		if(cnt == n) cout << str[id] << endl;
		else cout <<"No\n";
	}
	return 0;
}