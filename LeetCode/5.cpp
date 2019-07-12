#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string str = "*#";
		for(int i = 0; i < s.length(); i ++) {
			str += s[i];
			str += '#';
		}
		str += "$";
		int *p = new int[2*s.length()+2];
		memset(p, 0, (2*s.length()+2)*sizeof(int));
		int MAX = 0, id = 0, index = 0;
		for(int i = 2; i <= 2*s.length(); i ++) {
			if(p[id]+id > i) p[i] = min(p[2*id-i], p[id]+id-i);
			else p[i] = 1;
			while(str[i-p[i]] == str[i+p[i]]) ++ p[i];
			if(p[i]+i > p[id]+id) id = i;
			if(MAX < p[i]) {
				MAX = p[i];
				index = i;
			}
		}
		string result = "";
		for(int i = index-MAX+1; i < index+MAX; i ++) {
			if(str[i] != '$' && str[i] != '*' && str[i] != '#')
				result += str[i];
		}
		delete []p;
		return result;
    }
};
int main() {
	Solution sol;
	string s = "cbbd";
	cout << sol.longestPalindrome(s);
	
	return 0;
}