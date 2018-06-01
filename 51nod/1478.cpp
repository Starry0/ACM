#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
typedef pair<int,char> P;
stack<P> st;
const int N = 1000010;
char str[N];
int main() {
	cin >> str;
	int ans = 0, MAX = 0;
	st.push(make_pair(-1,'#'));
	for(int i = 0; str[i]; i ++) {
		if(str[i] == ')') {
			if(st.top().second == '('){
				st.pop();
				int x = st.top().first;
				if(i - x > MAX) {
					MAX = i - x;
					ans = 1;
				} else if(i - x == MAX) ans++;
			}else{
				st.push(P(i,')'));
			}
		} else st.push(P(i,str[i]));
	}
	if(MAX == 0) cout << "0 1\n";
	else cout << MAX << ' ' << ans << endl;
	return 0;
}
//)((())))(()())
//   (((()))(((