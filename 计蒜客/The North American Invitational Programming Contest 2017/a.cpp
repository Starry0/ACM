#include <bits/stdc++.h>
using namespace std;
const int N = 301;
char str[N];
struct Nod{
	int l, m, r;
	Nod() {l = m = r = 0;}
}e[N];
struct Node {
	int num;
	bool l, r;
	Node(){
		num = l = r = 0;
	}
};
typedef pair<int,int> P;
map<int, map<int, P> > dp;
map<int, map<int, P> > :: iterator it;
map<int, p> :: iterator it1;
// set<Node> dp[N*N];
int main() {
	int n, tot = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		scanf("%s", str);
		stack<char> st;
		int ans = 0;
		for(int j = 0; str[j]; j ++) {
			if(str[j] == '(') {
				st.push('(');
				tot++;
			} else {
				if(!st.empty() && st.top() == '(') ans++, st.pop();
				else st.push(')');
			}
		}
		e[i].m = ans*2;
		int a = 0, b = 0;
		while(!st.empty()) {
			if(st.top() == '(') a++;
			else b++;
			st.pop();
		}
		e[i].l = a, e[i].r = b;
	}
	printf("%d\n",tot);
	int MAX = 0;
	dp[0][0] = P(0,0);
	for(int i = 0; i < n; i ++) {
		if(e[i].l == 0 && e[i].r == 0) {
			MAX += e[i].m;
			continue;
		}
		for(it = dp.begin(); it != dp.end(); ++ it) {
			// printf("%d\n",(*it).first);
			if((*it).first < e[i].l) continue;
		}
	
	}
	printf("%d\n",MAX);
	return 0;
}