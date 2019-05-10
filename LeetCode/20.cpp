#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		for(int i = 0; i < s.length(); i ++) {
			if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
			else {
				if(st.empty()) return false;
				if(st.top() == '(' && s[i] != ')') return false;
				if(st.top() == '[' && s[i] != ']') return false;
				if(st.top() == '{' && s[i] != '}') return false;
				st.pop();
			}
		}
		return st.empty();
    }
};

int main() {
	Solution sol;
	cout << sol.isValid("()[]{}");
	return 0;
}