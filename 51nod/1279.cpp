#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
const int N = 50010;
stack<int> st;
int main(){
	int n, m, x, ans = 0;
	scanf("%d%d",&n,&m);
	scanf("%d", &x); st.push(x);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &x);
		if(x <= st.top()) st.push(x);
		else st.push(st.top());
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%d", &x);
		if(st.size() == 0) continue;
		while(x > st.top()) {
			st.pop();
			if(st.size() == 0) break;
		}
		if(st.size() > 0) {
			st.pop();
			ans = i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
4 4
3 6 8 9
4 6 2 2
*/