#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
#define ll long long
using namespace std;
const int N = 1100010;
int t, len;
char str[N];
ll pos[N], ans[N];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%s",str+1);
		len = strlen(str+1);
		for(int i = 0; i <= len; i ++) {
			pos[i] = -1;
			ans[i] = 0;
		}
		stack<int> st;
		for(int i = 1; i <= len; i ++) {
			if(str[i] == '(') st.push(i);
			else {
				if(!st.empty()) {
					pos[i] = st.top();
					st.pop();
				}
			}
		}
		ll toc = 0;
		for(int i = 1; i <= len; i ++) {
			if(pos[i] != -1) {
				ans[i] = ans[pos[i]-1]+1;
				toc += ans[i];
			}
		}
		cout << toc << endl;
	}
	return 0;
}