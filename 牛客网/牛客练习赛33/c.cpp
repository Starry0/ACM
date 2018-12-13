#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
int num[10], sum, len;
char str[N];
bool vis[N][10];
struct Nod{
	int n, len, num;
	string s;
	int a[10];
};
string max(string a, string b) {
	if(a.length() > b.length()) return a;
	else if(a.length() < b.length()) return b;
	else {
		if(a > b) return a;
		else return b;
	}
}
void bfs() {
	queue<Nod> que;
	Nod ss;
	ss.n = ss.len = ss.num = 0;
	for(int i = 0; i < 10; i ++) ss.a[i] = 0;
	que.push(ss);
	vis[0][0] = 1;
	string MAX = "";
	while(que.size()) {
		Nod nod = que.front();
		que.pop();
		if(nod.len > len) continue;
		if(nod.len > 1 && nod.s[0] == '0') continue;
		if(nod.n == 0 && nod.num >= sum) {
			MAX = max(MAX, nod.s);
		}
		for(int i = 9; i >= 0; i --) {
			if(num[i]-nod.a[i] > 0) {
				int nn = (nod.n*10+i)%8;
				if(!vis[nod.len+1][nn]) {
					vis[nod.len+1][nn] = 1;
					Nod tmp;
					tmp.len = nod.len+1; tmp.n = nn;
					tmp.num = nod.num;
					if(i) tmp.num++;
					for(int j = 0; j < 10; j ++) tmp.a[j] = nod.a[j];
					tmp.a[i]++;
					tmp.s = nod.s+char(i+'0');
					que.push(tmp);
					// cout << tmp.s << endl;
				}
			}
		}
	}
	// cout << "-------------\n";
	if(MAX.length() == 0) printf("-1\n");
	else cout << MAX << endl;
}

void init() {
	memset(vis, 0, sizeof(vis));
	memset(str, 0, sizeof(str));
	for(int i = 0; i < 10; i ++) num[i] = 0;
	len = sum = 0;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		init();
		scanf("%s",str);
		for(int i = 0; str[i]; i ++) num[str[i]-'0'] ++;
		for(int i = 1; i <= 9; i ++) sum += num[i];
		len = strlen(str);
		bfs();
	}
	return 0;
}