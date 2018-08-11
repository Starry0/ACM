#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
string s;
int main() {	
	cin >> s;
	stack<int> st;
	stack<char> st1;
	int x, y, len = s.length();
	for(int i = 0; i < len; i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			int ans = s[i] - '0';
			while(s[i+1] >= '0' && s[i+1] <= '9') {
				ans = ans * 10 + s[i+1] - '0';
				i++;
			}
			st.push(ans%10000);
		} else if(s[i] == '+') {
			while(!st1.empty()) {
				x = st.top(), st.pop();
				y = st.top(), st.pop();
				if(st1.top() == '+') {
					st.push((x+y)%10000);
				} else if(st1.top() == '*') {
					st.push((x*y)%10000);
				}
				st1.pop();
			}
			st1.push('+');
		} else if(s[i] == '*') {			
			while(!st1.empty() && st1.top() == '*') {
				x = st.top(), st.pop();
				y = st.top(), st.pop();
				st.push((x*y)%10000);
				st1.pop();
			}
			st1.push('*');
		}
	}
	while(!st1.empty()) {
		x = st.top(), st.pop();
		y = st.top(), st.pop();
		if(st1.top() == '+') {
			st.push((x+y)%10000);
		} else {
			st.push((x*y)%10000);
		}
		st1.pop();
	}
	cout << st.top() << endl;
	return 0;
}