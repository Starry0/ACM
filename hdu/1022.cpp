#include <iostream>
#include <stack>
using namespace std;
const int N = 1e4+10;
char s1[N], s2[N];
bool vis[N];

int main() {
	int n, cnt, pos;
	while(cin >> n >> s1 >> s2) {
		stack<int> st;
		bool flag = true; 
		pos = cnt = 0;
		for(int i = 0; i < n; i ++) {
			st.push(s1[i]);
			vis[cnt++] = 1;
			while(!st.empty() && st.top() == s2[pos]) {
				vis[cnt++] = 0;
				pos ++;
				st.pop();
			}
		}
		if(!st.empty()) printf("No.\nFINISH\n");
		else {
			printf("Yes.\n");
			for(int i = 0; i < 2*n; i ++) {
				if(vis[i]) printf("in\n");
				else printf("out\n");
			}
			printf("FINISH\n");
		}
	}
	return 0;
}